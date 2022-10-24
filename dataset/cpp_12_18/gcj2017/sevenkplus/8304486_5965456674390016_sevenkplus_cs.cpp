#include <bits/stdc++.h>
 
 using namespace std;
 
 typedef long long ll;
 typedef pair<int, int> PII;
 
 #define fi first
 #define se second
 #define mp make_pair
 #define pb push_back
 
 #define INF 1000000007
 #define N 2010
 int n;
 int E[N], L[N], D[N];
 int v[N];
 
 int main() {
 	int _;
 	cin >> _;
 	for (int __ = 1; __ <= _; __ ++) {
 		cin >> n;
 		for (int i = 0; i < n*2; i ++) {
 			// start = i
 			cin >> E[i] >> L[i] >> D[i];
 			E[i] --;
 		}
 		int S = INF;
 		for (int p = 0; p < (1<<n); p ++) {
 			memset(v, 0, sizeof v);
 			int cur = 0;
 			int x = 0;
 			int es = 0;
 			int T = 0;
 			while (true) {
 				if (v[x] == 2) break;
 				v[x] ++;
 				es++;
 				int e;
 				if (v[x] == 1) e = x*2+((p>>x)&1);
 				else e = x*2+1-((p>>x)&1);
 				int wt = L[e] - cur;
 				if (wt < 0) wt += 24;
 				T += wt;
 				T += D[e];
 				cur = (L[e] + D[e])%24;
 				x = E[e];
 			}
 			if (es == n*2) S = min(S, T);
 		}
 		printf ("Case #%d: %d\n", __, S);
 	}
 	return 0;
 }