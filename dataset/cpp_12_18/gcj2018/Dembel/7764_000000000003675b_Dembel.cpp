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

vector<int> calc_eq(const vector<int> & a) {
  int n = int(a.size());
  vector <int> eq(n);
  for (int i = n - 1; i >= 0; --i) {
    if (i == n - 1 || a[i + 1] != a[i]) {
      eq[i] = i + 1;
    } else {
      eq[i] = eq[i + 1];
    }
  }
  return eq;
}

vector<int> stupid(int n, const vector<int> & a, const vector<int> & b) {
  vector <int> jump(n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      for (int L = 0, R = 0; L < n; ++L) {
        if (R < L) { R = L; }
        while (R < n && (a[R] == a[i] || b[R] == b[j])) {
          ++R;
        }
        jump[L] = max(jump[L], R);
      }
    }
  }
  return jump;
}

#ifdef LOCAL
  //#define RANDOM
#endif

void solve() {
#ifdef RANDOM
  int n = rand() % 500;
  dbg("%d\n", n);
  vector <int> a(n);
  vector <int> b(n);
  for (int i = 0; i < n; ++i) {
    a[i] = rand() % 1;
    b[i] = rand() % 1;
    dbg("%d %d %d\n", i, a[i] - i, i - b[i]);
  }
#else
  int n;
  scanf("%d", &n);
  vector <int> a(n), b(n);
  for (int i = 0; i < n; ++i) {
    int d, aa, bb;
    scanf("%d%d%d", &d, &aa, &bb);
    a[i] = d + aa;
    b[i] = d - bb;
    dbg("%d %d\n", a[i], b[i]);
  }
#endif
  vector <int> eqA = calc_eq(a);
  vector <int> eqB = calc_eq(b);


  vector <int> jumpA(n), jumpB(n);
  for (int i = n - 1; i >= 0; --i) {
    jumpA[i] = eqA[i];
    if (jumpA[i] < n) {
      jumpA[i] = eqB[eqA[i]];
      if (jumpA[i] < n && a[jumpA[i]] == a[i]) {
        jumpA[i] = jumpB[eqA[i]];
      }
    }
    jumpB[i] = eqB[i];
    if (jumpB[i] < n) {
      jumpB[i] = eqA[eqB[i]];
      if (jumpB[i] < n && b[jumpB[i]] == b[i]) {
        jumpB[i] = jumpA[eqB[i]];
      }
    }

    dbg("i %d eqA %d eqB %d jumpA %d jumpB %d\n", i, eqA[i], eqB[i], jumpA[i], jumpB[i]);
  }

#ifdef LOCAL
  vector <int> stup = stupid(n, a, b);
#endif
  
  int ansLen = -1;
  int ansCnt = 0;
  for (int i = 0; i < n; ++i) {
    int curLen = max(jumpA[i], jumpB[i]) - i;
    //int curLen = stup[i] - i;
#ifdef LOCAL
    if (i + curLen != stup[i]) {
      dbg("i %d ans %d wa %d\n", i, stup[i] - i, curLen);
    }
    assert(i + curLen == stup[i]);
#endif
    if (curLen > ansLen) {
      ansLen = curLen;
      ansCnt = 0;
    }
    if (curLen == ansLen) {
      ansCnt += 1;
    }
  }
  printf("%d %d\n", ansLen, ansCnt);
}

int main() {
  int tt;
#ifdef RANDOM
  tt = 10000;
#else
  scanf("%d", &tt);
#endif
  for (int ii = 1; ii <= tt; ++ii) {
    printf("Case #%d: ", ii);
    dbg("Case #%d:\n", ii);
    solve();
  }
  return 0;
}
