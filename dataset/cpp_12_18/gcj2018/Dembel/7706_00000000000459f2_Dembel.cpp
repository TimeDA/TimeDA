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

void check(const vector<string> & res, const vector<int> &a) {
  int n = int(a.size());
  int m = int(res.size());
  for (int i = 0; i < m; ++i) {
    assert((int)res[i].size() == n);
    for (int j = 0; j < n; ++j) {
      assert(res[i][j] == '.' || res[i][j] == '\\' || res[i][j] == '/');
      if (j == 0 || j == n - 1 || i == m - 1) {
        assert(res[i][j] == '.');
      }
    }
  }
  vector<int> cnt(n, 0);
  for (int i = 0; i < n; ++i) {
    int x = 0;
    int y = i;
    while (x != m - 1) {
      if (res[x][y] == '.') {
        x++;
      } else if (res[x][y] == '\\') {
        x++, y++;
      } else if (res[x][y] == '/') {
        x++, y--;
      } else {
        assert(0);
      }
    }
    cnt[y] += 1;
  }
  for (int i = 0; i < n; ++i) {
    assert(cnt[i] == a[i]);
  }
}

void solve() {
  int n;
  scanf("%d", &n);
  vector <int> a(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  if (a[0] == 0 || a[n - 1] == 0) {
    printf("IMPOSSIBLE\n");
    return;
  }
  vector <int> dir(n, 0);
  for (int i = 0, sum = 0; i < n; ++i) {
    sum += a[i] - 1;
    if (a[i] == 0) {
      if (sum >= 0) {
        dir[i] = -1;
      } else {
        dir[i] = 1;
      }
    }
  }
  vector <string> res;
  for (int i = 0; i < n; ++i) {
    if (dir[i] == 0) { continue; }
    int j = i, k = 0;
    while (dir[j] != 0) {
      assert(dir[j] == dir[i]);
      if (k == int(res.size())) {
        //dbg("ipush_back i %d j %d k %d res.size() %d \n", i, j, k, int(res.size()));
        res.push_back(string(n, '.'));
      }
      res[k][j] = (dir[j] == 1 ? '\\' : '/');
      j += dir[j];
      k++;
    }
    assert(dir[j] == 0);
    //dbg("i %d j %d k %d res.size() %d \n", i, j, k, int(res.size()));
  }
  res.push_back(string(n, '.'));
  printf("%d\n", int(res.size()));
  for (auto s : res) {
    printf("%s\n", s.c_str());
  }
  check(res, a);
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
