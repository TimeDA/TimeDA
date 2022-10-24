/* 2015.6.13-14 Celicath */
 #include <stdio.h>
 #include <vector>
 #include <algorithm>
 #include <map>
 #include <set>
 #include <stdint.h>
 
 int P[1000];
 int S[1000];
 
 int main()
 {
 	FILE* fin = fopen("input.txt", "r");
 	FILE* fout = fopen("output.txt", "w");
 
 	int T;
 
 	fscanf(fin, "%d", &T);
 
 	for (int c_n = 1; c_n <= T; c_n++)
 	{
 		int Y, N;
 		fscanf(fin, "%d%d\n", &Y, &N);
 
 		for (int i = 0; i < N; i++)
 			fscanf(fin, "%d", P + i);
 		for (int i = 0; i < N; i++)
 			fscanf(fin, "%d", S + i);
 
 		double min = 0, max = 0;
 
 		for (int i = 0; i < N; i++)
 		{
 			double t = (double)std::abs(P[i]) / (Y - S[i]);
 
 			if (P[i] < 0)
 			{
 				if (min < t)
 					min = t;
 			}
 			else
 			{
 				if (max < t)
 					max = t;
 			}
 		}
 
 		double minmax = min, maxmin = max;
 		for (int i = 0; i < N; i++)
 		{
 			if (P[i] < 0)
 			{
 				double t = (-P[i] + (max * (Y + S[i]))) / (Y - S[i]) + max;
 				if (maxmin < t)
 					maxmin = t;
 			}
 			else
 			{
 				double t = (P[i] + (min * (Y + S[i]))) / (Y - S[i]) + min;
 				if (minmax < t)
 					minmax = t;
 			}
 		}
 
 		double result = minmax > maxmin ? maxmin : minmax;
 
 		fprintf(fout, "Case #%d: %f\n", c_n, result);
 		printf("Case #%d: %f\n", c_n, result);
 	}
 	return -0;
 }
