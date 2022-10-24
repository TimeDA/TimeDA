#define BUFSIZE 1000000
 int Tests, cnum;
 // #define USEWIN
 #define MANYTESTS 1
 // #define LINEBYLINE
 
 #include <algorithm>
 #include <string>
 #include <stdio.h>
 using namespace std;
 
 #define LS <
 #define Size(x) (int(x.size()))
 
 // All macros with parameters "k,a,b" run the "k" variable in range [a,b)
 #define FOR(k,a,b) for(__typeof(a) k=(a); k LS (b); ++k)
 
 string getLine() {
   string s;
   while(!feof(stdin)) {
     char c = fgetc(stdin);
     if(c == 13) continue;
     if(c == 10) return s;
     s += c;
     }
   return s;
   }
 
 int scanerr;
 
 int getNum() {
 #ifdef LINEBYLINE
   string s = getLine();
   return atoi(s.c_str());
 #else
   int i;
   scanerr = scanf("%d", &i);
   return i;
 #endif
   }
 
 #ifndef BUFSIZE
 #define BUFSIZE 1000000
 #endif
 
 char buf[BUFSIZE];
 
 #line 10 "work.cpp"
 
 /// ----
 
 
 //Eryx
 
 // !FDI
 
 int xgroups[4];
 
 int dp[120][120][120][4];
 
 void solveCase() {
   int res = 0;
 
   int N = getNum();
   int P = getNum();
   FOR(i,0,P) xgroups[i] = 0;
   FOR(i,0,N) xgroups[getNum() % P]++;
   
   int a[4];
   for(a[1]=0; a[1]<=xgroups[1]; a[1]++)
   for(a[2]=0; a[2]<=xgroups[2]; a[2]++)
   for(a[3]=0; a[3]<=xgroups[3]; a[3]++)
   for(int p=0; p<P; p++) {
     int best = 0;
     for(int u=1; u<P; u++) if(a[u] > 0)
       best = max(best,
         dp[a[1]-(u==1?1:0)][a[2]-(u==2?1:0)][a[3]-(u==3?1:0)][(p+u)%P] + (p?0:1));
     dp[a[1]][a[2]][a[3]][p] = best;
 //    printf("%d %d %d : %d\n", a[1], a[2], a[3], best);
     }
     
   printf("Case #%d: %d\n", cnum, xgroups[0] + dp[xgroups[1]][xgroups[2]][xgroups[3]][0]);
   }
 
 #define P 1000000007
 
 int main() {
 
   if(!MANYTESTS) Tests = 1;
   else Tests = getNum();
   
   for(cnum=1; cnum<=Tests; cnum++)
     solveCase();
     
   // finish
   return 0;
   }
 
 // This solution includes hidden routines to solve test cases in separate
 // processes in order to make it faster. I will update them to run on a
 // cluster if I get one ;)
 // See https://github.com/eryxcc/templates
