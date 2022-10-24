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

void solve() {
  int a;
  scanf("%d", &a);
  int n = 15;
  int m = max(3, (a + 14) / 15);
  vector<vector<int>> mark(n, vector<int>(m));
  for (;;) {
    int bestvalue = 9;
    pair<int, int> bestp;
    for (int i = 1; i + 1 < n; i++) {
      for (int j = 1; j + 1 < m; j++) {
        int ecnt = mark[i - 1][j - 1] + mark[i - 1][j] + mark[i - 1][j + 1]
          + mark[i][j - 1] + mark[i][j] + mark[i][j + 1]
          + mark[i + 1][j - 1] + mark[i + 1][j] + mark[i + 1][j + 1];
        if (ecnt < bestvalue) {
          bestvalue = ecnt;
          bestp = make_pair(i, j);
        }
      }
    }
    if (bestvalue == 9) {
      // should not happen
      return;
    }
    printf("%d %d\n", bestp.first + 1, bestp.second + 1); fflush(stdout);
    int r1, r2;
    scanf("%d%d", &r1, &r2);
    if (r1 == -1 && r2 == -1) exit(0);
    if (r1 == 0 && r2 == 0) return;
    mark[r1 - 1][r2 - 1] = 1;
  }
}

int main() {
  int T;
  scanf("%d", &T);
  for (int testcase = 1; testcase <= T; testcase++) {
    solve();
  }
  return 0;
}