#include <bits/stdc++.h>
 
 #define INF 1000000010
 #define FO(i,a,b) for (int (i) = (a); (i) < (b); ++(i))
 
 using namespace std;
 //PAIRS:
 #define mp make_pair
 #define fi first
 #define se second
 typedef pair<int,int> pii;
 typedef long long ll;
 
 /*~~~~TEMPLATE END~~~~*/
 
 int dy[4] = {-1,0,1,0};
 int dx[4] = {0,1,0,-1};
 
 int T;
 int R, C;
 char gr[105][105];
 
 int ans;
 
 bool outBounds (int y, int x) {
     if (y < 0 || y >= R) return true;
     if (x < 0 || x >= C) return true;
     return false;
 }
 
 int main() {
     freopen ("a.in", "r", stdin);
     freopen ("a.out", "w", stdout);
     scanf ("%d", &T);
     FO (_z,0,T) {
         ans = 0;
         printf ("Case #%d: ", _z+1);
         scanf ("%d %d", &R, &C);
         FO (i,0,R) {
             FO (p,0,C) {
                 scanf (" %c ", &gr[i][p]);
                 if (gr[i][p] == '.') gr[i][p] = 5;
                 else if (gr[i][p] == '^') gr[i][p] = 0;
                 else if (gr[i][p] == '>') gr[i][p] = 1;
                 else if (gr[i][p] == 'v') gr[i][p] = 2;
                 else if (gr[i][p] == '<') gr[i][p] = 3;
             }
         }
         FO (i,0,R) {
             FO (p,0,C) {
                 bool isPos = false;
                 if (gr[i][p] != 5) {
                     int cY = i;
                     int cX = p;
                     for (;;) {
                         cY += dy[gr[i][p]];
                         cX += dx[gr[i][p]];
                         if (outBounds (cY,cX)) break;
                         if (gr[cY][cX] != 5) {
                             isPos = true;
                             break;
                         }
                     }
                     if (isPos) continue;
                     FO (t,0,4) {
                         cY = i;
                         cX = p;
                         for (;;) {
                             cY += dy[t];
                             cX += dx[t];
                             if (outBounds (cY,cX)) break;
                             if (gr[cY][cX] != 5) {
                                 isPos = true;
                                 break;
                             }
                         }
                     }
                     if (!isPos) {
                         ans = INF;
                     } else {
                         ans++;
                     }
                 }
             }
         }
         if (ans >= INF) {
             printf ("IMPOSSIBLE\n");
         } else {
             printf ("%d\n", ans);
         }        
     }
     return 0;
 }
