#include <iostream>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int dx[] = {10, 10, 11, 11, 12, 12};
int dy[] = {10, 11, 10, 11, 10, 11};

void solve(int tcase) {
  int a;
  cin >> a;

  int idx = 0;
  while (true) {
    cout << dx[idx] << " " << dy[idx] << endl;
    idx = (idx + 1) % 6;

    int nx, ny;
    cin >> nx >> ny;
    if (nx == 0 && ny == 0) {
      return;
    }
  }
}

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    solve(i + 1);
  }

  return 0;
}