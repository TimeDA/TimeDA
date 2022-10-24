#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <assert.h>
#include <vector>

using namespace std;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
static const double EPS = 1e-9;
static const double PI = acos(-1.0);

#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, s, n) for (int i = (s); i < (int)(n); i++)
#define FOREQ(i, s, n) for (int i = (s); i <= (int)(n); i++)
#define FORIT(it, c) for (__typeof((c).begin())it = (c).begin(); it != (c).end(); it++)
#define MEMSET(v, h) memset((v), h, sizeof(v))

void solve();
int main() {
  int test;
  scanf("%d", &test);
  char str[1000];
  fgets(str, 999, stdin);
  int test_case = 0;
  while (test--) {
    test_case++;
    printf("Case #%d: ", test_case);
    // puts("");
    solve();
  }
}

int dp1[600][600];
int dp2[600][600];
void solve() {
  int r, b;
  scanf("%d %d", &r, &b);
  MEMSET(dp1, 0);
  MEMSET(dp2, 0);
  int sr = 1;
  int sb = 1;
  while ((sr + 1) * (sr + 2) / 2 <= r) { sr++; }
  while ((sb + 1) * (sb + 2) / 2 <= b) { sb++; }
  FOREQ(i, 0, sr) {
    FOREQ(j, 0, sb) {
      if (i == 0 && j == 0) { continue; }
      FOREQ(k, 0, r) {
        FOREQ(l, 0, b) {
          dp2[k][l] = max(dp1[k][l], dp2[k][l]);
          dp2[k + i][j + l] = max(dp2[k + i][j + l], dp1[k][l] + 1);
        }
      }
      swap(dp1, dp2);
    }
  }
  int ans = 0;
  FOREQ(i, 0, r) {
    FOREQ(j, 0, b) {
      ans = max(ans, dp1[i][j]);
    }
  }
  printf("%d\n", ans);
}
