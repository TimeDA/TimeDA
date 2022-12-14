#include <cstdio>
 #include <cstring>
 #include <cmath>
 #include <algorithm>
 #include <vector>
 using namespace std;
 
 #define FOR(it, c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); it++)
 #define SZ(c) ((int)(c).size())
 typedef long long LL;
 
 double C, F, X;
 void solve(int cs) {
   scanf("%lf%lf%lf", &C, &F, &X);
   printf("Case #%d: ", cs);
   if (X <= C) { printf("%.9f\n", X/2.0); }
   else {
     double t = X/C-2.0/F-1.0;
     double r = floor(t), ans = X/2.0, acc = X/(2.0+(r+1)*F);
     while(r>=0) {
       acc += C / (2.0+r*F);
       r-=1.0;
     }
     ans = min(ans, acc);
     printf("%.9f\n", ans);
   }
 }
 
 int main(void) {
   int T;
   scanf("%d", &T);
   for(int cs=1;cs<=T;cs++) solve(cs);
   return 0;
 }
