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
 typedef long double Double;
 
 int cs=0;
 Double p[205], q[205];
 void solve() {
   ++cs;
   fprintf(stderr, "Case #%d: ", cs);
   printf("Case #%d: ", cs);
 
   int n, k;
   scanf("%d%d", &n, &k);
   for(int i=0;i<n;i++)
     cin >> p[i];
   sort(p, p+n);
   int m=0;
   for(int i=0;i<k/2;i++) q[m++] = p[i];
   for(int i=n-k/2;i<n;i++) q[m++] = p[i];
   
   Double ans = 0;
   for(int i=0;i<(1<<n);i++) {
     if(__builtin_popcount(i) == k) {
       
       Double rans = 0;
       for(int s=i;s!=0;s=((s-1)&i)) {
         if (__builtin_popcount(s) == k/2) {
           Double t=1.0;
           for(int j=0;j<n;j++)
             if((1<<j)&i) {
               if((1<<j)&s) {
                 t *= (1.0-p[j]);
               } else {
                 t *= p[j];
               }
             }
           rans += t;
         }
       }
       if (rans > ans) ans = rans;
     }
   }
 
 
   /*Double ans = 0;
   for(int i=0;i<(1<<m);i++)
     if(__builtin_popcount(i) == k/2) {
       Double t=1.0;
       for(int j=0;j<m;j++)
         if((1<<j)&i) {
           t *= q[j];
         }
         else {
           t *= (1.0-q[j]);
         }
       ans += t;
     }
   */
   printf("%.9f\n", (double)ans);
   fprintf(stderr, "%.9f\n", (double)ans);
 }
 
 
 int main(void) {
   int T;
   scanf("%d", &T);
   while(T--) solve();  
   return 0;
 }
