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
#define Size(x) (int(x.size()))

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

  vector<int> data[2];
  
  int did = 0;  
  FOR(i,0,N) { data[did].push_back(getNum()); did = 1-did; }
  
  sort(data[0].begin(), data[0].end());
  sort(data[1].begin(), data[1].end());
  
  vector<int> alldata;
  
  for(int i=0; i<Size(data[0]); i++) {
    alldata.push_back(data[0][i]);
    if(i < Size(data[1]))
      alldata.push_back(data[1][i]);
    }
  
  for(int i=0; i<Size(alldata)-1; i++)
    if(alldata[i] > alldata[i+1]) {
      printf("Case #%d: %d\n", cnum, i);
      return;
      }

  printf("Case #%d: OK\n", cnum);
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
