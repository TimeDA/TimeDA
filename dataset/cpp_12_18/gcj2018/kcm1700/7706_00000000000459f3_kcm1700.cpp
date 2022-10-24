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

//short d[51][51];
short dt[501][501][501];

/*
int calc(int r, int c) {
  int v[51][51] = { 1, 0, };
  for (int i = 0; i <= r; i++) {
    for (int j = 0; j <= c; j++) {
      if (i == 0 && j == 0) continue;
      for (int a = r - i; a >= 0; a--) {
        for (int b = c - j; b>=0; b--) {
          if (v[a][b] == 0) continue;
          v[a + i][b + j] = max(v[a + i][b + j], v[a][b] + 1);
        }
      }
    }
  }
  return v[r][c] - 1;
}*/

void precompute() {
  /*
  for (int r = 0; r <= 50; r++) {
    for (int c = 0; c <= 50; c++) {
      d[r][c] = calc(r, c);
    }
  }*/

  for (int i = 1; i <= 500; i++) {
    for (int j = 0; j <= 500; j++) {
      for (int k = 0; k <= 500; k++) {
        dt[i][j][k] = -1;
      }
    }
  }
  for (int r = 1; r <= 500; r++) {
    for (int c = 0; c <= 500; c++) {
      dt[r][c][r] = 1;
      for (int i = r - 1; i >= 0; i--) {
        int ru = r;
        int cu = c;
        int best = -1;
        for (int cnt = 0; ru >= 0 && cu >= 0; cnt++) {
          int targ = dt[ru][cu][i + 1];
          if (targ >= 0) {
            best = max(best, targ + cnt);
          }
          ru -= i;
          cu -= cnt + (i == 0);
        }
        dt[r][c][i] = best;
      }
    }
  }
}


struct Solver {
  int r, b;
  void input() {
    scanf("%d%d", &r, &b);
  }
  void solve() {
  }
  void output(int testcase) {
    printf("Case #%d: %d\n", testcase, (int)dt[max(r,b)][min(r,b)][0]);
  }
};


int main() {
  precompute();
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