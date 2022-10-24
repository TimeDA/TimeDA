#include <bits/stdc++.h>
 #define REP(i,n) for(int i=0; i<(int)(n); ++i)
 
 using namespace std;
 
 typedef long long LL;
 
 int main(){
     int T;
     cin >> T;
     for(int casenum = 1; casenum <= T; casenum++){
         printf("Case #%d: ", casenum);
         LL n, p, q, r, s;
         cin >> n >> p >> q >> r >> s;
 
         vector<LL> v(n);
         REP(i, n) {
             v[i] = ((i * p + q) % r + s);
         }
         LL sum = 0;
         REP(i, n) sum += v[i];
         LL lb = 0, ub = 10000000000000000LL;
         while(ub - lb > 1) {
             LL x = (lb + ub) / 2;
             int size = 1;
             bool ok = true;
             LL cur = 0;
             for(int i = 0; i < n; i++){
                 if(v[i] > x) {
                     ok = false;
                     break;
                 }
                 if(cur + v[i] > x) {
                     size ++;
                     cur = 0;
                 }
                 cur += v[i];
                 assert(cur <= x);
             }
             if(ok && size <= 3) {
                 ub = x;
             } else {
                 lb = x;
             }
         }
         printf("%.10f\n", 1.0 * (sum - ub) / sum);
     }
     return 0;
 }
 
