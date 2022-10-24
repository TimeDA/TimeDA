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
 #include <iostream>
 #include <set>
 #include <queue>
 
 using namespace std;
 
 int nt;
 int a[10000];
 
 int main()
 {
 	int nt;
 	scanf("%d", &nt);
 	for(int tt = 1; tt <= nt; tt++)
 	{
 		fprintf(stderr, "test = %d\n", tt);
 		printf("Case #%d: ", tt);
 
 		int n, x;
 
 		scanf("%d %d", &n, &x);
 
 		int res = 0;
 
 		for(int i = 0; i < n; i++) scanf("%d", &a[i]);
 
 		sort(a, a + n, greater<int>());
 
 		int L = 0, R = n - 1;
 		while(L < R)
 		{
 			if (a[L] + a[R] <= x)
 			{
 				res++;
 				L++;
 				R--;
 			}
 			else
 			{
 				res++;
 				L++;
 			}
 		}
 
 		if (L == R) res++;
 
 		printf("%d\n", res);
 	}
 	return 0;
 }
