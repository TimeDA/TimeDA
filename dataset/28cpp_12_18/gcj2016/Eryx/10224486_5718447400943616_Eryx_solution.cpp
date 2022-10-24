#define BUFSIZE 1000000
 char buf[BUFSIZE];
 int Tests, cnum;
 // #define USEWIN
 #define MANYTESTS 1
 // #define LINEBYLINE
 
 // Eryx's new template for I/O contests, May 3, 2015
 
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
 
 string getStr() {
 #ifdef LINEBYLINE
   return getStr();
 #else
   scanerr = scanf("%s", buf);
   return buf;
 #endif
   }
 
 #line 10 "work.cpp"
 
 /// ----
 
 
 //Eryx
 
 // !FDI
 
 string ability[30], tability[30];
 
 bool workingw[30], workingm[30];
 
 int N;
 
 bool checkable(int left) {
   if(!left) return true;
   FOR(y,0,N) if(!workingw[y]) {
     int choices = 0;
     FOR(x,0,N) if(tability[y][x] == '1' && !workingm[x]) {
       // printf("Left %d, %d -> %d\n", left, y, x);
       workingw[y] = true;
       workingm[x] = true;
       bool b = checkable(left-1);
       workingw[y] = false;
       workingm[x] = false;
       if(!b) return false;
       choices++;
       }
     if(!choices) return false;
     }
   
   return true;
   }
 
 void solveCase() {
   int res = 0;
 
   N = getNum();
   FOR(y,0,N) ability[y] = getStr();
   
   FOR(y,0,N) tability[y] = ability[y];
   
   int mincost = 9999;
   
   FOR(t, 0, (1<<(N*N))) { 
     FOR(y,0,N) FOR(x,0,N) tability[y][x] = ((t >> (x+y*N))&1) ? '1' : '0';
     if(checkable(N)) {
       int ccost = 0;
       FOR(y,0,N) FOR(x,0,N)
         if(tability[y][x] == '1' && ability[y][x] == '0')
           ccost++;
         else if(tability[y][x] == '0' && ability[y][x] == '1')
           ccost += 500;
 
       // FOR(y,0,N) printf("%s\n", tability[y].c_str()); printf("\n => cost = %d\n", ccost);
       if(ccost < mincost) mincost = ccost;
       }
     }
   
   printf("Case #%d: %d\n", cnum, mincost);
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
