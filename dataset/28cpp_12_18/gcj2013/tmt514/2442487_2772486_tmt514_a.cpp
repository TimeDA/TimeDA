#include <cstdio>
 #include <cstring>
 #include <cmath>
 #include <algorithm>
 #include <vector>
 #include <queue>
 using namespace std;
 
 #define FOR(it, c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); it++)
 #define SZ(c) ((int)(c).size())
 
 typedef long long LL;
 
 int cs;
 int n, m;
 const LL MOD = 1000002013LL;
 
 LL tri(LL x) {
 	return x*(x-1)/2 % MOD;
 }
 
 void solve() {
 	LL orig=0, better=0;
 	vector<pair<int, pair<int, int> > > a;
 	vector<pair<int, int> > b;
 	scanf("%d%d", &n, &m);
 	for(int i=0;i<m;i++) {
 		int l, r, p;
 		scanf("%d%d%d", &l, &r, &p);
 		a.push_back(make_pair(r, make_pair(l, p)));
 		b.push_back(make_pair(l, p));
 		orig = (orig + tri(r-l) * p) % MOD;
 	}
 	sort(a.begin(), a.end());
 	sort(b.begin(), b.end());
 	priority_queue<pair<int, int> > Q;
 	int I=0,J=0;
 	while(J<SZ(a)) {
 		while(I<SZ(b) && b[I].first <= a[J].first) {
 			Q.push(b[I]);
 			I++;
 		}
 		int rem = a[J].second.second;
 		//int xL = a[J].second.first;
 		while(rem) {
 			pair<int, int> F = Q.top(); Q.pop();
 			int rP = min(rem, F.second);
 			better = (better + tri(a[J].first - F.first) * rP) % MOD;
 			F.second -= rP;
 			rem -= rP;
 			if(F.second > 0) Q.push(F);
 		}
 		J++;
 	}
 	LL ans = ((better - orig)%MOD + MOD)%MOD;
 	printf("Case #%d: %I64d\n", cs, ans);
 	fprintf(stderr, "Case #%d: %I64d\n", cs, ans);
 }
 
 int main(void) {
 	int T;
 	scanf("%d", &T);
 	for(cs=1;cs<=T;cs++) solve();
 	return 0;
 }
