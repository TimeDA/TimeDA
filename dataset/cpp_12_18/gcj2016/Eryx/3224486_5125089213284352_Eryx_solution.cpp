#define BUFSIZE 1000000
 char buf[BUFSIZE];
 int Tests, cnum;
 // #define USEWIN
 #define MANYTESTS 1
 // #define LINEBYLINE
 
 // Eryx's new template for I/O contests, May 3, 2015
 
 #include <algorithm>
 #include <string>
 #include <vector>
 #include <stdio.h>
 #include <stdlib.h>
 using namespace std;
 
 #define LS <
 #define Size(x) (int(x.size()))
 
 // All macros with parameters "k,a,b" run the "k" variable in range [a,b)
 #define FOR(k,a,b) for(__typeof(a) k=(a); k LS (b); ++k)
 
 string getLine() {
   string s;
   while(!feof(stdin)) {
     char c = fgetc(stdin);
     if(c <= 0) continue;
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
 
 int prereq[200];
 
 string cool[10];
 
 vector<int> pfor[200];
 
 string S;
 
 string construct(int id) {
   vector<string> pr;
   string out; out += S[id];
   int tlen[200], left[200];
   for(int k: pfor[id]) pr.push_back(construct(k));
   int T = Size(pr);
   int xtotal = 0;
   FOR(u,0,T) tlen[u] = Size(pr[u]), left[u] = 0, xtotal += tlen[u];
   while(xtotal) {
     int z = rand() % xtotal;
     FOR(u,0,T) { z -= (tlen[u] - left[u]); if(z < 0) { out += pr[u][left[u]++]; break; } }
     xtotal--;
     }
   return out;
   }
 
 void solveCase() {
   int res = 0;
 
   int t = time(NULL);
 
   int N = getNum();
   
   FOR(a, 0, N) prereq[a+1] = getNum();
   S = "@" + getStr();
   int M = getNum();
   FOR(m, 0, M) cool[m] = getStr();
   
   FOR(i,0,N+1) pfor[i].clear();
   FOR(i,1,N+1) pfor[prereq[i]].push_back(i);
 
   int freq[200], qsim = 0;  
   FOR(u,0,M) freq[u] = 0;
     
   while(time(NULL) < t+2) {
     string out = construct(0);
     FOR(m,0,M) if(out.find(cool[m]) != string::npos) freq[m]++;
     qsim++;
     }
   
   fprintf(stderr, "qsim = %d\n", qsim);
   
   printf("Case #%d:", cnum);
   FOR(u,0,M) printf(" %.6lf", (freq[u] + .0) / qsim);
   printf("\n");
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
