#define BUFSIZE 1000000
int Tests, cnum;
// #define USEWIN
#define MANYTESTS 1
// #define LINEBYLINE

#include <algorithm>
#include <string>
#include <vector>
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

#line 9 "work.cpp"

/// ----


//Eryx

// !FDI

void solveCase() {
  int res = 0;

  int N = getNum();
  int qty[200];
  FOR(i,0,N) qty[i] = getNum();
  
  int total = 0;
  FOR(i,0,N) total += qty[i];
  
  if(total != N || !qty[0] || !qty[N-1]) {
    printf("Case #%d: IMPOSSIBLE\n", cnum);
    return;
    }
  
  
  string line = "";
  FOR(i,0,N) line += ".";
  vector<string> sol;
  FOR(i,0,N) sol.push_back(line);
  
  int ncol = 0, maxy = 0;
  FOR(i,0,N) if(qty[i]) {
    int c = ncol, d = ncol + qty[i];
    ncol = d;
    int y1 = 0, y2 = 0;
    while(c < i) {
      sol[y1][c] = '\\';
      y1++; c++;
      } d--;
    while(d > i) {
      sol[y2][d] = '/';
      y2++; d--;
      }
    maxy = max(maxy, max(y1, y2));
    }
  
  printf("Case #%d: %d\n", cnum, maxy+1);
  FOR(y,0,maxy+1) printf("%s\n", sol[y].c_str());
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
