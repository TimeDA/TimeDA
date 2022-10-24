#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>
#include <functional>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <cstring>
#include <ctime>
#include <memory.h>
#include <string>
#include <sstream>

using namespace std;

typedef long long LL;

const int inf = 1 << 30;
const LL INF = 1LL << 60;
const int MOD = (int)1e9 + 7;

int L, N;
vector<int> C;
vector<int> val;

int f(int p)
{
	int r = p * 100 % N;
	return p * 100 / N + (2 * r >= N);
}

void read()
{
	cin >> N >> L;
	C.assign(L, 0);
	for (int i = 0; i < L; ++i)
		cin >> C[i];
}

int best[251];

int dp[251][251];

int go2(int have)
{
	int & res = best[have];
	if (res != -1)
		return res;
	res = 0;
	for (int i = 1; i <= have; ++i)
		res = max(res, go2(have - i) + f(i));
	return res;
}

int go(int pos, int have)
{
	if (pos == L)
		return go2(have);
	int & res = dp[pos][have];
	if (res != -1)
		return res;
	res = 0;
	for (int i = 0; i <= have; ++i)
		res = max(res, go(pos + 1, have - i) + f(C[pos] + i));
	return res;
}

int solve()
{
	memset(dp, -1, sizeof(dp));
	memset(best, -1, sizeof(best));
	return go(0, N - accumulate(begin(C), end(C), 0));
}

int main()
{
	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i)
	{
		read();
		cout << "Case #" << i << ": " << solve() << "\n";
	}
	return 0;
}