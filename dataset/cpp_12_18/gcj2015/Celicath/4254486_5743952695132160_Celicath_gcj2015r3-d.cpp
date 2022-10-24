/* 2015.6.14 Celicath */
 #include <stdio.h>
 #include <vector>
 #include <algorithm>
 #include <map>
 #include <set>
 #include <stdint.h>
 
 int pascal[30][30];
 
 int main()
 {
 	pascal[0][0] = 1;
 	for (int i = 1; i <= 25; i++)
 	{
 		pascal[i][0] = pascal[i][i] = 1;
 		for (int j = 1; j < i; j++)
 			pascal[i][j] = pascal[i - 1][j - 1] + pascal[i - 1][j];
 	}
 
 	FILE* fin = fopen("input.txt", "r");
 	FILE* fout = fopen("output.txt", "w");
 
 	int T;
 
 	std::set<int> E;
 	std::map<int, int> F;
 	std::map<int, int> G;
 
 	fscanf(fin, "%d", &T);
 
 	for (int c_n = 1; c_n <= T; c_n++)
 	{
 		E.clear();
 		F.clear();
 		G.clear();
 
 		int P;
 		fscanf(fin, "%d\n", &P);
 
 		for (int i = 0; i < P; i++)
 		{
 			int x;
 			fscanf(fin, "%d", &x);
 			E.insert(x);
 		}
 		for (int e : E)
 		{
 			int x;
 			fscanf(fin, "%d", &x);
 			F.insert(std::make_pair(e, x));
 		}
 
 		for (int e : E)
 		{
 			int f = F[e];
 			if (f == 0) continue;
 
 			if (e == 0)
 			{
 				for (int x : E)
 					F[x] /= f;
 
 				while (f > 1)
 				{
 					f >>= 1;
 					G[0]++;
 				}
 			}
 			else
 			{
 				G[e] = f;
 				for (int x : E)
 				{
 					if (F[x] > 0)
 					{
 						for (int y = 1; y <= f; y++)
 						{
 							F[x + e * y] -= F[x] * pascal[f][y];
 						}
 					}
 				}
 			}
 		}
 
 		int result = 0;
 
 		fprintf(fout, "Case #%d:", c_n);
 		printf("Case #%d:", c_n);
 
 		for (auto a : G)
 		{
 			for (int i = 0; i < a.second; i++)
 			{
 				fprintf(fout, " %d", a.first);
 				printf(" %d", a.first);
 			}
 		}
 		fprintf(fout, "\n");
 		printf("\n");
 	}
 	return -0;
 }
