#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <cassert>
#include <sstream>
#include <functional>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
#include <set>
#include <queue>

using namespace std;

int nt;
int a[10][10];
int res, N;
int b[10][10];

int col[10][10][2];
int row[10][10][2];

int s(int x)
{
    if (x < 0) return 0; else return 1;
}

void go(int cur, int x, int y)
{
    if (cur >= res) return;

    if (y == N) { go(cur, x + 1, 0); return; }
    if (x == N)
    {
        res = cur;
        return;
    }

    for(int i = -N; i <= N; i++)
    if (i)
    {
        if (row[x][abs(i)][s(i)]) continue;
        if (col[y][abs(i)][s(i)]) continue;
        row[x][abs(i)][s(i)] = true;
        col[y][abs(i)][s(i)] = true;

        go(cur + (i != a[x][y]), x, y + 1);

        row[x][abs(i)][s(i)] = false;
        col[y][abs(i)][s(i)] = false;
    }
}

int main()
{
	scanf("%d", &nt);
	for(int tt = 1; tt <= nt; tt++)
	{
		printf("Case #%d: ", tt);

		scanf("%d", &N);
        for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++) scanf("%d", &a[i][j]);

        res = N * N;
        go(0, 0, 0);

        printf("%d\n", res);
	}
	return 0;
}