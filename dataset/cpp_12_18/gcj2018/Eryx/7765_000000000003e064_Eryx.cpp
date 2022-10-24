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

set<string> used;
vector<set<char> > pchar;
int N, L;

string build(string base, int pos) {
//  printf("pos=%d base=%s\n", pos, base.c_str());
  if(pos == L) {
    if(used.count(base)) return "-";
    else return base;
    }
  else {
    for(char c: pchar[pos]) {
//      printf("*%c\n", c);
      string s = build(base+c, pos+1);
      if(s != "-") return s;
      }
    }
  return "-";
  }

void solveCase() {
  int res = 0;

  N = getNum();
  L = getNum();
  
  vector<string> allwords;
  FOR(k,0,N) allwords.push_back(getStr());
  
  used.clear();
  for(string s: allwords) used.insert(s);
  
  pchar.clear(); pchar.resize(L);
  FOR(i,0,L) for(string& s: allwords) pchar[i].insert(s[i]);
  
  printf("Case #%d: %s\n", cnum, build("", 0).c_str());
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
