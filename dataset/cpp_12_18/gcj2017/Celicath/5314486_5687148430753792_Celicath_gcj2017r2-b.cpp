/* 2017.5.13 Celicath */
 #include <stdio.h>
 #include <vector>
 #include <algorithm>
 #include <map>
 #include <set>
 #include <stdint.h>
 
 FILE* fin = fopen("input.txt", "r");
 FILE* fout = fopen("output.txt", "w");
 
 // Customer's # of tickets
 int Cs[2000];
 // Seat's # of tickets
 int Ss[2000];
 // Accumulative Seat's # of tickets
 int ASs[2000];
 
 int main()
 {
 	int T;
 	fscanf(fin, "%d", &T);
 
 	Cs[0] = 0;
 	for (int c_n = 1; c_n <= T; c_n++)
 	{
 		int N, C, M;
 
 		fscanf(fin, "%d%d%d", &N, &C, &M);
 
 
 		for (int i = 1; i <= C; i++)
 			Cs[i] = 0;
 		for (int i = 1; i <= N; i++)
 			Ss[i] = 0;
 		for (int i = 0; i < M; i++)
 		{
 			int P, B;
 			fscanf(fin, "%d%d", &P, &B);
 			Ss[P]++;
 			Cs[B]++;
 		}
 
 		for (int i = 1; i <= N; i++)
 			ASs[i] = ASs[i - 1] + Ss[i];
 
 		int y = 1;
 		for (int i = 1; i <= N; i++)
 			y = std::max(y, (Ss[i] + i - 1) / i);
 		for (int i = 1; i <= C; i++)
 			y = std::max(y, Cs[i]);
 		int z = 0;
 		for (int i = N; i >= 1; i--)
 		{
 			if (Ss[i] > y)
 				z += Ss[i] - y;
 		}
 		fprintf(fout, "Case #%d: %d %d\n", c_n, y, z);
 		printf("Case #%d: %d %d\n", c_n, y, z);
 	}
 	return -0;
 }
