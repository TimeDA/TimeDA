/* 2014.5.31 Celicath */
 #include <stdio.h>
 #include <vector>
 #include <algorithm>
 #include <map>
 #include <stdint.h>
 
 int S[20000];
 
 int main()
 {
 	FILE* fin = fopen("input.txt", "r");
 	FILE* fout = fopen("output.txt", "w");
 
 	int T;
 
 	fscanf(fin, "%d", &T);
 
 	for (int c_n = 1; c_n <= T; c_n++)
 	{
 		int N, X;
 
 		fscanf(fin, "%d%d", &N, &X);
 
 		for (int i = 0; i < N; i++)
 		{
 			fscanf(fin, "%d", S + i);
 		}
 
 		std::sort(S, S + N);
 
 		int left = N;
 		int count = 0;
 		while (left > 0)
 		{
 			count++;
 			int now = S[--left];
 			if (left > 0)
 			{
 				int pos = 0;
 				for (; pos < left; pos++)
 				{
 					if (now + S[pos] > X)
 						break;
 				}
 				pos--;
 				if (pos >= 0)
 				{
 					for (int i = pos; i < left; i++)
 						S[i] = S[i+1];
 					left--;
 				}
 			}
 		}
 
 		fprintf(fout, "Case #%d: %d\n", c_n, count);
 		printf("Case #%d: %d\n", c_n, count);
 	}
 	return -0;
 }
