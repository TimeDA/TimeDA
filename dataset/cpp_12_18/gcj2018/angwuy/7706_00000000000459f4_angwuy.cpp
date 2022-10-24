#include<cstdio>
#include<cstring>

const int MAXN = 25;
const int D[4][2] = {{0,1}, {1,0}, {0, -1}, {-1, 0}};

int n, m;
char a[MAXN][MAXN];
char b[MAXN][MAXN];
bool chk[MAXN][MAXN];
int ans;
int tot;

void dfs(int x, int y)
{
	chk[x][y] = true;
	++tot;
	for (int i = 0; i < 4; ++i)
	{
		int nx = x + D[i][0];
		int ny = y + D[i][1];
		if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && !chk[nx][ny] && a[nx][ny] == b[nx][ny])
			dfs(nx, ny);
	}
}

void floodfill()
{
	memset(chk, 0, sizeof(chk));
	for (int i = 1; i <= n; ++i)
	for (int j = 1; j <= m; ++j)
	if (!chk[i][j] && a[i][j] == b[i][j])
	{
		tot = 0;
		dfs(i, j);
		if (tot > ans) ans = tot;
	}
}

void check1()
{
	memset(b, 'B', sizeof(b));
	floodfill();
	memset(b, 'W', sizeof(b));
	floodfill();
}

void check2()
{
	if (m > 1)
	for (int k = 1; k < m; ++k)
	{
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= k; ++j)
				b[i][j] = 'W';
			for (int j = k + 1; j <= m; ++j)
				b[i][j] = 'B';
		}
		floodfill();
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= k; ++j)
				b[i][j] = 'B';
			for (int j = k + 1; j <= m; ++j)
				b[i][j] = 'W';
		}
		floodfill();
	}
	if (n > 1)
	for (int k = 1; k < n; ++k)
	{
		for (int i = 1; i <= m; ++i)
		{
			for (int j = 1; j <= k; ++j)
				b[j][i] = 'W';
			for (int j = k + 1; j <= n; ++j)
				b[j][i] = 'B';
		}
		floodfill();
		for (int i = 1; i <= m; ++i)
		{
			for (int j = 1; j <= k; ++j)
				b[j][i] = 'B';
			for (int j = k + 1; j <= n; ++j)
				b[j][i] = 'W';
		}
		floodfill();
	}
}

void check4(char c1, char c2, char c3, char c4)
{
	if (n == 1 || m == 1) return;

	bool flag = false;
	for (int i = 1; i < n; ++i)
	for (int j = 1; j < m; ++j)
	if (a[i][j] == c1 &&
	    a[i][j+1] == c2 &&
		a[i+1][j] == c3 &&
		a[i+1][j+1] == c4)
		flag = true;
	if (!flag) return;



	for (int k = 1; k < n; ++k)
	for (int l = 1; l < m; ++l)
	{
		for (int i = 1; i <= k; ++i)
		{
			for (int j = 1; j <= l; ++j)
				b[i][j] = c1;
			for (int j = l + 1; j <= m; ++j)
				b[i][j] = c2;
		}
		for (int i = k + 1; i <= n; ++i)
		{
			for (int j = 1; j <= l; ++j)
				b[i][j] = c3;
			for (int j = l + 1; j <= m; ++j)
				b[i][j] = c4;
		}
		floodfill();
	}
}


void init()
{
	scanf("%d %d\n", &n, &m);
	for (int i = 1; i <= n; ++i)
		scanf("%s\n", a[i] + 1);
}


void solve()
{
	if (n <= 2 && m <= 2)
	{
		printf("%d\n", n * m);
		return;
	}
	ans = 0;
	check1();
	check2();
	check4('W', 'W', 'W', 'B');
	check4('W', 'W', 'B', 'W');
	check4('W', 'B', 'W', 'W');
	check4('B', 'W', 'W', 'W');
	
	check4('B', 'B', 'B', 'W');
	check4('B', 'B', 'W', 'B');
	check4('B', 'W', 'B', 'B');
	check4('W', 'B', 'B', 'B');
	
	check4('B', 'W', 'W', 'B');
	check4('W', 'B', 'B', 'W');
	printf("%d\n", ans);
}


int main()
{
	//freopen("in.txt", "r", stdin);
	int tt;
	scanf("%d\n", &tt);
	for (int ii = 1; ii <= tt; ++ii)
	{
		init();
		printf("Case #%d: ", ii);
		solve();
	}
	return 0;
}