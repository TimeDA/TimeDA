/* 2016.5.28 Celicath */
 #include <stdio.h>
 #include <vector>
 #include <algorithm>
 #include <map>
 #include <set>
 #include <stdint.h>
 
 FILE* fin = fopen("input.txt", "r");
 FILE* fout = fopen("output.txt", "w");
 
 char line[5000];
 int p;
 
 void Go(char ch, int level)
 {
 	if (level == 1)
 	{
 		switch (ch)
 		{
 		case 'S':
 			line[p++] = 'P';
 			line[p++] = 'S';
 			break;
 		case 'P':
 			line[p++] = 'P';
 			line[p++] = 'R';
 			break;
 		case 'R':
 			line[p++] = 'R';
 			line[p++] = 'S';
 			break;
 		}
 	}
 	else
 	{
 		switch (ch)
 		{
 		case 'S':
 			Go('P', level - 1);
 			Go('S', level - 1);
 			break;
 		case 'P':
 			Go('P', level - 1);
 			Go('R', level - 1);
 			break;
 		case 'R':
 			Go('R', level - 1);
 			Go('S', level - 1);
 			break;
 		}
 	}
 }
 void Merge(int level, int s = 1)
 {
 	if (s > p)
 		return;
 	for (int i = 0; i < p / s / 2; i++)
 	{
 		bool rev = false;
 		for (int j = 0; j < s; j++)
 		{
 			if (line[2 * i * s + j] > line[(2 * i + 1) * s + j])
 			{
 				rev = true;
 				break;
 			}
 			else if (line[2 * i * s + j] < line[(2 * i + 1) * s + j])
 			{
 				rev = false;
 				break;
 			}
 		}
 		if (rev)
 		{
 			for (int j = 0; j < s; j++)
 			{
 				char sw = line[i * s + j];
 				line[2 * i * s + j] = line[(2 * i + 1) * s + j];
 				line[(2 * i + 1) * s + j] = sw;
 			}
 		}
 	}
 	Merge(level + 1, s * 2);
 }
 
 int main()
 {
 
 	int T;
 
 	fscanf(fin, "%d", &T);
 
 
 	for (int c_n = 1; c_n <= T; c_n++)
 	{
 		int N, FR, FP, FS;
 		fscanf(fin, "%d%d%d%d", &N, &FR, &FP, &FS);
 
 		int R = FR;
 		int P = FP;
 		int S = FS;
 		for (int i = 0; i < N; i++)
 		{
 			int mid = (R + P + S) / 2;
 			int R2 = mid - P;
 			int P2 = mid - S;
 			int S2 = mid - R;
 			if (R2 < 0 || P2 < 0 || S2 < 0)
 				goto hell;
 			R = R2;
 			P = P2;
 			S = S2;
 		}
 
 		p = 0;
 		Go(R ? 'R' : S ? 'S' : 'P', N);
 		Merge(0);
 		line[p] = '\0';
 
 
 		fprintf(fout, "Case #%d: %s\n", c_n, line);
 		printf("Case #%d: %s\n", c_n, line);
 		continue;
 	hell:
 		fprintf(fout, "Case #%d: IMPOSSIBLE\n", c_n);
 		printf("Case #%d: IMPOSSIBLE\n", c_n);
 	}
 	return -0;
 }
