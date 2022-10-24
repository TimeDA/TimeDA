#include <stdio.h>
 #include <algorithm>
 
 int n;
 int dat[10000];
 int ans[10000];
 
 int rec(int a, int b)
 {
 	if(a == n-1)return 1;
 	if(a >= b) return 1;
 	if(dat[a] > b) return 0;
 	if(rec(dat[a], b) == 0) return 0;
 	ans[dat[a]] = ans[dat[a]];
 	long long maxVal = ans[a];
 	for(int i = dat[a] + 1; i < n; i ++)
 	{
 		if(ans[i] <= ans[dat[a]]) continue;
 		if(maxVal > ans[i] - ((ans[i] - ans[dat[a]]) * (long long)(i-a) + i - dat[a] - 1) / (i-dat[a]) ) {
 			maxVal = ans[i] - ((ans[i] - ans[dat[a]]) * (long long)(i-a) + i - dat[a] - 1) / (i-dat[a]);
 		}
 	}
 	if(maxVal < 0)
 		return 0;
 	ans[a] = maxVal;
 	for(int i = a + 1; i < dat[a]; i ++)
 	{
 		ans[i] = std::min<long long>(ans[i], ans[a] + ((ans[dat[a]] - ans[a]) * (long long )(i - a) + dat[a] - a - 1) / (dat[a] - a) - 1 );
 	}
 	if(rec(a + 1, dat[a]) == 0) return 0;
 
 	return 1;
 }
 
 int main()
 {
 	int T;
 	scanf("%d",&T);
 	for(int testcase = 1; testcase <= T; testcase ++)
 	{
 		scanf("%d",&n);
 		for(int i = 0;i < n - 1;i ++) {
 			scanf("%d",&dat[i]);
 			dat[i] --;
 		}
 		for(int i = 0; i < n; i ++) {
 			ans[i] = 1000000000;
 		}
 		if(rec(0,n) == 0)
 		{
 			printf("Case #%d: Impossible\n",testcase);
 		}
 		else
 		{
 			for(int i = 0; i < n - 1; i ++)
 			{
 				int maxIndex = -1;
 				double maxSee = -1e60;
 				for(int j = i + 1; j < n; j ++)
 				{
 					double curSee = (ans[j] - ans[i]) / (double)(j - i);
 					if(maxSee < curSee - 1e-9)
 					{
 						maxSee = curSee;
 						maxIndex = j;
 					}
 				}
 				if(maxIndex != dat[i]) 
 				{
 					fprintf(stderr,"Error! %d, %d, %d\n", testcase, i, maxIndex);
 
 					maxIndex = maxIndex;
 				}
 			}
 			printf("Case #%d:",testcase);
 			for(int i = 0;i < n;i ++) {
 				printf(" %d", ans[i]);
 			}
 			printf("\n");
 		}
 	}
 	return 0;
 }