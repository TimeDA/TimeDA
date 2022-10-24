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
 
 void solveCase() {
 
   int N = getNum();
   
   if(N == 0) { 
     printf("Case #%d: INSOMNIA\n", cnum);
     return;
     }
   
   bool ex[10];
   
   for(int v=0; v<10; v++) ex[v] = false;
   
   for(int i=1;; i++) {
     int k = i * N;
     while(k) { ex[k%10] = true; k /= 10; }
     int q = 0;
     for(int t=0; t<10; t++) if(!ex[t]) q++;
     if(!q) {
       printf("Case #%d: %d\n", cnum, i*N);
       return;
       }
     }
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
