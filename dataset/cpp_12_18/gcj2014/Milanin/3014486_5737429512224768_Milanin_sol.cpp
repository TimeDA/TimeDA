#include <algorithm>
 #include <stdio.h>
 #include <vector>
 #include <queue>
 #include <set>
 #include <map>
 using namespace std;
 #define N 10010
 int a[N];
 int main()
 {
 	int nts;
 	scanf("%d", &nts);
 	for(int ts=1; ts<=nts; ts++)
 	{
 		printf("Case #%d: ", ts);
 		int n, s, i, j, k;
 		scanf("%d%d", &n, &s);
 		for(i=0; i<n; scanf("%d", &a[i]), i++);
 		sort(a, a+n);
 		for(i=0, j=n-1, k=0; i<=j; )
 			if(i==j) { k++; i++; }
 			else if(a[i]+a[j]<=s) { k++; i++; j--; }
 			else { k++; j--; }
 		printf("%d\n", k);
 	}
 	return 0;
 }
