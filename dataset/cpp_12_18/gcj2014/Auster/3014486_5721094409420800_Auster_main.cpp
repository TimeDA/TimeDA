#include <iostream>
 #include <vector>
 #include <algorithm>
 #include <queue>
 #include <functional>
 #include <map>
 #include <set>
 #include <memory.h>
 
 using namespace std;
 
 typedef long long LL;
 
 const int N = 1 << 10;
 
 int T;
 
 int n;
 
 int a[1 << 10];
 int b[1 << 10];
 
 int main()
 {
 
 
 	freopen("input.txt", "r", stdin);
 	freopen("output.txt", "w", stdout);
 	scanf("%d", &T);
 	for(int I = 1; I <= T; ++I)
 	{
 		scanf("%d", &n);
 		for(int i = 0; i < n; ++i)
 			scanf("%d", &a[i]);
 		int res = (int)1e9;
 		for(int i = 0; i < 1 << n; ++i)
 		{
 			int pos = 0;
 			int cnt = 0;
 			for(int j = 0; j < n; ++j)
 			{
 				if (i & (1 << j))
 				{
 					b[pos++] = a[j];
 					cnt++;
 				}
 			}
 			for(int j = 0; j < n; ++j)
 				if (!(i & (1 << j)))
 					b[pos++] = a[j];
 			sort(b, b + cnt);
 			sort(b + cnt, b + n, greater<int>());
 			for(int j = 0; j < n; ++j)
 			{
 				for(int k = 0; k < n; ++k)
 					if (a[k] == b[j])
 					{
 						b[j] = k;
 						break;
 					}
 			}
 			int cur = 0;
 			for(int j = 0; j < n; ++j)
 				for(int k = 0; k < j; ++k)
 					if (b[k] > b[j])
 						++cur;
 			res = min(res, cur);
 		}
 		printf("Case #%d: %d\n", I, res);
 	}
 	return 0;
 }