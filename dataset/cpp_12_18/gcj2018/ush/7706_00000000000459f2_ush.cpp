
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
using namespace std;
typedef long long ll;

int n;
int vs[110];
char buf[110][110];


int solve(void) {
  if(vs[0] < 1 || vs[n-1] < 1) {
    return 0;
  }
  REP(i, n+10) {
    REP(j, n) {
      buf[i][j] = '.';
    }
    buf[i][n] = 0;
  }
  int pos = 0;
  int res = 1;
  REP(p, n) {
    int cur = 0;
    while(cur < vs[p]) {
      // pos -> p
      res = max(res, abs(pos-p) + 1);
      if(p < pos) {
        REP(i, pos-p) {
          buf[i][pos-i] = '/';
        }
      } else if(p == pos) {
        // nothing
      } else {
        REP(i, p-pos) {
          buf[i][pos+i] = '\\';
        }
      }
      ++cur;
      ++pos;
    }
  }
  return res;
}

int main(void) {
  int nCase;
  scanf("%d", &nCase);
  REP(iCase, nCase) {
    scanf("%d", &n);
    REP(i, n) {
      scanf("%d", &vs[i]);
    }
    printf("Case #%d: ", iCase+1);
    int res = solve();
    if(res == 0) {
      puts("IMPOSSIBLE");
      continue;
    }
    printf("%d\n", res);
    REP(i, res) {
      puts(buf[i]);
    }
  }
  return 0;
}
