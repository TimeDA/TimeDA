#include <cstdio>
 #include <vector>
 #include <string>
 #include <sstream>
 #include <set>
 #include <algorithm>
 #include <iostream>
 
 using namespace std;
 
 typedef long long LL;
 
 char a[1 << 5][1 << 5];
 const int dx[4] = {-1, -1, 1, 1};
 const int dy[4] = {-1, 1, 1, -1};
 
 int h, w, d, t;
 int sx, sy;
 
 set<pair<int, int> > S;
 
 int gcd(int x, int y)
 {
 	return y == 0 ? x : gcd(y, x % y);
 }
 
 pair<int, int> N(int x, int y)
 {
 	if (x == 0)
 		return make_pair(0, y / abs(y));
 	if (y == 0)
 		return make_pair(x / abs(x), 0);
 	int d = gcd(abs(x), abs(y));
 	return make_pair(x / d, y / d);
 }
 
 int len(int x, int y)
 {
 	return x * x + y * y;
 }
 
 int main()
 {
 	freopen("D.in", "r", stdin);
 	freopen("output.txt", "w", stdout);
 	scanf("%d", &t);
 	for(int test = 1; test <= t; ++test)
 	{
 		S.clear();
 		scanf("%d%d%d", &h, &w, &d);
 		for(int i = 0; i < h; ++i)
 			scanf("%s", a[i]);
 		for(int i = 0; i < h; ++i)
 			for(int j = 0; j < w; ++j)
 				if (a[i][j] == 'X')
 					sx = 2 * (j - 1) + 1, sy = 2 * (i - 1) + 1;
 		w = (w - 2) * 2, h = (h - 2) * 2;
 		int x, y;
 		for(int i = -d; i <= d; ++i)
 		{
 			for(int j = -d; j <= d; ++j)
 			{
 				for(int k = 0; k < 4; ++k)
 				{
 					x = dx[k] * sx + 2 * w * i - sx;
 					y = dy[k] * sy + 2 * h * j - sy;
 					if (x == 0 && y == 0)
 						continue;
 					if (len(x, y) <= 4 * d * d)
 						S.insert(N(x, y));
 				}
 			}
 		}
 		printf("Case #%d: %d\n", test, (int)S.size());
 	}
 	return 0;
 }