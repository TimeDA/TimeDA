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

int seq[110];
char field[110][110];
void solve() {
  MEMSET(field, 0);
  int n;
  scanf("%d", &n);
  int sum = 0;
  REP(x, n) {
    scanf("%d", &seq[x]);
    sum += seq[x];
    REP(y, 110) { field[y][x] = '.'; }
  }
  if (sum != n || seq[0] == 0 || seq[n - 1] == 0) {
    puts("IMPOSSIBLE");
    return;
  }
  int ans = 1;
  int pos = 0;
  REP(target, n) {
    REP(iter, seq[target]) {
      int cnt = abs(pos - target);
      ans = max(ans, cnt + 1);
      if (pos == target) {
        ;
      } else if (pos < target) {
        REP(i, cnt) {
          field[i][pos + i] = '\\';
        }
      } else if (pos > target) {
        REP(i, cnt) {
          field[i][pos - i] = '/';
        }
      }
      pos += 1;
    }
  }
  printf("%d\n", ans);
  REP(y, ans) {
    printf("%s\n", field[y]);
  }
}
