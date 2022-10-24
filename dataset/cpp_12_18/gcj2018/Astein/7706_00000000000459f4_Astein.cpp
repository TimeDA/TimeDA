#define _CRT_SECURE_NO_WARNINGS

#include <cstring>
#include <queue>
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

char a[22][22];
int valid[22][22];
char copy4[88][88];

int main()
{
	int T;
	scanf("%d", &T);
	for (int cn = 1; cn <= T; ++cn)
	{
		printf("Case #%d: ", cn);
		int r, c;
		scanf("%d%d", &r, &c);
		for (int i = 0; i < r; ++i)
			for (int j = 0; j < c; ++j)
				scanf(" %c", &a[i][j]);

		int ret = 1;
		//for (int bit = 1; bit < (1 << (r * c)) - 1; ++bit)
		for (int bit = (1 << (r * c)) - 1; bit > 0; --bit)
		{
			pair<int, int> one;
			int counts = 0;
			for (int i = 0; i < r; ++i)
				for (int j = 0; j < c; ++j)
					if (bit & (1 << (i * c + j)))
					{
						valid[i][j] = 1;
						one = { i, j };
						counts++;
					}
					else
					{
						valid[i][j] = 0;
					}

			queue<pair<int, int>> Q;
			Q.push(one);
			valid[one.first][one.second] = 2;
			counts--;
			int dx[4] = { -1, 0, 0, 1 };
			int dy[4] = { 0, -1, 1, 0 };

			while (!Q.empty())
			{
				pair<int, int> now = Q.front(); Q.pop();
				for (int i = 0; i < 4; ++i)
				{
					int xx = now.first + dx[i], yy = now.second + dy[i];
					if (xx < 0 || yy < 0 || xx == r || yy == c) continue;
					if (valid[xx][yy] == 1)
					{
						Q.push({ xx, yy });
						valid[xx][yy] = 2;
						counts--;
					}
				}
			}
			if (counts != 0)
			{
				// not connected
				continue;
			}
			int minx = 99, miny = 99, maxx = -99, maxy = -99;
			for (int i = 0; i < r; ++i)
				for (int j = 0; j < c; ++j)
				{
					if (valid[i][j] == 2)
					{
						if (minx > i) minx = i;
						if (miny > j) miny = j;
						if (maxx < i) maxx = i;
						if (maxy < j) maxy = j;
					}
				}
			int sx = maxx - minx + 1;
			int sy = maxy - miny + 1;
			memset(copy4, 0, sizeof(copy4));
			for (int i = 0; i < sx; ++i)
				for (int j = 0; j < sy; ++j)
				{
					int v = valid[i + minx][j + miny];
					char c = a[i + minx][j + miny];
					if (v == 0)
					{
						c = ' ';
						for (int xx = 0; xx < 8; ++xx) for (int yy = 0; yy < 8; ++yy)
							copy4[8 * i + xx][8 * j + yy] = c;
					}
					else
					{
						for (int xx = 0; xx < 8; ++xx) for (int yy = 0; yy < 8; ++yy)
							copy4[8 * i + xx][8 * j + yy] = c;
					}
				}

			bool found = false;
			for (int i = 0; i < 8 * sx; ++i)
				for (int j = 0; j < 8 * sy; ++j)
				{
					if (found) break;
					bool same = true;
					for (int xx = 0; xx < sx; ++xx)
						for (int yy = 0; yy < sy; ++yy)
						{
							if (valid[minx + xx][miny + yy] == 0) continue;
							if (copy4[i + xx][j + yy] != a[xx + minx][yy + miny]) same = false;
						}
					if (same)
					{
						found = true;
						break;
					}
				}
			if (found)
			{
				int cnt = 0;
				for (int j = 0; j < r * c; ++j)
					if (bit & (1 << j)) cnt++;
				if (ret < cnt)
				{
					ret = cnt;
				}
			}
		}
		printf("%d\n", ret);
	}
}
