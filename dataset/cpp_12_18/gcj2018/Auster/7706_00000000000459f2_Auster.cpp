#include <algorithm>
#include <iostream>
#include <sstream>
#include <map>
#include <cmath>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <functional>
#include <numeric>
#include <memory.h>

using namespace std;

typedef long long LL;

int b[100];
int c;

void read()
{
	cin >> c;
	for (int i = 0; i < c; ++i)
		cin >> b[i];
}

void solve()
{
	if (b[0] == 0 || b[c - 1] == 0)
	{
		cout << "IMPOSSIBLE\n";
		return;
	}
	int r = 0;
	int s = 0;
	for (int i = 0; i < c; ++i)
	{
		int L = s;
		int R = s + b[i] - 1;
		r = max(r, abs(R - i));
		r = max(r, abs(L - i));
		s += b[i];
	}
	r++;
	cout << r << '\n';

	vector<vector<char>> res(r, vector<char>(c, '.'));
	s = 0;
	for (int i = 0; i < c; ++i)
	{
		int L = s;
		int left = max(0, i - L);
		for (int j = 0; j < left; ++j)
			res[j][L + j] = '\\';
		int R = s + b[i] - 1;
		int right = max(0, R - i);
		for (int j = 0; j < right; ++j)
			res[j][R - j] = '/';
		s += b[i];
	}

	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
			cout << res[i][j];
		cout << '\n';
	}
}

int main() {
	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i) {
		read();
		cout << "Case #" << i << ": ";
		solve();
	}
	return 0;
}