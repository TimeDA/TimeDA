// by tmt514
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#define SZ(x) ((int)(x).size())
#define FOR(it, c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
using namespace std;
typedef long long LL;

void solve() {
	int A, B, N;
	cin >> A >> B >> N;
	++A;
	while(A<=B) {
		int M = (A+B)/2;
		cout << M << endl;
		cout.flush();
		string s;
		cin >> s;
		if (s == "TOO_SMALL") {
			A = M+1;
		} else if (s == "TOO_BIG") {
			B = M-1;
		} else
			break;
	}
}

int main(void) {
	int T;
	cin >> T;
	while(T--) solve();
  return 0;
}
