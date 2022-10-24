#include <iostream>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

const double pi = 2 * acos(0.);

long long evalst(const string& s) {
  long long res = 0;
  long long cur = 1;
  for (int i = 0; i < s.length(); ++i) {
    if (s[i] == 'S') {
      res += cur;
    } else {
      cur *= 2;
    }
  }
  return res;
}

void solve(int tcase) {
  cout << "Case #" << tcase << ":" << endl;

  double x;
  cin >> x;

  double ang = acos(x / sqrt(2.0));

  double ang2 = ang + pi / 4.;

  double cx = cos(ang) * sqrt(2.) / 2, cy = sin(ang) * sqrt(2.) / 2;

  ang2 = pi - ang2; ang2 = -ang2;

  ang = pi - ang; ang = -ang;
  double fx = cx + cos(ang2) * 0.5, fy = cy + sin(ang2) * 0.5;
  double sx = fx + cos(ang) * sqrt(2.) / 2, sy = fy + sin(ang) * sqrt(2.) / 2;

  printf("%.10lf %.10lf %.10lf\n", fx, fy, 0.);
  printf("%.10lf %.10lf %.10lf\n", sx, sy, 0.);
  printf("%.10lf %.10lf %.10lf", 0., 0., 0.5);

  cout << endl;
}

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    solve(i + 1);
  }

  return 0;
}