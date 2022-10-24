#include <cstdio>
 #include <cstring>
 #include <vector>
 #include <algorithm>
 #include <cassert>
 #include <set>
 
 using namespace std;
 
 int n;
 int nt, W, H;
 int r[1000];
 int o[1000];
 int rx[1000], ry[1000];
 
 bool cmp(int i, int j)
 {
 	return r[i] > r[j];
 }
 
 bool goWL()
 {
 	int i = 0;
 	int x = 0, y = 0;
 	int nextX = -1, nextY = 0;
 
 	int prevX = -1000000000;
 	int prevY = -1000000000;
 
 	while(i < n)
 	{
 		int k = o[i];
 
 		x = prevX + r[k]; if (x < 0) x = 0;
 		y = prevY  + r[k]; if (y < 0) y = 0;
 
 		if (x > W || y > H) return false;
 
 		rx[k] = x;
 		ry[k] = y;
 
 		nextX = x + r[k];
 		prevY = y + r[k];
 
 		i++;
 		while(i < n)
 		{
 			k = o[i];
 
 			y = prevY + r[k];
 			if (y > H) break;
 
 			nextY = y + r[k];
 
 			x = prevX + r[k]; if (x < 0) x = 0;
 
 			while(1)
 			{
 				rx[k] = x;
 				ry[k] = y;
 				assert(x >= 0 && y >= 0 && x <= W && y <= H);
 				x += r[k];
 				i++;
 
 				if (i == n) break;
 
 				k = o[i];
 				x += r[k];
 				if (x > W) break;
 				if (x + r[k] > nextX) break;
 			}
 
 			prevY = nextY;
 		}
 
 		prevX = nextX;
 		prevY = -1000000000;
 	}
 
 	for(int i = 0; i < n; i++) printf(" %d %d", rx[i], ry[i]);
 	puts("");
 
 	return true;
 }
 
 void goLW()
 {
 	puts("NOOO!!");
 }
 
 int main()
 {
 	scanf("%d", &nt);
 	
 	for(int tt = 1; tt <= nt; tt++)
 	{	
 		printf("Case #%d:", tt);
 		
 		scanf("%d %d %d", &n, &W, &H);
 
 		for(int i = 0; i < n; i++)
 		{
 			scanf("%d", &r[i]);
 			o[i] = i;
 		}
 
 		sort(o, o + n, cmp);
 		
 		if (goWL()) continue;
 		goLW();
 	}
 	
 	return 0;
 }
