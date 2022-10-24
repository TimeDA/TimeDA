
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <iostream>
#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
using namespace std;
typedef long long ll;

int n;
int vs[110][110];
bool bs[110][110];

int solve(void) {
  int res = n*n+1;
  REP(pat, 1 << (n*n)) {
    int cur = 0;
    REP(i, n) REP(j, n) {
      if(pat & (1 << (i*n+j))) {
        bs[i][j] = false;
        ++cur;
      } else {
        bs[i][j] = true;
      }
    }
    if(cur >= res) {
      continue;
    }
    bool ok = true;
    REP(i, n) REP(j, n) if(bs[i][j]) {
      for(int jj = j+1; jj < n; ++jj) {
        if(bs[i][jj] && vs[i][j] == vs[i][jj]) {
          // fprintf(stderr, "(%d, %d) == (%d, %d) for pat = %x, v=%d,%d\n", i, j, i, jj, pat, vs[i][j], vs[i][jj]);
          ok = false;
          goto HOGE;
        }
      }
      for(int ii = i+1; ii < n; ++ii) {
        if(bs[ii][j] && vs[i][j] == vs[ii][j]) {
          // fprintf(stderr, "(%d, %d) == (%d, %d) for pat = %x, v=%d,%d\n", i, j, ii, j, pat, vs[i][j], vs[ii][j]);
          ok = false;
          goto HOGE;
        }
      }
    }
    // fprintf(stderr, "OK for pat = %x\n", pat);
    res = min(res, cur);
  HOGE:
    ;
  }
  return res;
}

int main(void) {
  int nCase;
  scanf("%d", &nCase);
  REP(iCase, nCase) {
    scanf("%d", &n);
    REP(i, n) {
      REP(j, n) {
        scanf("%d", &vs[i][j]);
      }
    }
    int res = solve();
    printf("Case #%d: %d\n", iCase+1, res);
  }
  return 0;
}
