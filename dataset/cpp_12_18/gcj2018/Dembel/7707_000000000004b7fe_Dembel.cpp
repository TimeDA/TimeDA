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

int solve(vector<int> x) {
  sort(x.begin(), x.end());
  int n = int(x.size());
  return (x[0] + x.back()) / 2;
}

void solve() {
  int n;
  scanf("%d", &n);
  vector<pii> p(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", &p[i].first, &p[i].second);
  }

  vector<int> x(n), y(n);
  for (int i = 0; i < n; ++i) {
    x[i] = p[i].first;
    y[i] = p[i].second;
  }

  int x0 = solve(x);
  int y0 = solve(y);
  dbg("%d %d\n", x0, y0);
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    ans = max(ans, max(abs(x0 - p[i].first), abs(y0 - p[i].second)));
  }
  printf("%d\n", ans);
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