#define BUFSIZE 1000000
int Tests, cnum;
// #define USEWIN
#define MANYTESTS 1
// #define LINEBYLINE

#include <algorithm>
#include <string>
#include <math.h>
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

double getDouble() {
#ifdef LINEBYLINE
  string s = getLine();
  return atof(s.c_str());
#else
  scanerr = scanf("%s", buf);
  return atof(buf);
#endif
  }

#line 9 "work.cpp"

/// ----


//Eryx

// !FDI

void solveCase() {
  int res = 0;

  double A = getDouble();
  
  printf("Case #%d:\n", cnum);
  
  printf("0.5 0 0\n");
  // 0 a b
  // 0 b -a
  // a, b > 0
  // a^2+b^2 = .25
  // a + b = A/2
  
  // b = A/2 - a
  // a^2 + (A/2 - a)^2 = .25
  // 2a^2 + A^2/4 - Aa = .25
  
  double a0 = 0, a1 = .5 / sqrt(2);
  
  for(int it=0; it<500; it++) {
    double a = (a0+a1) / 2;
    double b = sqrt(.25 - a*a);
    double xA = 2*(a+b);
    // printf("a = %20lf xA = %20lf\n", a, xA);
    if(xA < A) a0 = a;
    else a1 = a;
    }
  
  double a = a0;

  double b = sqrt(.25 - a*a);  
  printf("0 %.20lf %.20lf\n", a, b);
  printf("0 %.20lf %.20lf\n", b, -a);
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
