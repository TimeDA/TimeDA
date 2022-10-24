#define BUFSIZE 1000000
 char buf[BUFSIZE];
 int Tests, cnum;
 // #define USEWIN
 #define MANYTESTS 1
 // #define LINEBYLINE
 
 // Eryx's new template for I/O contests, May 3, 2015
 
 #include <algorithm>
 #include <map>
 #include <stdio.h>
 using namespace std;
 
 typedef long long ll;
 
 #define Size(x) (int(x.size()))
 
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
 
 ll getLL() {
 #ifdef LINEBYLINE
   string s = getLine();
   return atoll(s.c_str());
 #else
 #ifdef USEWIN
   string s = getStr();
   return atoll(s.c_str());
 #else
   ll v;
   scanerr = scanf("%Ld", &v);
   return v;
 #endif
 #endif
   }
 
 #line 10 "work.cpp"
 
 #include <queue>
 
 /// ----
 
 
 //Eryx
 
 // !FDI
 
 void solveCase() {
   int res = 0;
 
   ll N = getLL();
   ll K = getLL();
   
   ll last = 0;
   
   map<ll, ll> bysize;
   
   bysize[N] = 1;
   
   while(K > 0) {
     auto it = bysize.end();
     it--;
     
     last = it->first;
     
     ll take = min(K, it->second);
     // printf("%d (x%d) take=%d/%d\n", it->first, it->second, take, K);
 
     bysize[last] -= take;    
     bysize[(last-1)/2] += take;
     bysize[last/2] += take;
 
     if(bysize[last] == 0) bysize.erase(last);
     K -= take;
     }
   
   printf("Case #%d: %Ld %Ld\n", cnum, last/2, (last-1)/2);
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
