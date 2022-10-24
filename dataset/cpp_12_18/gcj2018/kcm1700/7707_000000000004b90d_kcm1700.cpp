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
#include <tuple>

using namespace std;

struct point {
  int x, y, z;
  point() :x(0), y(0), z(0) {}
  point(int x, int y, int z) : x(x), y(y), z(z) {}

  point operator -(const point &o) const {
    return point(x - o.x, y - o.y, z - o.z);
  }
};

long long sqdist(const point &a, const point &b) {
  long long x = a.x - b.x;
  long long y = a.y - b.y;
  long long z = a.z - b.z;
  return x*x + y*y + z*z;
}

double distance(tuple<double, double, double> a, const point &b) {
  double x, y, z;
  tie(x, y, z) = a;
  x -= b.x;
  y -= b.y;
  z -= b.z;
  return sqrt((double)(x*x + y*y + z*z));
}

double distance(const point &a, const point &b) {
  long long x = a.x - b.x;
  long long y = a.y - b.y;
  long long z = a.z - b.z;
  return sqrt((double)(x*x + y*y + z*z));
}

double dlinep(const point &p1, const point &p2, const point &a) {
  double up = fabs((long long)(p2.y - p1.y) * a.x - (long long)(p2.x - p1.x) * a.y + (long long)p2.x * p1.y - (long long)p2.y * p1.x);
  return up / distance(p1, p2);
}

tuple<double, double, double> getprojection(const point &p1, const point &p2, const point &c) {
  double dot =
    (double)(p2.x - p1.x) * (c.x - p1.x) +
    (double)(p2.y - p1.y) * (c.y - p1.y) +
    (double)(p2.z - p1.z) * (c.z - p1.z);
  dot /= sqdist(p1, p2);
  return make_tuple(
    dot * (p2.x - p1.x) + p1.x,
    dot * (p2.y - p1.y) + p1.y,
    dot * (p2.z - p1.z) + p1.z
  );
}

tuple<double, double, double> cross(const point &a, const point &b) {
  return make_tuple(
    (double)a.y * b.z - (double)a.z * b.y,
    (double)a.z * b.x - (double)a.x * b.z,
    (double)a.x * b.y - (double)a.y * b.x
  );
}

bool under(const point &p1, const point &p2, const point &p3, const point &u) {
  double nx, ny, nz;
  tie(nx, ny, nz) = cross(p2 - p1, p3 - p1);
  double a = nx, b = ny, c = nz;
  double d = -(a * p1.x + b * p1.y + c*p1.z);
  //a * u.x + b * u.y + c * ? +d = 0;
  //a * u.x + b * u.y + d = -c * ?;
  // ? = -(a*u.x + b*u.y + d) / c
  double nh = -(a*u.x + b*u.y + d) / c;
  if (nh >= u.z) {
    return true;
  }
  return false;
}

struct Solver {
  int n;
  vector<point> dat;
  void input() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      int x, y, z;
      scanf("%d%d%d", &x, &y, &z);
      dat.emplace_back(x, y, z);
    }
  }
  vector<int> ans;

  bool rec(vector<int> &rev, vector<bool> &used) {
    if (rev.size() < 2) {
      for (int i = 0; i < n; i++) {
        if (used[i]) continue;
        used[i] = true;
        rev.emplace_back(i);
        if (rec(rev, used)) {
          return true;
        }
        rev.pop_back();
        used[i] = false;
      }
    }
    else {
      int i = rev.size();
      if (i == n) return true;
      point p1 = dat[rev[i - 2]];
      point p2 = dat[rev[i - 1]];
      int bestcand = -1;
      for (int j = 0; j < n; j++) {
        if (used[j]) continue;
        bool ok = true;
        for (int k = 0; k < n; k++) {
          if (used[k]) continue;
          if (k == j) continue;
          if (!under(p1, p2, dat[j], dat[k])) {
            ok = false;
            break;
          }
        }

        if (ok) {
          rev.emplace_back(j);
          used[j] = true;
          if (rec(rev, used)) {
            return true;
          }
          used[j] = false;
          rev.pop_back();
        }
      }
    }
    return false;
  }
  void solve() {
    vector<int> rev;
    rev.reserve(n + 2);
    vector<bool> used(n);
    {
      int mz = 0;
      for (int i = 0; i < n; i++) { if (dat[i].z > dat[mz].z) { mz = i; } }
      rev.emplace_back(mz);
      used[mz] = true;
    }

    rec(rev, used);

    reverse(rev.begin(), rev.end());
    ans = rev;
  }
  void output(int testcase) {
    printf("Case #%d: ", testcase);
    for (int i = 0; i < n; i++) {
      printf("%d%c", ans[i] + 1, " \n"[i + 1 == n]);
    }
  }
};

int main() {
  int testCaseCount;
  scanf("%d", &testCaseCount);

  const int batchSize = max(1, (int)(thread::hardware_concurrency() / 2));
  for (int testcase = 1; testcase <= testCaseCount; testcase += batchSize) {
    vector<unique_ptr<Solver>> solvers; solvers.reserve(batchSize);
    vector<unique_ptr<thread>> threads; threads.reserve(batchSize);
    for (int batchInd = 0; batchInd < batchSize && testcase + batchInd <= testCaseCount; batchInd++) {
      solvers.emplace_back(new Solver());
    }
    for (auto &solver : solvers) {
      solver->input();
      threads.emplace_back(new thread(&Solver::solve, solver.get()));
    }
    for (int batchInd = 0; batchInd < solvers.size(); batchInd++) {
      threads[batchInd]->join();
      solvers[batchInd]->output(testcase + batchInd);
    }
  }
  return 0;
}