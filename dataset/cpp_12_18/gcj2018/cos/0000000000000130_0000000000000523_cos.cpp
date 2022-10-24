#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <assert.h>
#include <vector>
#include <unistd.h>

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
    // printf("Case #%d: ", test_case);
    // puts("");
    solve();
  }
}


void solve() {
  int a, b, n;
  char str[1000];
  scanf("%d %d %d", &a, &b, &n);
  a += 1;
  REP(iter, n) {
    int mid = (a + b) / 2;
    printf("%d\n", mid);
    fflush(stdout);
    scanf("%s", str);
    if (strcmp(str, "CORRECT") == 0) { break; }
    if (strcmp(str, "TOO_SMALL") == 0 ) {
      a = mid + 1;
    } else if (strcmp(str, "TOO_BIG") == 0) {
      b = mid - 1;
    } else {
      // WA
      // assert(false);
      return;
    }
  }
}