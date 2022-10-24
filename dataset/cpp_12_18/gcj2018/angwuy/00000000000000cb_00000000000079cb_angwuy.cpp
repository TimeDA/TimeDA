#include <cstdio>
#include <cstring>
#include <algorithm>

const int MAXN = 110000;

int n;
int a[MAXN], b[MAXN], c[MAXN];

void solve()
{
	scanf("%d", &n);
	int n1 = 0, n2 = 0;
	for (int i = 1; i <= n; ++i)
	{
		if (i & 1)
			scanf("%d", &a[++n1]);
		else
			scanf("%d", &b[++n2]);
	}
	std::sort(a + 1, a + n1 + 1);
	std::sort(b + 1, b + n2 + 1);
	n1 = 0, n2 = 0;
	
	for (int i = 1; i <= n; ++i)
	{
		if (i & 1)
			c[i] = a[++n1];
		else
			c[i] = b[++n2];
	}
	for (int i = 1; i < n; ++i)
	if (c[i] > c[i+1])
	{
		printf("%d\n", i - 1);
		return;
	}
	printf("OK\n");
}

int main()
{
	int tt;
	scanf("%d", &tt);
	for (int ii = 1; ii <= tt; ++ii)
	{
		printf("Case #%d: ", ii);
		solve();
	}
	return 0;
}