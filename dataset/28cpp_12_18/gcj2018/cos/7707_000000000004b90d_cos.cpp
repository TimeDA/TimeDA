#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <assert.h>
#include <vector>
#include <set>
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


#include <deque>
template <class T>
ostream &operator<<(ostream &os, const vector<T> &rhs) {
  os << "[ ";
  FORIT(it, rhs) {
    if (it != rhs.begin()) { os << ", "; }
    os << *it;
  }
  os << " ]";
  return os;
}
template <class T>
ostream &operator<<(ostream &os, const deque<T> &rhs) {
  os << "[ ";
  FORIT(it, rhs) {
    if (it != rhs.begin()) { os << ", "; }
    os << *it;
  }
  os << " ]";
  return os;
}
template <class T, class U>
ostream &operator<<(ostream &os, const map<T, U> &rhs) {
  os << "{" << endl;
  FORIT(it, rhs) {
    if (it != rhs.begin()) { os << "," << endl; }
    os << "  " << it->first << " : " << it->second;
  }
  os << endl << "}";
  return os;
}
template <class T>
ostream &operator<<(ostream &os, const set<T> &rhs) {
  os << "{ ";
  FORIT(it, rhs) {
    if (it != rhs.begin()) { os << ", "; }
    os << *it;
  }
  os << " }";
  return os;
}
template <class T, class U>
ostream &operator<<(ostream &os, const pair<T, U> &rhs) {
  os << "( " << rhs.first << ", " << rhs.second << " )";
  return os;
}

void solve();
int main() {
  int test;
  scanf("%d", &test);
  char str[1000];
  fgets(str, 999, stdin);
  int test_case = 0;
  while (test--) {
    test_case++;
    printf("Case #%d:", test_case);
    // puts("");
    solve();
  }
}

vector<double> GaussElimination(vector<vector<double> > matrix, vector<double> vect) {
  const int n = vect.size();
  vector<double> ret(n, 0.0);
  for (int x = 0; x < n; x++) {
    int pivot = x;
    for (int i = x + 1; i < n; i++) {
      if (fabs(matrix[i][x]) - fabs(matrix[pivot][x]) > EPS) {
        pivot = i;
      }
    }
    swap(matrix[x], matrix[pivot]);
    swap(vect[x], vect[pivot]);
    if (fabs(matrix[x][x]) < EPS) { continue; }
    for (int y = x + 1; y < n; y++) {
      double ratio = -matrix[y][x] /  matrix[x][x];
      matrix[y][x] = 0.0;
      for (int i = x + 1; i < n; i++) {
        matrix[y][i] += matrix[x][i] * ratio;
      }
      vect[y] += vect[x] * ratio;
    }
  }
  for (int x = n - 1; x >= 0; x--) {
    double sum = vect[x];
    for (int i = n - 1; i > x; i--) {
      sum -= ret[i] * matrix[x][i];
    }
    ret[x] = sum / matrix[x][x];
  }
  return ret;
}

int n;
double xs[20];
double ys[20];
double zs[20];

bool solve(vector<int> &order) {
  // printf("\n");
  FOR(i, 3, n) {
    vector<vector<double>> matrix = { { 0, 0 }, { 0, 0 } };
    matrix[0][0] = xs[order[i - 1]] - xs[order[i]];
    matrix[0][1] = xs[order[i - 2]] - xs[order[i]];
    matrix[1][0] = ys[order[i - 1]] - ys[order[i]];
    matrix[1][1] = ys[order[i - 2]] - ys[order[i]];
    // cout << matrix << endl;
    REP(j, i - 2) {
      vector<double> vect = { 0, 0 };
      vect[0] = xs[order[j]] - xs[order[i]];
      vect[1] = ys[order[j]] - ys[order[i]];
      vector<double> amp = GaussElimination(matrix, vect);
      // cout << vect << endl;
      // cout << amp << endl;
      double z = zs[order[i]] + amp[0] * (zs[order[i - 1]] - zs[order[i]]) + amp[1] * (zs[order[i - 2]] - zs[order[i]]);
      // printf("%lf %lf\n", z, zs[order[j]]);
      if (z - zs[order[j]] <= EPS) { return false; }
    }
  }
  return true;
}

bool dfs(int used, vector<int> &order) {
  if ((int)order.size() == n) {
    return solve(order);
  }
  REP(i, n) {
    int nused = used | (1 << i);
    if (used == nused) { continue; }
    order.push_back(i);
    if (dfs(nused, order)) { return true; }
    order.pop_back();
  }
  return false;
}

void solve() {
  scanf("%d", &n);
  REP(i, n) {
    scanf("%lf %lf %lf", &xs[i], &ys[i], &zs[i]);
  }
  vector<int> order;
  bool ans = dfs(0, order);
  assert(ans);
  REP(i, n) {
    printf(" %d", order[i] + 1);
  }
  puts("");
}
