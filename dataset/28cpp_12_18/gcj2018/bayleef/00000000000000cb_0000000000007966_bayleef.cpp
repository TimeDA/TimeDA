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

int main()
{
	int T, d, n, i, ans, sum;
	char s[50];
	scanf("%d", &T);
	for (int ts = 1; ts <= T; ts++)
	{
		scanf("%d%s", &d, &s);
		for (n = 0; s[n]; n++);
		for (ans = 0;; ans++)
		{
			int p = 1;
			sum = 0;
			for (i = 0; i < n; i++)
				if (s[i] == 'C')
					p *= 2;
				else
					sum += p;
			if (sum <= d)
				break;
			for (i = n - 1; i; i--)
				if (s[i] == 'S' && s[i - 1] == 'C')
					break;
			if (!i)
				break;
			swap(s[i], s[i - 1]);
		}
		if (sum > d)
			printf("Case #%d: IMPOSSIBLE\n", ts);
		else
			printf("Case #%d: %d\n", ts, ans);
	}
	return 0;
}