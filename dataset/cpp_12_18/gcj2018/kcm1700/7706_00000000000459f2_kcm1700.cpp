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
  vector<int> arr;
  void input() {
    scanf("%d", &n);
    arr.resize(n);
    for (int i = 0; i < n; i++) {
      scanf("%d", &arr[i]);
    }
    ans = 0;
  }
  int ans;
  vector<string> board;
  void solve() {
    if (accumulate(arr.begin(), arr.end(), 0) != n)
    {
      ans = -1;
      return;
    }
    vector<int> match(n);
    vector<int> pos(n);
    int j = -1, rem = 0;
    for (int i = 0; i < n; i++) {
      for (; rem <= 0;) {
        ++j;
        rem = arr[j];
      }
      rem--;
      match[i] = j;
      pos[i] = i;
    }
    if (match[0] != 0 || match[n - 1] != n - 1) {
      ans = -1;
      return;
    }
    for (int i = 0; i < n; i++) {
      ans = max(ans, abs(match[i] - i) + 1);
    }
    board.assign(ans, string(n, '.'));
    for (int i = 0; i + 1< ans; i++) {
      for (int j = 0; j < n; j++) {
        if (pos[j] == match[j]) {
          continue;
        }
        else if (pos[j] < match[j]) {
          board[i][pos[j]] = '\\';
          pos[j]++;
        }
        else {
          board[i][pos[j]] = '/';
          pos[j]--;
        }
      }
    }
  }
  void output(int testcase) {
    printf("Case #%d: ", testcase);
    if (ans <= 0) {
      printf("IMPOSSIBLE\n");
    }
    else {
      printf("%d\n", ans);
      for (int i = 0; i < ans; i++) {
        printf("%s\n", board[i].c_str());
      }
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