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
 
 #line 9 "work.cpp"
 
 /// ----
 
 
 //Eryx
 
 // !FDI
 
 int endtour[4000];
 int tstart[4000];
 int ttime[4000];
 
 int which1[2000];
 
 void solveCase() {
   int res = 0;
 
   int C = getNum();
   FOR(cu,0,2*C)
     endtour[cu] = getNum()-1,
     tstart[cu] = getNum(),
     ttime[cu] = getNum();
   
   // FOR(cu,0,2*C) which1[endtour[cu]] = cu;
   
   int besttime = 2000000000;
   
   FOR(sol,0,1<<C) {
     // printf("SOL %d\n", sol);
     int usedsite[4000];
     FOR(c,0,C) usedsite[c] = 0;
     int timesofar = 0;
     int at = 0;
     
     int trips = 0;
     
     while(usedsite[at] < 2) {
       // printf("at=%d\n", at);
       trips++;
       int tripid = 2*at + (usedsite[at] ^ ((sol >> at) & 1));
       usedsite[at]++;
       while(timesofar % 24 != tstart[tripid]) timesofar++;
       at = endtour[tripid];
       timesofar += ttime[tripid];
       }
     
     // printf("trips = %d\n", trips);
     
     if(trips == 2*C && timesofar < besttime)
       besttime = timesofar;
     }
       
   printf("Case #%d: %d\n", cnum, besttime);
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
