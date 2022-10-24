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
  int n;
  int x0, x1, y0, y1;
  int ans;
  void input() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      int x, y;
      scanf("%d%d", &x, &y);
      if (i == 0) {
        x0 = x1 = x;
        y0 = y1 = y;
      }
      else {
        x0 = min(x0, x);
        x1 = max(x1, x);
        y0 = min(y0, y);
        y1 = max(y1, y);
      }
    }
  }
  void solve() {
    ans = max((x1 - x0 + 1) / 2, (y1 - y0 + 1)/2);
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