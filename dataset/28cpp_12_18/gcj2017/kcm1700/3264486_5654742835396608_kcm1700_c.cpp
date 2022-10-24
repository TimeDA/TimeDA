#include <cstdio>
 #include <map>
 #include <algorithm>
 
 using namespace std;
 
 pair<long long, long long> solve(long long N, long long K) {
   map<long long, long long> cnts;
   cnts[N] = 1;
   for (;;) {
     auto I = --cnts.end();
     long long cursize = I->first;
     long long curcnt = I->second;
     cnts.erase(I);
 
     long long p1 = (cursize - 1) / 2;
     long long p2 = p1 + (cursize - 1) % 2;
     if (K <= curcnt) {
       return make_pair(p2, p1);
     }
     K -= curcnt;
     if (p1 > 0) cnts[p1] += curcnt;
     if (p2 > 0) cnts[p2] += curcnt;
   }
 }
 
 int main() {
   int T;
   scanf("%d", &T);
   for (int testcase = 1; testcase <= T; testcase++) {
     long long N, K;
     scanf("%lld%lld", &N, &K);
     pair<long long, long long> sz = solve(N, K);
     printf("Case #%d: %lld %lld\n", testcase, sz.first, sz.second);
   }
   return 0;
 }