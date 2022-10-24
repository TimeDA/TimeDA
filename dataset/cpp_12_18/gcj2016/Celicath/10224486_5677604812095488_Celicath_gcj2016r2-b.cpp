/* 2016.5.29 Celicath */
 #include <stdio.h>
 #include <vector>
 #include <algorithm>
 #include <map>
 #include <set>
 #include <stdint.h>
 
 FILE* fin = fopen("input.txt", "r");
 FILE* fout = fopen("output.txt", "w");
 
 double pr[300];
 double DP[300][300];
 
 int N, K;
 
 double getpr(int i, int j)
 {
 	if (j <= i)
 		return pr[j - 1];
 	else return pr[N - K + (j - 1)];
 }
 
 int main()
 {
 	int T;
 
 	fscanf(fin, "%d", &T);
 
 	for (int c_n = 1; c_n <= T; c_n++)
 	{
 		fscanf(fin, "%d%d", &N, &K);
 
 		for (int i = 0; i < N; i++)
 		{
 			fscanf(fin, "%lf", pr + i);
 		}
 		std::sort(pr, pr + N);
 
 		double result = 0;
 
 		for (int i = 0; i <= K; i++)
 		{
 			DP[0][0] = 1;
 			for (int j = 1; j <= N; j++)
 				DP[0][j] = 0;
 
 			// ʿ i , ʿ K-i 
 			for (int j = 1; j <= K; j++)
 			{
 				double p = getpr(i, j);
 				for (int k = 0; k <= K; k++)
 				{
 					DP[j][k] = DP[j - 1][k] * (1 - p) + (k > 0 ? DP[j - 1][k - 1] * p : 0);
 				}
 			}
 			if (DP[K][K / 2] > result)
 			{
 				result = DP[K][K / 2];
 			}
 		}
 		fprintf(fout, "Case #%d: %f\n", c_n, result);
 		printf("Case #%d: %f\n", c_n, result);
 	}
 	return -0;
 }
