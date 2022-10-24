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
 	freopen("A-small-attempt0.in" , "r" , stdin);
 	//freopen("input.txt" , "r" , stdin);
 	freopen("A-small-attempt0.out" , "w" , stdout);
 	int cas;
 	scanf("%d" , &cas);
 	for (int ca = 1; ca <= cas; ca ++)
 	{
 		printf("Case #%d: " , ca);
 		int n;
 		int d[10010] , l[10010];
 		int f[10010];
 		int D;
 		scanf("%d" , &n);
 		for (int i = 0; i < n; i ++) scanf("%d %d" , &d[i] , &l[i]);
 		scanf("%d" , &D);
 		f[0] = 0;
 		for (int i = 1; i < n; i ++)
 		{
 			f[i] = 0x7fffffff;
 			for (int j = 0; j < i; j ++)
 				if (d[j] - f[j] >= d[i] - d[j])
 				{
 					int s = min(d[i] - d[j] , l[i]);
 					f[i] = min(f[i] , d[i]-s);
 				}
 		}
 		int yes = 0;
 		for (int i = 0; i < n; i ++)
 			if (f[i] != 0x7fffffff && d[i] + d[i] - f[i] >= D) {yes = 1; break;}
 		if (yes) printf("YES\n");
 		else printf("NO\n");
 	}
 	return 0;
 }