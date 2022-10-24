#include <cstdio>
 #include <cstring>
 #include <cassert>
 #include <iostream>
 #include <algorithm>
 #include <queue>
 using namespace std;
 #define REP(i, n) for(int i = 0; i < (int)(n); ++i)
 
 typedef long long ll;
 
 int base[60];
 int vs[60][60];
 int idx[60];
 
 ll calcUb(int i, int j) {
   ll v = vs[i][j];
   ll b = base[i];
   ll left = 0;
   ll right = 100000000;
   while(left + 1 < right) {
     ll mid = (left + right) / 2;
     if(b * mid * 9 <= v * 10) {
       left = mid;
     } else {
       right = mid;
     }
   }
   // cerr << "ub = " << left << " for v=" << v << " b=" << b << " i=" << i << " j=" << j << endl;
   return left;
 }
 
 ll calcLb(int i, int j) {
   ll v = vs[i][j];
   ll b = base[i];
   ll left = -1;
   ll right = 100000000;
   while(left + 1 < right) {
     ll mid = (left + right) / 2;
     if(v * 10 <= b * mid * 11) {
       right = mid;
     } else {
       left = mid;
     }
   }
   // cerr << "lb = " << right << " for v=" << v << " b=" << b << " i=" << i << " j=" << j << endl;
   return right;
 }
 
 int main(void) {
   int nCase;
   scanf("%d", &nCase);
   REP(iCase, nCase) {
     int n;
     int nPackage;
     scanf("%d%d", &n, &nPackage);
     REP(i, n) {
       scanf("%d", &base[i]);
     }
     REP(i, n) REP(j, nPackage) {
       scanf("%d", &vs[i][j]);
     }
     REP(i, n) {
       sort(vs[i], vs[i] + nPackage);
       idx[i] = nPackage-1;
     }
 
     int res = 0;
     for(; idx[0] >= 0; --idx[0]) {
       ll ub = calcUb(0, idx[0]);
       ll lb = calcLb(0, idx[0]);
       for(int i = 1; i < n; ++i) {
         ll u = -1;
         ll l = -1;
         for(; idx[i] >= 0; ) {
           u = calcUb(i, idx[i]);
           l = calcLb(i, idx[i]);
           if(ub < l) {
             --idx[i];
           } else {
             break;
           }
         }
         if (idx[i] < 0 || u < lb) {
           ub = -1;
           lb = -1;
           break;
         } else {
           ub = min(ub, u);
           lb = max(lb, l);
         }
       }
       if(lb <= ub && ub > 0) {
         // cerr << "++res" << endl;
         ++res;
         for(int i = 1; i < n; ++i)
           --idx[i];
       }
     }
     
     printf("Case #%d: %d\n", iCase+1, res);
   }
   return 0;
 }
