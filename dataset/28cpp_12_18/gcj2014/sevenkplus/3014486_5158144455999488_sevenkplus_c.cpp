#include <cstdio>
 #include <cstring>
 #include <string>
 #include <iostream>
 #include <sstream>
 #include <map>
 #include <set>
 #include <vector>
 #include <queue>
 #include <bitset>
 #include <numeric>
 #include <ctime>
 #include <cassert>
 #include <algorithm>
 
 using namespace std;
 
 typedef pair<int, int> PII;
 typedef long long ll;
 
 #define fi first
 #define se second
 #define mp make_pair
 #define pb push_back
 #define pct __builtin_popcount
 
 #define INF 1000000007
 #define N 1010
 int x0[N], y0[N], x1[N], y1[N], n, W, H;
 int d[N]; bool v[N];
 
 int mdis(int x0, int y0, int x1, int y1) {
 	return max(abs(x1-x0),abs(y1-y0))-1;
 }
 
 int dis(int x, int y) {
 	int S = INF;
 	S = min(S, mdis(x0[x], y0[x], x0[y], y0[y]));
 	S = min(S, mdis(x0[x], y0[x], x0[y], y1[y]));
 	S = min(S, mdis(x0[x], y0[x], x1[y], y0[y]));
 	S = min(S, mdis(x0[x], y0[x], x1[y], y1[y]));
 	S = min(S, mdis(x0[x], y1[x], x0[y], y0[y]));
 	S = min(S, mdis(x0[x], y1[x], x0[y], y1[y]));
 	S = min(S, mdis(x0[x], y1[x], x1[y], y0[y]));
 	S = min(S, mdis(x0[x], y1[x], x1[y], y1[y]));
 	S = min(S, mdis(x1[x], y0[x], x0[y], y0[y]));
 	S = min(S, mdis(x1[x], y0[x], x0[y], y1[y]));
 	S = min(S, mdis(x1[x], y0[x], x1[y], y0[y]));
 	S = min(S, mdis(x1[x], y0[x], x1[y], y1[y]));
 	S = min(S, mdis(x1[x], y1[x], x0[y], y0[y]));
 	S = min(S, mdis(x1[x], y1[x], x0[y], y1[y]));
 	S = min(S, mdis(x1[x], y1[x], x1[y], y0[y]));
 	S = min(S, mdis(x1[x], y1[x], x1[y], y1[y]));
 	if (max(x0[x], x0[y]) <= min(x1[x],x1[y])) {
 		S = min(S, abs(y0[x]-y0[y])-1);
 		S = min(S, abs(y0[x]-y1[y])-1);
 		S = min(S, abs(y1[x]-y0[y])-1);
 		S = min(S, abs(y1[x]-y1[y])-1);
 	}
 	if (max(y0[x], y0[y]) <= min(y1[x], y1[y])) {
 		S = min(S, abs(x0[x]-x0[y])-1);
 		S = min(S, abs(x0[x]-x1[y])-1);
 		S = min(S, abs(x1[x]-x0[y])-1);
 		S = min(S, abs(x1[x]-x1[y])-1);
 	}
 	return S;
 }
 
 int ff(int s, int t, int c) {
 	for (int i = 0; i < c; i ++) d[i] = INF;
 	d[s] = 0;
 	memset(v, 0, sizeof v);
 	for (int i = 0; i < c; i ++) {
 		int mw = 0;
 		while (v[mw]) mw ++;
 		for (int j = 0; j < c; j ++) 
 			if (!v[j] && d[j] < d[mw]) mw = j;
 		v[mw] = 1;
 		if (mw == t) return d[t];
 		for (int j = 0; j < c; j ++) 
 			if (!v[j]) d[j] = min(d[j], d[mw] + dis(mw,j));
 	}
 }
 
 int main () {
 	int _; cin >> _;
 	for (int __ = 1; __ <= _; __ ++) {
 		cin >> W >> H >> n;
 		for (int i = 0; i < n; i ++) 
 			cin >> x0[i] >> y0[i] >> x1[i] >> y1[i];
 		x0[n] = -1; y0[n] = 0; x1[n] = -1; y1[n] = H-1;
 		x0[n+1] = W; y0[n+1] = 0; x1[n+1] = W; y1[n+1] = H-1;
 		printf ("Case #%d: %d\n", __, ff(n,n+1,n+2)); 
 	}
 	return 0; 
 }