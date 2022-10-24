#define BUFSIZE 1000000
int Tests, cnum;
// #define USEWIN
#define MANYTESTS 1
// #define LINEBYLINE

#include <algorithm>
#include <string>
#include <stdio.h>
#include <stdlib.h>
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

int tab[300][300];

// for each boy find a girl he likes...

#define MAXBOYS 200
#define MAXGIRLS 200

int boys, girls;

bool likes[MAXBOYS][MAXGIRLS];

int girlFor[MAXBOYS];
int boyFor[MAXGIRLS];

int queue[MAXBOYS], qb, qe;

int findMatching() {
  int comefrom[MAXGIRLS];
  
  FOR(b,0,boys) girlFor[b] = -1;
  FOR(g,0,girls) boyFor[g] = -1;
  
  int good = 0;
  
  FOR(b,0,boys) {
    qb = 0; qe = 1; queue[0] = b;
    
    FOR(g,0,girls) comefrom[g] = -1;

    while(qb < qe) {

      int cb = queue[qb++];

      FOR(g,0,girls) if(likes[cb][g]) if(comefrom[g] == -1) {
        comefrom[g] = cb;
//      printf("Try G%d for B%d\n", g, cb);
        if(boyFor[g] == -1) {
          int cg = g;
          while(cg != -1) {
            cb = comefrom[cg];
            swap(girlFor[cb], cg);
            boyFor[girlFor[cb]] = cb;
//          printf("%d -> %d\n", cb, girlFor[cb]);
            }
          good++;
          goto nextBoy;
          }
        else {
//        printf("- go to B%d\n", boyFor[g]);
          queue[qe++] = boyFor[g];
          }
        }
      }
    
    nextBoy: ;
    }
  
  return good;
  }

int colors[200][200];

void solveCase() {
  int res = 0;

  int N = getNum();
  FOR(y,0,N) FOR(x,0,N) 
    colors[y][x] = getNum();
    
  // int N = 100;
  // FOR(y,0,N) FOR(x,0,N) colors[y][x] = rand() % 100 + 1;
  
  int changes = N * N;
  boys = girls = N;
  FOR(k, -N, 1+N) {
    FOR(y,0,N) FOR(x,0,N) likes[y][x] = colors[y][x] == k;
    int fm = findMatching();
    // if(fm > 0) printf("%d: %d\n", k, fm);
    changes -= fm;
    }
  
  printf("Case #%d: %d\n", cnum, changes);
  }

#define P 1000000007

int main() {

  // FOR(y,0,100) solveCase();

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
