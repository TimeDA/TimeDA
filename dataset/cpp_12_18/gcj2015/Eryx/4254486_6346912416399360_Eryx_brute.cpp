#define BUFSIZE 1000000
 char buf[BUFSIZE];
 int Tests, cnum;
 // #define USEWIN
 #define MANYTESTS 1
 // #define LINEBYLINE
 
 // Eryx's new template for I/O contests, May 3, 2015
 
 #include <algorithm>
 #include <stdio.h>
 using namespace std;
 
 typedef long long ll;
 
 #define LS <
 #define Size(x) (int(x.size()))
 
 #include <string>
 
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
 
 #line 10 "work.cpp"
 
 /// ----
 
 
 //Eryx
 
 // !FDI
 
 ll tval[10000], mintemp[200], maxtemp[200], hdif[200];
 
 int N, K;
 
 ll hmaxtemp;
 
 void solveCase() {
   int res = 0;
 
   N = getNum(), K = getNum();
   int lasts = 0;
   
   FOR(x,0,K-1) {
     ll t = rand() % 1000;
     tval[x] = t;
     lasts += t;
     }
   
   // tval[0] = -4; tval[1] = 8; lasts = 4;
   
   FOR(x,K-1,N) {
     int s = getNum();
     tval[x] = s - lasts;
     lasts += tval[x];
     lasts -= tval[x-(K-1)];
     }
   
 //FOR(x,0,N) printf("%Ld ", tval[x]); printf("\n");
   
   FOR(x,0,K) mintemp[x] = maxtemp[x] = tval[x];
   FOR(x,K,N) mintemp[x%K] = min(mintemp[x%K], tval[x]);
   FOR(x,K,N) maxtemp[x%K] = max(maxtemp[x%K], tval[x]);
 
   int wmin = 0, wmax = 0;  
   
   ll cbest = 1000000000;
   
   int steps = 0;
   
   while(steps < 100000) {
     steps++;
     FOR(wh,0,K) 
       if(make_pair(mintemp[wh], maxtemp[wh]) < 
          make_pair(mintemp[wmin], maxtemp[wmin])) wmin = wh;
       
     FOR(wh,0,K) 
       if(make_pair(maxtemp[wh], mintemp[wh]) > 
         make_pair(maxtemp[wmax], mintemp[wmax]))
       wmax = wh;
 
     ll cur = maxtemp[wmax] - mintemp[wmin];
     if(cur < cbest) steps=0, cbest = cur;
     if(wmin == wmax) break;
     mintemp[wmin]++; maxtemp[wmin]++;
     mintemp[wmax]--; maxtemp[wmax]--;
     }
   
   printf("Case #%d: %Ld\n", cnum, cbest);
   fflush(stdout);
   }
 
 #define P 1000000007
 
 int main() {
 
 /*  int a[50];
   a[0] = 10; a[1] = 8;
   FOR(i,2, 50) {
     a[i] = -a[i-2]-a[i-1];
     printf("%d\n", a[i]);
     }
   exit(0); */
 
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
