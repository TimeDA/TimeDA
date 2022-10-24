#include <algorithm>
 #include <string>
 #include <vector>
 #include <ctype.h>
 #include <math.h>
 #include <stdio.h>
 //#include <iostream>
 #include <set>
 //#include <map>
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
 
 #define BINFIRST(k,a,b,cond)          \
   CLC(                                \
     LET(Type, a+b);                   \
     LET(k##mIn, (__typeof(Type))(a)); LET(k##mAx, (__typeof(Type))(b));   \
     while(k##mIn != k##mAx) {         \
       LET(k, (k##mIn>>1)+(k##mAx>>1)+ \
       (((k##mIn&1)+(k##mAx&1))>>1)    \
       ); \
       if(cond) k##mAx = k;            \
       else k##mIn = k+1;              \
       },                              \
     k##mIn                            \
     )                                 
 
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
 
 ll data[2000000];
 ll datat[2000000];
 
 ll total;
 
 ll s3(ll l, ll r) {
   ll third = total - l - r;
   if(third < 0) return 0;
   return min(l+r, min(l+third, r+third));
   }
 
 void solveCase() {
   int res = 0;
   
   int N, p, q, r, s;
   
   scanf("%d%d%d%d%d", &N, &p, &q, &r, &s);
   
   FOR(i,0,N) data[i] = (i*ll(p)+q) % r + s;
   
   FOR(i,0,N) datat[i+1] = datat[i] + data[i];
   
   if(cnum == 992) {
     FOR(i,0,N) printf("%4d (%4d)\n", data[i], datat[i]);
     }
   
   total = 0;
   FOR(i,0,N) total += data[i];
   
   ll lost = total;
   
   FOR(a,0,N) {
   
     int b = BINFIRST(bb, a+1, N, datat[bb] >= (datat[a] + datat[N]) / 2);
     
     {
     ll left = datat[a] - datat[0];
     ll midd = datat[b] - datat[a];
     ll rght = datat[N] - datat[b];
                
     if(cnum == 992) printf("a=%d b=%d %d,%d,%d\n", a,b, int(left), int(midd), int(rght));
     
     ll newlost = max(left, max(midd, rght));
 
     if(newlost < lost) lost = newlost;
     }
     
     b--; if(b==a) continue;
     
     {
     ll left = datat[a] - datat[0];
     ll midd = datat[b] - datat[a];
     ll rght = datat[N] - datat[b];
     
     ll newlost = max(left, max(midd, rght));
 
     if(newlost < lost) lost = newlost;
     }
     }
   
   ll chance = total - lost;
   
   printf("Case #%d: %.10Lf\n", cnum, (chance * ld(1.0)) / total);
   fflush(stdout);
   
   if(cnum==992) exit(0);
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
