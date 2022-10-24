#define BUFSIZE 1000000
 int Tests, cnum;
 // #define USEWIN
 #define MANYTESTS 1
 // #define LINEBYLINE
 
 #include <algorithm>
 #include <string>
 #include <vector>
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
 
 string getStr() {
 #ifdef LINEBYLINE
   return getStr();
 #else
   scanerr = scanf("%s", buf);
   return buf;
 #endif
   }
 
 #line 9 "work.cpp"
 
 /// ----
 
 
 //Eryx
 
 // !FDI
 
 string mmap[60];
 
 #define XY(x,y) ((y)*64+(x))
 
 char mymap[64*64];
 
 int dxy[4] = {1, 64, -1, -64};
 
 int mirror1[4] = {1,0,3,2};
 int mirror2[4] = {3,2,1,0};
 
 vector<int> cells;
 
 vector<int> ecells, beamcells, goodbeamcells;
 
 int qbeamto[64*64], beamsto[64*64][4], isgood[64*64];
 
 int solve();
 
 int X, Y;
 
 void solveCase() {
 
   Y = getNum();
   X = getNum();
   
   FOR(y,0,Y) mmap[y] = getStr();
   
   bool b = solve();
 
   printf("Case #%d: %s\n", cnum, b ? "POSSIBLE" : "IMPOSSIBLE");
   if(b) FOR(y,0,Y) printf("%s\n", mymap+XY(1,y+1));
   }
 
 int sels[5000];
 
 vector<int> imps[5000];
 
 vector<int> lastsets;
 
 void dfs(int at) {
   if(sels[at]) return;
   // printf("set %d\n", at);
   sels[at] = true;
   lastsets.push_back(at);
   for(int k: imps[at]) {
     // printf("%d->%d\n", at, k);
     dfs(k);
     }
   }
 
 int solve() {  
 
   cells.clear();
   beamcells.clear();
   ecells.clear();
   goodbeamcells.clear();
 
   FOR(i,0,64*64) mymap[i] = 0;
   FOR(y,0,Y) FOR(x,0,X) {
     int c = XY(x+1,y+1);
     mymap[c] = mmap[y][x];
     cells.push_back(c);
     }  
 
   for(int c: cells) {
     if(mymap[c] == '-' || mymap[c] == '|') 
       mymap[c] = '+',
       beamcells.push_back(c);
     if(mymap[c] == '.') 
       ecells.push_back(c),
       qbeamto[c] = 0;
     }
         
   for(int c:cells) if(mymap[c] == '+') {
     bool okay[2];
     okay[0] = true;
     okay[1] = true;
     FOR(d,0,4) {
       int d0 = d;
       int c0 = c + dxy[d0];
       while(true) {
         if(mymap[c0] == 0 || mymap[c0] == '#') break;
         if(mymap[c0] == '+' || mymap[c0] == '-' || mymap[c0] == '|') {
           okay[d&1] = false;
           break;
           }
         if(mymap[c0] == '/')  d0 = mirror2[d0];
         if(mymap[c0] == '\\') d0 = mirror1[d0];
         if(mymap[c0] == '.') beamsto[c0][qbeamto[c0]++] = 2*c + (d&1);
         c0 += dxy[d0];
         }
       }
     if(!okay[0] && !okay[1]) {
       mymap[c] = 'X';
       return false;
       }
     else if(okay[0] && !okay[1]) mymap[c] = '-';
     else if(okay[1] && !okay[0]) mymap[c] = '|';
     else goodbeamcells.push_back(c);
     }
   
   for(int c: goodbeamcells) imps[2*c].clear(), imps[2*c+1].clear();  
 
   for(int c: ecells) {
     bool satisfied = false;
     for(int i=0; i<qbeamto[c]; i++) {
       int b = beamsto[c][i];
       int bc = (b>>1), bi = (b&1);
       bool valid = true;
       if(mymap[bc] == '|' && (bi == 0)) valid = false;
       if(mymap[bc] == '-' && (bi == 1)) valid = false;
       if(mymap[bc] == '-' && (bi == 0)) satisfied = true;
       if(mymap[bc] == '|' && (bi == 1)) satisfied = true;
       if(!valid) { beamsto[c][i] = beamsto[c][qbeamto[c]-1]; qbeamto[c]--; i--; continue; }    
       }
     if(satisfied) continue;
     // if(cnum == 8) printf("%d: %d (%d %d)\n", c, qbeamto[c], beamsto[c][0], beamsto[c][1]);
     if(qbeamto[c] == 0) { 
       mymap[c] = 'N';
       return false;
       }
     int beam0 = beamsto[c][0];
     int beam1 = beamsto[c][1];
     if(qbeamto[c] == 1) imps[beam0^1].push_back(beam0);
     if(qbeamto[c] == 2) imps[beam0^1].push_back(beam1);
     if(qbeamto[c] == 2) imps[beam1^1].push_back(beam0);
     if(qbeamto[c] > 2) { printf("beam error\n"); exit(1); }
     }
 
   if(0) if(cnum == 8)
     for(int b: goodbeamcells) for(int u=0; u<2; u++)
       for(int a: imps[2*b+u]) printf("%d -> %d\n", 2*b+u, a);
   
   for(int b: goodbeamcells) sels[2*b] = sels[2*b+1] = false;
     
   // run 2SAT
   for(int b: goodbeamcells) {
     if(sels[2*b] || sels[2*b+1]) goto xsel;
     lastsets.clear();
     dfs(2*b);
     if(sels[2*b+1]) {
       for(int u: lastsets) sels[u] = false;
       dfs(2*b+1);
       if(sels[2*b]) return false;
       }
     xsel:
     if(sels[2*b]) mymap[b] = '-';
     else mymap[b] = '|';
     }
     
   return true;  
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
