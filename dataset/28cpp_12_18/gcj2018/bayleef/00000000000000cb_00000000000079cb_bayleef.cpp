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

int a[200000];
int b[200000];
int c[200000];

int main()
{
	int T, i, n, m, k;
	scanf("%d", &T);
	for (int ts = 1; ts <= T; ts++)
	{
		scanf("%d", &n);
		for (i = 0; i < n; i++)
			scanf("%d", &a[i]);
		m = k = 0;
		for (i = 0; i < n; i += 2)
			b[m++] = a[i];
		for (i = 1; i < n; i += 2)
			c[k++] = a[i];
		sort(b, b + m);
		sort(c, c + k);
		m = k = 0;
		for (i = 0; i < n; i += 2)
			a[i] = b[m++];
		for (i = 1; i < n; i += 2)
			a[i] = c[k++];
		for (i = 1; i < n; i++)
			if (a[i] < a[i - 1])
				break;
		if (i == n)
			printf("Case #%d: OK\n", ts);
		else
			printf("Case #%d: %d\n", ts, i - 1);
	}
	return 0;
}