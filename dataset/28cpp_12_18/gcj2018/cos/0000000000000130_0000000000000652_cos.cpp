#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <assert.h>
#include <vector>
#include <map>

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

void solve() {
  ll n, k;
  scanf("%lld %lld", &n, &k);
  k--;
  map<ll, ll> cnts;
  cnts[n] = 1;
  while (k > 0) {
    ll s = cnts.rbegin()->first;
    ll cnt = cnts.rbegin()->second;
    ll use = min(k, cnt);
    k -= use;
    cnts.rbegin()->second -= use;
    cnts[s / 2] += use;
    cnts[(s - 1) / 2] += use;
    if (cnts.rbegin()->second == 0) { cnts.erase(s); }
  }
  ll ans1 = cnts.rbegin()->first / 2;
  ll ans2 = (cnts.rbegin()->first - 1) / 2;
  printf("%lld %lld\n", ans1, ans2);
}
