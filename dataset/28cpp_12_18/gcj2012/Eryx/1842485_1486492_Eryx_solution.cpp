#include <algorithm>
 #include <string>
 #include <vector>
 #include <ctype.h>
 #include <math.h>
 #include <stdio.h>
 #include <stdlib.h>
 
 //#include <iostream>
 //#include <set>
 //#include <map>
 //#include <sstream>
 
 using namespace std;
 
 typedef long long ll;
 typedef long double ld;
 typedef vector<int> vi;
 typedef vector<int> vll;
 typedef vector<string> vs;
 
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
 
 #define Pa(xy) ((xy).first)
 #define Ir(xy) ((xy).second)
 
 string cts(char c) {string s=""; s+=c; return s;}
 
 int cnum, Tests, err;
 
 //Eryx
 // (th
 
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
 
 int N;
 bool ok;
 
 int hi[3000];
 
 int midhi = 1000000000;
 
 int lev[3000];
 
 void subsolve(int id, int right) {
   if(!ok) return;
   //printf("sub %d %d\n", id, right);
   if(id == N-1) return;
   if(hi[id] > right) { ok = false; return; }
   if(hi[id] < right) {
     lev[hi[id]] = lev[id] + (ll(lev[right] - lev[id])) * (hi[id]-id) / (right-id);
     subsolve(hi[id], right);
     }
   if(hi[id] > id+1) {
     lev[id+1] = lev[id] - 36288000;
     subsolve(id+1, hi[id]);
     }
   }
 
 void solveCase() {
   int res = 0;
   // proceed
   err=scanf("%d", &N);
   FOR(k,0,N-1) { err=scanf("%d", &hi[k]); hi[k]--; }
   
   printf("Case #%d:", cnum+1, res);
   
   ok = true;
 
   FOR(k,0,N-1) if(hi[k] <= k) ok = false;
 
   lev[0] = midhi;
   lev[N] = midhi;
 
   subsolve(0, N);
   
   if(!ok) { printf(" Impossible\n"); return; }
   
   FOR(k,0,N) printf(" %d", lev[k]); printf("\n");
   
   FOR(k,0,N-1) {
     int bhi = k+1;
     FOR(l,k+2, N) if((lev[l] - lev[k]) * ll(bhi-k) > (lev[bhi]-lev[k]) * ll(l-k))
       bhi = l;
     if(bhi != hi[k]) printf("error\n");
     // printf("%d:%d\n", bhi, hi[k]);
     }
   }
 
 int main() {
   if(0) Tests = 1;
   else if(0) {
     string Nstr = getLine();
     Tests = atoi(Nstr.c_str());
     }
   else {
     err = scanf("%d", &Tests);
     }
 
   for(cnum=0; cnum<Tests; cnum++)
     solveCase();
     
   // finish
   return 0;
   }
 
 // I also have a preprocessor which turns this solution into one that
 // runs test cases in separate processes in order to make it faster
