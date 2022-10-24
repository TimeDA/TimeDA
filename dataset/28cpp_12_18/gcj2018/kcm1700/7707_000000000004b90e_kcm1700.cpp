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

struct Solver {
  int f;
  int fixed;
  struct fence {
    int a, b, c, d;
    int A, B;
    fence():a(0),b(0),c(0),d(0) {}
    fence(int a, int b, int c, int d) :a(a), b(b), c(c), d(d) { }
  };
  vector<fence> dat;
  void input() {
    scanf("%d%d", &f, &fixed);
    for (int i = 0; i < f; i++) {
      int a, b, c, d;
      scanf("%d%d", &a, &b);
      scanf("%d%d", &c, &d);
      dat.emplace_back(a, b, c, d);
    }
  }

  vector<int> ans;

  map<pair<int, int>, int> vindex;
  int register_vertex(int x, int y) {
    if (vindex.count(make_pair(x, y))) {
      return vindex[make_pair(x, y)];
    }
    int new_index = vindex.size();
    return vindex[make_pair(x, y)] = new_index;
  }
  int n;
  vector<vector<int>> graph;
  vector<vector<int>> dist;
  void dfs(vector<int> &dist, int node, int d) {
    dist[node] = d;
    for (auto next : graph[node]) {
      if (dist[next] == -1) {
        dfs(dist, next, d + 1);
      }
    }
  }

  void solve() {
    vector<bool> used(f);
    vindex.clear();
    for (int i = 0; i < f; i++) {
      dat[i].A = register_vertex(dat[i].a, dat[i].b);
      dat[i].B = register_vertex(dat[i].c, dat[i].d);
    }
    n = vindex.size();

    graph.resize(n);
    set<int> included;
    {
      included.insert(dat[0].A);
      included.insert(dat[0].B);
      graph[dat[0].A].emplace_back(dat[0].B);
      graph[dat[0].B].emplace_back(dat[0].A);
      used[0] = true;
      ans.emplace_back(0);
    }

    // do the tree first
    for (;;) {
      bool did_something = false;
      for (int i = 0; i < f; i++) {
        if (used[i]) continue;
        int ac = included.count(dat[i].A);
        int bc = included.count(dat[i].B);
        if (ac == 0 && bc == 0) continue;
        if (ac == 1 && bc == 1) continue;
        did_something = true;
        ans.emplace_back(i);
        used[i] = true;
        included.insert(dat[i].A);
        included.insert(dat[i].B);
        graph[dat[i].A].emplace_back(dat[i].B);
        graph[dat[i].B].emplace_back(dat[i].A);
      }
      if (!did_something) break;
    }

    dist.resize(n);
    for (int i = 0; i < n; i++) {
      dist[i].assign(n, -1);
      dfs(dist[i], i, 0);
    }

    // calc_tree distance
    vector<pair<int, int>> remaining;
    for (int i = 0; i < f; i++) {
      if (used[i]) continue;
      remaining.emplace_back(dist[dat[i].A][dat[i].B], i);
    }
    sort(remaining.begin(), remaining.end());
    for (auto v : remaining) {
      ans.emplace_back(v.second);
    }
  }

  void output(int testcase) {
    printf("Case #%d:", testcase);
    for (int i = 0; i < n; i++) {
      printf(" %d", ans[i] + 1);
    }
    printf("\n");
  }
};

int main() {
  int testCaseCount;
  scanf("%d", &testCaseCount);

  const int batchSize = max(1, (int)(thread::hardware_concurrency() / 2));
  for (int testcase = 1; testcase <= testCaseCount; testcase += batchSize) {
    vector<unique_ptr<Solver>> solvers; solvers.reserve(batchSize);
    vector<unique_ptr<thread>> threads; threads.reserve(batchSize);
    for (int batchInd = 0; batchInd < batchSize && testcase + batchInd <= testCaseCount; batchInd++) {
      solvers.emplace_back(new Solver());
    }
    for (auto &solver : solvers) {
      solver->input();
      threads.emplace_back(new thread(&Solver::solve, solver.get()));
    }
    for (int batchInd = 0; batchInd < solvers.size(); batchInd++) {
      threads[batchInd]->join();
      solvers[batchInd]->output(testcase + batchInd);
    }
  }
  return 0;
}