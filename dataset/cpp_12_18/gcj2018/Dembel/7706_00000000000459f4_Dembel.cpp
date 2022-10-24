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

vector<string> multiple(const vector<string> & a) {
  vector<string> b;
  for (int i = 0; i < int(a.size()); ++i) {
    static char s[1 << 15];
    for (int j = 0; j < int(a[i].size()); ++j) {
      s[2 * j] = s[2 * j + 1] = a[i][j];
    }
    b.push_back(string(s, s + 2 * a[i].size()));
    b.push_back(b.back());
  }
  return b;
}

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

int dfs(vector<vector<bool>> & good, int n, int m, int x, int y) {
  if (!(0 <= x && x < n && 0 <= y && y < m)) {
    return 0;
  }
  if (!good[x][y]) {
    return 0;
  }

  good[x][y] = false;
  int cnt = 1;
  for (int i = 0; i < 4; ++i) {
    cnt += dfs(good, n, m, x + dx[i], y + dy[i]);
  }
  return cnt;
}

void solve() {
  int n, m;
  scanf("%d%d", &n, &m);
  vector <string> a;
  for (int i = 0; i < n; ++i) {
    static char s[100];
    scanf("%s", s);
    a.push_back(string(s));
  }
  vector <vector<bool>> good(n, vector <bool>(m));
  vector<string> a0 = a;
  int res = 0; //max(cnt0, n * m - cnt0);
  for (int i = 0; i < 6; ++i) {
    a = multiple(a);
    /*for (auto & s : a) {
      dbg("%s\n", s.c_str());
    }*/
    for (int dx = -n+1; dx < int(a.size()); ++dx) {
      for (int dy = -m+1; dy < int(a[0].size()); ++dy) {
        for (int x = 0; x < n; ++x) {
          for (int y = 0; y < m; ++y) {
            int x0 = x + dx;
            int y0 = y + dy;
            good[x][y] = (0 <= x0 && x0 < int(a.size())
                          && 0 <= y0 && y0 < int(a[0].size())
                          && a[x0][y0] == a0[x][y]);
          }
        }
        for (int x = 0; x < n; ++x) {
          for (int y = 0; y < m; ++y) {
            int cur = dfs(good, n, m, x, y);
            if (cur > res) {
              //dbg("i %d dx %d dy %d x %d y %d cur %d\n", i, dx, dy, x, y, cur);
              res = cur;
            }
          }
        }
      }
    }
  }
  printf("%d\n", res);
}

int main() {
  int tt;
  scanf("%d", &tt);
  for (int ii = 1; ii <= tt; ++ii) {
    printf("Case #%d: ", ii);
    solve();
  }
  return 0;
}
