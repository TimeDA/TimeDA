#include <cstdio>
 #include <cstring>
 #include <cassert>
 #include <iostream>
 #include <algorithm>
 #include <queue>
 using namespace std;
 #define REP(i, n) for(int i = 0; i < (int)(n); ++i)
 
 typedef long long ll;
 
 
 
 ll hpDragon;
 ll atkDragon;
 ll hpKnight;
 ll atkKnight;
 ll buff;
 ll debuff;
 
 int main(void) {
   int nCase;
   scanf("%d", &nCase);
   REP(iCase, nCase) {
     scanf("%lld%lld%lld%lld%lld%lld", &hpDragon, &atkDragon, &hpKnight, &atkKnight, &buff, &debuff);
 
     // ll bufAndAttack = (hpKnight + atkDragon-1) / atkDragon;
     // ll nBuff = 0;
     // for(ll nB = 1; ; ++nB) {
     //   ll a = atkDragon + buff * nB;
     //   ll tmp = nB + (hpKnight + a - 1) / a;
     //   if(tmp < bufAndAttack) {
     //     bufAndAttack = tmp;
     //     nBuff = nB;
     //   } else {
     //     break;
     //   }
     //   // cerr << ">>" << nBuff << " " << bufAndAttack << endl;
     // }
     // cerr << "> " << bufAndAttack << endl;
     // cerr << "> " << nBuff << endl;
 
     ll res = -1;
     for(ll nDebuff = 0; nDebuff <= atkKnight; ++nDebuff) for(ll nBuff = 0; nBuff <= hpKnight; ++nBuff) {
       // cerr << ">>> " << nDebuff << endl;
       // simulate
       bool dead = false;
       ll nTurn = 1;
       ll hd = hpDragon;
       ll ad = atkDragon;
       ll hk = hpKnight;
       ll ak = atkKnight;
       ll lastCure = -2;
       ll iDebuff = 0;
       ll iBuff = 0;
       for(;; ++nTurn) {
         // cerr << ">> " << hd << " " << hk << " " << endl;
         // cerr << ">>>>" << nTurn << endl;
         int mode;
         if (iDebuff < nDebuff) {
           mode = 0;
         } else if(iBuff < nBuff) {
           mode = 1;
         } else {
           mode = 2;
         }
         if(mode == 0) {
           ak -= debuff;
           iDebuff++;
         } else if (mode == 1) {
           ad += buff;
           iBuff++;
         } else {
           hk -= ad;
         }
         hd -= ak;
 
         if (hk <= 0) {
           break;
         }
         if (hd <= 0) { // undo & cure
           if (mode == 0) {
             ak += debuff;
             iDebuff--;
           } else if(mode == 1) {
             ad -= buff;
             iBuff--;
           } else {
             hk += ad;
           }
           hd += ak;
           if (lastCure == nTurn - 1) { // cure loop!
             dead = true;
             break;
           } else {
             lastCure = nTurn;
             hd = hpDragon;
             hd -= ak;
             if (hd <= 0) { // dead!
               dead = true;
               break;
             }
           }
         }
       }
       // cerr << "dead = " << dead << " nDebuff = " << nDebuff << " res = " << res << endl;
       if (!dead && (nTurn < res || res == -1)) {
         res = nTurn;
       }
     }
 
     if(res < 0) {
       printf("Case #%d: IMPOSSIBLE\n", iCase+1);
     } else {
       printf("Case #%d: %lld\n", iCase+1, res);
     }
   }
   return 0;
 }
