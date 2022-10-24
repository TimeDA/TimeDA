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

int w, h;
char field[110][110];
int xcnt, ycnt;
int total_cnt;

bool valid(int s, int e, int dir) {
  if (dir == 0) {
    int sum = 0;
    FOR(x, s, e) {
      REP(y, h) {
        if (field[y][x] == '@') { sum++; }
      }
    }
    if (total_cnt / (xcnt + 1) == sum) { return true; }
  } else {
    int sum = 0;
    FOR(y, s, e) {
      REP(x, w) {
        if (field[y][x] == '@') { sum++; }
      }
    }
    if (total_cnt / (ycnt + 1) == sum) { return true; }
  }
  return false;
}

void solve() {
  scanf("%d %d %d %d", &h, &w, &ycnt, &xcnt);
  total_cnt = 0;
  REP(y, h) {
    scanf("%s", field[y]);
    REP(x, w) {
      if (field[y][x] == '@') { total_cnt++; }
    }
  }
  int divide = total_cnt / ((xcnt + 1) * (ycnt + 1));
  int yends[110];
  int yprev = 0;
  int xends[110];
  int xprev = 0;
  FOREQ(yindex, 0, ycnt) {
    FOREQ(e, yprev + 1, h) {
      if (valid(yprev, e, 1)) {
        yends[yindex] = e;
        goto ynext;
      }
    }
    goto ng;
ynext:
    yprev = yends[yindex];
    // cout << yends[yindex] << endl;
  }
  FOREQ(xindex, 0, xcnt) {
    FOREQ(e, xprev + 1, w) {
      if (valid(xprev, e, 0)) {
        xends[xindex] = e;
        goto xnext;
      }
    }
    goto ng;
xnext:;
    xprev = xends[xindex];
    // cout << yends[yindex] << endl;
  }
  yprev = 0;
  FOREQ(yindex, 0, ycnt) {
    xprev = 0;
    FOREQ(xindex, 0, xcnt) {
      int sum = 0;
      FOR(y, yprev, yends[yindex]) {
        FOR(x, xprev, xends[xindex]) {
          if (field[y][x] == '@') { sum += 1; }
        }
      }
      if (sum != divide) { goto ng; }
      xprev = xends[xindex];
    }
    yprev = yends[yindex];
  }
  printf("POSSIBLE\n");
  return;
ng:
  printf("IMPOSSIBLE\n");
}
