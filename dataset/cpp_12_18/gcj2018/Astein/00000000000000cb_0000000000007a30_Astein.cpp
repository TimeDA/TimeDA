#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int min_x, min_y, max_x, max_y;
int table[100][100];

int main()
{
	int T;
	scanf("%d", &T);
	for (int cn = 1; cn <= T; ++cn)
	{
		int A;
		scanf("%d", &A);

		min_x = 10; min_y = 10;
		if (A == 20)
		{
			max_x = 13; max_y = 14;
		}
		else if (A == 200)
		{
			max_x = 23; max_y = 24;
		}

		int step = 0;
		memset(table, 0, sizeof(table));
		while (true)
		{
			step++;
			pair<int, int> optimal;

			int optimal_count = -1;

			for (int i = min_x + 1; i <= max_x - 1; ++i)
				for (int j = min_y + 1; j <= max_y - 1; ++j)
				{
					int count_empty = 0;
					for (int dx = -1; dx <= 1; ++dx)
						for (int dy = -1; dy <= 1; ++dy)
							if (table[i + dx][j + dy] == 0)
							{
								count_empty++;
							}

					if (count_empty > optimal_count)
					{
						optimal_count = count_empty;
						optimal = make_pair(i, j);
					}
				}
			printf("%d %d\n", optimal.first, optimal.second);
			fflush(stdout);

			int x, y;
			scanf("%d %d", &x, &y);
			if (x == 0 && y == 0)
			{
				break;
			}
			if (x == -1 && y == -1) return 0;
			table[x][y] = 1;
		}
	}
}