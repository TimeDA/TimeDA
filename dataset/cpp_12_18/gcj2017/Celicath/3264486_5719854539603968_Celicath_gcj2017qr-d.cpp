/* 2017.4.8 Celicath */
 #include <stdio.h>
 #include <vector>
 #include <algorithm>
 #include <map>
 #include <set>
 #include <stdint.h>
 
 FILE* fin = fopen("input.txt", "r");
 FILE* fout = fopen("output.txt", "w");
 
 char grid[105][105];
 char grid_org[105][105];
 
 int count[210][4];
 
 void print_grid(int N)
 {
 	for (int i = 1; i <= N; i++)
 	{
 		for (int j = 1; j <= N; j++)
 			printf("%c ", grid[i][j]);
 		printf("\n");
 	}
 	printf("\n");
 }
 
 int max = 0;
 int score = 0;
 
 void clear_grid(int N)
 {
 	for (int i = 1; i <= N; i++)
 		for (int j = 1; j <= N; j++)
 			grid_org[i][j] = grid[i][j] = '.';
 	for (int i = 1; i <= N; i++)
 		count[i][0] = count[i][1] = 0;
 	for (int i = 2; i <= 2 * N; i++)
 		count[i][2] = count[i][3] = 0;
 	max = score = 0;
 }
 
 bool set_cell(int N, int x, int y, char c)
 {
 	bool result = true;
 	int diff_row = (c == 'x' || c == 'o') - (grid[x][y] == 'x' || grid[x][y] == 'o');
 	int diff_dai = (c == '+' || c == 'o') - (grid[x][y] == '+' || grid[x][y] == 'o');
 	int diff_sco = (c == 'x' || c == '+') + (c == 'o') * 2 - (grid[x][y] == 'x' || grid[x][y] == '+') - (grid[x][y] == 'o') * 2;
 	if ((count[x][0] += diff_row) > 1) result = false;
 	if ((count[y][1] += diff_row) > 1) result = false;
 	if ((count[x+y][2] += diff_dai) > 1) result = false;
 	if ((count[x + (N + 1) - y][3] += diff_dai) > 1) result = false;
 	grid[x][y] = c;
 	score += diff_sco;
 	return result;
 }
 
 void add_cell(int N, int x, int y, char c, std::map<int, char>& diff)
 {
 	if (grid[x][y] == c || grid[x][y] == 'o')
 		return;
 
 	char ch = grid[x][y] == '.' ? c : 'o';
 
 	char ori = grid[x][y];
 	if (set_cell(N, x, y, ch))
 		diff[x * 1000 + y] = ch;
 	else set_cell(N, x, y, ori);
 }
 
 bool check_cell(int N, int x, int y)
 {
 	return !(
 		grid[x][y] == '+' && (grid_org[x][y] == 'x' || grid_org[x][y] == 'o') ||
 		grid[x][y] == 'x' && (grid_org[x][y] == '+' || grid_org[x][y] == 'o') ||
 		grid[x][y] == '.' && grid_org[x][y] != '.');
 }
 
 // only for checking answer
 char s[5] = ".+xo";
 void backtrack(int N, int x, int y)
 {
 	for (int k = 0; k < 4; k++)
 	{
 		if (set_cell(N, x, y, s[k]) && check_cell(N, x, y))
 		{
 			if (x == N)
 			{
 				if (y == N)
 				{
 					if (score > max)
 					{
 						max = score;
 						printf("%d\n", score);
 						print_grid(N);
 					}
 				}
 				else backtrack(N, 1, y + 1);
 			}
 			else backtrack(N, x + 1, y);
 		}
 	}
 	set_cell(N, x, y, grid_org[x][y]);
 }
 
 int main()
 {
 	int T;
 	fscanf(fin, "%d", &T);
 
 	for (int c_n = 1; c_n <= T; c_n++)
 	{
 		int N, M;
 		fscanf(fin, "%d%d\n", &N, &M);
 
 		clear_grid(N);
 		for (int i = 0; i < M; i++)
 		{
 			char c;
 			int x, y;
 			fscanf(fin, "%c %d %d\n", &c, &x, &y);
 			grid_org[x][y] = c;
 			set_cell(N, x, y, c);
 		}
 		//print_grid(N);
 
 		std::map<int, char> diff;
 
 		for (int i = 1; i <= N; i++)
 		{
 			if (count[i][0] == 0)
 			{
 				for (int j = 1; j <= N; j++)
 					if (count[j][1] == 0)
 					{
 						add_cell(N, i, j, 'x', diff);
 						break;
 					}
 			}
 		}
 		for (int i = 0; i < N; i++)
 		{
 			add_cell(N, 1, N - i, '+', diff);
 			add_cell(N, N - i, 1, '+', diff);
 			add_cell(N, i + 1, N, '+', diff);
 			add_cell(N, N, i + 1, '+', diff);
 		}
 //		backtrack(N, 1, 1);
 //		print_grid(N);
 		fprintf(fout, "Case #%d: %d %d\n", c_n, score, diff.size());
 		printf("Case #%d: %d %d\n", c_n, score, diff.size());
 		for (auto a : diff)
 		{
 			fprintf(fout, "%c %d %d\n", a.second, a.first / 1000, a.first % 1000);
 			printf("%c %d %d\n", a.second, a.first / 1000, a.first % 1000);
 		}
 	}
 	return -0;
 }
