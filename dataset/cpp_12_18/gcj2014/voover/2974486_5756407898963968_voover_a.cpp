#include <cstdio>
 #include <algorithm>
 #include <map>
 #define FOR(i,a,b) for (int i = (a); i < (b); ++i)
 #define REP(i,N) for (int i = 0; i < (N); ++i)
 
 using namespace std;
 
 void scase() {
   map<int, int> P;
   REP(i,2) {
     int G;
     scanf("%d", &G);
     --G;
     REP(a,4)REP(b,4) {
       int c;
       scanf("%d",&c);
       if (a == G) P[c]++;
     }
   }
   int card = -1;
   for(map<int,int>::iterator it = P.begin(); it != P.end(); ++it) {
     if (it->second != 2) continue;
     if (card != -1) {
       printf("Bad magician!\n");
       return;
     }
     card = it->first;
   }
   if (card == -1)
     printf("Volunteer cheated!\n");
   else printf("%d\n", card);
 }
 
 
 int main() {
   int C;
   scanf("%d",&C);
   REP(i,C) {
     printf("Case #%d: ", i+1);
     scase();
   }
 }
