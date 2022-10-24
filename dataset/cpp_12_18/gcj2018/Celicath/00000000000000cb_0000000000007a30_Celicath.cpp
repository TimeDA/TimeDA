/* initial code copied from whatever GCJ problem found in the Go, Gopher! problem statement */

#include <stdio.h>
#include <string.h>

bool map[20][20];

const int WIDTH = 15;
const int HEIGHT = 14;

void check(int& x, int& y)
{
	int max = 0;
	int rx = x, ry = y;
	for (int i = -1; i <= 1; i++)
	{
		int tx = x + i;
		if (tx <= 1 || tx >= WIDTH) continue;
		for (int j = -1; j <= 1; j++)
		{
			int ty = y + j;
			if (ty <= 1 || ty >= HEIGHT) continue;

			int count = 0;
			for (int a = -1; a <= 1; a++)
				for (int b = -1; b <= 1; b++)
					count += !map[tx + a][ty + b];
			if (count > max)
			{
				max = count;
				rx = tx;
				ry = ty;
			}
		}
	}
	x = rx;
	y = ry;
}

int main()
{
	int T;
	scanf("%d", &T);

	for (int c_n = 1; c_n <= T; c_n++)
	{
		int whatever;
		scanf("%d", &whatever);

		for (int i = 1; i <= WIDTH; i++)
			for (int j = 1; j <= HEIGHT; j++)
				map[i][j] = false;
		for (int i = 1; i <= WIDTH; i++)
		{
			for (int j = 1; j <= HEIGHT; j++)
			{
				while (!map[i][j])
				{
					int x = i, y = j;
					check(x, y);
					printf("%d %d\n", x, y);
					fflush(stdout);
					scanf("%d%d", &x, &y);
					if (x <= 0 || y <= 0)
						goto hell;
					map[x][y] = true;
				}
			}
		}
	hell:;
	}
	return -0;
}
