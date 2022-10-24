#include <bits/stdc++.h>
 
 #define INF 1000000010
 #define FO(i,a,b) for (int (i) = (a); (i) < (b); ++(i))
 #define sz(v) int(v.size())
 
 using namespace std;
 //PAIRS:
 #define mp make_pair
 #define fi first
 #define se second
 typedef pair<int,int> pii;
 typedef long long ll;
 
 /*~~~~TEMPLATE END~~~~*/
 
 int _T;
 int N, ans;
 bool canDo[4][4];
 
 bool taken[4];
 int myOrd[4];
 
 bool doPerm(int c) {
     int cV = myOrd[c];
     if (c == N) return true;
     bool hadPos = false;
     FO (i,0,N) {
         if (canDo[cV][i] && !taken[i]) {
             hadPos = true;
             taken[i] = true;
             if (!doPerm(c+1)) return false;
             taken[i] = false;
         }
     }
     if (!hadPos) return false;
     else return true;
 }
 
 
 
 bool doMatrix() {
     // Try all permutaions:
     FO (i,0,N) myOrd[i] = i;
     do {
         memset(taken,0,sizeof(taken));
         if (!doPerm(0)) return false;
     } while (next_permutation(myOrd,myOrd+N));
     return true;
 }
 
 
 void tryAll (int a, int b, int cost) {
     if (b == N) {
         tryAll(a+1,0,cost);
         return;
     } 
     if (a == N) {
         if (doMatrix()) {
             ans = min (ans, cost);
         }
         return;
     }
     if (canDo[a][b] == false) {
         tryAll(a,b+1,cost);
         canDo[a][b] = true;
         tryAll(a,b+1,cost+1);
         canDo[a][b] = false;
     } else {
         tryAll(a,b+1,cost);
     }
 }
 
 int main() {
     scanf ("%d", &_T);
     FO (_z,0,_T) {
         printf ("Case #%d: ", _z+1);
         scanf ("%d", &N);
         ans = INF;
         FO (i,0,N) {
             FO (p,0,N) {
                 char _a;
                 scanf (" %c", &_a);
                 if (_a == '1') {
                     canDo[i][p] = true;
                 } else {
                     canDo[i][p] = false;
                 }
             }
         }
         tryAll(0,0,0);
         printf ("%d\n", ans);
     }
     return 0;
 }
