#include <stdio.h>
 #include <algorithm>
 #include <set>
 #include <map>
 #include <vector>
 #include <string>
 #include <queue>
 #include <math.h>
 using namespace std;
 #define N 10
 int cnt(int n)
 {
 	int r=0;
 	for(; n; r+=n&1, n/=2);
 	return r;
 }
 int main()
 {
 	int i, j, n, p, k, l;
 	int ts, tst;
 	for(scanf("%d", &tst), ts=1; ts<=tst; ts++)
 	{
 		printf("Case #%d: ", ts);
 		scanf("%d%d", &n, &p);
 		for(k=(1<<n)-1; k>=0; k--)
 		{
 			for(j=k+1, l=0; (1<<l)<=j; l++); l--;
 			for(j=0; l<n; j=j*2+1, l++);
 			if((1<<n)-1-j<p) break;
 		}
 		for(j=n, i=0; i<p; j=min(j, cnt((1<<n)-1-i)), i++);
 		printf("%d %d\n", k, (1<<n)-(1<<j));
 	}
 	return 0;
 }