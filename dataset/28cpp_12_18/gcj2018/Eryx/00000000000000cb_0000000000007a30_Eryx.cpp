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

#line 9 "work.cpp"

/// ----


//Eryx

// !FDI

void solveCase() {
  int res = 0;

  int A = getNum();
  int X = 0, Y = 0;
  
  while(X * Y < A) {
    X++;
    if(X * Y < A) Y++;
    }
  
  int fdata[64][64];
  
  for(int y=0; y<64; y++)
  for(int x=0; x<64; x++)
    fdata[y][x] = 0;
  
  for(int y=1; y<=Y; y++)
  for(int x=1; x<=X; x++)
    fdata[y][x] = 1;

  int moves = 0;  
  while(true) {
    moves++;
    int best = -1, bestx = 0, besty = 0;
    for(int y=2; y<20; y++)
    for(int x=2; x<20; x++) {
      int here = 0;
      for(int dy=-1; dy<=1; dy++)
      for(int dx=-1; dx<=1; dx++)
        here += fdata[y+dy][x+dx];
//      printf("%d %d: %d\n", y,x, here);
      if(here > best) best = here, bestx = x, besty = y;
      }
    printf("%d %d\n", bestx, besty);
    fflush(stdout);
    int ax = getNum(), ay = getNum();
    if(ax == 0 && ay == 0) break;
    if(ax == -1 && ay == -1) break;
    fdata[ay][ax] = 0;
    }
  
  fprintf(stderr, "%d moves\n", moves);
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
