#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <numeric>
#include <functional>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <memory>
#include <thread>
#include <tuple>

using namespace std;

void matmul(unsigned int res[50][50], unsigned int more[50][50], int n) {
  unsigned int v[50][50] = { 0, };
  for (int i = 0; i < n; i++) {
    for (int k = 0; k < n; k++) {
      for (int j = 0; j < n; j++) {
        v[i][j] += (res[i][k] * (more[k][j]));
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      res[i][j] = v[i][j];
    }
  }
}


bool make_random(int n, int deg[], unsigned int matr[50][50]) {
  for (int i = 1; i < n; i++) {
    for (;;) {
      int p = rand() % i;
      if (deg[p] >= 4) continue;
      matr[i][p] = matr[p][i] = 1;
      deg[i]++; deg[p]++;
      break;
    }
  }
  for (int i = 0; i < n; i++) {
    int rem = 4 - deg[i];
    for (int j = 0; j < rem; j++) {
      int trycnt = 0;
      for (;;) {
        trycnt++;
        if (trycnt > 100) return false;
        int v = rand() % n;
        if (i == v) continue;
        if (deg[v] >= 4) { continue; }
        if (matr[i][v]) { continue; }
        matr[i][v] = matr[v][i] = 1;
        deg[i]++; deg[v]++;
        break;
      }
    }
  }
  return true;
}


struct solution {
  vector<pair<int, int>> edges;
  vector<unsigned int> p;
};

vector<unsigned int> calc_hash(unsigned int matr[50][50], int n) {
  vector<unsigned int> p(n);
  for (int i = 0; i < n; i++) {
    p[i] = 1;
  }
  unsigned int da[50][50];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      da[i][j] = matr[i][j];
  for (int i = 0; i < n; i++) {
    matmul(da, matr, n);
    for (int j = 0; j < n; j++) {
      p[j] *= 17l;
      p[j] += da[j][j];
    }

    vector<unsigned int> pp = p;
    sort(pp.begin(), pp.end());
    bool fail = false;
    for (int j = 0; j + 1 < n; j++) {
      if (pp[j] == pp[j + 1]) {
        fail = true;
        break;
      }
    }

    if (!fail) {
      return p;
    }
  }
  return vector<unsigned int>();
}

solution mknetwork(int n) {
  for (;;) {
    unsigned int matr[50][50] = { 0, };
    int deg[50] = { 0, };
    if (!make_random(n, deg, matr)) continue;

    vector<unsigned int> p = calc_hash(matr, n);
    if (p.empty()) continue;

    solution sol;
    vector<pair<int, int>> res;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        if (matr[i][j]) {
          res.emplace_back(i + 1, j + 1);
        }
      }
    }
    sol.edges = res;
    sol.p = p;
    return sol;
  }
}

int main() {
  vector<solution> solved(60);
  for (int i = 10; i <= 50; i++) {
    //printf("%d\n", i);
    solved[i] = mknetwork(i);
    //printf("%d finshed %d\n", i, (int)(clock() / CLOCKS_PER_SEC));
  }
  int T;
  scanf("%d", &T);
  for (int testcase = 1; testcase <= T; testcase++) {
    int L, U;
    scanf("%d%d", &L, &U);
    int n = U;
    printf("%d\n", n);
    auto edges = solved[n];
    for (auto e : edges.edges) {
      printf("%d %d\n", e.first, e.second);
    }
    fflush(stdout);

    int judge_n;
    scanf("%d", &judge_n);
    if (judge_n == -1) return 0;

    unsigned int matr[50][50];
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        matr[i][j] = 0;
      }
    }
    for (int i = 0; i < 2*n; i++) {
      int a, b;
      scanf("%d%d", &a, &b);
      a--, b--;
      matr[a][b] = 1;
      matr[b][a] = 1;
    }

    auto p = solved[n].p;
    auto judge_p = calc_hash(matr, n);

    vector<int> result(n);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (p[i] == judge_p[j]) {
          result[i] = j;
        }
      }
    }

    for (int i = 0; i < n; i++) {
      printf("%d%c", result[i] + 1, " \n"[i + 1 == n]);
    }
    fflush(stdout);
  }
  return 0;
}
