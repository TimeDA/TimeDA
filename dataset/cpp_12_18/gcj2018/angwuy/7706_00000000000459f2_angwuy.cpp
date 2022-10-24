#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<iostream>
#include<map>

using namespace std;

const int MAXN = 110;

int n;
int a[MAXN], b[MAXN];
char c[MAXN][MAXN];


void init()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}
}

int absint(int x){return x < 0 ? -x : x;}

void solve()
{
	int cur = 1;
	int m = 0;
	for (int i = 1; i <= n; ++i)
	while (a[i] > 0)
	{
		b[cur++] = i;
		--a[i];
	}
	if (b[1] != 1 || b[n] != n)
	{
		printf("IMPOSSIBLE\n");
		return;
	}
	for (int i = 1; i <= n; ++i)
	if (absint(i - b[i]) > m)
		m = absint(i - b[i]);
	++m;
	printf("%d\n", m);
	memset(c, '.', sizeof(c));
	for (int i = 1; i <= n; ++i)
	{
		if (b[i] < i)
		{
			int t = 1;
			for (int j = i; j > b[i]; --j)
				c[t++][j] = '/';
		}
		if (b[i] > i)
		{
			int t = 1;
			for (int j = i; j < b[i]; ++j)
				c[t++][j] = '\\';
		}
	}
	for (int i = 1; i <= m; ++i)
	{
		c[i][n+1] = '\0';
		puts(c[i] + 1);
	}
}


int main()
{
	int tt;
	cin >> tt;
	for (int ii = 1; ii <= tt; ++ii)
	{
		init();
		cout << "Case #" << ii << ": ";
		solve();
	}
	return 0;
}