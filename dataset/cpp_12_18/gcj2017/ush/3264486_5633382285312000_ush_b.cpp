#include <cstdio>
 #include <cstring>
 #include <cassert>
 #include <iostream>
 using namespace std;
 #define REP(i, n) for(int i = 0; i < (int)(n); ++i)
 typedef long long ll;
 
 bool isOK(ll v) {
   int last = 9;
   while(v > 0) {
     int d = v % 10;
     v /= 10;
     if(d > last) {
       return false;
     }
     last = d;
   }
   return true;
 }
 
 ll solve(ll v) {
   if(isOK(v)) {
     return v;
   }
 
   for(ll d = 10; ; d *= 10) {
     ll cur = v / d * d - 1;
     if(isOK(cur)) {
       return cur;
     }
   }
   assert(false);
 }
 
 
 int main(void) {
   int nCase;
   scanf("%d", &nCase);
   REP(iCase, nCase) {
     ll v;
     scanf("%lld", &v);
     ll res = solve(v);
     printf("Case #%d: %lld\n", iCase+1, res);
   }
   return 0;
 }
