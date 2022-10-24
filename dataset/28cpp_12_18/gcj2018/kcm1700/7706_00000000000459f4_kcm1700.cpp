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
  int r, c;
  vector<string> board;
  void input() {
    scanf("%d%d", &r, &c);
    for (int i = 0; i < r; i++) {
      char buf[30];
      scanf("%s", buf);
      board.emplace_back(buf);
    }
  }
  int make_bit(char c0, char c1, char c2, char c3) {
    return
      ((c3 == 'B' ? 1 : 0) << 3) +
      ((c2 == 'B' ? 1 : 0) << 2) +
      ((c1 == 'B' ? 1 : 0) << 1) +
      ((c0 == 'B' ? 1 : 0));
  }
  int rec(vector<vector<bool>> &board, int row, int col) {
    if (row < 0 || col < 0 || row >= r || col >= c || !board[row][col]) return 0;
    int sum = 1;
    board[row][col] = false;
    sum += rec(board, row - 1, col);
    sum += rec(board, row + 1, col);
    sum += rec(board, row, col - 1);
    sum += rec(board, row, col + 1);
    return sum;
  }
  int find_largest_connected_group(vector<vector<bool>> board) {
    int result = 0;
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        if (!board[i][j]) continue;
        result = max(result, rec(board, i, j));
      }
    }
    return result;
  }
  int ans;
  void solve() {
    bool hasComplex[16];
    ans = 0;
    // 0, 1
    // 2, 3
    {
      for (int i = 0; i < 16; i++) hasComplex[i] = false;
      for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
          if (board[i][j] == 'B') { // B = 1
            hasComplex[15] = true;
          }
          if (board[i][j] == 'W') {
            hasComplex[0]= true;
          }
          if (i + 1 < r && board[i][j] != board[i+1][j]) {
            char c0 = board[i][j];
            char c2 = board[i+1][j];
            hasComplex[make_bit(c0, c0, c2, c2)] = true;
          }
          if (j + 1 < c && board[i][j] != board[i][j + 1]) {
            char c0 = board[i][j];
            char c1 = board[i][j + 1];
            hasComplex[make_bit(c0, c1, c0, c1)] = true;
          }
          if (i + 1 < r && j + 1 < c) {
            char c0 = board[i][j];
            char c1 = board[i][j + 1];
            char c2 = board[i + 1][j];
            char c3 = board[i + 1][j + 1];
            hasComplex[make_bit(c0, c1, c2, c3)] = true;
          }
        }
      }
    }
    for (int patternIndex = 0; patternIndex < 16; patternIndex++) {
      if (!hasComplex[patternIndex]) continue;
      for (int centerRow = 0; centerRow <= r; centerRow++) {
        for (int centerCol = 0; centerCol <= c; centerCol++) {
          vector<vector<bool>> newboard(r, vector<bool>(c));
          for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
              int partition = (i < centerRow ? 0 : 1) * 2 + (j < centerCol ? 0 : 1);
              char expectedColor = ((patternIndex & (1 << (partition))) != 0) ? ('B') : ('W');
              newboard[i][j] = (expectedColor == board[i][j]);
            }
          }

          ans = max(ans, find_largest_connected_group(newboard));
        }
      }
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