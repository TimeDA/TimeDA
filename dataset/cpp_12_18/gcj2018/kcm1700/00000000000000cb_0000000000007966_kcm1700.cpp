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
  int d;
  string p;
  void input() {
    char buffer[256];
    scanf("%d%s", &d, buffer);
    p = buffer;
  }
  int ans;
  void solve() {
    long long total = 0;

    long long damage_value = 1;
    int n = p.length();
    for (int i = 0; i < n; i++) {
      if (p[i] == 'C') {
        damage_value *= 2;
      }
      else {
        total += damage_value;
      }
    }

    int swaps = 0;
    while (total > d) {
      long long cur_damage = damage_value;
      bool found = false;
      for (int i = n - 1; i >= 0; i--) {
        if (p[i] == 'C') {
          cur_damage /= 2;
        }
        else if (i > 0 && p[i] == 'S' && p[i - 1] == 'C') {
          total -= cur_damage / 2;
          swaps++;
          swap(p[i], p[i - 1]);
          found = true;
          break;
        }
      }

      if (!found) {
        ans = -1;
        return;
      }
    }
    ans = swaps;
  }
  void output(int testcase) {
    printf("Case #%d: ", testcase);
    if (ans == -1) {
      printf("IMPOSSIBLE\n");
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