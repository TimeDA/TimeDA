#include <iostream>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

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
  cout << "Case #" << tcase << ": ";

  int d;
  string s;
  cin >> d >> s;

  int tot = 0;

  while (true) {
    long long val = evalst(s);
    if (val <= d) {
      break;
    }
    ++tot;

    long long nval = val;
    string ns;

    for (int i = 0; i + 1 < s.length(); ++i) {
      string ncur = s;
      swap(ncur[i], ncur[i + 1]);
      long long curval = evalst(ncur);
      if (curval < nval) {
        nval = curval;
        ns = ncur;
      }
    }

    s = ns;

    if (nval == val) {
      cout << "IMPOSSIBLE" << endl;
      return;
    }
  }
  cout << tot << endl;
}

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    solve(i + 1);
  }

  return 0;
}