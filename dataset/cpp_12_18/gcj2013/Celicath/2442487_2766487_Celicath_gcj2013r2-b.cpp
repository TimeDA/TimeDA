/* 2013.6.2 Yoshi-TS4 */
 
 #include <stdio.h>
 #include <stdlib.h>
 #include <limits>
 #include <algorithm>
 #include <vector>
 #include <map>
 
 int N, P;
 
 long long mem1[100][100];
 long long mem2[100][100];
 long long mem3[100][100];
 long long mem4[100][100];
 
 int main()
 {
 	for(int i = 1; i <= 50; i++)
 	{
 		long long t = ((long long)1 << i) + 1;
 		for(int j = 0; j <= i; j++)
 		{
 			mem1[i][j] = t - ((long long)1 << (i-j));
 			mem2[i][j] = ((long long)1 << (j+1)) - 2;
 
 			mem3[i][j] = (long long)1 << j;
 			mem4[i][j] = t - ((long long)1 << (i-j)) - 1;
 		}
 		mem2[i][i] = t - 2;
 	}
 
 	FILE* fin = fopen("input.txt", "r");
 	FILE* fout = fopen("output.txt", "w");
 
 	int T;
 
 	fscanf(fin, "%d", &T);
 
 	for(int a = 1; a <= T; a++)
 	{
 		long long r1,r2;
 		fscanf(fin, "%d%lld", &N, &P);
 
 		for(r1 = 0; r1 < N; r1++)
 			if(mem1[N][r1+1] > P) break;
 		r1 = mem2[N][r1];
 
 		for(r2 = 0; r2 < N; r2++)
 			if(mem3[N][r2+1] > P) break;
 		r2 = mem4[N][r2];
 
 		fprintf(fout, "Case #%d: %lld %lld\n", a, r1, r2);
 	}
 
 	return -0;
 }
