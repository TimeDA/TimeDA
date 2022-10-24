/* 2015.6.13 Celicath */
 #include <stdio.h>
 #include <vector>
 #include <algorithm>
 #include <map>
 #include <set>
 #include <stdint.h>
 
 int sum[1500];
 int max[150];
 int min[150];
 int cur[150];
 
 int main()
 {
 	FILE* fin = fopen("input.txt", "r");
 	FILE* fout = fopen("output.txt", "w");
 
 	int T;
 
 	fscanf(fin, "%d", &T);
 
 	for (int c_n = 1; c_n <= T; c_n++)
 	{
 		int N, K;
 		fscanf(fin, "%d%d\n", &N, &K);
 
 		for (int i = 0; i < K; i++)
 		{
 			max[i] = min[i] = cur[i] = 0;
 		}
 
 		for (int i = 0; i <= N - K; i++)
 		{
 			fscanf(fin, "%d", sum + i);
 			if (i > 0)
 			{
 				int delta = sum[i] - sum[i - 1];
 				int pos = i%K;
 				cur[pos] += delta;
 				if (cur[pos] > max[pos])
 					max[pos] = cur[pos];
 				if (cur[pos] < min[pos])
 					min[pos] = cur[pos];
 			}
 		}
 
 		int osum = sum[0];
 		int maxx = 0;
 		for (int i = 0; i < K; i++)
 		{
 			max[i] -= min[i];
 			osum += min[i];
 			if (maxx < max[i])
 				maxx = max[i];
 		}
 		int avail = 0;
 		for (int i = 0; i < K; i++)
 			avail += maxx - max[i];
 		osum %= K;
 		if (osum < 0)
 			osum += K;
 
 		int result = (osum > avail ? maxx + 1 : maxx);
 
 		fprintf(fout, "Case #%d: %d\n", c_n, result);
 		printf("Case #%d: %d\n", c_n, result);
 	}
 	return -0;
 }
