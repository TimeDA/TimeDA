/* 2017.4.15 Celicath */
 #include <stdio.h>
 #include <vector>
 #include <algorithm>
 #include <map>
 #include <set>
 #include <stdint.h>
 
 FILE* fin = fopen("input.txt", "r");
 FILE* fout = fopen("output.txt", "w");
 
 char board[30][30];
 
 int main()
 {
 	int T;
 	fscanf(fin, "%d", &T);
 
 	for (int c_n = 1; c_n <= T; c_n++)
 	{
 		int R, C;
 		fscanf(fin, "%d%d\n", &R, &C);
 
 		for (int i = 0; i < R; i++)
 		{
 			fscanf(fin, "%s", board[i]);
 		}
 
 		for (int i = 0; i < R; i++)
 		{
 			bool empty_now = true;
 			for (int j = 0; j < C; j++)
 			{
 				if (board[i][j] != '?')
 				{
 					if (empty_now)
 					{
 						for (int k = 0; k <= j; k++)
 							board[i][k] = board[i][j];
 						empty_now = false;
 					}
 				}
 				else if (!empty_now)
 					board[i][j] = board[i][j - 1];
 			}
 			if (empty_now && i > 0)
 				for (int j = 0; j < C; j++)
 					board[i][j] = board[i - 1][j];
 		}
 
 		for (int i = R - 1; i >= 0; i--)
 		{
 			for (int j = 0; j < C; j++)
 				if (board[i][j] == '?')
 					board[i][j] = board[i + 1][j];
 		}
 
 		fprintf(fout, "Case #%d:\n", c_n);
 		printf("Case #%d:\n", c_n);
 
 		for (int i = 0; i < R; i++)
 		{
 			fprintf(fout, "%s\n", board[i]);
 			printf("%s\n", board[i]);
 		}
 	}
 	return -0;
 }
