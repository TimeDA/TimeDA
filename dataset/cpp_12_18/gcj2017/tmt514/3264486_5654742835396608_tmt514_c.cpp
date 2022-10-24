// by tmt514
 #include <algorithm>
 #include <cmath>
 #include <cstdio>
 #include <cstdlib>
 #include <cstring>
 #include <iostream>
 #include <string>
 #include <vector>
 #define SZ(x) ((int)(x).size())
 #define FOR(it, c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
 #include <queue>
 using namespace std;
 typedef long long LL;
 
 void solve() {
   LL n, k;
   scanf("%lld%lld", &n, &k);
   static int cs=0;
   priority_queue<pair<LL, LL>> p;
   p.push({n, 1});
   LL amax, amin;
   while(!p.empty() && k>0) {
     auto v = p.top();
     auto x = v.first;
     auto cnt = v.second;
     p.pop();
     LL b = min(cnt, k);
     cnt -= b;
     k -= b;
     if (k <= 0) {
       amax = (x)/2;
       amin = (x-1)/2;
       break;
     } else {
       amax = x/2;
       amin = (x-1)/2;
       if(amax > 0) {p.push({amax, b});}
       if(amin > 0) {p.push({amin, b});}
     }
   }
 
   ++cs;
   printf("Case #%d: %lld %lld\n", cs, amax, amin);
   fprintf(stderr, "Case #%d: %lld %lld\n", cs, amax, amin);
 }
 
 int main(void) {
   int T;
   scanf("%d", &T);
   while(T--) solve();
   return 0;
 }
