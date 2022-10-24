/* 2014.5.31 Celicath */
 #include <stdio.h>
 #include <vector>
 #include <algorithm>
 #include <map>
 #include <stdint.h>
 
 int A[2000];
 int B[2000];
 int C[2000];
 
 int swap_B[2000];
 int swap_C[2000];
 
 int main()
 {
 	FILE* fin = fopen("input.txt", "r");
 	FILE* fout = fopen("output.txt", "w");
 
 	int T;
 
 	fscanf(fin, "%d", &T);
 
 	for (int c_n = 1; c_n <= T; c_n++)
 	{
 		int N;
 
 		fscanf(fin, "%d", &N);
 
 		for (int i = 0; i < N; i++)
 		{
 			fscanf(fin, "%d", A + i);
 			B[i] = C[i] = A[i];
 		}
 
 		int count = 0;
 		// do insertion sort
 		for (int i = 0; i < N; i++)
 		{
 			int temp = B[i];
 			int pos;
 			for (pos = i; pos > 0; pos--)
 			{
 				if (B[pos - 1] < temp)
 					break;
 				B[pos] = B[pos - 1];
 				count++;
 			}
 			B[pos] = temp;
 			swap_B[i] = count;
 		}
 		count = 0;
 		// do insertion sort
 		for (int i = N - 1; i >= 0; i--)
 		{
 			int temp = C[i];
 			int pos;
 			for (pos = i; pos < N - 1; pos++)
 			{
 				if (C[pos + 1] < temp)
 					break;
 				C[pos] = C[pos + 1];
 				count++;
 			}
 			C[pos] = temp;
 			swap_C[i] = count;
 		}
 		swap_C[N] = 0;
 
 		int min = swap_C[0];
 		for (int i = 0; i < N; i++)
 		{
 			if (min > swap_B[i] + swap_C[i + 1])
 				min = swap_B[i] + swap_C[i + 1];
 		}
 
 		fprintf(fout, "Case #%d: %d\n", c_n, min);
 		printf("Case #%d: %d\n", c_n, min);
 	}
 	return -0;
 }
