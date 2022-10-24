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

ll r, b, c;
ll ms[1010];
ll ss[1010];
ll ps[1010];

ll cnts[1010];
bool calc(ll max_time) {
  REP(i, c) {
    cnts[i] = min(ms[i], (max_time - ps[i]) / ss[i]);
  }
  sort(cnts, cnts + c);
  reverse(cnts, cnts + c);
  ll sum = 0;
  REP(i, r) {
    sum += max(0LL, cnts[i]);
  }
  return sum >= b;
}

void solve() {
  scanf("%lld %lld %lld", &r, &b, &c);
  REP(i, c) {
    scanf("%lld %lld %lld", &ms[i], &ss[i], &ps[i]);
  }
  ll left = 0;
  ll right = 1LL << 62;
  while (right - left > 1) {
    ll mid = (left + right) / 2;
    if (calc(mid)) {
      right = mid;
    } else {
      left = mid;
    }
  }
  printf("%lld\n", right);
}
