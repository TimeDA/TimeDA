#include <cstdio>
#include <cstring>

const int MAXN = 100;

int n;
char s[MAXN];
int a[MAXN];
int d;

void solve()
{
	scanf("%d %s\n", &d, s);
	n = strlen(s);
	long long cur = 1;
	for (int i = 0; i < n; ++i)
	if (s[i] == 'S')
	{
		a[i] = cur;
		d -= cur;
	}
	else if (s[i] == 'C')
	{
		a[i] = 0;
		cur = cur * 2;
	}
	int t = 0;
	while (d < 0)
	{
		bool ok = false;
		for (int i = n-1; i > 0; --i)
		if (s[i] == 'S' && s[i-1] == 'C')
		{
			s[i] = 'C';
			s[i-1] = 'S';
			d += a[i] / 2;
			a[i-1] = a[i] /2;
			a[i] = 0;
			++t;
			ok = true;
			break;
		}
		if (!ok)
		{
			printf("IMPOSSIBLE\n");
			return;
		}
	}
	printf("%d\n", t);
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