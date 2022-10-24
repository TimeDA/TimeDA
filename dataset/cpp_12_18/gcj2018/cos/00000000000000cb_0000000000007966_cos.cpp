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

ll total_damage(const string &str) {
  int n = str.size();
  ll d = 1;
  ll ret = 0;
  REP(i, n) {
    if (str[i] == 'C') {
      d *= 2;
    } else {
      ret += d;
    }
  }
  return ret;
}

void solve() {
  ll d;
  string str;
  cin >> d >> str;
  int n = str.size();
  int ans = 0;
  while (d < total_damage(str)) {
    for (int i = n - 1; i > 0; i--) {
      if (str[i - 1] =='C' && str[i] == 'S') {
        swap(str[i - 1], str[i]);
        ans += 1;
        goto next;
      }
    }
    puts("IMPOSSIBLE");
    return;
next:;
  }
  printf("%d\n", ans);
}