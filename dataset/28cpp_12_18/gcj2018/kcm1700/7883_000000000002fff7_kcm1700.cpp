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
  int baseP;
  int p; // reduced p = (P - sum(w,h)*2)
  vector<pair<int, int>> cookies; // first <= second
  void input() {
    int n;
    scanf("%d%d", &n, &p);
    baseP = 0;
    for (int i = 0; i < n; i++) {
      int w, h;
      scanf("%d%d", &w, &h);
      if (w > h) swap(w, h);
      cookies.emplace_back(w, h);
      p -= (w + h) * 2;
      baseP += (w + h) * 2;
    }
  }

  static bool cmpLen(const pair<int,int> &a, const pair<int,int> &b) {
    // min a.first * 2
    // max hypot(a.first, a.second) * 2
    double len1 = hypot((double)a.first, (double)a.second) - a.first;
    double len2 = hypot((double)b.first, (double)b.second) - b.first;
    return len1 > len2;
  }

  double subans;

  void solve() {
    sort(cookies.begin(), cookies.end(), cmpLen);
    {
      double pureMax = 0;
      for (const auto &c : cookies) {
        double right = hypot((double)c.first, (double)c.second) * 2;
        pureMax += right;
      }
      if (pureMax <= p) {
        subans = pureMax;
        return;
      }
    }
    map<double, double> dp;
    dp[0] = 0;
    for (const auto &c : cookies) {
      double left = c.first * 2, right = hypot((double)c.first, (double)c.second) * 2;
      for (auto I = dp.end(); ;) {
        if (I == dp.begin()) break;
        --I;
        double newFirst = I->first + left;
        if (newFirst > p) continue;
        double newSecond = min((double)p, I->second + right);
        if (newFirst <= I->second) {
          I->second = newSecond;
          continue;
        }
        dp[newFirst] = max(dp[newFirst], newSecond);
      }
      for (auto I = dp.begin(); I != dp.end();) {
        auto J = I; ++J;
        if (J == dp.end()) break;
        if (J->first <= I->second) {
          I->second = max(I->second, J->second);
          dp.erase(J);
        }
        else {
          I = J;
        }
      }
      subans = dp.rbegin()->second;
      if (subans >= (double)p) {
        return;
      }
    }
  }

  void output(int testcase) {
    double ans = subans + baseP;
    printf("Case #%d: %.10f\n", testcase, ans);
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