#define BUFSIZE 1000000
 char buf[BUFSIZE];
 int Tests, cnum;
 // #define USEWIN
 #define MANYTESTS 1
 // #define LINEBYLINE
 
 // Eryx's new template for I/O contests, May 3, 2015
 
 #include <algorithm>
 #include <vector>
 #include <math.h>
 #include <set>
 #include <stdio.h>
 using namespace std;
 
 #define LS <
 #define Size(x) (int(x.size()))
 
 // All macros with parameters "k,a,b" run the "k" variable in range [a,b)
 #define FOR(k,a,b) for(__typeof(a) k=(a); k LS (b); ++k)
 
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
 
 #line 10 "work.cpp"
 
 /// ----
 
 
 //Eryx
 
 // !FDI
 
 int N, S;
 int x[2000], y[2000], z[2000], vx[2000], vy[2000], vz[2000];
 
 double bestt[1024][1024];
 double vel2[1024][1024];
 double bestd[1024][1024];
 
 bool stable[1024][1024];
 
 void prepare() {
   FOR(i,0,N) FOR(j,0,N) {
     int dx = x[i] - x[j];
     int dy = y[i] - y[j];
     int dz = z[i] - z[j];
     int dvx = vx[i] - vx[j];
     int dvy = vy[i] - vy[j];
     int dvz = vz[i] - vz[j];
 
     stable[i][j] = (dvx == 0 && dvy == 0 && dvz == 0);
     
     if(stable) {
       bestd[i][j] = dx*dx+dy*dy+dz*dz;
       continue;
       }
     int a = 2 * (dvx * dx + dvy * dy + dvz * dz);
     int b = 2 * (dvx * dvx + dvy * dvy + dvz * dvz);
     
     double t = -a * 1.0 / b;
     bestt[i][j] = t;
     
     double dxb = dx + t*dvx;
     double dyb = dy + t*dvy;
     double dzb = dz + t*dvz;
     
     bestd[i][j] = dxb*dxb+dyb*dyb+dzb*dzb;
     
     vel2[i][j] = (dvx * dvx + dvy * dvy + dvz * dvz);
     }
   }
 
 #define INFF 1e100
 
 struct event { 
   double t; int i, j; bool closing; 
   };
 
 bool operator < (const event& e1, const event &e2) {
   if(e1.t != e2.t) return e1.t < e2.t;
   if(e1.closing != e2.closing) return e1.closing;
   return false;
   }
 
 vector<event> events;
 
 double lasttime[2000];
 
 set<int> xnear[2000];
 int qnear[2000];
 bool onast[2000];
 
 double curtime;
 
 bool addjump(int i) {
   if(qnear[i] == 0 && lasttime[i] < curtime - S)
     onast[i] = false;
 //printf("%lf: addjump to %d (%d)\n", curtime, i, onast[i]);
   qnear[i]++;
   }
 
 bool deljump(int i) {
   qnear[i]--;
   if(!qnear[i] && onast[i]) lasttime[i] = curtime;
 //printf("%lf: deljump to %d (%d)\n", curtime, i, onast[i]);
   }
 
 void reach(int where) {
   if(onast[where]) return;
   onast[where] = true;
 //printf("%lf : reached %d\n", curtime, where);
   for(int j: xnear[where]) reach(j);
   }
 
 bool solvable(double d) {
   events.clear();
   double ds = d * d;
   
   FOR(i,0,N) FOR(j,0,N) if(i != j) if(bestd[i][j] <= ds) {
     if(stable[i][j]) 
       events.push_back(event { 0, i,j, true } );
     else {
       double ct = sqrt((ds - bestd[i][j]) / vel2[i][j]);
       events.push_back(event { bestt[i][j] - ct - 1e-6, i, j, true });
       events.push_back(event { bestt[i][j] + ct + 1e-6, i, j, false });
       }
     }
   sort(events.begin(), events.end());
   
   FOR(i,0,N) lasttime[i] = 0, onast[i] = false, qnear[i] = 0, xnear[i].clear();
   onast[0] = true;
   
   for(auto e: events) {
 //  printf("time = %lf connect: %d,%d (%d)\n", e.t, e.i, e.j, e.closing);
     curtime = e.t;
     if(e.closing) {
       xnear[e.i].insert(e.j);
       addjump(e.i);
       addjump(e.j);
       }
     if(onast[e.i]) reach(e.j);
     if(!e.closing) {
       xnear[e.i].erase(e.j);
       deljump(e.i);
       deljump(e.j);
       }
     if(onast[1]) return true;
     }
   
   return false;
   }
 
 void solveCase() {
   int res = 0;
 
   N = getNum();
   S = getNum();
   FOR(i,0,N) 
     x[i] = getNum(), y[i] = getNum(), z[i] = getNum(),
     vx[i] = getNum(), vy[i] = getNum(), vz[i] = getNum();
   
   prepare();
   
   double mindist = 0, maxdist = 10000;
   
   while(maxdist - mindist > 1e-6) {
     double cdist = (maxdist + mindist) / 2;
     if(solvable(cdist)) maxdist = cdist;
     else mindist = cdist;
     } 
   
   printf("Case #%d: %lf\n", cnum, (maxdist+mindist)/2);
   fflush(stdout);
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
