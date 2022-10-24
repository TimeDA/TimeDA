#include <algorithm>
 #include <string>
 #include <vector>
 #include <ctype.h>
 #include <math.h>
 #include <stdio.h>
 //#include <iostream>
 #include <set>
 #include <map>
 //#include <sstream>
 
 using namespace std;
 
 typedef long long ll;
 typedef long double ld;
 typedef vector<int> vi;
 typedef vector<int> vll;
 typedef vector<string> vs;
 
 int err;
 
 #define LS <
 #define Size(x) (int(x.size()))
 #define LET(k,val) typeof(val) k = (val)
 #define CLC(act,val) (*({act; static typeof(val) CLCR; CLCR = (val); &CLCR;}))
 
 #define FOR(k,a,b) for(typeof(a) k=(a); k LS (b); ++k)
 #define FORREV(k,a,b) for(typeof(b) k=(b); (a) <= (--k);)
 
 #define FIRST(k,a,b,cond) CLC(LET(k, a); for(; k LS (b); ++k) if(cond) break, k)
 #define LAST(k,a,b,cond) CLC(LET(k, b); while((a) <= (--k)) if(cond) break, k)
 #define EXISTS(k,a,b,cond) (FIRST(k,a,b,cond) LS (b))
 #define FORALL(k,a,b,cond) (!EXISTS(k,a,b,!(cond)))
 #define FOLD0(k,a,b,init,act) CLC(LET(k, a); LET(R##k, init); for(; k LS (b); ++k) {act;}, R##k)
 #define SUMTO(k,a,b,init,x)  FOLD0(k,a,b,init,R##k += (x))
 #define SUM(k,a,b,x) SUMTO(k,a,b,(typeof(x)) (0), x)
 #define PRODTO(k,a,b,init,x) FOLD0(k,a,b,init,R##k *= (x))
 #define PROD(k,a,b,x) PRODTO(k,a,b,(typeof(x)) (1), x)
 #define MAXTO(k,a,b,init,x)  FOLD0(k,a,b,init,R##k >?= (x))
 #define MINTO(k,a,b,init,x)  FOLD0(k,a,b,init,R##k <?= (x))
 #define QXOR(k,a,b,x) FOLD0(k,a,b,(typeof(x)) (0), R##k ^= x)
 #define QAND(k,a,b,x) FOLD0(k,a,b,(typeof(x)) (-1), R##k &= x)
 #define QOR(k,a,b,x) FOLD0(k,a,b,(typeof(x)) (-1), R##k |= x)
 #define FOLD1(k,a,b,init,act) CLC(LET(k, a); LET(R##k, init); for(++k; k LS (b); ++k) act, R##k)
 #define MAX(k,a,b,x) FOLD1(k,a,b,x, R##k >?= (x))
 #define MIN(k,a,b,x) FOLD1(k,a,b,x, R##k <?= (x))
 #define FIRSTMIN(k,a,b,x) (MIN(k,a,b,make_pair(x,k)).second)
 
 int bitc(ll r) {return r == 0 ? 0 : (bitc(r>>1) + (r&1));}
 ll gcd(ll x, ll y) {return x ? gcd(y%x,x) : y;}
 
 // template<class T> T& operator >?= (T& x, T y) {if(y>x) x=y; return x;}
 // template<class T> T& operator <?= (T& x, T y) {if(y<x) x=y; return x;}
 // template<class T> T operator >? (T x, T y) {return x>y?x:y;}
 // template<class T> T operator <? (T x, T y) {return x<y?x:y;}
 
 #define Pa(xy) ((xy).first)
 #define Ir(xy) ((xy).second)
 
 string cts(char c) {string s=""; s+=c; return s;}
 
 /// ----
 
 #define BUFSIZE 1000000
 char buf[BUFSIZE];
 
 #ifdef DEBUG
 #define DEB(x) x
 #else
 #define DEB(x)
 #endif
 
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
 
 int getNum() {
   string s = getLine();
   return atoi(s.c_str());
   }
 
 vi parsevi(string s) {
   s = s + " ";
   int q = 0;
   bool minus = false;
   vi res;
   FOR(l,0, Size(s)) {
     if(s[l] == ' ') { res.push_back(minus?-q:q); q = 0; minus = false;}
     else if(s[l] == '-') { minus = true; }
     else { q = q * 10 + s[l] - '0'; }
     }
   return res;
   }
 
 int Tests, cnum;
 
 //Eryx
 
 // !FDI
 
 int N;
 
 char type[30][60];
 int kto[2000];  
 
 map<int, int> whw;
 
 int best;
 
 set< pair<int, int> > S;
 
 void possible(int at, int whoin);
 
 void check(int at, int whoin, int z) {
   // printf("check [%d, %d, %d]\n", at, whoin, z);
   switch(type[at][0]) { 
     case 'E':
       if(whoin & (1<<z)) return;
       possible(at+1, whoin | (1<<z));
       break;
     
     case 'L':
       if(!(whoin & (1<<z))) return;
       possible(at+1, whoin & ~(1<<z));
       break;
     }
   }
 
 #define PP 15
 
 bool mtab[16][32768];
 
 void possible(int at, int whoin) {
   // printf("possible [%d, %d]\n", at, whoin);
   if(at == N) {
     int c = 0;
     while(whoin) { if(whoin&1) c++; whoin >>= 1; }
     // printf("c=%d\n", c);
     if(c < best) best = c;
     }
   else {
     if(mtab[at][whoin]) return;
     mtab[at][whoin] = true;
 
     if(kto[at] == 0) FOR(z,0,PP) check(at, whoin, z);
     else check(at, whoin, whw[kto[at]]);
     }
   }
 
 void solveCase() {
   int res = 0;
 
   scanf("%d", &N);
   
   FOR(i, 0, N) scanf("%s%d", type[i], &kto[i]);
   
   set<int> whowas;
   FOR(i,0,N) if(kto[i]) whowas.insert(kto[i]);
   
   whw.clear();
   int qw = 0;
   #undef LS
   #define LS !=
   FOR(i,whowas.begin(), whowas.end()) whw[*i] = qw++;
   
   best = 100;
   
   for(int z=0; z<16; z++) for(int ss=0; ss<(1<<PP); ss++)
     mtab[z][ss] = 0;
   
   FOR(p, 0, (1<<PP)) 
     possible(0, p);
     
   if(best == 100)
     printf("Case #%d: CRIME TIME\n", cnum);
   else
     printf("Case #%d: %d\n", cnum, best);
     
   fflush(stdout);
   }
 
 int main() {
 
   if(0)
     Tests = 1;
   else if(1)
     err = scanf("%d", &Tests);
   else {
     string Nstr = getLine();
     Tests = atoi(Nstr.c_str());
     }
   
   for(cnum=1; cnum<=Tests; cnum++)
     solveCase();
     
   // finish
   return 0;
   }
 
 // This solution includes hidden routines to solve test cases in separate
 // processes in order to make it faster. I will update them to run on a
 // cluster if I get one ;)
