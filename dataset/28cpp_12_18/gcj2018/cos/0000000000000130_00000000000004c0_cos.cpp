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
    solve();
    puts("");
  }
}

void solve() {
  int n;
  pair<int, char> cnts[100];
  scanf("%d", &n);
  REP(i, n) {
    scanf("%d", &cnts[i].first);
    cnts[i].second = 'A' + i;
  }
  while (true) {
    REP(iter, 2) {
      sort(cnts, cnts + n);
      reverse(cnts, cnts + n);
      int sum = 0;
      REP(i, n) { sum += cnts[i].first; }
      if (sum == 2 && iter == 1) { continue; }
      putchar(cnts[0].second);
      cnts[0].first--;
      if (cnts[0].first == 0 && cnts[1].first == 0) { goto end; }
    }
    putchar(' ');
  }
end:;
}
