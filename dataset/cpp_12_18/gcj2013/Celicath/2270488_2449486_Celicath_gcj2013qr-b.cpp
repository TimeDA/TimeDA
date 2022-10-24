/* 2013.4.13 Yoshi-TS4 */
 
 #include <stdio.h>
 #include <Windows.h>
 
 int target[200][200];
 
 int maxrow[200];
 int maxcol[200];
 
 int main()
 {
 	FILE* fin = fopen("input.txt", "r");
 	FILE* fout = fopen("output.txt", "w");
 
 	int T, N, M;
 
 	fscanf(fin, "%d", &T);
 
 	for(int a = 1; a <= T; a++)
 	{
 		fscanf(fin, "%d%d", &N, &M);
 
 		for(int i = 0; i < N; i++)
 			maxrow[i] = 0;
 		for(int i = 0; i < M; i++)
 			maxcol[i] = 0;
 
 		for(int i = 0; i < N; i++)
 			for(int j = 0; j < M; j++)
 			{
 				fscanf(fin, "%d", &target[i][j]);
 				if(maxrow[i] < target[i][j]) maxrow[i] = target[i][j];
 				if(maxcol[j] < target[i][j]) maxcol[j] = target[i][j];
 			}
 
 		fprintf(fout, "Case #%d: ", a);
 
 		for(int i = 0; i < N; i++)
 			for(int j = 0; j < M; j++)
 			{
 				if(target[i][j] != min(maxrow[i], maxcol[j]))
 					goto hell;
 			}
 		fprintf(fout, "YES\n");
 		continue;
 hell:				
 		fprintf(fout, "NO\n");
 	}
 
 	return -0;
 }
