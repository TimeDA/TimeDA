#ifdef DBG1
  #define LOCAL
#endif

#ifdef LOCAL
  #define _GLIBCXX_DEBUG
#endif

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cassert>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

#ifdef DBG1
    #define dbg(...) fprintf(stderr, __VA_ARGS__)
#else
    #define dbg(...)
#endif

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> pii;

const int MAXN = 500;
//const int MAXN = 10;

int dp[MAXN + 1][MAXN + 1];
int dp2[2][MAXN + 1][MAXN + 1];

void solve_all() {
  const int n = 500;
  memset(dp, 0, sizeof(dp));
  memset(dp2, 0, sizeof(dp2));
  for (int i = 0; i * (i + 1) / 2 <= n; ++i) {
    for (int a = 0; a <= n; ++a) {
      for (int b = 0; b <= n; ++b) {
        int a0 = a, b0 = b;
        for (int x = 0; ; ++x) {
          a0 += x;
          b0 += i;
          if (a0 > n || b0 > n) {
            break;
          }
          assert(0 <= a0 && a0 <= n);
          assert(0 <= b0 && b0 <= n);
          dp2[(i + 1)&1][a0][b0] = max(dp2[(i + 1)&1][a0][b0], dp2[i&1][a][b] + x + 1);
        }
      }
    }
    /*dbg("\n");
    for (int a = 0; a <= n; ++a) {
      for (int b = 0; b <= n; ++b) {
        //dbg("%d:", dp[a][b]);
        dbg("%d ", dp2[(i+1)&1][a][b]);
      }
      dbg("\n");
    }*/
    for (int a = 0; a <= n; ++a) {
      for (int b = 0; b <= n; ++b) {
        dp[a][b] = max(dp[a][b], dp2[(i+1)&1][a][b]);
        dp2[i&1][a][b] = 0;
      }
    }
  }
/*  dbg("\n");
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= n; ++j) {
      dbg("%d ", dp[i][j]);
    }
    dbg("\n");
  }*/
}

void solve() {
  int n, m;
  scanf("%d%d", &n, &m);
  printf("%d\n", dp[n][m] - 1);
}

int main() {
  solve_all();
  int tt;
  scanf("%d", &tt);
  for (int ii = 1; ii <= tt; ++ii) {
    printf("Case #%d: ", ii);
    solve();
  }
  return 0;
}
