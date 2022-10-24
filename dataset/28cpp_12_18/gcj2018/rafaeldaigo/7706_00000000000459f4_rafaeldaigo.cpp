#include<cstdio>
#include<cstring>
#include<queue>
#include<utility>
#include<vector>
#include<algorithm>
#include<map>
#include<cmath>

using namespace std;
int r, c;
char pattern[30][30];
bool match[30][30];
bool marked[30][30];
int resp;
bool quadpattern[16];
// 0 1
// 2 3
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int cand;

void dfs(int x, int y)
{
	marked[x][y] = true;
	cand++;
	for (int k = 0; k < 4; k++)
	{
		int nx = x + dx[k];
		int ny = y + dy[k];
		if (nx < 0 || ny < 0 || nx >= r || ny >= c)
			continue;
		if (marked[nx][ny])
			continue;
		dfs(nx, ny);
	}
}

void test()
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			marked[i][j] = !match[i][j];
		}
	}

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (marked[i][j] == false)
			{
				cand = 0;
				dfs(i, j);
				resp = max(resp, cand);
			}
		}
	}
}

int main()
{
	int t, teste;
	scanf("%d\n", &teste);
	for (int t = 0; t < teste; t++)
	{
		scanf("%d %d\n", &r, &c);
		for (int i = 0; i < r; i++)
		{
			scanf("%s\n", pattern[i]);
		}
		resp = 0;

		for (int i = 0; i < 16; i++)
		{
			quadpattern[i] = false;
		}

		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				if (pattern[i][j] == 'B')
					quadpattern[0] = true;
				else
					quadpattern[15] = true;
			}
		}
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j + 1 < c; j++)
			{
				if (pattern[i][j] == 'B' && pattern[i][j + 1] == 'W')
					quadpattern[10] = true;
				else if (pattern[i][j] == 'W' && pattern[i][j + 1] == 'B')
					quadpattern[5] = true;
			}
		}
		for (int i = 0; i + 1 < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				if (pattern[i][j] == 'B' && pattern[i + 1][j] == 'W')
					quadpattern[12] = true;
				else if (pattern[i][j] == 'W' && pattern[i + 1][j] == 'B')
					quadpattern[3] = true;
			}
		}
		for (int i = 0; i + 1 < r; i++)
		{
			for (int j = 0; j + 1 < c; j++)
			{
				int quadindex = 0;
				if (pattern[i][j] == 'W')
					quadindex |= 1;
				if (pattern[i][j + 1] == 'W')
					quadindex |= 2;
				if (pattern[i + 1][j] == 'W')
					quadindex |= 4;
				if (pattern[i + 1][j + 1] == 'W')
					quadindex |= 8;
				quadpattern[quadindex] = true;
			}
		}

		for (int quadindex = 0; quadindex < 16; quadindex++)
		{
			if (!quadpattern[quadindex])
				continue;
			for (int a = 0; a < r; a++)
			{
				for (int b = 0; b < c; b++)
				{
					for (int i = 0; i < r; i++)
					{
						for (int j = 0; j < c; j++)
						{
							int expo = 0;
							if (i >= a) expo+=2;
							if (j >= b) expo++;
							char expected = ((quadindex & (1 << expo)) == 0) ? 'B' : 'W';
							match[i][j] = (pattern[i][j] == expected);
						}
					}
					test();
				}
			}
		}

		printf("Case #%d: %d\n", t + 1, resp);
	}
	return 0;
}
