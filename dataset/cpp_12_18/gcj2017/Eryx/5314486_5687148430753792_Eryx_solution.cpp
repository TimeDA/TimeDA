#define BUFSIZE 1000000
 int Tests, cnum;
 // #define USEWIN
 #define MANYTESTS 1
 // #define LINEBYLINE
 
 #include <algorithm>
 #include <string>
 #include <vector>
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
 
 void solveCase() {
   int res = 0;
 
   int N = getNum();
   int C = getNum();
   int M = getNum();
   vector<pair<int, int> > tickets;
   FOR(m,0,M) { int bi = getNum()-1; int pi = getNum()-1; tickets.emplace_back(bi, pi); }
   
   // if(cnum != 5) return;
   // FOR(m,0,M) printf("%d,%d\n", tickets[m].second, tickets[m].first);
   
   sort(tickets.begin(), tickets.end());
   
   FOR(rid, 1, M+1) {
     bool inride[2000][2000];
     bool isfree[2000][2000];
     FOR(c,0,C) FOR(r,0,rid) inride[c][r] = false;
     FOR(n,0,N) FOR(r,0,rid) isfree[n][r] = true;
     bool done[2000];
     FOR(m,0,M) done[m] = false;
     FOR(m,0,M) FOR(r,0,rid) if(!done[m])
       if(!inride[tickets[m].second][r]) 
       if(isfree[tickets[m].first][r])
 //        printf("%d,%d ->> %d,%d (ok)\n", tickets[m].second, tickets[m].first, r, tickets[m].first),
         done[m] = true,
         isfree[tickets[m].first][r] = false,
         inride[tickets[m].second][r] = true;
 
     int bugs = 0;
 
     FOR(m,0,M) if(!done[m]) {
       bugs++;
       int c = tickets[m].second;
       int spot = tickets[m].first;
       while(!done[m]) {
         spot--;
         if(spot == -1) { 
           // printf("failed %d,%d\n", tickets[m].second, tickets[m].first);  
           goto failed; }
         FOR(r,0,rid) if(!inride[c][r]) if(isfree[spot][r])
  //         printf("%d,%d ->> %d,%d (bad)\n", tickets[m].second, tickets[m].first, r, spot),
           done[m] = true, isfree[spot][r] = false, inride[c][r] = true;
         }
       }
     
     printf("Case #%d: %d %d\n", cnum, rid, bugs);
     return;
     
     failed: ;
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
 // See https://github.com/eryxcc/templates
