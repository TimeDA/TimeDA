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

using namespace std;

struct BipartiteMatching
{
  int n, m;
  vector<vector<int> > graph;
  vector<int> matched, match;
  vector<int> edgeview;
  vector<int> level;
  vector<int> reached[2];
  BipartiteMatching(int n, int m) : n(n), m(m), graph(n), matched(m, -1), match(n, -1) {}

  bool assignLevel()
  {
    bool reachable = false;
    level.assign(n, -1);
    reached[0].assign(n, 0);
    reached[1].assign(m, 0);
    queue<int> q;
    for (int i = 0; i < n; i++) {
      if (match[i] == -1) {
        level[i] = 0;
        reached[0][i] = 1;
        q.push(i);
      }
    }
    while (!q.empty()) {
      auto cur = q.front(); q.pop();
      for (auto adj : graph[cur]) {
        reached[1][adj] = 1;
        auto next = matched[adj];
        if (next == -1) {
          reachable = true;
        }
        else if (level[next] == -1) {
          level[next] = level[cur] + 1;
          reached[0][next] = 1;
          q.push(next);
        }
      }
    }
    return reachable;
  }

  int findpath(int nod) {
    for (int &i = edgeview[nod]; i < graph[nod].size(); i++) {
      int adj = graph[nod][i];
      int next = matched[adj];
      if (next >= 0 && level[next] != level[nod] + 1) continue;
      if (next == -1 || findpath(next)) {
        match[nod] = adj;
        matched[adj] = nod;
        return 1;
      }
    }
    return 0;
  }

  int solve()
  {
    int ans = 0;
    while (assignLevel()) {
      edgeview.assign(n, 0);
      for (int i = 0; i < n; i++)
        if (match[i] == -1)
          ans += findpath(i);
    }
    return ans;
  }
};


struct Solver {
  int n;
  vector<vector<int>> dat;
  void input() {
    scanf("%d", &n);
    dat.assign(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        scanf("%d", &dat[i][j]);
      }
    }
  }
  int ans;
  void solve() {
    ans = 0;
    for (int i = -n; i <= n; i++) {
      if (i == 0) continue;
      BipartiteMatching bp(n, n);
      int edges = 0;
      for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
          if (dat[r][c] == i) {
            edges++;
            bp.graph[r].push_back(c);
          }
        }
      }
      int cnt = bp.solve();
      ans += edges - cnt;
    }
  }
  void output(int testcase) {
    printf("Case #%d: %d\n", testcase, ans);
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