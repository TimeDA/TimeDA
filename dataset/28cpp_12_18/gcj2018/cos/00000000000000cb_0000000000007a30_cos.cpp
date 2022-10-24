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
    // printf("Case #%d: ", test_case);
    // puts("");
    solve();
  }
}

bool board[1000][1000];
void solve() {
  MEMSET(board, false);
  int n;
  scanf("%d", &n);
  n = max(n, 9);
  n += (3 - n % 3) % 3;
  int w = n / 3;
  REP(i, w) {
    int x = i;
    if (x == 0) { x = 1; }
    if (x == w - 1) { x = w - 2; }
    while (true) {
      if (board[0][i] && board[1][i] && board[2][i]) { break; }
      printf("%d 2\n", x + 1);
      fflush(stdout);
      int rx, ry;
      scanf("%d %d", &rx, &ry);
      // fprintf(stderr, "%d %d\n", rx, ry);
      if (rx == -1) { exit(1); }
      if (rx == 0) { return; }
      rx--; ry--;
      board[ry][rx] = true;
    }
  }
  assert(false);
}