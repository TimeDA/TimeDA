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
  vector<int> p;
  void input() {
    scanf("%d", &n);
    p.resize(n);
    for (int i = 0; i < n; i++) {
      scanf("%d", &p[i]);
    }
  }

  string result;
  void solve() {
    int total = accumulate(p.begin(), p.end(), 0);
    while (total > 0) {
      int max0 = 0, max1 = 0;
      int max0i = 0, max1i = 0;
      for (int i = 0; i < n; i++) {
        if (p[i] > max0) {
          max1 = max0; max1i = max0i;
          max0 = p[i], max0i = i;
        }
        else if (p[i] > max1) {
          max1 = p[i]; max1i = i;
        }
      }
      bool found = false;
      for (int i = 0; i < n; i++) {
        if (p[i] == 0) continue;
        int t0 = max0, t1 = max1;
        if (max0i == i) {
          t0--;
        }
        else if (max1i == i) {
          t1--;
        }
        if (t0 * 2 > total-1 || t1 * 2 > total-1) {
          continue;
        }
        found = true;
        total--;
        p[i]--;
        if (!result.empty()) result += " ";
        result.push_back('A' + i);
        break;
      }
      if (found) continue;
      found = true;
      total -= 2;
      p[max0i]--, p[max1i]--;
      if (!result.empty()) result += " ";
      result.push_back('A' + max0i);
      result.push_back('A' + max1i);
    }
  }
  void output(int testcase) {
    printf("Case #%d: ", testcase);
    printf("%s", result.c_str());
    printf("\n");
  }
};

int main() {
  int testCaseCount;
  scanf("%d", &testCaseCount);

  const int batchSize = max(1, (int)(thread::hardware_concurrency()/2));
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