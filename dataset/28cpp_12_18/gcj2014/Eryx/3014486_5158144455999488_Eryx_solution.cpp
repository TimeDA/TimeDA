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
 
 int rivermap[600][200];
 
 int X, Y, B;
 
 int dx[4] = {0, -1, 0, 1};
 int dy[4] = {1, 0, -1, 0};
 
 void solveCase() {
   int res = 0;
 
   err = scanf("%d%d%d", &X, &Y, &B);
   
   FOR(y,0,Y+4) FOR(x,0,X+2) rivermap[y][x] = 1;
   FOR(y,1,Y+3) FOR(x,1,X+1) rivermap[y][x] = 0;
   
   rivermap[1][X+1] = 0;
   
   FOR(b,0,B) {
     int x0, y0, x1, y1;
     err = scanf("%d%d%d%d", &x0, &y0, &x1, &y1);
     y0 += 1; x0 += 1;
     y1 += 1; x1 += 1;
     y0++; y1++;
     x1++; y1++;
     FOR(y,y0,y1) FOR(x,x0,x1) rivermap[y][x] = 1;
     }
   
   /* fprintf(stderr, "orig: \n");
   if(0) FOR(y,0,Y+4) {
     FOR(x,0,X+2) fprintf(stderr, "%d", rivermap[y][x]);
     fprintf(stderr, "\n");
     }
   
   fprintf(stderr, "got: \n");
   fflush(stderr);*/
   
 
   int nextflow = 2, nextx = 1;
   while(nextx <= X) {
     trynextx:
     if(rivermap[1][nextx] != 0) nextx++;
     else {
       int atx = nextx, aty = 1, atd = 1;
       while(true) {
         rivermap[aty][atx] = nextflow;
         if(atx == X+1) 
           goto finish;
         if(aty == Y+2) {
           nextflow++;
           goto trynextx;
           }
         if(rivermap[aty+dy[atd]][atx+dx[atd]] == 0 || rivermap[aty+dy[atd]][atx+dx[atd]] == nextflow)
           atx += dx[atd], aty += dy[atd], atd = (1+atd) % 4;
         else
           atd = (3+atd) % 4;
         if(atx == nextx && aty == 1 && atd == 1) {
           nextx++;
           goto trynextx;
           }
         }
       }
     }
   
   finish:
   
   if(0) FOR(y,0,Y+4) {
     FOR(x,0,X+2) fprintf(stderr, "%d", rivermap[y][x]);
     fprintf(stderr, "\n");
     }
   
   printf("Case #%d: %d\n", cnum, nextflow - 2);
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
