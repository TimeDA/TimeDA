#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <assert.h>
#include <vector>
#include <queue>

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

int h, w;
char field[30][30];
int usable_colors[1 << 4];
bool visit[30][30];

int is_usable(int x, int y, int cx, int cy, int color) {
  int index = 0;
  if (x <= cx && y <= cy) {
    index = 0;
  } else if (cx < x && y <= cy) {
    index = 1;
  } else if (x <= cx && cy < y) {
    index = 2;
  } else if (cx < x && cy < y) {
    index = 3;
  } else {
    assert(false);
  }
  bool ret = (field[y][x] == 'B' ? 1 : 0) == ((color >> index) & 1);
  return ret;
}

int bfs_with_constraint(int sx, int sy, int cx, int cy, int color) {
  if (!is_usable(sx, sy, cx, cy, color)) { return 0; }
  int cnt = 0;
  queue<pair<int, int> > que = queue<pair<int, int> >();
  que.push(make_pair(sx, sy));
  visit[sy][sx] = true;
  while (!que.empty()) {
    int x = que.front().first;
    int y = que.front().second;
    que.pop();
    cnt++;
    REP(dir, 4) {
      int dx[4] = { 1, 0, -1, 0 };
      int dy[4] = { 0, 1, 0, -1 };
      int nx = x + dx[dir];
      int ny = y + dy[dir];
      if (nx < 0 || nx >= w || ny < 0 || ny >= h || visit[ny][nx]) { continue; }
      if (!is_usable(nx, ny, cx, cy, color)) { continue; }
      visit[ny][nx] = true;
      que.push(make_pair(nx, ny));
    }
  }
  return cnt;
}

void solve() {
  MEMSET(usable_colors, 0);
  scanf("%d %d", &h, &w);
  REP(y, h) {
    scanf("%s", field[y]);
  }
  usable_colors[0] = 1;
  usable_colors[(1 << 4) - 1] = 1;
  REP(y, max(h - 1, 1)) {
    REP(x, max(w - 1, 1)) {
      int c = 0;
      c |= (field[y][x] == 'B' ? 1 : 0) << 0;
      c |= (field[y][x + 1] == 'B' ? 1 : 0) << 1;
      c |= (field[y + 1][x] == 'B' ? 1 : 0) << 2;
      c |= (field[y + 1][x + 1] == 'B' ? 1 : 0) << 3;
      // cout << c << endl;
      usable_colors[c] = 1;
    }
  }
  int ans = 0;
  REP(c, 1 << 4) {
    if (!usable_colors[c]) { continue; }
    FOR(cy, -1, h) {
      FOR(cx, -1, w) {
        MEMSET(visit, false);
        REP(sy, h) {
          REP(sx, w) {
            if (visit[sy][sx]) { continue; }
            ans = max(ans, bfs_with_constraint(sx, sy, cx, cy, c));
            // printf("%d %d %d %d %d\n", x, y, offset, c, ans);
          }
        }
      }
    }
  }
  printf("%d\n", ans);
}
