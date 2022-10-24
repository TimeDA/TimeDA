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

#ifdef DBG1
  //#define AUTO_INTERACT
#endif

pii send_to_cell(int x, int y) {
  dbg("SEND %d %d\n", x + 1, y + 1);
  printf("%d %d\n", x + 1, y + 1);
  fflush(stdout);
#ifdef AUTO_INTERACT
  return pii(x - 1 + rand() % 3, y - 1 + rand() % 3);
#else
  scanf("%d%d", &x, &y);
  return pii(x - 1, y - 1);
#endif
}

void solve() {
  int A;
  scanf("%d", &A);
  int n = 3;
  int m = max(3, (A + n - 1) / n);

  bool isEnd = false;
  int moves_count = 0;
  vector <string> a(n, string(m, '.'));
  for (int i = 0; i < m; ) {
    int j = 0;
    while (j < n && a[j][i] == '#') {
      ++j;
    }
    if (j == n) {
      ++i;
      continue;
    }

    assert(!isEnd);
    assert(++moves_count <= 1000);
    pii p = send_to_cell(min(j + 1, n - 2), min(i + 1, m - 2));
    if (p.first < 0 && p.second < 0) {
      isEnd = true;
      break;
    }
    a[p.first][p.second] = '#';

    /*for (int i = 0; i < n; ++i) {
      dbg("%s\n", a[i].c_str());
    }*/
  }
#ifndef AUTO_INTERACT
  assert(isEnd);
#endif
  dbg("total moves %d\n", moves_count);
}

int main() {
  int tt;
  scanf("%d", &tt);
  for (int ii = 1; ii <= tt; ++ii) {
    dbg("Case #%d:\n", ii);
    solve();
  }
  return 0;
}
