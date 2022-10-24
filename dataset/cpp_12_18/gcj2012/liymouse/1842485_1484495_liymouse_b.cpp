#include <algorithm>
 #include <iostream>
 #include <sstream>
 #include <string>
 #include <vector>
 #include <queue>
 #include <set>
 #include <map>
 #include <cstdio>
 #include <cstdlib>
 #include <cctype>
 #include <cmath>
 #include <numeric>
 #include <cstring>
 
 typedef long long i64d;
 
 using namespace std;
 
 int main()
 {
 	freopen("B-small-attempt2.in" , "r" , stdin);
 	//freopen("input.txt" , "r" , stdin);
 	freopen("B-small-attempt2.out" , "w" , stdout);
 	int cas;
 	scanf("%d" , &cas);
 	for (int ca = 1; ca <= cas; ca ++)
 	{
 		printf("Case #%d:" , ca);
 		int n , w , l;
 		scanf("%d %d %d" , &n , &w , &l);
 		int r[1010] , tmp[1010];
 		int x[1010] , y[1010];
 		for (int i = 0; i < n; i ++) {scanf("%d" , &r[i]); tmp[i] = r[i];}
 		sort(r , r + n);
 		x[0] = y[0] = 0;
 		for (int i = 1; i < n; i ++)
 		{
 			if (y[i-1]+r[i-1] + r[i] > l) y[i] = 0;
 			else y[i] = y[i-1]+r[i-1] + r[i];
 			int a = y[i] - r[i];
 			int b = y[i] + r[i];
 			int m = -r[i];
 			for (int j = 0; j < i; j ++)
 			{
 				if ((y[j]-r[j] < a && a < y[j] + r[j]) || (y[j]-r[j] < b && b < y[j] + r[j]) ||
 					(a < y[j] - r[j] && y[j]-r[j] < b) || (a < y[j]+r[j] && y[j] + r[j] < b))
 				{
 					m = max(m , x[j] + r[j]);
 				}
 			}
 			x[i] = m + r[i];
 		}
 		int ok = 1;
 		for (int i = 0; i < n; i ++)
 			if (x[i] > w || y[i] > l) {ok = 0; break;}
 		if (ok)
 		{
 			int check[1010] = {0};
 			for (int i = 0; i < n; i ++)
 			{
 				int tt = 0;
 				for (int j = 0; j < n; j ++)
 					if (check[j] == 0 && tmp[i] == r[j]) {tt = j; break;}
 				check[tt] = 1;
 				printf(" %d %d" , x[tt] , y[tt]);
 			}
 			//for (int i = 0; i < n; i ++) printf(" %d %d" , x[i] , y[i]);
 		}
 		printf("\n");
 	}
 	return 0;
 }