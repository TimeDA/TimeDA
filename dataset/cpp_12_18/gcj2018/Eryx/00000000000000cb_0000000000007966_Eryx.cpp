#define BUFSIZE 1000000
int Tests, cnum;
// #define USEWIN
#define MANYTESTS 1
// #define LINEBYLINE

#include <algorithm>
#include <string>
#include <stdio.h>
using namespace std;

#define Size(x) (int(x.size()))

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

void solveCase() {
  int res = 0;

  int D = getNum();
  string S = getStr();
  
  int shoots = 0;
  int at = 0;
  int sat[40];
  for(int i=0; i<40; i++) sat[i] = 0;
  
  int total = 0;
  
  for(char c: S) {
    if(c == 'C') at++;
    else sat[at]++, shoots++, total += (1<<at);
    }
  
  // printf("D=%d total=%d shoots=%d\n", D, total, shoots);
  
  if(shoots > D) { printf("Case #%d: IMPOSSIBLE\n", cnum); return; }
  
  int score = 0;
  
  while(total > D) 
    if(sat[at] == 0) at--;
    else { sat[at]--; sat[at-1]++; total -= (1<<(at-1)); score++; }
  
  printf("Case #%d: %d\n", cnum, score);
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
