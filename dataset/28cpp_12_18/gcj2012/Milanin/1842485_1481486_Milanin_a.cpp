#include <stdio.h>
 #include <algorithm>
 #include <set>
 #include <map>
 #include <vector>
 #include <string>
 #include <queue>
 #include <math.h>
 #define N 10010
 using namespace std;
 int m[N], h[N], d[N];
 int main()
 {
 	int ts, tst, i, j, n;
 	for(scanf("%d", &tst), ts=1; ts<=tst; ts++)
 	{
 		printf("Case #%d: ", ts);
 		for(scanf("%d", &n), i=0; i<n; scanf("%d%d", &m[i], &h[i]), i++);
 		scanf("%d", &m[i]);
 		h[i]=1;
 		for(i=0; i<=n; d[i]=0, i++);
 		for(d[0]=m[0], i=0; i<n; i++)
 			for(j=i+1; j<=n; j++)
 				if(d[i]>=m[j]-m[i]) d[j]=max(d[j], min(m[j]-m[i], h[j]));
 		if(d[n]) printf("YES\n");
 		else printf("NO\n");
 	}
 	return 0;
 }