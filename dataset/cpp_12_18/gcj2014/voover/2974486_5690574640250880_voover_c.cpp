#include <cstdio>
 #define FOR(i,a,b) for (int i = (a); i < (b); ++i)
 #define REP(i,N) for (int i = 0; i < (N); ++i)
 
 using namespace std;
 
 bool board[100][100];
 
 void scase() {
   printf("\n");
   int R,C,M;
   scanf("%d%d%d", &R,&C,&M);
   REP(i,R)REP(j,C) board[i][j] = true;
   if (R != 1 && C != 1 && (M == R*C - 2 || M == R*C - 3)) {
     printf("Impossible\n");
     return;
   }
   if (R == 1) REP(i,C-M) board[0][i] = false;
   else if (C == 1) REP(i,R-M) board[i][0] = false;
   else if (M == R*C - 1) board[0][0] = false;
   else {
     REP(i,2)REP(j,2) board[i][j] = false;
     int F = R*C - M - 4;
     FOR(j,2,C)REP(i,2) if (F-- > 0) board[i][j] = false;
     FOR(i,2,R)REP(j,C) if (F-- > 0) board[i][j] = false;
   }
   
   REP(i,R) {
     REP(j,C) if ((i|j) == 0) printf("c");
     else printf(board[i][j] ? "*" : ".");
     printf("\n");
   }
 }
 
 
 int main() {
   int C;
   scanf("%d",&C);
   REP(i,C) {
     printf("Case #%d:", i+1);
     scase();
   }
 }
