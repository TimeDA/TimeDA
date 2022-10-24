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

bool dfs(int s, const vector<vector<int>> &ed, vector<int> & color, int curC, vector<int> & match) {
  if (color[s] == curC) {
    return false;
  }
  color[s] = curC;
  for (int v : ed[s]) {
    if (match[v] == -1 || dfs(match[v], ed, color, curC, match)) {
      match[v] = s;
      return true;
    }
  }
  return false;
}

void solve() {
  int n;
  scanf("%d", &n);
  vector<vector<int>> a(n, vector<int>(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      scanf("%d", &a[i][j]);
    }
  }
  int res = 0;
  for (int i = -n; i <= n; ++i) {
    int cnt = 0;
    vector <vector<int>> ed(n);
    for (int x = 0; x < n; ++x) {
      for (int y = 0; y < n; ++y) {
        if (a[x][y] == i) {
          cnt += 1;
          ed[x].push_back(y);
        }
      }
    }
    vector<int> match(n, -1);
    vector<int> color(n, -1);
    for (int i = 0; i < n; ++i) {
      if (dfs(i, ed, color, i, match)) {
        cnt--;
      }
    }
    res += cnt;
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
