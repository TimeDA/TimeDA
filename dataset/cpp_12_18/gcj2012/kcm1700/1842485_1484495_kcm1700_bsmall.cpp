#include <stdio.h>
 #include <math.h>
 #include <numeric>
 #include <functional>
 #include <algorithm>
 
 using namespace std;
 
 int n;
 int dat[1024];
 double x[1024];
 double y[1024];
 
 int main()
 {
 	int T;
 	scanf("%d",&T);
 	for(int testcase = 1; testcase <= T; testcase++)
 	{
 		int W,L;
 		scanf("%d%d%d",&n,&W,&L);
 		for(int i = 0;i < n; i++)
 		{
 			scanf("%d",&dat[i]);
 		}
 		
 		bool finished = false;
 		do 
 		{
 			finished = true;
 			for(int i = 0; i < n;i ++)
 			{
 				int failCount;
 				for(failCount = 0; failCount < 100; failCount ++)
 				{
 					x[i] = (double) (rand() * (RAND_MAX + 1) + rand()) / (double)((RAND_MAX + 1) * (RAND_MAX + 1)) * W;
 					y[i] = (double) (rand() * (RAND_MAX + 1) + rand()) / (double)((RAND_MAX + 1) * (RAND_MAX + 1)) * L;
 
 					int fail = 0;
 					for(int j = 0;j < i && fail == 0; j ++) 
 					{
 						if(hypot(x[i] - x[j], y[i] - y[j]) < dat[i] + dat[j] + 1e-5)
 						{
 							fail = 1;
 						}
 					}
 					if(fail == 0) break;
 				}
 				if(failCount == 100) {
 					finished = false;
 					break;
 				}
 			}
 		} while (!finished);
 		printf("Case #%d:", testcase);
 		for(int i = 0;i < n; i ++)
 		{
 			printf(" %.10f %.10f", x[i], y[i]);
 		}
 		printf("\n");
 	}
 	return 0;
 }