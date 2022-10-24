/* 2013.4.13 Yoshi-TS4 */
 
 #include <stdio.h>
 
 char line[6][6];
 
 bool rowcheck(int row, char team)
 {
 	for(int i = 0; i < 4; i++)
 	{
 		if(line[row][i] != team && line[row][i] != 'T')
 			return false;
 	}
 	return true;
 }
 
 bool colcheck(int col, char team)
 {
 	for(int i = 0; i < 4; i++)
 	{
 		if(line[i][col] != team && line[i][col] != 'T')
 			return false;
 	}
 	return true;
 }
 
 bool diagcheck(int dir, char team)
 {
 	for(int i = 0; i < 4; i++)
 	{
 		int j = dir ? i : 3 - i;
 		if(line[i][j] != team && line[i][j] != 'T')
 			return false;
 	}
 	return true;
 }
 
 bool isdot()
 {
 	for(int i = 0; i < 4; i++)
 		for(int j = 0; j < 4; j++)
 			if(line[i][j] == '.') return true;
 
 	return false;
 }
 
 int main()
 {
 	FILE* fin = fopen("input.txt", "r");
 	FILE* fout = fopen("output.txt", "w");
 
 	int T;
 
 	fscanf(fin, "%d", &T);
 
 	for(int a = 1; a <= T; a++)
 	{
 		for(int i = 0; i < 4; i++)
 		{
 			fscanf(fin, "%s", line[i]);
 		}
 		bool Xwon = false;
 		bool Owon = false;
 		for(int i = 0; i < 4; i++)
 		{
 			Xwon |= rowcheck(i, 'X');
 			Xwon |= colcheck(i, 'X');
 			Owon |= rowcheck(i, 'O');
 			Owon |= colcheck(i, 'O');
 		}
 		for(int i = 0; i < 2; i++)
 		{
 			Xwon |= diagcheck(i, 'X');
 			Owon |= diagcheck(i, 'O');
 		}
 
 		if(Xwon && Owon)
 		{
 			printf("??\n");
 			fprintf(fout, "Case #%d: Draw\n", a);
 		}
 		else if(Xwon)
 			fprintf(fout, "Case #%d: X won\n", a);
 		else if(Owon)
 			fprintf(fout, "Case #%d: O won\n", a);
 		else if(isdot())
 			fprintf(fout, "Case #%d: Game has not completed\n", a);
 		else
 			fprintf(fout, "Case #%d: Draw\n", a);
 	}
 
 	return -0;
 }
