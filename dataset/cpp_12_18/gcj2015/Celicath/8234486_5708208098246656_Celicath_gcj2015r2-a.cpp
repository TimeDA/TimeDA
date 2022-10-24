/* 2015.5.30 Celicath */
 #include <stdio.h>
 #include <vector>
 #include <algorithm>
 #include <map>
 #include <set>
 #include <stdint.h>
 #include <iostream>
 
 char map[105][105];
 
 int main()
 {
 	FILE* fin = fopen("input.txt", "r");
 	FILE* fout = fopen("output.txt", "w");
 
 	int T;
 
 	fscanf(fin, "%d", &T);
 
 	for (int c_n = 1; c_n <= T; c_n++)
 	{
 		int R, C;
 		fscanf(fin, "%d%d", &R, &C);
 
 		for (int i = 0; i < R; i++)
 			fscanf(fin, "%s", map[i]);
 
 		int result = 0;
 		for (int i = 0; i < R; i++)
 			for (int j = 0; j < C; j++)
 			{
 				if (map[i][j] != '.')
 				{
 					int possible = 0;
 					// v
 					for (int k = i + 1; k < R; k++)
 						if (map[k][j] != '.')
 						{
 							possible++;
 							break;
 						}
 					// ^
 					for (int k = i - 1; k >= 0; k--)
 						if (map[k][j] != '.')
 						{
 							possible += 2;
 							break;
 						}
 					// >
 					for (int k = j + 1; k < C; k++)
 						if (map[i][k] != '.')
 						{
 							possible += 4;
 							break;
 						}
 					// <
 					for (int k = j - 1; k >= 0; k--)
 						if (map[i][k] != '.')
 						{
 							possible += 8;
 							break;
 						}
 
 					if (possible == 0)
 					{
 						result = -1;
 						goto hell;
 					}
 					if (!(
 						map[i][j] == 'v' && (possible & 1) ||
 						map[i][j] == '^' && (possible & 2) ||
 						map[i][j] == '>' && (possible & 4) ||
 						map[i][j] == '<' && (possible & 8)))
 						result++;
 				}
 			}
 
 	hell:
 		if (result == -1)
 		{
 			fprintf(fout, "Case #%d: IMPOSSIBLE\n", c_n);
 			printf("Case #%d: IMPOSSIBLE\n", c_n);
 		}
 		else
 		{
 			fprintf(fout, "Case #%d: %d\n", c_n, result);
 			printf("Case #%d: %d\n", c_n, result);
 		}
 	}
 	return -0;
 }
