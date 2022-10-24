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
  
  int likes[300];
  bool sold[300];
  
  vector<int> current;
    
  FOR(i,0,N+1) likes[i] = 0;
  FOR(i,0,N+1) sold[i] = false;
  
  FOR(i,0,N) {
    int D = getNum();
    current.clear();
    FOR(d,0,D) current.push_back(getNum());
    for(int c: current) likes[c]++;
    int which;
    if(D) {
      which = current[0];
    
      for(int c: current)
        if(sold[which] || (!sold[c] && likes[c] < likes[which]))
          which = c;
      }
    
    if(sold[which] || D == 0) printf("-1\n");
    else printf("%d\n", which), sold[which] = true;
    fflush(stdout);
    }
  
  // printf("Case #%d: %d\n", cnum, res);
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
