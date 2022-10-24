#include<stdio.h>
 
 #define MAX(a,b) (a)>(b)?(a):(b)
 #define MIN(a,b) (a)<(b)?(a):(b)
 
 int d[20000];
 int l[20000];
 int dp[20000];
 
 int main()
 {
 	int T;
 
 	FILE* fin = fopen("input.txt", "r");
 	FILE* fout = fopen("output.txt","w");
 
 	fscanf(fin, "%d\n", &T);
 
 	for(int i = 1; i <= T; i++)
 	{
 		int N;
 		fscanf(fin, "%d\n", &N);
 
 		for(int j = 0; j < N; j++)
 			fscanf(fin, "%d%d", d+j, l+j);
 
 		int last;
 		fscanf(fin, "%d", &last);
 
 		if((dp[0] = 2 * d[0]) >= last) goto good;
 
 		for(int j = 1; j < N; j++)
 		{
 			dp[j] = -1;
 			for(int k = 0; k < j; k++)
 			{
 				if(dp[k] >= d[j])
 				{
 					int res = MIN(d[j] - d[k], l[j]);
 					if(d[j] + res > dp[j]) dp[j] = d[j] + res;
 				}
 			}
 			if(dp[j] == -1) goto hell;
 			if(dp[j] >= last) goto good;
 		}
 		if(dp[N-1] < last) goto hell;
 
 		good: fprintf(fout,"Case #%d: YES\n", i); continue;
 		hell: fprintf(fout,"Case #%d: NO\n", i);
 	}
 	return 0;
 }
