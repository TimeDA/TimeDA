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

int r, b;

void read()
{
	cin >> r >> b;
}

vector<pair<int, int>> d;
int dp[700][501][501];

const int inf = (int)1e9;

int go(int k, int r, int b)
{
	if (k == d.size())
		return 0;
	int & res = dp[k][r][b];
	if (res != -1)
		return res;
	res = go(k + 1, r, b);
	if (r - d[k].first >= 0 && b - d[k].second >= 0)
		res = max(res, 1 + go(k + 1, r - d[k].first, b - d[k].second));
	return res;
}

void init()
{
	memset(dp, -1, sizeof(dp));
	for (int k = 1; k <= 32; ++k)
		for (int i = 0; i <= k; ++i)
			d.push_back({ i, k - i });
	for (int i = 0; i <= 500; ++i)
		for (int j = 0; j <= 500; ++j)
			go(0, i, j);
}

void solve()
{
	cout << go(0, r, b) << '\n';
}

int main() {
	init();
	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i)
	{
		read();
		cout << "Case #" << i << ": ";
		solve();
	}
	return 0;
}