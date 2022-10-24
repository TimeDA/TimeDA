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

void brute(int n, int sum, int it, const vector<vector<int>> &sets, vector<int> & g, int & totAns, set<vector<int>> &cache) {
  dbg("brute it %d (", it);
  for (int x : g) {
    dbg("%d ", x);
  }
  dbg(")\n");
  if (g[0] + (sum - g[0]) / 2 <= totAns) {
    return;
  }
  g.push_back(it);
  if (cache.count(g)) {
    g.pop_back();
    return;
  }
  cache.insert(g);
  g.pop_back();
  totAns = max(totAns, g[0]);

  if (it == (int)sets.size()) {
    return;
  }

  brute(n, sum, it + 1, sets, g, totAns, cache);
  const auto& s = sets[it];
  dbg("it %d s = ", it);
  for (int x : s) {
    dbg("%d ", x);
  }
  dbg("\n");
  bool ok = 1;
  for (int i = 0; i < n; ++i) {
    ok &= (g[i] >= s[i]);
  }
  if (ok) {
    for (int i = 0; i < n; ++i) {
      g[i] -= s[i];
      sum -= s[i];
    }
    g[0] += 1;
    sum += 1;

    brute(n, sum, it, sets, g, totAns, cache);

    sum -= 1;
    g[0] -= 1;
    for (int i = 0; i < n; ++i) {
      g[i] += s[i];
      sum += s[i];
    }  
  }
}

void brute2(int n, int sum, const vector<int> & a, const vector<int> & b, vector<int> & g, set<vector<int>> &sets) {
  for (const auto & s : sets) {
    bool ok = 1;
    for (int i = 0; i < n; ++i) {
      ok &= (s[i] <= g[i]);
    }
    if (ok) { return; }
  }
  if (!g[0]) {
    sets.insert(g);
  }
  for (auto x : g) {
    dbg("%d ", x);
  }
  dbg("\n");
  
  if (sum == 0) {
    return;
  }
  
  for (int i = 0; i < n; ++i) {
    if (a[i] == i || b[i] == i) { continue; }
    if (a[i] == 0 || b[i] == 0) { continue; }
    if (g[i]) {
      ++g[a[i]];
      ++g[b[i]];
      --g[i];
      brute2(n, sum - 1, a, b, g, sets);
      ++g[i];
      --g[a[i]];
      --g[b[i]];
    }
  }
}

void solve() {
  int n;
  scanf("%d", &n);
  vector<int> a(n), b(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", &a[i], &b[i]);
    --a[i], --b[i];
  }
  int sum = 0;
  vector <int> g(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &g[i]);
    sum += g[i];
  }
  vector<int> g2(n);
  g2[0] = 1;
  set<vector<int>> sets;
  brute2(n, sum - 1, a, b, g2, sets);


  vector<vector<int>> sets2(sets.begin(), sets.end());

  set<vector<int>> cache;
  int totAns = g[0];
  brute(n, sum, 0, sets2, g, totAns, cache);
  printf("%d\n", totAns);
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
