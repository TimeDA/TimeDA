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
 
 char strs[10000][128];
 
 int strid[10000];
 
 #define P 1000000007
 
 int bin[1000][1000];
 
 void calcBinom() {
   FOR(n,0,1000) FOR(k,0,1000)
     bin[n][k] =
       k == 0 ? 1 :
       n == 0 ? 0 :
       (bin[n-1][k-1] + bin[n-1][k]) % P;
   }
 
 struct trie {
   trie *to[30];
   int qty;
   int spawn;
   };
 
 trie *root;
 
 ll result;
 
 int nodes, nodes0;
 
 int M, N;
 
 void buildTrie(char *p, trie* &where) {
   if(where == NULL) {
     where = new trie;
     for(int i=0; i<30; i++) where->to[i] = NULL;
     where->qty = 0;
     where->spawn = 0;
     nodes0++;
     }
   where->spawn++;
   if(where->spawn <= N) nodes++;
   if(*p)
     buildTrie(p+1, where->to[p[0] - 'A']);
   else
     where->qty++;
   }
 
 void freetrie(trie* &where) {
   if(where) {
     for(int i=0; i<30; i++) freetrie(where->to[i]);
     delete where;
     }
   }
 
 void invoke(trie* where) {
   for(int i=0; i<30; i++) 
     if(where->to[i]) invoke(where->to[i]);
 
   int maxspawn = 1;
   for(int i=0; i<30; i++) 
     if(where->to[i] && where->to[i]->spawn >= maxspawn) 
       maxspawn = where->to[i]->spawn;
 
   // printf("spawn = %d maxspawn = %d\n", where->spawn, maxspawn);
 
   if(maxspawn >= N) {
     // fill small children
     for(int i=0; i<30; i++) if(where->to[i] && where->to[i]->spawn < N)
       result = (result * bin[N][where->to[i]->spawn]) % P;
 
   
     return;
     }
   
   // inclusion-exclusion
   ll total = 0;
   
   int cfrom = where->spawn; if(cfrom > N) cfrom = N;
 
   FOR(k, maxspawn, cfrom+1) {
     ll component = ((k^cfrom) & 1) ? -1 : 1;
     
     component = (component * bin[cfrom][k]) % P;
     
     for(int i=0; i<30; i++) if(where->to[i])
       component = (component * bin[k][where->to[i]->spawn]) % P;
     if(where->qty) component = (component * k) % P;
     
     // printf("for k=%d [%d-%d] component is: %d\n", k, maxspawn, cfrom, int(component));
     
     total = (total + component) % P;
     }
   
   // printf("total is: %d\n", int(total));
   
   result = (result * total) % P;
   }
 
 void solveCase() {
 
   err = scanf("%d%d", &M, &N);
   FOR(m,0,M) err = scanf("%s", strs[m]);
   
   // proceed
   nodes = 0;
   
   int val = 0;
   
   int bestnodes = 0, q = 0;
   
   while(true) {
     nodes0 = 0;
     FOR(n,0,N) {
       int sv = val;
       root = NULL;
       FOR(m,0,M) {
         if(sv % N == n)
           buildTrie(strs[m], root);
         sv /= N;
         }
       if(sv > 0) goto complete;
       }
     freetrie(root);
     if(nodes0 > bestnodes)
       bestnodes = nodes0, q = 0;
     if(nodes0 == bestnodes)
       q += N;
     val+=N;
     }
   
   complete: ;
   
   printf("Case #%d: %d %d\n", cnum, bestnodes, q);
   fflush(stdout);
   }
 
 int main() {
 
   calcBinom();
   
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
