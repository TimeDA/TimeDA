#include<stdio.h>
 #include<stdlib.h>
 
 #define MAX(a,b) (a)>(b)?(a):(b)
 #define MIN(a,b) (a)<(b)?(a):(b)
 
 int rad[2000];
 int X[2000];
 int Y[2000];
 
 int dummy[2000];
 
 int N,W,L;
 
 int comparerad(const void* left, const void* right)
 {
 	return - rad[*((int*)left)] + rad[*((int*)right)];
 }
 
 int main()
 {
 	for(int i = 0; i < 2000; i++)
 		dummy[i] = i;
 
 	int T;
 
 	FILE* fin = fopen("input.txt", "r");
 	FILE* fout = fopen("output.txt","w");
 
 	fscanf(fin, "%d\n", &T);
 
 	// 簢  ص Ұ̴.
 	// ׷ϱ   ϴ  簢 ϰ,
 	// ū 簢 Ѵ.
 	// 0,0,  ̸鼭 ä Ѵ.
 	//     ִ.   ּҰ Ƶд.
 	
 	for(int i = 1; i <= T; i++)
 	{
 		fscanf(fin, "%d%d%d\n", &N, &W, &L);
 
 		int curX = 0;
 		int right = 1; //  ̴°(1)  ̴°(-1)
 
 		int llimit = 0; //  ּҰ
 
 		for(int j = 0; j < N; j++)
 			fscanf(fin, "%d", rad + j);
 		rad[N] = 0;
 
 		// ƮѴ.
 		qsort(dummy, N, sizeof(int), comparerad);
 
 		for(int j = 0; j < N; j++)
 		{
 			if(curX != 0 && curX != W)	// ܰ   ִ.
 			{
 				curX += right * rad[dummy[j]];
 				if(curX > W)
 				{
 					curX = W;
 					right = -1;
 				}
 				else if(curX < llimit)
 				{
 					curX = llimit;
 					right = 1;
 				}
 			}
 
 			X[dummy[j]] = curX;
 			Y[dummy[j]] = 0;
 			for(int k = 0; k < j; k++)
 			{
 				if(X[dummy[k]] + rad[dummy[k]] + rad[dummy[j]] > curX && X[dummy[k]] - rad[dummy[k]] - rad[dummy[j]] < curX)
 				{
 					Y[dummy[j]] = MAX(Y[dummy[j]], Y[dummy[k]] + rad[dummy[k]] + rad[dummy[j]]);
 				}
 			}
 			if(Y[dummy[j]] + rad[dummy[j]] > L)
 			{
 				llimit = rad[dummy[j]] + X[dummy[j]];
 			}
 			curX += right * rad[dummy[j]];
 			if(curX > W)
 			{
 				curX = W;
 				right = -1;
 			}
 			else if(curX < llimit)
 			{
 				curX = llimit;
 				right = 1;
 			}
 		}
 
 		fprintf(fout,"Case #%d:", i);
 		for(int j = 0; j < N; j++)
 			fprintf(fout, " %d %d", X[j], Y[j]);
 		fprintf(fout, "\n");
 	}
 	return 0;
 }
