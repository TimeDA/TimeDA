#include <cstdio>
 #include <algorithm>
 #include <vector>
 using namespace std;
 
 int N;
 double V,X;
 pair<double,double> A[101];
 
 
 int main () {
     freopen("input.txt","r",stdin);
     freopen("output0.txt","w",stdout);
     
     int T = 1;
     scanf("%d",&T);
     for (int zz=1;zz<=T;++zz) {
         scanf("%d %lf %lf",&N,&V,&X);
         for (int i=1;i<=N;++i) scanf("%lf %lf",&A[i].second,&A[i].first);
         sort(A+1,A+N+1);
         int from = N + 1;
         int to = 0;
         for (int i=1;i<=N;++i) if (A[i].first == X) to = i;
         for (int i=N;i>=1;--i) if (A[i].first == X) from = i;
         double l = 0, r = 120000000;
         bool possible = 0;
         while (r-l > 1e-9) {
             double m = (l+r)/2;
             double left = V;
             double sum = 0;
             double sum2 = 0;
             for (int i=from;i<=to;++i) left -= A[i].second * m;
             if (left <= 0) {
                 r = m;
                 possible =1;
                 continue;
             }
             double copyleft =left;
             int i = 1;
             while (i <= N && left > 0) {
                 if (i >= from && i <= to) {
                     ++i;
                     continue;
                 }
                 if (A[i].second * m <= left) {
                     left -= A[i].second * m;
                     sum += A[i].second * m * A[i].first;
                 }
                 else {
                     sum += left * A[i].first;
                     left = 0;
                 }
                 ++i;
             }
             //printf("1 %lf\n",sum);
             if (left > 0 || sum > X * V) {
                 l = m;
                 continue;
             }
             left = copyleft;
             i = N;
             while (i>= 1&& left > 0) {
                 if (i >= from && i <= to) {
                     --i;
                     continue;
                 }
                 if (A[i].second * m <= left) {
                     left -= A[i].second * m;
                     sum2 += A[i].second * m * A[i].first;
                 }
                 else {
                     sum2 += left * A[i].first;
                     left = 0;
                 }
                 --i;
             }
             //printf("2 %lf\n",sum2);
             if (left > 0 || sum2 < X * V) {
                 l = m;
                 continue;
             }
             r = m;
             possible = 1;
         }
         
         printf("Case #%d: ",zz);
         if (possible) printf("%.9lf\n",l);
         else printf("IMPOSSIBLE\n");
     }
     return 0;
 }
