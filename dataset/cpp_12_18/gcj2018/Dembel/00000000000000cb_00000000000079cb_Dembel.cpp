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

void solve() {
  int n;
  scanf("%d", &n);
  vector<vector <int>> a(2);
  for (int i = 0; i < n; ++i) {
    int x;
    scanf("%d", &x);
    a[i&1].push_back(x);
  }
  for (int i = 0; i < 2; ++i) {
    sort(a[i].begin(), a[i].end());
  }
  vector <int> v;
  for (int i = 0; i < n; ++i) {
    v.push_back(a[i&1][i/2]);
  }
  for (int i = 0; i < n - 1; ++i) {
    if (v[i] > v[i + 1]) {
      printf("%d\n", i);
      return;
    }
  }
  printf("OK\n");
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
