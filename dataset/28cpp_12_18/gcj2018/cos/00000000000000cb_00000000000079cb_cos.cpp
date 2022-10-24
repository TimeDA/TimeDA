#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <assert.h>
#include <vector>

using namespace std;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
static const double EPS = 1e-9;
static const double PI = acos(-1.0);

#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, s, n) for (int i = (s); i < (int)(n); i++)
#define FOREQ(i, s, n) for (int i = (s); i <= (int)(n); i++)
#define FORIT(it, c) for (__typeof((c).begin())it = (c).begin(); it != (c).end(); it++)
#define MEMSET(v, h) memset((v), h, sizeof(v))

void solve();
int main() {
  int test;
  scanf("%d", &test);
  char str[1000];
  fgets(str, 999, stdin);
  int test_case = 0;
  while (test--) {
    test_case++;
    printf("Case #%d: ", test_case);
    // puts("");
    solve();
  }
}

int seq[2][100001];
void solve() {
  int n;
  scanf("%d", &n);
  REP(i, n) {
    scanf("%d", &seq[i % 2][i / 2]);
  }
  sort(seq[0], seq[0] + (n + 1) / 2);
  sort(seq[1], seq[1] + n / 2);
  REP(i, n - 1) {
    if (seq[i % 2][i / 2] > seq[(i + 1) % 2][(i + 1) / 2]) {
      printf("%d\n", i);
      return;
    }
  }
  puts("OK");
}