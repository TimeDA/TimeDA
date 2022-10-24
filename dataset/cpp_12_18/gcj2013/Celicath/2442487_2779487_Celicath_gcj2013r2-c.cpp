/* 2013.6.2 Yoshi-TS4 */
 
 #include <stdio.h>
 #include <stdlib.h>
 #include <limits>
 #include <algorithm>
 #include <vector>
 #include <map>
 
 int N, P;
 
 int left[3000];
 int left2[3000];
 int seq[3000];
 
 int main()
 {
 	FILE* fin = fopen("input.txt", "r");
 	FILE* fout = fopen("output.txt", "w");
 
 	int T;
 
 	fscanf(fin, "%d", &T);
 
 	for(int a = 1; a <= T; a++)
 	{
 		fscanf(fin, "%d", &N);
 
 		int temp;
 		for(int i = 0; i < N; i++)
 		{
 			left[i] = left2[i] = 0;
 		}
 		for(int i = 0; i < N; i++)
 		{
 			fscanf(fin, "%d", seq + i);
 			left[seq[i]]++;
 			left2[seq[i]]++;
 		}
 		for(int i = 0; i < N; i++)
 		{
 			fscanf(fin, "%d", &temp);
 		}
 
 
 		fprintf(fout, "Case #%d: ", a);
 		for(int i = 0; i < N; i++)
 		{
 
 			int res = left2[seq[i]]--;
 			for(int j = seq[i]-1; j >= 0; j--)
 				res += left[j];
 			fprintf(fout, "%d ", res);
 		}
 
 		fprintf(fout, "\n");
 	}
 
 	return -0;
 }
