#include <cstdio>
 #include <vector>
 #include <string>
 #include <sstream>
 #include <set>
 #include <algorithm>
 #include <iostream>
 
 using namespace std;
 
 typedef long long LL;
 
 int a[1 << 7];
 
 int n, t, s, p;
 
 int main()
 {
 	freopen("B.in", "r", stdin);
 	freopen("output.txt", "w", stdout);
 	scanf("%d", &t);
 	for(int test = 1; test <= t; ++test)
 	{
 		scanf("%d%d%d", &n, &s, &p);
 		for(int i = 0; i < n; ++i)
 			scanf("%d", &a[i]);
 		sort(a, a + n);
 		int res = 0;
 		for(int i = 0; i < n; ++i)
 		{
 			if ((a[i] + 2) / 3 >= p)
 				++res;
 			else
 			{
 				if (a[i] >= 2 && a[i] % 3 == 0 || a[i] % 3 == 2)
 				{
 					if ((a[i] + 2) / 3 + 1 >= p && s > 0)
 					{
 						s--;
 						res++;
 					}
 				}
 			}
 		}
 		printf("Case #%d: %d\n", test, res);
 	}
 	return 0;
 }