#ifdef DBG12
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

/*vector<int> calcHash(int n, const vector<vector<int>> & ed) {
  vector<int> h0(n, 0);
  for (int i = 0; i < n - 1; ++i) {
    for (int i = 0; i < n; ++i) {
      dbg("%d ", h0[i]);
    }
    dbg("\n");
    vector<vector<pii>> neigh(n);
    for (int u = 0; u < n; ++u) {
      vector <int> ww;
      for (int v : ed[u]) {
        for (int w : ed[v]) {
          ww.push_back(ww);
        }
      }
      sort(ww.begin(), ww.end());
      for (int v : ed[u]) {
        for (int w : ed[v]) {
          neigh[u].push_back(pii(w, h0[w]));
        }
      }
      sort(neigh[u].begin(), neigh[u].end());
    }
    vector<int> ind(n);
    for (int i = 0; i < n; ++i) {
      ind[i] = i;
    }
    sort(ind.begin(), ind.end(), [&neigh](int i, int j) { return neigh[i] < neigh[j]; });

    vector <int> h1(n);
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
      h1[ind[i]] = cnt;
      if (i != 0 && neigh[ind[i - 1]] != neigh[ind[i]]) {
        cnt++;
      }
    }
    h0.swap(h1);
  }
  return h0;
}*/

bool check(int n, const vector<vector<int>> & ed) {
  return true;
  /*vector <int> h = calcHash(n, ed);
  sort(h.begin(), h.end());
  return h.back() == n - 1;*/
}

vector<int> getInversePerm(const vector<int> & p) {
  int n = int(p.size());
  vector<int> inv(n, -1);
  for (int i = 0; i < n; ++i) {
    assert(0 <= p[i] && p[i] < n);
    assert(inv[p[i]] == -1);
    inv[p[i]] = i;
  }
  return inv;
}

bool brute(int s, int n, const vector<vector<int>> & ed, const vector<vector<int>> & ed2, vector<int> & perm, vector<int> &invPerm) {
  dbg("brute s=%d perm = (", s);
  for (int i = 0; i < n; ++i) {
    if (perm[i] != -1) {
      dbg("%d ", perm[i]);
    } else {
      dbg("? ");
    }
  }
  dbg(")\n");
  vector <int> v1;
  vector <int> v2;
  for (int v : ed[s]) {
    if (perm[v] == -1) {
      v1.push_back(v);
    }
  }
  for (int v : ed2[perm[s]]) {
    if (invPerm[v] == -1) {
      v2.push_back(v);
    }
  }


  assert(v1.size() == v2.size());
  if (v1.empty()) {
    return true;
  }

  int k = int(v1.size());
  do {
    for (int i = 0; i < k; ++i) {
      //dbg("try p[%d] = %d\n", v1[i], v2[i]);
      perm[v1[i]] = v2[i];
      invPerm[v2[i]] = v1[i];
    }
    bool ok = true;
    for (int v : v1) {
      if (!ok) { break; }
      for (int u : ed[v]) {
        if (!ok) { break; }
        if (perm[u] != -1) {
          ok &= (find(ed2[perm[u]].begin(), ed2[perm[u]].end(), perm[v]) != ed2[perm[u]].end());
        }
      }
    }
    for (int v : v2) {
      if (!ok) { break; }
      for (int u : ed2[v]) {
        if (!ok) { break; }
        if (invPerm[u] != -1) {
          ok &= (find(ed[invPerm[u]].begin(), ed[invPerm[u]].end(), invPerm[v]) != ed[invPerm[u]].end());
        }
      }
    }
    for (int i = 0; ok && i < k; ++i) {
      ok &= brute(v1[i], n, ed, ed2, perm, invPerm);
    }
    if (ok) {
      return true;
    }
    for (int i = 0; i < k; ++i) {
      perm[v1[i]] = -1;
      invPerm[v2[i]] = -1;
    }
  } while (next_permutation(v2.begin(), v2.end()));
  return false;
}

void restore(int n, const vector<vector<int>> & ed) {
  /*vector <int> h1 = calcHash(n, ed);
  vector <int> invH1 = getInversePerm(h1);

  dbg("h1: ");
  for (int i = 0; i < n; ++i) {
    dbg("%d ", h1[i]);
  }
  dbg("\n");*/

#ifdef LOCAL
  vector <int> p(n);
  for (int i = 0; i < n; ++i) {
    p[i] = i;
  }
  random_shuffle(p.begin(), p.end());
  dbg("perm: ");
  for (int i = 0; i < n; ++i) {
    dbg("%d ", p[i]);
  }
  dbg("\n");
  vector<vector<int>> ed2(n);
  for (int u = 0; u < n; ++u) {
    for (int v : ed[u]) {
      ed2[p[u]].push_back(p[v]);
    }
  }
#else
  scanf("%*d");
  vector<vector<int>> ed2(n);
  for (int i = 0; i < 2 * n; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    ed2[u].push_back(u);
    ed2[v].push_back(u);
  }
#endif

  for (int i = 0; i < n; ++i) {
    sort(ed2[i].begin(), ed2[i].end());
  }

/*  vector<int> h2 = calcHash(n, ed2);
  dbg("h2: ");
  for (int i = 0; i < n; ++i) {
    dbg("%d ", h2[i]);
  }
  dbg("\n");

  vector <int> resP(n);
  for (int i = 0; i < n; ++i) {
    resP[i] = invH1[h2[i]];
  }*/

  vector<int> resP(n, -1);
  vector<int> invResP(n, -1);
  for (int i = 0; i < n; ++i) {
    resP[0] = i;
    invResP[i] = 0;
    dbg("try p[%d] = %d\n", 0, i);
    if (brute(0, n, ed, ed2, resP, invResP)) {
      break;
    }
    resP[0] = -1;
    invResP[i] = -1;
  }
  assert(resP[0] != -1);

  for (int i = 0; i < n; ++i) {
    printf("%d ", resP[i] + 1);
  }
  printf("\n");
#ifdef LOCAL
  assert(p == resP);
#endif

  fflush(stdout);
}

bool gen(int n, const int d) {
  dbg("gen %d\n", n);
  vector <vector<int>> ed(n);
  set<pii> has;
  vector <int> arr;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < d; ++j) {
      arr.push_back(i);
    }
  }
  for (int i = 0; i < 2 * n; ++i) {
    const int MAX = 1000;
    for (int it = 0; it <= MAX; ++it) {
      if (it == MAX) {
        dbg("bad\n");
        return false;
      }
      int i1 = rand() % arr.size();
      int i2 = rand() % arr.size();
      if (i1 < i2) { 
        swap(i1, i2);
      }

      int u = arr[i1];
      int v = arr[i2];
      if (u == v) { continue; }
      if (int(ed[u].size()) == d || int(ed[v].size()) == d) {
        continue;
      }
      if (has.count(pii(u, v))) { continue; }
      assert(u == arr[i1]);
      arr.erase(arr.begin() + i1);
      assert(v == arr[i2]);
      arr.erase(arr.begin() + i2);
      ed[u].push_back(v);
      ed[v].push_back(u);
      has.insert(pii(u, v));
      has.insert(pii(v, u));
      break;
    }
  }

  if (!check(n, ed)) {
    return false;
  }

  printf("%d\n", n);
  for (int u = 0; u < n; ++u) {
    for (int v : ed[u]) {
      if (u < v) {
        printf("%d %d\n", u + 1, v + 1);
      }
    }
  }
  fflush(stdout);

  restore(n, ed);
  return true;
}

void solve(int L, int R) {
  while (1) {
    int n = rand() % (R - L + 1) + L;
    if (gen(n, 4)) {
      break;
    }
  }
}

int main() {
#ifdef LOCAL
  for (int n = 10; n <= 10; ++n) {
    dbg("Case #%d: ", n);
    solve(n, n);
  }
#else
  int tt;
  scanf("%d", &tt);
  for (int ii = 1; ii <= tt; ++ii) {
    //printf("Case #%d: ", ii);
    int L, R;
    scanf("%d%d", &L, &R);
    solve(L, R);
  }
#endif
  return 0;
}
