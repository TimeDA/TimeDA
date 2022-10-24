#include <cstdio>
 #include <algorithm>
 #define FOR(i,a,b) for (int i = (a); i < (b); ++i)
 #define REP(i,N) for (int i = 0; i < (N); ++i)
 
 using namespace std;
 
 bool board[100][100];
 
 void scase() {
   double C,F,X;
   scanf("%lf%lf%lf",&C,&F,&X);
   double best = X / 2;
   double current = 0;
   for (int farms = 0;; ++farms) {
     best = min(best, current + X / (2 + farms * F));
     if (current > best) break;
     double t = C / (2 + farms * F);
     current += t;
   }
   printf("%0.7lf\n", best);
 }
 
 
 int main() {
   int C;
   scanf("%d",&C);
   REP(i,C) {
     printf("Case #%d: ", i+1);
     scase();
   }
 }
