#include <cstdio>
 #include <cstdlib>
 #include <cstring>
 #include <string>
 #include <vector>
 #include <cmath>
 #include <algorithm>
 #include <cassert>
 #include <set>
 #include <map>
 #include <queue>
 #include <iostream>
 #include <fstream>
 using namespace std;
 #define pb push_back 
 #define REP(i,n) for(int i=0;i<(n);i++ )
 typedef long long LL;
 typedef pair<int, int> pii;
 
 map<pii, int> T1;
 pii T2[1024];
 
 
 int main(){
     int caseNumber;
     //scanf("%d", &caseNumber);
     cin>>caseNumber;
     REP(caseN, caseNumber) {
     	int R, C; cin>>R>>C;
     	int K = 2 * R + 2 * C;
     	int offset = 0;
     	int x = -1, y = 0;
     	REP(i, C) {
     		pii p = make_pair(x, y);
     		T1[p] = offset;
     		T2[offset] = p;
     		y++;
     		offset++;
     	}
     	x = 0, y = C;
     	REP(i, R) {
     		pii p = make_pair(x, y);
     		T1[p] = offset;
     		T2[offset] = p;
     		offset++; x++;
     	}
     	x = R, y = C - 1;
     	REP(i, C) {
     		pii p = make_pair(x, y);
     		T1[p] = offset;
     		T2[offset] = p;
     		offset++; y--;
     	}
     	x = R - 1, y = -1;
     	REP(i, R) {
     		pii p = make_pair(x, y);
     		T1[p] = offset;
     		T2[offset] = p;
     		offset++; x--;
     	}
     	int v[100];
     	REP(i, K / 2) {
     		int g, h; cin>>g>>h; g--;h--;
     		v[g] = h; v[h] = g;
     		// cin>>v[i]; v[i]--;
     	}
     	int good = false;
     	int dir[5][2] = {-1, -1,1, 0, -1, 0, 0, -1, 0, 1};
     	REP(_i, 1<<(R * C)) {
     		bool ok = true;
     		REP(i, K) {
     			int x, y, d;
     			// int ii = i;
     			if (i < C) {
     				d = 1;
     			} else if (i < C + R) {
     				d = 3;
     			} else if (i < C + R + C) {
     				d = 2;
     			} else {
     				d = 4;
     			}
     			x = T2[i].first, y = T2[i].second;
     			// cout<<x<<' '<<y<<' '<<i<<' '<<d<<endl;
     			x += dir[d][0]; y += dir[d][1];
     			// cout<<x<<' '<<y<<' '<<i<<' '<<d<<endl;
     			assert(x >= 0 && y >= 0 && x < R && y < C);
     			while (1) {
     				char t;
     				if (((1<<(x * C + y))&_i)) t = '\\'; else t  = '/';
     				if (t == '/') {
     					if (d == 1) d = 3;else
     					if (d == 3) d = 1;else
     					if (d == 2) d = 4;else
     					if (d == 4) d = 2;
     				} else {
     					if (d == 1) d = 4; else
     					if (d == 4) d = 1;else
     					if (d == 2) d = 3;else
     					if (d == 3) d = 2;
 
     				}
     				// cout<<t;
     				x += dir[d][0]; y += dir[d][1];
     				bool good = (x >= 0 && y >= 0 && x < R && y < C);
     				if (!good) {
     					//out
     					// cout<<'g'<<x<<' '<<y<<' '<<d<<endl;
     					pii pr = make_pair(x, y);
     					assert(T1.count(pr));
     					int pos = T1[pr];
     					// cout<<'r'<<i<<' '<<pos<<endl;
     					ok &= pos == v[i];
     					break;
     				}
     			}
 
     		}
     		// cout<<_i<<endl;
 					// if  {
     		if (ok) {
     			printf("Case #%d:\n", caseN + 1);
     			REP(i, R) {
     				REP(j, C) 
     					if ((1<<(i * C + j))&_i) {
     						putchar('\\');
     					} else putchar('/');
     				puts("");
     			}
     			// puts("");
     			good = true;
     			break;
     		}
     	}
     	if (!good)
     	printf("Case #%d:\nIMPOSSIBLE\n", caseN + 1);
     }
     return 0;
 }