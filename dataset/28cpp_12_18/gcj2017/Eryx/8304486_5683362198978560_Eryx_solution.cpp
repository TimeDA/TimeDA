#define BUFSIZE 1000000
 int Tests, cnum;
 // #define USEWIN
 #define MANYTESTS 1
 // #define LINEBYLINE
 
 #include <algorithm>
 #include <string>
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
 
 #ifndef BUFSIZE
 #define BUFSIZE 1000000
 #endif
 
 char buf[BUFSIZE];
 
 #line 10 "work.cpp"
 
 #include <queue>
 
 /// ----
 
 
 //Eryx
 
 // !FDI
 
 ll mp[300][300];
 
 priority_queue<pair<ll, pair<int, int> > > pq; 
 
 int X, Y;
 
 bool error = false;
 
 void sset(int x, int y, ll v)  {
   if(y<0 || x<0 || y>=Y || x>=X) return;
   if(mp[y][x] == -1) {
     mp[y][x] = v;
     pq.push(make_pair(-v, make_pair(x, y)));
     }
   else if(mp[y][x] > v) error = true;
   }
 
 void solveCase() {
   int res = 0;
 
   Y = getNum();
   X = getNum();
   int N = getNum();
   int D = getNum();
   
   FOR(y,0,Y) FOR(x,0,X) mp[y][x] = -1;
   error = false;
   
   FOR(n,0,N) {
     int y = getNum()-1, x = getNum()-1, v = getNum();
     sset(x,y,v);
     }
   
   while(!pq.empty()) {
     auto a = pq.top();
     pq.pop();
     int x = a.second.first;
     int y = a.second.second;
     ll v = -a.first;
 //("%d %d %d\n", x, y, v);
     sset(x-1,y,v+D);
     sset(x+1,y,v+D);
     sset(x,y-1,v+D);
     sset(x,y+1,v+D);
     }
   
   /* FOR(y,0,Y) {
     printf("|"); FOR(x,0,X) printf("%d ", mp[y][x]);
     printf("\n");
     } */
     
   if(error)
     printf("Case #%d: IMPOSSIBLE\n", cnum);
   else {
     ll tot = 0;
     FOR(y,0,Y) FOR(x,0,X) tot += mp[y][x], tot %= 1000000007;
     printf("Case #%d: %d\n", cnum, int(tot % 1000000007));
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
