#define BUFSIZE 1000000
int Tests, cnum;
// #define USEWIN
#define MANYTESTS 1
// #define LINEBYLINE

#include <algorithm>
#include <string>
#include <stdio.h>
using namespace std;

#define LS <
#define Size(x) (int((x).size()))

// All macros with parameters "k,a,b" run the "k" variable in range [a,b)
#define FOR(k,a,b) for(auto k=(a); k LS (b); ++k)

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

string grid[100];

int gri[100][100];

int good[100][100];

int countgood(int x, int y) {
  if(!good[y][x]) return 0;
  good[y][x] = 0;
  return 1 + countgood(x+1,y) + countgood(x-1,y) + countgood(x,y-1) + countgood(x,y+1);
  }

void solveCase() {
  int res = 0;

  int Y = getNum(), X = getNum();
  
  FOR(y,0,Y) grid[y] = getStr();
  FOR(y,0,Y) FOR(x,0,X) gri[y][x] = grid[y][x] == 'W';
  
  bool app[16];
  FOR(u,0,16) app[u] = false;
  
  FOR(y,0,2*Y-1) FOR(x,0,2*X-1) {
    int y0 = y>>1, y1 = (y+1)>>1;
    int x0 = x>>1, x1 = (x+1)>>1;
    app[gri[y0][x0] + 2 * gri[y1][x0] + 4 * gri[y0][x1] + 8 * gri[y1][x1]] = true;
    }
  
  
  int best = 0;
  
  FOR(a,0,16) if(app[a])
    FOR(sy,0,Y+1) FOR(sx,0,X+1) {
      // if(sx != 3 || sy != 5) continue;
      FOR(y,0,Y) FOR(x,0,X) 
        good[y+1][x+1] = gri[y][x] == ((a >> ((y>=sy ? 1:0) + (x>=sx?2:0))) & 1);
      // printf("%d:\n", a); FOR(y,0,Y) { FOR(x,0,X) printf("%d", good[y+1][x+1]); printf("\n"); }
      FOR(y,0,Y) FOR(x,0,X) {
        int found = countgood(x+1, y+1);
        if(found > best) {
          best = found;
          // printf("%d @ %d,%d,%d\n", best, a, sx, sy);
          }
        }
      }

  printf("Case #%d: %d\n", cnum, best);
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
