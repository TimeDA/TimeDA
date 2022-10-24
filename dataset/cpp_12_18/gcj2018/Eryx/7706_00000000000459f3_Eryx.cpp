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
// the range is traversed from b-1 to a in FORREV
#define FORREV(k,a,b) for(auto k=(b); (a) <= (--k);)

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

#line 9 "work.cpp"

/// ----


//Eryx

// !FDI

int maxjug[501][501], omaxjug[501][501];

bool changed = false;

int include(int q, int bx, int by) {
  FORREV(iy, by, 501) FORREV(ix, bx, 501) {
    int nv = maxjug[iy-by][ix-bx] + q;
    if(nv > maxjug[iy][ix]) {
      maxjug[iy][ix] = nv, changed = true;
      // if(ix == 2 && iy == 0) printf("%d %d +%d\n", bx, by, maxjug[iy-by][ix-bx]);
      }
    }
  }

void prepare() {
  FOR(y,0,501) FOR(x,0,501) maxjug[y][x] = 0;
  
  FOR(total, 1, 40) {
    // FOR(y,0,501) FOR(x,0,501) omaxjug[y][x] = maxjug[y][x];
    changed = false;
    FOR(v, 0, total+1) 
      include(1, v, total - v);
//     FOR(minx, 0, total+1)
//     FOR(maxx, minx, total+1) {
/*       int q = maxx-minx+1;
      int xes = (minx + maxx) * q/2;
      int yes = total * q - xes;
      to_include.insert(make_pair(xes, yes));
      include(q, xes, yes);
      FOR(u, minx, maxx+1)
        include(q-1, xes - u, yes - (total - u)); */
    // printf("tot = %d (%d)\n", total, changed);
    }
  }

void solveCase() {
  int res = 0;

  int Y = getNum(), X = getNum();
  
  printf("Case #%d: %d\n", cnum, maxjug[X][Y]);
  }

#define P 1000000007

int main() {

  prepare();
  
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
