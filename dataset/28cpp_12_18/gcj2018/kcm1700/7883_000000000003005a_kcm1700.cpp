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
  int R, C, H, V;
  vector<string> dat;
  void input() {
    scanf("%d%d%d%d", &R, &C, &H, &V);
    for (int i = 0; i < R; i++) {
      char buffer[256];
      scanf("%s", buffer);
      dat.emplace_back(buffer);
    }
  }
  bool ans;
  void solve() {
    ans = false;
    vector<int> sumh(R), sumv(C);
    for (int i = 0; i < R; i++) {
      for (int j = 0; j < C; j++) {
        if (dat[i][j] == '@') {
          sumh[i]++;
          sumv[j]++;
        }
      }
    }
    int tot = accumulate(sumh.begin(), sumh.end(), 0);
    if (tot % ((H+1)*(V+1)) != 0) {
      return;
    }
    int each = tot / (H+1) / (V+1);

    vector<int> hcuts;
    {
      int cuts = 0;
      int step = tot / (H+1);
      int sum = 0;
      for (int i = 0; i < R; i++) {
        sum += sumh[i];
        if (sum > step) return;
        if (sum == step) {
          hcuts.emplace_back(i + 1);
          sum = 0;
        }
      }
    }
    vector<int> vcuts;
    {
      int cuts = 0;
      int step = tot / (V + 1);
      int sum = 0;
      for (int i = 0; i < C; i++) {
        sum += sumv[i];
        if (sum > step) return;
        if (sum == step) {
          vcuts.emplace_back(i + 1);
          sum = 0;
        }
      }
    }

    for (int si = 0; si + 1 < hcuts.size(); si++) {
      for (int sj = 0; sj + 1 < vcuts.size(); sj++) {
        int r1 = hcuts[si], r2 = hcuts[si + 1];
        int c1 = vcuts[sj], c2 = vcuts[sj + 1];
        int sum = 0;
        for (int r = r1; r < r2; r++) {
          for (int c = c1; c < c2; c++) {
            sum += ((dat[r][c] == '@') ? 1 : 0);
          }
        }
        if (sum != each) return;
      }
    }
    ans = true;
  }
  void output(int testcase) {
    printf("Case #%d: ", testcase);
    if (ans) {
      printf("POSSIBLE\n");
    } else {
      printf("IMPOSSIBLE\n");
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