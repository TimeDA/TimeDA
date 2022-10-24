#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
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

vector<int>a;
int good[100100];

bool pr(int i, int j)
{
	return good[i] < good[j];
}

int value(int x, int n)
{
	return (200 * x + n) / n / 2;
}

int main()
{
	int T;
	int i;
	scanf("%d", &T);
	for (int ts = 1; ts <= T; ts++)
	{
		a.clear();
		int n, m;
		scanf("%d%d", &n, &m);
		for (i = n - 1; i >= 0; i--)
			if (100 * i%n * 2 >= n)
				good[i] = 0;
			else
				good[i] = good[i + 1] + 1;
		int nn = n;
		int ans = 0;
		for (i = 0; i < m; i++)
		{
			int x;
			scanf("%d", &x);
			nn -= x;
			if (good[x])
				a.push_back(x);
			else
				ans += value(x, n);
		}
		sort(a.begin(), a.end(), pr);
		for (i = 0; i < a.size() && good[a[i]] < good[0]; i++)
			if (nn >= good[a[i]])
			{
				nn -= good[a[i]];
				a[i] += good[a[i]];
				ans += value(a[i], n);
			}
			else
				break;
		while (nn >= good[0])
		{
			nn -= good[0];
			ans += value(good[0], n);
		}
		for (; i < a.size(); i++)
		{
			if (nn >= good[a[i]])
			{
				nn -= good[a[i]];
				a[i] += good[a[i]];
			}
			ans += value(a[i], n);
		}
		ans += value(nn, n);
		printf("Case #%d: %d\n", ts, ans);
	}
	return 0;
}