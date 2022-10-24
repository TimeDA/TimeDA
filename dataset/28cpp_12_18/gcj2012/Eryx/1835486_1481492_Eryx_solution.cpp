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
 ll Cash, Fee;
 
 ll price[256], stale[256];
 
 bool mode;
 
 ll liveforcash(ll cash, ll &cashleft, ll &nextprice) {
   int cf = 0;
   int day = 0;
   while(true) {
   
     if(cf >= N) {
       cashleft = 0; 
       nextprice = -1;
       return day;
       }
     else if(stale[cf] < day) cf++;
     else if(price[cf] > cash) { 
       cashleft = cash; nextprice = price[cf]; 
       return day; }
     else if(mode == 1) {
       day++; cash -= price[cf];
       }
     else {
 
       int ds = min(cash / price[cf], stale[cf] - day + 1);
     
       day += ds; cash -= ds * price[cf];
       }
     }
   }
 
 void solveCase() {
   int res = 0;
   // proceed
   
   err=scanf("%lld%lld%d", &Cash, &Fee, &N);
   
   FOR(a,0,N) err=scanf("%lld%lld", &price[a], &stale[a]);
   
   FOR(a,0,N) if(a>0 && price[a] < price[a-1]) swap(price[a], price[a-1]), swap(stale[a], stale[a-1]), a-=2;
   
   ll best = 0;
   
   // fprintf(stderr, "Cash=%lld fee=%lld CF=%d\n", Cash, Fee, N);
   
   // if(Cash > 5000 && Fee == 1) return;
   
   ll ldays = 0;
   
   for(int del=1;; del++) {
     ll xdays = 0;
     ll mcash = Cash - Fee * del;
     if(mcash < 0) break;
 
     ll ccash = mcash / del;
     ll cashleft, nextprice=1;
     
     mode = 0;
     ll cdays = liveforcash(ccash, cashleft, nextprice);
     
     if(0) {
       mode = 1;
       ll cdays0 = liveforcash(ccash, cashleft, nextprice);
       if(cdays0 != cdays) { printf("err\n"); exit(1); }
       }
       
     xdays = del * cdays;
     if(nextprice > 0) xdays += (cashleft * del + mcash%del) / nextprice;
 
     if(xdays < best && xdays > ldays) {
       // printf("not unimodal\n"); exit(1);
       }
       
     if(xdays > best) best = xdays;
     ldays = xdays;
     
     if(0) if(del<1000) {
       ll ydays = xdays, mmcash = mcash;
       ll xdays = 0;
       ll mcash = Cash - Fee * del;
       if(mcash < 0) break;
   
       FOR(z,0,del) {
         ll ccash = mcash / (del-z);
         ll cashleft, nextprice=0;
       
         ll cdays = liveforcash(ccash, cashleft, nextprice);
         xdays += cdays;
         mcash -= ccash; mcash += cashleft;
         }
   
       if(xdays !=  ydays) {
         printf("can=%d thinks=%d\n", int(xdays), int(ydays));
 
         printf("Cash=%lld fee=%lld CF=%d $%d\n", int(Cash), int(Fee), int(N), int(del));
 
         printf("mcash=%d\n", mmcash);
         printf("ccash=%d\n", ccash);
         printf("cdays=%d\n", cdays);
         printf("cashleft=%d\n", cashleft);
         printf("nextprice=%d\n", nextprice);
         exit(1);
         }
       }
     }
   
   printf("Case #%d: %lld\n", cnum+1, best);
   fflush(stdout);
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
