#include <bits/stdc++.h>
 
 using namespace std;
 
 typedef long long ll;
 typedef pair<int, int> PII;
 
 #define fi first
 #define se second
 #define mp make_pair
 #define pb push_back
 #define pct __builtin_popcount
 
 // 1<<19
 #define NN 1000010
 #define N 20
 
 string s0;
 int n;
 bool v[NN];
 vector<int> A[NN];
 int C[N][N];
 
 int ff(int i) {
 	int num = 0;
 	int nw = n;
 	int S = 1;
 	for (int j = 0; j < (2*n); j ++) {
 		if ((i>>j)&1) {
 			S *= C[nw][num];
 			nw -= num;
 			num = 0;
 		} else num ++;
 	}
 	return S;
 }
 
 int main() {
 	for (int i = 0; i < N; i ++) {
 		C[i][0] = 1;
 		for (int j = 1; j <= i; j ++)
 			C[i][j] = C[i-1][j] + C[i-1][j-1];
 	}
 	int _;
 	cin >> _;
 	for (int __ = 1; __ <= _; __ ++) {
 		cin >> s0;
 		n = (int) s0.length();
 		int nn = 1<<(2*n);
 		memset(v, 0, sizeof v);
 		for (int i = 0; i < nn; i ++)
 			A[i].clear();
 		
 		
 		queue<int> q;
 		for (int i = 0; i < nn; i ++) if (pct(i) == n) {
 			vector<int> a(n+1, 0);
 			int cur = 0;
 			int num = 0;
 			string s = "";
 			for (int j = 0; j < (2*n); j ++) {
 				if ((i>>j)&1) {
 					if (cur) {
 						s += (char)('0'+num);
 						a[num]++;
 					}
 					num = 0;
 					cur++;
 				} else num ++;
 			}
 			s += (char)('0'+num);
 			a[num]++;
 			//cout << s0 << " " << s << endl;
 			if (s == s0) {
 				v[i] = true;
 				q.push(i);
 				//puts ("HI");
 			}
 			int nw = 0;
 			int p = 0;
 			for (int j = 0; j < n+1; j ++) {
 				if (j) {
 					p += (1<<nw);
 					nw++;
 				}
 				nw += a[j];
 			}
 			A[p].pb(i);
 		}
 		while (!q.empty()) {
 			int x = q.front();
 			q.pop();
 			for (vector<int>::iterator i = A[x].begin(); i != A[x].end(); i ++)
 				if (!v[*i]) {
 					v[*i] = true;
 					q.push(*i);
 				}
 		}
 		ll S = 0;
 		for (int i = 0; i < nn; i ++)
 			if (v[i]) S += ff(i);
 		string s = "";
 		for (int i = 1; i <= n; i ++) {
 			int t = 0;
 			for (int j = 0; j < n; j ++) 
 				if (s0[j] == (char)('0'+i)) t++;
 			s += (char)('0'+t);
 		}
 		if (s0 != s) S++;
 		
 		printf ("Case #%d: ", __);
 		cout << S << endl;
 	}
 	return 0;
 }