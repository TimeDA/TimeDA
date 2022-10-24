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

int u[1000][10];

int main()
{
	int T, a;
	scanf("%d", &T);
	for (int ts = 1; ts <= T; ts++)
	{
		scanf("%d", &a);
		int x = 2, y = 2;
		int i, j;
		for (i = 1; i < 1000; i++)
			for (j = 1; j < 10; j++)
				u[i][j] = 0;
		while (1)
		{
			printf("%d %d\n", x, y);
			fflush(stdout);
			scanf("%d%d", &i, &j);
			if (i <= 0 && j <= 0)
				break;
			u[i][j] = 1;
			int s = 0;
			for (int k = x - 1; k <= x + 1; k++)
				for (int l = y - 1; l <= y + 1; l++)
					s += u[k][l];
			if (s == 9)
				x += 3;
		}
	}
	return 0;
}