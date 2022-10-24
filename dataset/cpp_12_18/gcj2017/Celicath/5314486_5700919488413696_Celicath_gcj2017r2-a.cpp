/* 2017.4.15 Celicath */
 #include <stdio.h>
 #include <vector>
 #include <algorithm>
 #include <map>
 #include <set>
 #include <stdint.h>
 
 FILE* fin = fopen("input.txt", "r");
 FILE* fout = fopen("output.txt", "w");
 
 int G[105];
 int r[10];
 
 int main()
 {
 	int T;
 	fscanf(fin, "%d", &T);
 
 	for (int c_n = 1; c_n <= T; c_n++)
 	{
 		int N, P;
 
 		fscanf(fin, "%d%d", &N, &P);
 
 		for (int i = 0; i < P; i++)
 			r[i] = 0;
 		for (int i = 0; i < N; i++)
 		{
 			fscanf(fin, "%d", G + i);
 			r[G[i] % P]++;
 		}
 
 		int result = 0;
 
 		if (P == 2) result = r[0] + (r[1] + 1) / 2;
 		else if (P == 3) result = r[0] + std::min(r[1], r[2]) + (std::max(r[1], r[2]) - std::min(r[1], r[2]) + 2) / 3;
 		else //if (P == 4)
 		{
 			result = r[0];
 
 			int temp = std::min(r[1], r[3]);
 			result += temp;
 			r[1] = r[1] + r[3] - 2 * temp;
 			result += (r[1] + 2 * r[2] + 3) / 4;
 		}
 		fprintf(fout, "Case #%d: %d\n", c_n, result);
 		printf("Case #%d: %d\n", c_n, result);
 	}
 	return -0;
 }
