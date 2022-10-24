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
    puts("");
    solve();
  }
}

vector<double> rot3(const vector<double> &from, double theta, double phi) {
  vector<double> ret = {0, 0, 0};
  vector<double> temp = {0, 0, 0};
  temp[0] = from[0];
  temp[1] = from[1] * cos(theta) - from[2] * sin(theta);
  temp[2] = from[1] * sin(theta) + from[2] * cos(theta);
  ret[0] = temp[0] * cos(phi) + temp[2] * sin(phi);;
  ret[1] = temp[1];
  ret[2] = - temp[0] * sin(phi) + temp[2] * cos(phi);
  return ret;
}

void solve() {
  double A;
  scanf("%lf", &A);
  double theta, phi;
  {
    double left = 0;
    double right = PI / 4.0;
    REP(iter, 200) {
      double mid = (left + right) / 2.0;
      double t = cos(mid) + sin(mid);
      // cout << mid << " " << t << endl;
      if (t < A) {
        left = mid;
      } else {
        right = mid;
      }
    }
    theta = left;
  }
  phi = 0;
  vector<double> ans[3] = {
    { 0.5, 0, 0 },
    { 0.0, 0.5, 0 },
    { 0.0, 0, 0.5 },
  };
  // cout << theta << " " << phi << endl;
  REP(i, 3) { ans[i] = rot3(ans[i], theta, phi); }
  REP(i, 3) {
    REP(j, 3) {
      if (j != 0) { putchar(' '); }
      printf("%.8f", ans[i][j]);
    }
    puts("");
  }
}