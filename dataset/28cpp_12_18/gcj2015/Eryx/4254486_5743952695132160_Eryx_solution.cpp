#define BUFSIZE 1000000
 char buf[BUFSIZE];
 int Tests, cnum;
 // #define USEWIN
 #define MANYTESTS 1
 // #define LINEBYLINE
 
 // Eryx's new template for I/O contests, May 3, 2015
 
 #include <algorithm>
 #include <vector>
 #include <map>
 #include <stdio.h>
 using namespace std;
 
 typedef long long ll;
 
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
 
 /// ----
 
 
 //Eryx
 
 // !FDI
 
 map<ll, ll> freq;
 
 ll E[20000], fq[20000];
 
 vector<ll> oset;
 
 int M;
 
 bool findtotal(int at, ll d) {
 //printf("ft %d,%Ld\n", at, d);
   if(at == M) return d==0;
   if(findtotal(at+1, d-oset[at])) {
     oset[at] = -oset[at];
     return true;
     }
   return findtotal(at+1, d);
   }
 
 void solveCase() {
   int res = 0;
 
   freq.clear();
   int P = getNum();
   FOR(p,0,P) E[p] = getLL();
   FOR(p,0,P) fq[p] = getLL();
   
   ll tfreq = 0; FOR(p,0,P) tfreq += fq[p];
   
   oset.clear();
   
   int zeros = 0;
   
   FOR(p,0,P) freq[E[p]] = fq[p];
   while(tfreq>1) {
     tfreq >>= 1;
     if(freq.begin()->second > 1) {
       zeros++;
       for(auto& p: freq) p.second >>= 1;
       }
     else {
       auto it = freq.begin();
       it++;
       ll v = it->first - freq.begin()->first;
       oset.push_back(v);
       for(auto p: freq) {
         freq[p.first+v] -= p.second;
         if(freq[p.first+v] == 0) freq.erase(p.first+v);
         }
       }
     }
   
   ll rdif = freq.begin()->first;
   
   reverse(oset.begin(), oset.end());
   
   M = Size(oset);
   findtotal(0, -rdif);
   
   while(zeros--) oset.push_back(0);
   sort(oset.begin(), oset.end());
 
   printf("Case #%d:", cnum);
   for(auto v: oset) printf(" %Ld", v); printf("\n");
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
