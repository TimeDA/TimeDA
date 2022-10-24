#include <iostream>
 #include <algorithm>
 #include <cmath>
 #include <cstring>
 #include <cstdlib>
 #include <string>
 #include <vector>
 #include <cstdio>
 #include <cassert>
 
 using namespace std;
 
 typedef long long ll;
 typedef long double ld;
 
 #ifdef WIN32
 #define LLD "%I64d"
 #else
 #define LLD "%lld"
 #endif
 
 const int dx[8] = {1, 1, 1, 0, -1, -1, -1, 0};
 const int dy[8] = {1, 0, -1, -1, -1, 0, 1, 1};
 
 const int maxn = 10;
 
 int p[maxn][maxn];
 int kv[maxn][maxn];
 bool was[maxn][maxn];
 int n, m;
 
 void go(int x, int y)
 {
 	if (was[x][y]) return;
 	if (x <= 0 || x > n || y <= 0 || y > m) return;
 	was[x][y] = true;
 	if (kv[x][y] != 0) return;
 	if (p[x][y] != 0) return;
 	for (int d = 0; d < 8; d++) go(x + dx[d], y + dy[d]);
 }
 
 int main()
 {
 	int NT = 0;
 	scanf("%d", &NT);
 	for (int T = 1; T <= NT; T++)
 	{
 		printf("Case #%d:\n", T);
 		
 		memset(p, 0, sizeof p);
 		
 		int c;
 		scanf("%d%d%d", &n, &m, &c);
 		if (n * m == c + 1)
 		{
 			printf("c");
 			for (int i = 1; i < m; i++) printf("*");
 			printf("\n");
 			for (int i = 1; i < n; i++)
 			{
 				for (int j = 0; j < m; j++) printf("*");
 				printf("\n");
 			}
 			continue;
 		}
 		int km = 1 << (n * m);
 		bool imposs = true;
 		for (int mask = 0; mask < km; mask++) if (__builtin_popcount(mask) == c)
 		{
 			for (int i = 0; i < n; i++)
 			{
 				for (int j = 0; j < m; j++)
 				{
 					int cur = i * m + j;
 					p[i + 1][j + 1] = (mask >> cur) & 1;
 				}
 			}
 			for (int i = 1; i <= n; i++)
 			{
 				for (int j = 1; j <= m; j++) if (p[i][j] == 0)
 				{
 					kv[i][j] = 0;
 					for (int d = 0; d < 8; d++)
 					{
 						kv[i][j] += p[i + dx[d]][j + dy[d]];
 					}
 				}
 			}
 			bool found = false;
 			for (int i = 1; i <= n; i++)
 			{
 				for (int j = 1; j <= m; j++) was[i][j] = false;
 			}
 			int whx, why;
 			for (int i = 1; i <= n && !found; i++)
 			{
 				for (int j = 1; j <= m && !found; j++) if (p[i][j] == 0 && kv[i][j] == 0)
 				{
 					go(i, j);
 					found = true;
 					whx = i;
 					why = j;
 				}
 			}
 // 			cout << mask << ' ' << found << endl;
 			bool ok = found;
 			for (int i = 1; i <= n; i++)
 			{
 				for (int j = 1; j <= m; j++) if (p[i][j] == 0 && !was[i][j]) ok = false;
 			}
 			if (ok)
 			{
 				for (int i = 1; i <= n; i++)
 				{
 					for (int j = 1; j <= m; j++)
 					{
 						if (i == whx && j == why) printf("c");
 						else if (p[i][j] == 1) printf("*");
 						else printf(".");
 					}
 					printf("\n");
 				}
 				imposs = false;
 				break;
 			}
 		}
 		if (imposs) printf("Impossible\n");
 		fprintf(stderr, "%d/%d cases done!\n", T, NT);
 	}
 	return 0;
 }
