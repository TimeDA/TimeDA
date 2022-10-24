#include <stdio.h>
 #include <algorithm>
 
 int d[10001];
 int l[10001];
 int v[10001];
 int maxlen[10001];
 
 int main()
 {
 	int n;
 	int T;
 	scanf("%d",&T);
 	for(int testcase = 1; testcase <= T; testcase ++)
 	{
 		scanf("%d",&n);
 		for(int i = 0; i < n; i ++)
 		{
 			scanf("%d%d",&d[i],&l[i]);
 			maxlen[i] = v[i] = 0;
 		}
 		scanf("%d",&d[n]); l[n] = 0;
 		maxlen[n] = v[n] = 0;
 		++n;
 
 		v[0] = 1;
 		maxlen[0] = d[0];
 		for(int cur = 0; cur < n; cur ++)
 		{
 			if(v[cur] == 0) continue;
 			for(int i = cur + 1; i < n; i ++)
 			{
 				if(d[i] - d[cur] <= maxlen[cur])
 				{
 					if(v[i] == 0 || maxlen[i] < std::min(d[i]-d[cur], l[i]))
 					{
 						v[i] = 1;
 						maxlen[i] = std::min(d[i]-d[cur], l[i]);
 					}
 				}
 			}
 		}
 
 		printf("Case #%d: %s\n", testcase, v[n-1] ? "YES" : "NO");
 	}
 	return 0;
 }