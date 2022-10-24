#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<iostream>
#include<map>

using namespace std;

const int MAXN = 510;

int n;
int f[MAXN][MAXN][MAXN];


void init()
{
	int n = 500;
	for (int i = 0; i <= n; ++i)
	for (int j = 0; j <= n; ++j)
	{
		int x, y;
		for (x = y = 0; x + y + 1 <= j; ++y, x += y);
		f[i][j][0] = y;
	}
	for (int k = 1; k <= n; ++k)
	for (int i = 0; i <= n; ++i)
	for (int j = 0; j <= n; ++j)
	{
		f[i][j][k] = f[i][j][k-1];
		int x, y;
		x = y = 0;
		while ((y + 1) * k <= i && x + y <= j)
		{
			x += y;
			f[i][j][k] = max(f[i][j][k], f[i - (y + 1) * k][j - x][k - 1] + y + 1);
			++y;
		}
	}
}


void solve()
{
	int r, b;
	cin >> r >> b;
	printf("%d\n", f[r][b][r]);
}


int main()
{
	init();
	int tt;
	cin >> tt;
	for (int ii = 1; ii <= tt; ++ii)
	{
		cout << "Case #" << ii << ": ";
		solve();
	}
	return 0;
}