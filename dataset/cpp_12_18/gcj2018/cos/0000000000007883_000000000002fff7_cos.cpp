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

double square(double x) { return x * x; }

int n;
double p;

void solve() {
  double ws[110];
  double hs[110];
  pair<double, double> initial_ranges[110];
  scanf("%d %lf", &n, &p);
  double total = 0;
  REP(i, n) {
    scanf("%lf %lf", &ws[i], &hs[i]);
    total += ws[i] * 2 + hs[i] * 2;
    initial_ranges[i] = make_pair(2 * min(ws[i], hs[i]), 2 * sqrt(square(ws[i]) + square(hs[i])));
    // cout << initial_ranges[i].first << " " << initial_ranges[i].second << endl;
  }
  sort(initial_ranges, initial_ranges + n);
  vector<pair<double, double> > ranges;
  ranges.push_back(make_pair(0, 0));
  REP(i, n) {
    int cnt = ranges.size();
    REP(j, cnt) {
      pair<double, double> nrange = make_pair(initial_ranges[i].first + ranges[j].first, initial_ranges[i].second + ranges[j].second);
      ranges.push_back(nrange);
    }
    sort(ranges.begin(), ranges.end());
    pair<double, double> prev = make_pair(0, 0);
    vector<pair<double, double> > nranges;
    FORIT(it, ranges) {
      if (it->first == 0) { continue; }
      if (prev.second < it->first) {
        nranges.push_back(prev);
        prev = *it;
      } else {
        prev.second = it->second;
      }
    }
    nranges.push_back(prev);
    swap(ranges, nranges);
  }
  double ans = total;
  // cout << endl;
  FORIT(it, ranges) {
    // cout << it->first << " " << it->second << endl;
    if (p < total + it->first) { continue; }
    if (p < total + it->second) {
      ans = p;
    } else {
      ans = max(ans, total + it->second);
    }
  }
  printf("%.8f\n", ans);
}
