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
  struct cashier {
    int m, s, p;
    cashier() : m(0), s(0), p(0) {}
    cashier(int m, int s, int p) : m(m), s(s), p(p) {}
  };

  int R, B;
  vector<cashier> cashiers;

  void input() {
    int C;
    scanf("%d%d%d", &R, &B, &C);
    for (int i = 0; i < C; i++) {
      int m, s, p;
      scanf("%d%d%d", &m, &s, &p);
      cashiers.emplace_back(m, s, p);
    }
  }

  long long ans = 0;

  bool check(long long dest) {
    vector<int> capacity;
    capacity.reserve(cashiers.size());
    for (const auto &c : cashiers) {
      capacity.emplace_back((int)min((long long)c.m, (dest - c.p) / c.s));
    }
    sort(capacity.begin(), capacity.end(), greater<int>());
    long long capsum = 0;
    for (int i = 0; i < R && i < capacity.size(); i++) {
      capsum += capacity[i];
      if (capsum >= B) {
        return true;
      }
    }
    return false;
  }

  void solve() {
    long long low = 0, high = LLONG_MAX / 2;
    while (low <= high) {
      long long mid = (low + high) / 2;
      if (check(mid)) {
        ans = mid;
        high = mid - 1;
      }
      else {
        low = mid + 1;
      }
    }
  }

  void output(int testcase) {
    printf("Case #%d: %lld\n", testcase, ans);
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