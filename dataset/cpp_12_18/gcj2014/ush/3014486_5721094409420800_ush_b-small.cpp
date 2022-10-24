
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
 
 #define REP(i,n) for(int i = 0; i < (int)(n); ++i)
 #define FOR(i,s) for(__typeof((s).begin()) i = (s).begin(); i != (s).end(); ++i)
 #define ALLOF(s) ((s).begin()), ((s).end())
 
 unsigned myrand() {
   static unsigned x = 123456789, y = 362436069, z = 521288629, w = 88675123;
   unsigned t = (x ^ (x << 11)); x = y; y = z; z = w;
   return (w = (w ^ (w >> 19)) ^ (t ^ (t >> 8)));
 }
 
 typedef long long ll;
 
 
 int vs[1000+10];
 
 int main(void) {
   int nCases;
   cin >> nCases;
   REP(iCase, nCases) {
     int n;
     cin >> n;
     REP(i, n)
       cin >> vs[i];
     
     int res = 0;
     int left = 0;
     int right = n;
     while(right - left > 2){
       int idx = left;
       for(int i = left; i < right; ++i){
 	if(vs[i] < vs[idx])
 	  idx = i;
       }
       if(idx-left < right-1-idx){
 	while(idx > left){
 	  swap(vs[idx], vs[idx-1]);
 	  res++;
 	  --idx;
 	}
 	left++;
       }else{	
 	while(idx < right-1){
 	  swap(vs[idx], vs[idx+1]);
 	  res++;
 	  ++idx;
 	}
 	--right;
       }
     }
     printf("Case #%d: %d\n", iCase+1, res);
   }
   return 0;
 }
