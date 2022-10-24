/* 2017.4.15 Celicath */
 #include <stdio.h>
 #include <vector>
 #include <algorithm>
 #include <map>
 #include <set>
 #include <stdint.h>
 
 FILE* fin = fopen("input.txt", "r");
 FILE* fout = fopen("output.txt", "w");
 
 int R[100];
 int Q[100][100];
 int p[100];
 
 int min[100][100];
 int max[100][100];
 
 int main()
 {
 	int T;
 	fscanf(fin, "%d", &T);
 
 	for (int c_n = 1; c_n <= T; c_n++)
 	{
 		int N, P;
 		fscanf(fin, "%d%d", &N, &P);
 
 		for (int i = 0; i < N; i++)
 		{
 			fscanf(fin, "%d", &R[i]);
 			R[i];
 		}
 
 		for (int i = 0; i < N; i++)
 		{
 			for (int j = 0; j < P; j++)
 			{
 				fscanf(fin, "%d", &Q[i][j]);
 				Q[i][j] *= 10;
 			}
 			std::sort(Q[i], Q[i] + P);
 		}
 
 		int result = 0;
 
 		for (int i = 0; i < N; i++)
 		{
 			p[i] = 0;
 			for (int j = 0; j < P; j++)
 			{
 				max[i][j] = Q[i][j] / (R[i] * 9);
 				min[i][j] = (Q[i][j] - 1) / (R[i] * 11) + 1;
 			}
 		}
 		for (;;)
 		{
 			int kmin = 0;
 			int kmax = 99999999;
 
 			int minmaxp = -1;
 
 			for (int i = 0; i < N; i++)
 			{
 				if (p[i] >= P) goto hell;
 				if (min[i][p[i]] > kmin)
 					kmin = min[i][p[i]];
 				if (max[i][p[i]] < kmax)
 				{
 					kmax = max[i][p[i]];
 					minmaxp = i;
 				}
 			}
 			if (kmax < kmin)
 				p[minmaxp]++;
 			else
 			{
 				result++;
 				for (int i = 0; i < N; i++)
 					p[i]++;
 			}
 		}
 		hell:
 
 		fprintf(fout, "Case #%d: %d\n", c_n, result);
 		printf("Case #%d: %d\n", c_n, result);
 	}
 	return -0;
 }
