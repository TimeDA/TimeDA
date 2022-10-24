#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

int table[501][501];
pair<int, int> pre[501][501];

void init()
{
	memset(table, -1, sizeof(table));
	table[0][0] = 0;
	int filled = 1;

	pair<int, int> last_update = { -1, -1 };

	for (int i = 1; i <= 40; ++i)
	{
		for (int j = 0; j <= i; ++j)
		{
			int red = j, blue = i - j;
			for (int x = 500 - red; x >= 0; --x)
				for (int y = 500 - blue; y >= 0; --y)
				{
					if (table[x][y] != -1 && table[x + red][y + blue]  != -1 && table[x + red][y + blue] < table[x][y] + 1)
					{
						table[x + red][y + blue] = table[x][y] + 1;
						pre[x + red][y + blue] = make_pair(red, blue);
						last_update = { red, blue };
					}
					if (table[x][y] != -1 && table[x + red][y + blue] == -1)
					{
						table[x + red][y + blue] = table[x][y] + 1;
						pre[x + red][y + blue] = make_pair(red, blue);
						last_update = { red, blue };
					}
				}
		}
	}
}

int main()
{
	init();

	int T;
	scanf("%d", &T);
	for (int cn = 1; cn <= T; ++cn)
	{
		int r, b;
		scanf("%d%d", &r, &b);
		printf("Case #%d: %d\n", cn, table[r][b]);
	}
}
