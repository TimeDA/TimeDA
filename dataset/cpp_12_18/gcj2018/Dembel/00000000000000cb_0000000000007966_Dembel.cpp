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
  int D;
  char s[40];
  scanf("%d %s", &D, s);
  vector <int> cnt(30, 0);
  int sum = 0;
  for (int i = 0, j = 0; s[i]; ++i) {
    if (s[i] == 'S') {
      sum += (1 << j);
      cnt[j] += 1;
    } else {
      assert(s[i] == 'C');
      j++;
    }
  }
  int ans = 0;
  while (sum > D) {
    int i = int(cnt.size()) - 1;
    while (i >= 0 && cnt[i] == 0) {
      --i;
    }
    if (i > 0) {
      ans++;
      cnt[i] -= 1;
      --i;
      cnt[i] += 1;
      sum -= (1 << i); 
    } else {
      printf("IMPOSSIBLE\n");
      return;
    }
  }
  printf("%d\n", ans);
}

int main() {
  int tt;
  scanf("%d", &tt);
  for (int ii = 1; ii <= tt; ++ii) {
    dbg("Case #%d:\n", ii);
    printf("Case #%d: ", ii);
    solve();
  }
  return 0;
}
