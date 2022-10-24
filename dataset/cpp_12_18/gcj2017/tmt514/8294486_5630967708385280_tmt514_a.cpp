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
 using namespace std;
 typedef long long LL;
 
 void solve() {
   double maxTime = 0;
   int n, K, D, S;
   scanf("%d%d", &D, &n);
   for(int i=0;i<n;i++) {
     scanf("%d%d", &K, &S);
     maxTime = max(maxTime, (D - K) / (double)S);
   }
   static int cs = 0;
   printf("Case #%d: %lf\n", ++cs, D / maxTime);
   fprintf(stderr, "Case #%d: %lf\n", cs, D / maxTime);
 }
 
 int main(void) {
   int T;
   scanf("%d", &T);
   while(T--) solve();
   return 0;
 }
