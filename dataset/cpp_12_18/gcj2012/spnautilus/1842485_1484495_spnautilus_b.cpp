#include <stdio.h>
 #include <algorithm>
 
 using namespace std;
 
 #define maxn (1005)
 
 typedef pair <int, int> PII;
 
 int T;
 
 int N;
 int W, H;
 
 PII R[maxn];
 double xi[maxn];
 double yi[maxn];
 
 int main()
 {
 	int tt;
 	scanf("%d", &T);
 	for(tt = 1; tt <= T; ++tt)
 	{
 		int i, j;
 
 		scanf("%d %d %d", &N, &W, &H);
 		for(i = 0; i < N; ++i)
 		{
 			int a;
 			scanf("%d", &a);
 
 			R[i] = PII(a, i);
 		}
 
 		sort(R, R + N);
 
 		int y = 0;
 
 		for(i = 0; i < N; )
 		{
 			int rmax = 0;
 			int l = 0;
 			for(j = i; j < N; ++j)
 			{
 				if(j == i)
 				{
 					xi[R[j].second] = 0;
 					l = R[j].first;
 				}
 				else if(l + R[j].first <= W)
 				{
 					xi[R[j].second] = l + R[j].first;
 					l += 2 * R[j].first;
 				}
 				else
 					break;
 
 				rmax = R[j].first;
 			}
 
 			if(y == 0)
 			{
 				while(i < j)
 					yi[R[i++].second] = 0;
 				y = rmax;
 			}
 			else
 			{
 				y += rmax;
 				while(i < j)
 					yi[R[i++].second] = y;
 				y += rmax;
 			}
 		}
 
 		printf("Case #%d:", tt);
 
 		for(i = 0; i < N; ++i)
 			printf(" %.1lf %.1lf", xi[i], yi[i]);
 
 		putchar('\n');
 	}
 
 	return 0;
 }
