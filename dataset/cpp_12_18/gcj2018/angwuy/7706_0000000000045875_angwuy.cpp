#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<iostream>
#include<map>

using namespace std;

const int MAXN = 110;

int n;
int a[MAXN][MAXN];

int ln, rn;
int lm[MAXN], rm[MAXN];
bool g[MAXN][MAXN];
int mat[MAXN];
bool chk[MAXN];


void init()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)
	for (int j = 1; j <= n; ++j)
	{
		cin >> a[i][j];
	}
}

bool dfs(int x)
{
	for (int i = 1; i <= rn; ++i)
	if (g[x][i] && !chk[i])
	{
		int t = mat[i];
		mat[i] = x;
		chk[i] = true;
		if (t == 0 || dfs(t)) return true;
		mat[i] = t;
	}
	return false;
}

int bmatch()
{
	/*for (int i = 1; i <= ln; ++i)
	{
		for (int j = 1; j <= rn; ++j)
			printf("%d", g[i][j]);
		printf("\n");
	}*/
	memset(mat, 0, sizeof(mat));
	int ret = 0;
	for (int i = 1; i <= ln; ++i)
	{
		memset(chk, 0, sizeof(chk));
		if (dfs(i)) ++ret;
	}
	return ret;
}

int find(int lab)
{
	memset(g, 0, sizeof(g));
	ln = rn = 0;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		if (a[i][j] == lab)
		{
			lm[i] = ++ln;
			break;
		}
		for (int j = 1; j <= n; ++j)
		if (a[j][i] == lab)
		{
			rm[i] = ++rn;
			break;
		}
	}
	int ret = 0;
	for (int i = 1; i <= n; ++i)
	for (int j = 1; j <= n; ++j)
	if (a[i][j] == lab)
	{
		g[lm[i]][rm[j]] = true;
		++ret;
	}
	return bmatch();
}

void solve()
{
	int ans = 0;
	for (int i = -n; i <= n; ++i)
		ans += find(i);
	printf("%d\n", n * n - ans);
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