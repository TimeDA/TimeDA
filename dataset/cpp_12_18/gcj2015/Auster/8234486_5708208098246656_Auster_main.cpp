#pragma comment(linker, "/STACK:134217728")
 
 #include <cstdio>
 #include <iostream>
 #include <map>
 #include <set>
 #include <vector>
 #include <queue>
 #include <string>
 #include <algorithm>
 #include <numeric>
 #include <functional>
 #include <cmath>
 #include <complex>
 #include <memory.h>
 #include <time.h>
 
 using namespace std;
 
 typedef long long LL;
 
 int t, n, m;
 
 char a[1 << 7][1 << 7];
 
 const int dx[4] = {-1, 1, 0, 0};
 const int dy[4] = {0, 0, -1, 1};
 int d[255];
 
 bool bound(int x, int y)
 {
 	return x >= 0 && y >= 0 && x < n && y < m;
 }
 
 int main()
 {
 	freopen("A-small-attempt0 (7).in", "r", stdin);
 	freopen("output.txt", "w", stdout);
 
 	d['^'] = 0;
 	d['v'] = 1;
 	d['<'] = 2;
 	d['>'] = 3;
 
 	scanf("%d", &t);
 	for(int test = 1; test <= t; ++test)
 	{
 		scanf("%d%d", &n, &m);
 		for(int i = 0; i < n; ++i)
 			scanf("%s", a[i]);
 
 		int res = 0;
 		int bad = 0;
 		for(int i = 0; i < n; ++i)
 		{
 			for(int j = 0; j < m; ++j)
 			{
 				if (a[i][j] != '.')
 				{
 					int ok = 0;
 					int add = (int)1e9;
 					for(int k = 0; k < 4; ++k)
 					{
 						int x = i, y = j;
 						bool ok = 0;
 						do
 						{
 							x += dx[k];
 							y += dy[k];
 							if (bound(x, y) && a[x][y] != '.')
 								ok = 1;
 						}
 						while (bound(x, y));
 						if (ok)
 							add = min(add, 1 - (k == d[a[i][j]]));
 					}
 					if (add == (int)1e9)
 						bad = 1;
 					res += add;
 				}
 			}
 		}
 
 		printf("Case #%d: ", test);
 		if (bad)
 			printf("IMPOSSIBLE\n");
 		else
 			printf("%d\n", res);
 	}
 	return 0;
 }