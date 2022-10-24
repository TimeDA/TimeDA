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

struct Solver {
  int n;
  vector<int> v;
  int ans;

  void input() {
    scanf("%d", &n);
    v.resize(n);
    for (int i = 0; i < n; i++) {
      scanf("%d", &v[i]);
    }
  }
  void solve() {
    vector<int> v1, v2;
    for (unsigned int i = 0; i < n; i++) {
      if (i % 2 == 0) {
        v1.emplace_back(v[i]);
      }
      else {
        v2.emplace_back(v[i]);
      }
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    vector<int> result;
    result.reserve(n);
    for (unsigned int i = 0; i < n; i++) {
      result.emplace_back((i % 2 == 0) ? v1[i / 2] : v2[i / 2]);
    }
    auto I = is_sorted_until(result.begin(), result.end());
    if (I == result.end()) {
      ans = -1;
    }
    else {
      ans = I - result.begin() - 1;
    }
  }
  void output(int testcase) {
    printf("Case #%d: ", testcase);
    if (ans == -1) {
      printf("OK\n");
    }
    else {
      printf("%d\n", ans);
    }
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