#include <algorithm>
 #include <stdio.h>
 #include <vector>
 #include <queue>
 #include <set>
 #include <map>
 using namespace std;
 #define N 10100
 int a[N];
 int main()
 {
 	int nts;
 	scanf("%d", &nts);
 	for(int ts=1; ts<=nts; ts++)
 	{
 		printf("Case #%d: ", ts);
 		int n, i, j, l, r, k;
 		scanf("%d", &n);
 		for(i=0; i<n; scanf("%d", &a[i]), i++);
 		k=0;
 		for(i=0; i<n; i++)
 		{
 			l=0;
 			r=0;
 			for(j=0; j<i; j++)
 				if(a[j]>a[i]) l++;
 			for(j=i+1; j<n; j++)
 				if(a[j]>a[i]) r++;
 			k+=min(l, r);
 		}
 		printf("%d\n", k);
 	}
 	return 0;
 }
