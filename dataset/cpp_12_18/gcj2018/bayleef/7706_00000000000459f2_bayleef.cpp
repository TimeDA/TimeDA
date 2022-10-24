#define _USE_MATH_DEFINES
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <map>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int main()
{
	char ans[101][101];
	int T;
	scanf("%d", &T);
	for (int ts = 1; ts <= T; ts++)
	{
		int a[200];
		int n, i;
		scanf("%d", &n);
		for (i = 0; i < n; i++)
			scanf("%d", &a[i]);
		if (!a[0] || !a[n - 1])
		{
			printf("Case #%d: IMPOSSIBLE\n", ts);
			continue;
		}
		int b[200];
		int j = 0;
		for (i = 0; i < n; i++)
		{
			for (; j < n && !a[j]; j++);
			a[j]--;
			b[i] = j;
		}
		for (i = 0; i < 100; i++)
		{
			for (j = 0; j < 100; j++)
				ans[i][j] = '.';
			ans[i][n] = 0;
		}
		int m = 1;
		for (i = 1; i < n; i++)
			if (b[i] != b[i - 1])
			{
				m = max(m, i - b[i - 1]);
				m = max(m, b[i] - i + 1);
				for (j = i - 1; j > b[i - 1]; j--)
					ans[j - b[i - 1]][j] = '/';
				for (j = i; j < b[i]; j++)
					ans[b[i] - j][j] = '\\';
			}
		printf("Case #%d: %d\n", ts, m);
		for (i = m - 1; i >= 0; i--)
			puts(ans[i]);
	}
	return 0;
}