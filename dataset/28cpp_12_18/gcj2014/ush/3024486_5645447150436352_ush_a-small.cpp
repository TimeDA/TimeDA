
 #include <cstdio>
 #include <cstdlib>
 #include <cstring>
 #include <cctype>
 #include <cmath>
 #include <cassert>
 #include <iostream>
 #include <sstream>
 #include <string>
 #include <algorithm>
 #include <vector>
 #include <map>
 #include <queue>
 #include <set>
 #include <list>
 #include <complex>
 #include <numeric>
 #include <limits>
 using namespace std;
 typedef long long ll;
 
 #define REP(i,n) for(int i = 0; i < (int)(n); ++i)
 #define FOR(i,s) for(__typeof((s).begin()) i = (s).begin(); i != (s).end(); ++i)
 
 unsigned myrand() {
   static unsigned x = 123456789, y = 362436069, z = 521288629, w = 88675123;
   unsigned t = x ^ (x << 11); x = y; y = z; z = w;
   return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));
 }
 
 ll n;
 ll vs[1000000+10];
 ll ss_[1000000+10];
 ll* ss = ss_+1;
 
 int main(void) {
   int nCase;
   cin >> nCase;
   REP(iCase, nCase) {
     ll p, q, r, s;
     cin >> n >> p >> q >> r >> s;
     vs[0] = 0;
     ss[0] = 0;
     REP(i, n){
       vs[i] = (i * p + q) % r + s;
       ss[i+1] = ss[i] + vs[i];
     }
     
     ll left = 0;
     ll right = ss[n];
     while(right - left > 1){
       ll md = (right + left) / 2;
       
       ll* p1 = upper_bound(ss, ss + n+1, md);
       ll* p2 = upper_bound(p1, ss + n+1, md + p1[-1]);
       ll* p3 = upper_bound(p2, ss + n+1, md + p2[-1]);
       if(p3 == ss + n+1){
 	right = md;
       }else{
 	left = md;
       }
     }
     
     ll md = right;
     ll* p1 = upper_bound(ss+1, ss + n+1, md);
     ll* p2 = upper_bound(p1, ss + n+1, md + p1[-1]);
     ll* p3 = upper_bound(p2, ss + n+1, md + p2[-1]);
     ll hoge = 0;
     hoge = max(hoge, p1[-1] - ss[-1]);
     hoge = max(hoge, p2[-1] - p1[-1]);
     hoge = max(hoge, p3[-1] - p2[-1]);
     
     double res = double(ss[n] - hoge) / ss[n];
     printf("Case #%d: %.10f\n", iCase+1, res);
 
   }
   return 0;
 }
