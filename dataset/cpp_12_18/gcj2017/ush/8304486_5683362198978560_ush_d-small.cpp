
 #include <cstdio>
 #include <cstring>
 #include <cstdlib>
 #include <algorithm>
 #include <set>
 #include <map>
 #include <iostream>
 using namespace std;
 #define REP(i, n) for(int i = 0; i < (int)(n); ++i)
 typedef long long ll;
 
 
 int nRow, nCol;
 ll dLimit;
 int field[210][210];
 
 const int MOD = 1000000000+7;
 
 struct K {
   int r, c, b;
 };
 
 K ks[210];
 
 ll calcDist(const K& k1, const K& k2) {
   return abs(k1.r - k2.r) + abs(k1.c - k2.c);
 }
 
 int main(void) {
   int nCase;
   scanf("%d", &nCase);
   REP(iCase, nCase) {
     int n;
     bool possible = true;
     scanf("%d%d%d%lld", &nRow, &nCol, &n, &dLimit);
     memset(field, 0, sizeof field);
     REP(i, n) {
       scanf("%d%d%d", &ks[i].r, &ks[i].c, &ks[i].b);
       ks[i].r--;
       ks[i].c--;
       field[ks[i].r][ks[i].c] = ks[i].b;
       REP(j, i) {
         ll d = calcDist(ks[i], ks[j]);
         if(d * dLimit < abs(ks[i].b - ks[j].b)) {
           possible = false;
         }
       }
     }
 
     printf("Case #%d: ", iCase+1);
     if(!possible) {
       printf("IMPOSSIBLE\n");
       continue;
     }
     
     
     ll res = 0;
     REP(i, nRow) REP(j, nCol) {
       if(field[i][j]) {
         res = (res + field[i][j]) % MOD;
       } else {
         ll maxi = 1e18;
         REP(t, n) {
           const K& k = ks[t];
           ll d = abs(k.r - i) + abs(k.c - j);
           maxi = min(maxi, k.b + d * dLimit);
         }
         // cerr << "[" << i << "][" << j << "] = " << maxi << endl;
         res = (res + maxi) % MOD;
       }
     }
     printf("%lld\n", res);
   }
   return 0;
 }
 
