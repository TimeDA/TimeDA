#include <cstdio>
 #include <vector>
 
 using namespace std;
 
 int r, c;
 char a[105][105];
 
 bool isok(int x, int y, int dx, int dy)
 {
 	while (true)
 	{
 		x = x + dx;
 		y = y + dy;
 		if (x < 0 || x == r) break;
 		if (y < 0 || y == c) break;
 		if (a[x][y] != '.') return true;
 	}
 	return false;
 }
 
 bool test(int x, int y)
 {
 	int dx[4] = { -1, 0, 0, 1 };
 	int dy[4] = { 0, -1, 1, 0 };
 	for (int i = 0; i < 4; ++i)
 		if (isok(x, y, dx[i], dy[i])) return true;
 	return false;
 }
 
 int main()
 {
 	freopen("a.in", "r", stdin);
 	freopen("a.out", "w", stdout);
 	int T;
 	scanf("%d", &T);
 	for (int cn = 1; cn <= T; ++cn)
 	{
 		scanf("%d%d", &r, &c);
 		for (int i = 0; i < r; ++i)
 			for (int j = 0; j < c; ++j)
 				scanf(" %c", &a[i][j]);
 
 		bool ispos = true;
 		int ret = 0;
 		for (int i = 0; i < r; ++i)
 			for (int j = 0; j < c; ++j)
 			{
 				if (a[i][j] == '.') continue;
 				if (a[i][j] == '^')
 				{
 					if (isok(i, j, -1, 0)) continue;
 					if (test(i, j))
 					{
 						ret++;
 					}
 					else
 					{
 						ispos = false;
 					}
 				}
 				if (a[i][j] == '<')
 				{
 					if (isok(i, j, 0, -1)) continue;
 					if (test(i, j))
 					{
 						ret++;
 					}
 					else
 					{
 						ispos = false;
 					}
 				}
 				if (a[i][j] == '>')
 				{
 					if (isok(i, j, 0, 1)) continue;
 					if (test(i, j))
 					{
 						ret++;
 					}
 					else
 					{
 						ispos = false;
 					}
 				}
 				if (a[i][j] == 'v')
 				{
 					if (isok(i, j, 1, 0)) continue;
 					if (test(i, j))
 					{
 						ret++;
 					}
 					else
 					{
 						ispos = false;
 					}
 				}
 			}
 		if (ispos)
 			printf("Case #%d: %d\n", cn, ret);
 		else
 			printf("Case #%d: IMPOSSIBLE\n", cn);
 	}
 	return 0;
 }