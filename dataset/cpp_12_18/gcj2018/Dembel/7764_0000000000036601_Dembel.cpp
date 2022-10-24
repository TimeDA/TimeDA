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

const int INF = (1 << 30);

int getW(int x, int n) {
  int div = (100 * x) / n;
  int mod = (100 * x) % n;
  if (mod >= (n + 1) / 2) {
    div++;
  }
  return div;
}

void solve() {
  int n, k;
  scanf("%d%d", &n, &k);
  vector <int> a(k);
  for (int i = 0; i < k; ++i) {
    scanf("%d", &a[i]);
  }
  while (k < n) {
    k++;
    a.push_back(0);
  }

  vector <int> dp(201, INF);
  dp[0] = 0;
  for (int i = 0; i < k; ++i) {
    vector <int> dp2(301, INF);
    for (int j = 0; j <= 200; ++j) {
      if (dp[j] == INF) { continue; }

      int cur = a[i];
      int curW = getW(cur, n);
      dp2[j + curW] = min(dp2[j + curW], dp[j] + cur);
      for (int z = curW + 1; z <= 100; ++z) {
        int y = (n * (2 * z - 1) + 199) / 200;
        assert(getW(y, n) >= z);
        if (getW(y, n) != z) {
          continue;
        }
        dbg("cur %d z %d y %d\n", cur, z, y);
        assert(y > cur);
        assert(getW(y - 1, n) < z);
        dp2[j + z] = min(dp2[j + z], dp[j] + y);
      }
    }
    dp.swap(dp2);
  }
  int ans = 200;
  while (dp[ans] > n) {
    ans--;
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
