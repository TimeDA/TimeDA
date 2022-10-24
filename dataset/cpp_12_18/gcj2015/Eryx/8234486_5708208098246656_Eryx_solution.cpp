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
 using namespace std;
 
 typedef vector<string> vs;
 
 #define LS <
 #define Size(x) (int(x.size()))
 #define LET(k,val) __typeof(val) k = (val)
 // execute "act", and return "val" as an expression result
 #define CLC(act,val) ([&] () {act; return (val); } ())
 
 // All macros with parameters "k,a,b" run the "k" variable in range [a,b)
 #define FOR(k,a,b) for(__typeof(a) k=(a); k LS (b); ++k)
 
 // Standard mathematical quantifiers, plus tools to implement them
 // find the first k in [a,b) that satisfies cond, or b if none
 #define FIRST(k,a,b,cond) CLC(LET(k, a); for(; k LS (b); ++k) if(cond) break, k)
 #define EXISTS(k,a,b,cond) (FIRST(k,a,b,cond) LS (b))
 #define FORALL(k,a,b,cond) (!EXISTS(k,a,b,!(cond)))
 
 // add guards to a vs
 vs addguards(vs data, char guard) {
   vs res;
   string border;
   FOR(k,0,Size(data[0])+2) border += guard;
   res.push_back(border);
   FOR(k,0,Size(data)) res.push_back(guard + data[k] + guard);
   res.push_back(border);
   return res;
   }
 
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
 
 int X, Y;
 vector<string> gmap;
 
 bool safe(int x, int y, int dx, int dy) {
   while(true) {
     x += dx;
     y += dy;
     if(gmap[y][x] == '#') return false;
     if(gmap[y][x] != '.') return true;
     }  
   }
 
 int solve() {
   if(FORALL(y,0,Y, FORALL(x,0,X, gmap[y][x] == '.')))
     return 0;
   int score = 0;
   gmap = addguards(gmap, '#');
   X += 2; Y += 2;
   FOR(y,0,Y) FOR(x,0,X) if(gmap[y][x] != '.' && gmap[y][x] != '#') {
     bool safe0 = safe(x,y,1,0);
     bool safe1 = safe(x,y,-1,0);
     bool safe2 = safe(x,y,0,-1);
     bool safe3 = safe(x,y,0,1);
     bool safeAny = safe0 || safe1 || safe2 || safe3;
     if(!safeAny) return -1;
     if(gmap[y][x] == '<' && !safe1) score++;
     if(gmap[y][x] == '>' && !safe0) score++;
     if(gmap[y][x] == '^' && !safe2) score++;
     if(gmap[y][x] == 'v' && !safe3) score++;
     }
   return score;
   }
 
 void solveCase() {
   int res = 0;
 
   Y = getNum();
   X = getNum();
   gmap.clear();
   for(int y=0; y<Y; y++) gmap.push_back(getStr());
   
   int s = solve();
   if(s >= 0)
     printf("Case #%d: %d\n", cnum, s);
   else
     printf("Case #%d: IMPOSSIBLE\n", cnum);
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
