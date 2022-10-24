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
 
 int nt, W, H, B;
 int res;
 
 const int oo = 0x3f3f3f3f;
 
 char s[100][500];
 int d[100][500];
 int prevx[100][500];
 int prevy[100][500];
 
 queue<int> Q;
 
 void go(int x, int y, int dd, int px, int py)
 {
 	if (x < 0 || y < 0 || x >= W || y >= H) return;
 	if (s[x][y]) return;
 	if (d[x][y] <= dd) return;
 	d[x][y] = dd;
 	Q.push(x);
 	Q.push(y);
 	prevx[x][y] = px;
 	prevy[x][y] = py;
 }
 
 void gogo(int x, int y)
 {
 	s[x][y] = 1;
 	if (!y) return;
 	int xx = prevx[x][y];
 	int yy = prevy[x][y];
 	gogo(xx, yy);
 }
 
 bool increase()
 {
 	memset(d, oo, sizeof d);
 
 	for(int i = 0; i < W; i++)
 		if (!s[i][0])
 		{
 			d[i][0] = 0;
 			Q.push(i);
 			Q.push(0);
 		}
 
 	while(!Q.empty())
 	{
 		int x = Q.front(); Q.pop();
 		int y = Q.front(); Q.pop();
 		int dd = d[x][y] + 1;
 
 		go(x + 1, y, dd, x, y);
 		go(x - 1, y, dd, x, y);
 		go(x, y + 1, dd, x, y);
 		go(x, y - 1, dd, x, y);
 	}
 
 	for(int i = 0; i < W; i++)
 		if (d[i][H - 1] != oo)
 		{
 			gogo(i, H - 1);
 			return true;
 		}
 
 	return false;
 }
 
 int main()
 {
 	int nt;
 	scanf("%d", &nt);
 	for(int tt = 1; tt <= nt; tt++)
 	{
 		fprintf(stderr, "test = %d\n", tt);
 		printf("Case #%d: ", tt);
 
 		scanf("%d %d %d", &W, &H, &B);
 
 		memset(s, 0, sizeof s);
 
 		for(int i = 0; i < B; i++)
 		{
 			int x1, y1, x2, y2;
 			scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
 			for(int x = x1; x <= x2; x++)
 				for(int y = y1; y <= y2; y++)
 					s[x][y] = 1;
 		}
 
 		res = 0;
 		while(increase()) res++;
 
 		printf("%d\n", res);
 	}
 	return 0;
 }
