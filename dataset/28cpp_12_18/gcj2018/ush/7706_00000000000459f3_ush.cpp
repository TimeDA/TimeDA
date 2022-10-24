
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <iostream>
#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
using namespace std;
typedef long long ll;

char memo[502][502][34][34];
short solve(int r, int b, int lastR, int lastB) {
  char& res = memo[r][b][lastR][lastB];
  if(res < 0) {
    res = 0;
    if(r >= lastR && b >= lastB+1) {
      res = max(res, (char)(1+solve(r-lastR, b-(lastB+1), lastR, lastB+1)));
    }
    if(r >= lastR+1) {
      res = max(res, (char)(1+solve(r-(lastR+1), b, lastR+1, 0)));
    }
    // fprintf(stderr, "solve(%d, %d, %d, %d) = %d\n", r, b, lastR, lastB, res);
  }
  return res;
}

int main(void) {
  int nCase;
  scanf("%d", &nCase);
  memset(memo, -1, sizeof memo);
  REP(iCase, nCase) {
    int r, b;
    scanf("%d%d", &r, &b);
    int res = solve(r, b, 0, 0);
    printf("Case #%d: %d\n", iCase+1, res);
  }
  return 0;
}
