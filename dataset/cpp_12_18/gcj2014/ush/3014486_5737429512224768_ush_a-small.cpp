
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
 using namespace std;
 typedef long long ll;
 
 #define REP(i,n) for(int i = 0; i < (int)(n); ++i)
 #define FOR(i,s) for(__typeof((s).begin()) i = (s).begin(); i != (s).end(); ++i)
 
 unsigned myrand() {
   static unsigned x = 123456789, y = 362436069, z = 521288629, w = 88675123;
   unsigned t = (x ^ (x << 11)); x = y; y = z; z = w;
   return (w = (w ^ (w >> 19)) ^ (t ^ (t >> 8)));
 }
 
 int vs[10000+10];
 bool used[10000+10];
 
 
 int main(void) {
   int nCase;
   cin >> nCase;
   REP(iCase, nCase) {
     int n;
     int cap;
     cin >> n >> cap;
     REP(i, n){
       cin >> vs[i];
     }
     sort(vs, vs + n);
     memset(used, 0, sizeof used);
     int res = 0;
     for(int i = n-1; i >= 0; --i){
       if(used[i])
 	continue;
       ++res;
       used[i] = true;
       int rest = cap - vs[i];
       
       int j;
       for(j = i-1; j >= 0; --j){
 	if(!used[j] && vs[j] <= rest)
 	  break;
       }
 //       cerr << i << " " << j << endl;
       if(j >= 0){
 	used[j] = true;
       }
     }
     
     printf("Case #%d: %d\n", iCase+1, res);
   }
   return 0;
 }
