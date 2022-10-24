#include <cstdio>
 #include <cstring>
 
 #include <vector>
 #include <queue>
 #include <algorithm>
 #include <string>
 #include <map>
 
 using namespace std;
 
 const int maxs = 50;
 int t[2 * maxs + 1][2 * maxs + 1];
 int f[2 * maxs + 1][2 * maxs + 1];
 int c[2 * maxs + 1][2 * maxs + 1];
 
 int dx[6] = {-1, -1, 0, 0, 1, 1};
 int dy[6] = {-1, 0, -1, 1, 0, 1};
 
 int main() {
 	int T;
 	scanf("%d", &T);
 	int cc = 1;
 	for (int cn = 1; cn <= T; ++cn) {
 		memset(t, 0, sizeof(t));
 		memset(f, 0, sizeof(f));
 		int s, m;
 		scanf("%d%d", &s, &m);
 		vector<int> x(m), y(m);
 		for (int i = 0; i < m; ++i) {
 			scanf("%d%d", &x[i], &y[i]);
 			x[i]--, y[i]--;
 		}
 		int S = 2 * s - 2;
 		int reti = -1;
 		string ret = "";
 		for (int i = 0; i < s; ++i) {
 			t[0][i] = 1 << 0;
 			t[i][0] = 1 << 1;
 			t[S - i][S] = 1 << 2;
 			t[S][S - i] = 1 << 3;
 			t[i][s - 1 + i] = 1 << 4;
 			t[s - 1 + i][i] = 1 << 5;
 		}
 		t[0][0] = 1 << 6;
 		t[0][s - 1] = 1 << 7;
 		t[s - 1][0] = 1 << 8;
 		t[s - 1][S] = 1 << 9;
 		t[S][s - 1] = 1 << 10;
 		t[S][S] = 1 << 11;
 
 		for (int i = 0; i < m; ++i) {
 			cc++;
 			f[x[i]][y[i]] = 1;
 			int bb = t[x[i]][y[i]];
 			
 			queue<pair<int, int> > Q;
 			Q.push(make_pair(x[i], y[i]));
 			c[x[i]][y[i]] = cc;
 			while (!Q.empty()) {
 				pair<int, int> now = Q.front(); Q.pop();
 				for (int i = 0; i < 6; ++i) {
 					int xx = now.first + dx[i], yy = now.second + dy[i];
 					if (xx < 0 || yy < 0 || xx > S || yy > S || abs(yy - xx) >= s) continue;
 					if (c[xx][yy] == cc) continue;
 					if (f[xx][yy]) {
 						bb |= t[xx][yy];
 						Q.push(make_pair(xx, yy));
 						c[xx][yy] = cc;
 					}
 				}
 			}
 
 			// check bridge
 			int numb = 0, numf = 0;
 			for (int j = 6; j <= 11; ++j)
 				if (bb & (1 << j)) numb++;
 			// check fork
 			for (int j = 0; j <= 5; ++j)
 				if (bb & (1 << j)) numf++;
 
 			if (numb >= 2) {
 				ret += "-bridge";
 			}
 			if (numf >= 3) {
 				ret += "-fork";
 			}
 			
 			// check ring
 			bool ring = false;
 			for (int k = 0; k < 6; ++k) {
 				int xx = x[i] + dx[k], yy = y[i] + dy[k];
 				if (xx < 0 || yy < 0 || xx > S || yy > S || abs(yy - xx) >= s) continue;
 				if (f[xx][yy]) continue;
 				if (t[xx][yy]) continue;
 
 				queue<pair<int, int> > Q;
 				Q.push(make_pair(xx, yy));
 				bool ispos = true;
 				cc++;
 				c[xx][yy] = cc;
 
 				while (!Q.empty() && ispos) {
 					pair<int, int> now = Q.front(); Q.pop();
 					for (int j = 0; j < 6; ++j) {
 						int xx = now.first + dx[j], yy = now.second + dy[j];
 						if (xx < 0 || yy < 0 || xx > S || yy > S || abs(yy - xx) >= s) continue;
 						if (f[xx][yy]) continue;
 						if (c[xx][yy] == cc) continue;
 						if (t[xx][yy] != 0) {
 							ispos = false;
 							break;
 						} else {
 							Q.push(make_pair(xx, yy));
 							c[xx][yy] = cc;
 						}
 					}
 				}
 				if (ispos) {
 					ring = true;
 				}
 			}
 			if (ring) {
 				ret += "-ring";
 			}
 			if (ret.size() > 0) {
 				reti = i + 1;
 				break;
 			}
 		
 		}
 		if (ret.size() > 0) {
 			printf("Case #%d: %s in move %d\n", cn, ret.substr(1).c_str(), reti);
 		} else {
 			printf("Case #%d: none\n", cn);
 		}
 		
 	}
 	return 0;
 }
