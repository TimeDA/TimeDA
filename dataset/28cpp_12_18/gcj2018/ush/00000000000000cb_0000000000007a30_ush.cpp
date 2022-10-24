
#include <cassert>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
using namespace std;
typedef long long ll;



void put(int i, int j, int& ri, int& rj) {
  assert(2 <= i && i <= 999);
  assert(2 <= j && j <= 999);
  printf("%d %d\n", i, j);
  fflush(stdout);
  scanf("%d%d", &ri, &rj);
  assert(!(ri == -1 && rj == -1));
}

bool field[10][1000];

int main(void) {
  int nCase;
  scanf("%d", &nCase);
  REP(iCase, nCase) {
    memset(field, 0, sizeof field);
    int atleast;
    scanf("%d", &atleast);
    int left = 1;
    REP(t, 1000) {
      for(; (left+2)*3 < atleast; ++left) {
        if(!field[1][left] || !field[2][left] || !field[3][left]) {
          break;
        }
      }
      int ri, rj;
      put(2, left+1, ri, rj);
      if(ri == 0 && rj == 0) {
        break;
      }
      field[ri][rj] = true;
    }
  }
  return 0;
}
