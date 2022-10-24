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

using namespace std;


struct point3 {
  double x, y, z;
  point3() :x(0), y(0), z(0) {}
  point3(double x, double y, double z) : x(x), y(y), z(z) {}
  void rotateYZ(double theta) {
    double ny = y * cos(theta) + z * (-sin(theta));
    double nz = y * sin(theta) + z * cos(theta);
    y = ny;
    z = nz;
  }
  void print() {
    printf("%.16f %.16f %.16f\n", x, y, z);
  }
};

struct Solver {
  double A;
  void input() {
    scanf("%lf", &A);
  }
  void solve() {
  }

  typedef pair<double, double> point;
  double ccw(point a, point b, point c) {
    b.first -= a.first; b.second -= a.second;
    c.first -= a.first; c.second -= a.second;
    return b.first * c.second - c.first * b.second;
  }
  vector<point> convexHull(vector<point> dat) {
    if (dat.size() <= 3)
      return dat;
    vector<point> upper, lower;
    sort(dat.begin(), dat.end());
    for (int i = 0; i < dat.size(); i++) {
      while (upper.size() >= 2 && ccw(*++upper.rbegin(), *upper.rbegin(), dat[i]) >= 0) upper.pop_back();
      while (lower.size() >= 2 && ccw(*++lower.rbegin(), *lower.rbegin(), dat[i]) <= 0) lower.pop_back();
      upper.emplace_back(dat[i]);
      lower.emplace_back(dat[i]);
    }
    upper.insert(upper.end(), ++lower.rbegin(), --lower.rend());
    return upper;
  }
  double calcArea(point3 a, point3 b, point3 c) {
    vector<point> points;
    points.emplace_back(a.x + b.x + c.x, a.z + b.z + c.z);
    points.emplace_back(a.x + b.x - c.x, a.z + b.z - c.z);
    points.emplace_back(a.x - b.x + c.x, a.z - b.z + c.z);
    points.emplace_back(a.x - b.x - c.x, a.z - b.z - c.z);
    points.emplace_back(-a.x + b.x + c.x, -a.z + b.z + c.z);
    points.emplace_back(-a.x + b.x - c.x, -a.z + b.z - c.z);
    points.emplace_back(-a.x - b.x + c.x, -a.z - b.z + c.z);
    points.emplace_back(-a.x - b.x - c.x, -a.z - b.z - c.z);
    vector<point> result = convexHull(points);
    {auto ff = result[0];  result.push_back(ff); }
    double area = 0;
    for (int i = 0; i + 1 < result.size(); i++) {
      area += result[i].first * result[i + 1].second;
      area -= result[i + 1].first * result[i].second;
    }
    return fabs(area) / 2;
  }
  void output(int testcase) {
    printf("Case #%d:\n", testcase);
    if (A < sqrt(2.0)) {
      double angle = asin(min(1.0, (A*A - 1))) / 2;
      point3 p1 = point3(0, 0, 0.5);
      point3 p2 = point3(cos(angle) / 2, sin(angle) / 2, 0);
      point3 p3 = point3(sin(angle) / 2, -cos(angle) / 2, 0);
      p1.print();
      p2.print();
      p3.print();
      //fprintf(stderr, "Calcarea: %.16f\n", calcArea(p1, p2, p3));
    }
    else {
      // * a = cos(theta)
      // * b = sqrt(2) sin(theta)
      // * 2a + b = sqrt(2)A
      // 2a^2 + b^2 = 2
      // b = sqrt(2)A - 2a
      // 2a^2 + 2A^2 - 4sqrt(2)A a + 4a^2 = 2
      // 6a^2 - 4sqrt(2)A a + 2A^2 - 2 = 0
      // a = (sqrt(2)A +- sqrt(3 - A^2)) / (3)
      double a1_2 = ((sqrt(2.0)*A - sqrt(3 - A*A)) / 3);
      double a2_2 = ((sqrt(2.0)*A + sqrt(3 - A*A)) / 3);
      double theta;
      theta = acos(min(1.0, a1_2));
      point3 p1 = point3(sqrt(2.0) / 4, sqrt(2.0) / 4, 0);
      point3 p2 = point3(-sqrt(2.0) / 4, sqrt(2.0) / 4, 0);
      point3 p3 = point3(0, 0, -0.5);
      p1.rotateYZ(-theta);
      p2.rotateYZ(-theta);
      p3.rotateYZ(-theta);
      p1.print();
      p2.print();
      p3.print();
      //fprintf(stderr, "Calcarea: %.16f\n", calcArea(p1, p2, p3));
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