
 #include <cassert>
 #include <cstring>
 #include <cstdio>
 #include <iostream>
 #include <vector>
 #include <map>
 #include <set>
 #include <queue>
 #include <algorithm>
 #define REP(i, n) for(int i = 0; i < (int)(n); ++i)
 #define FOR(i, c) for(__typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
 using namespace std;
 typedef long long ll;
 
 inline char getWinner(char a, char b) {
   if((a == 'P' && b == 'R') || (a == 'R' && b == 'P')) {
     return 'P';
   } else if((a == 'P' && b == 'S') || (a == 'S' && b == 'P')) {
     return 'S';
   } else if((a == 'R' && b == 'S') || (a == 'S' && b == 'R')) {
     return 'R';
   } else {
     return 0;
   }
 }
 
 struct K {
   // K* left;
   // K* right;
   char winner;
   string s;
   bool live;
   K() {
     // left = right = NULL;
     winner = 0;
     s = "";
     live = false;
   }
   K(char c) {
     // left = right = NULL;
     winner = c;
     s = "";
     s += c;
     live = true;
   }
   K(K* a, K* b) {
     // left = a;
     // right = b;
     winner = getWinner(a->winner, b->winner);
     if(a->s > b->s) {
       cerr << "not ORDER???" << endl;
       swap(a, b);
     }
     s = a->s + b->s;
     live = true;
   }
 };
 bool operator<(const K& a, const K& b) {
   return a.s < b.s;
 }
 
 K ks[13][3000];
 bool used[3000];
 
 int main(void) {
   int nCase;
   scanf("%d", &nCase);
   REP(iCase, nCase) {
     int n, nR, nP, nS;
     scanf("%d%d%d%d", &n, &nR, &nP, &nS);
     REP(i, nR){
       ks[0][i] = K('R');
     }
     REP(i, nP){
       ks[0][nR+i] = K('P');
     }
     REP(i, nS){
       ks[0][nR+nP+i] = K('S');
     }
     bool possible = true;
     REP(t, n) {
       if (nR+nP < nS || nP+nS < nR || nS+nR < nP) {
         possible = false;
         break;
       }
       int nM = 1 << (n-t-1);
       int pr = nP + nR - nM;
       int ps = nP + nS - nM;
       int rs = nR + nS - nM;
       nR = rs;
       nP = pr;
       nS = ps;
       sort(ks[t], ks[t] + (1 << (n-t)));
       memset(used, 0, sizeof used);
       int x = 0;
       REP(i, nM*2) {
         if(used[i]) {
           continue;
         }
         char ci = ks[t][i].winner;
         int j;
         for(j = i+1; j < nM*2; ++j){
           char cj = ks[t][j].winner;
           if(!used[j] && cj != ci) {
             if ((ci == 'P' && cj == 'R') || (ci == 'R' && cj == 'P')) {
               if (pr > 0) {
                 --pr;
                 break;
               }
             } else if ((ci == 'R' && cj == 'S') || (ci == 'S' && cj == 'R')) {
               if (rs > 0) {
                 --rs;
                 break;
               }
             } else if ((ci == 'P' && cj == 'S') || (ci == 'S' && cj == 'P')) {
               if (ps > 0) {
                 --ps;
                 break;
               }
             } else {
               assert(false);
             }
           }
         }
         assert(j < nM*2);
         ks[t+1][x++] = K(&ks[t][i], &ks[t][j]);
         used[i] = used[j] = true;
       }
     }
     
     printf("Case #%d: %s\n", iCase+1, possible ? ks[n][0].s.c_str() : "IMPOSSIBLE");
   }
   return 0;
 }
