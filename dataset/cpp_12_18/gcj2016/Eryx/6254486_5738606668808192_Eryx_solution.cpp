#define BUFSIZE 1000000
 char buf[BUFSIZE];
 int Tests, cnum;
 // #define USEWIN
 #define MANYTESTS 1
 // #define LINEBYLINE
 
 // Eryx's new template for I/O contests, May 3, 2015
 
 #include <algorithm>
 #include <string>
 #include <set>
 #include <stdio.h>
 #include <stdlib.h>
 using namespace std;
 
 #define Size(x) (int(x.size()))
 
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
 
 set<string> found;
 
 int certify(string s, int kk) {
   for(int divv=2; divv<100; divv++) {
     int rmod = 0;
     for(int i=0; i<Size(s); i++) {
       rmod *= kk;
       rmod += s[i] - '0';
       rmod %= divv;
       }
     if(!rmod) return divv;
     }
   // printf("%s found to be prime (%d)\n", s.c_str(), kk);
   return 0;
   }
 
 void solveCase() {
   int N = getNum(), J = getNum();
   
   printf("Case #%d:\n", cnum);
   
   for(int i=0; i<J; i++) {
     nexti:
     string s = "1";
     for(int i=2; i<N; i++) s += (rand() % 2) ? '0' : '1';
     s += "1";
     
     for(int k=2; k<=10; k++)
       if(!certify(s, k)) goto nexti;
       
     printf("%s", s.c_str());
     for(int k=2; k<=10; k++) printf(" %d", certify(s,k));
     printf("\n");
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
