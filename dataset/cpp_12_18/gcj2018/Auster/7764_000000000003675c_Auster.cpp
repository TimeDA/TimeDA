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

const int inf = (int)1e9;
const LL INF = 1LL << 60;
const int MOD = (int)1e9 + 7;


int m;
int r[100][2];
int g[100];
int w[100];

void read()
{
	cin >> m;
	for (int i = 0; i < m; ++i)
	{
		cin >> r[i][0] >> r[i][1];
		r[i][0]--;
		r[i][1]--;
	}
	for (int i = 0; i < m; ++i)
		cin >> g[i];
}

const int MAX = 200;

int need[MAX + 1][101];


bool can(int res)
{
	memset(need, 0, sizeof(need));
	memcpy(w, g, sizeof(g));
	need[0][0] = res;
	for(int d = 0; d < 100; ++d)
	{
		for (int i = 0; i < m; ++i)
		{
			int can = min(w[i], need[d][i]);
			w[i] -= can;
			if (can != need[d][i])
			{
				int & n1 = need[d + 1][r[i][0]];
				n1 += need[d][i] - can;
				if (n1 >= inf)
					n1 = inf;
				int & n2 = need[d + 1][r[i][1]];
				n2 += need[d][i] - can;
				if (n2 >= inf)
					n2 = inf;
			}
		}
	}
	for (int i = 0; i < m; ++i)
		if (need[100][i])
			return 0;
	return 1;
}

int solve()
{
	int L = 0, R = inf;
	while (R - L > 1)
	{
		int M = (L + R) / 2;
		if (can(M))
			L = M;
		else
			R = M;
	}
	return L;
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