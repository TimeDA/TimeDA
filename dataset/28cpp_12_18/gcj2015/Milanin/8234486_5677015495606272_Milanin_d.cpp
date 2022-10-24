#define _CRT_SECURE_NO_WARNINGS
 #pragma comment(linker, "/STACK:100000000")
 #include <stdio.h>
 #include <vector>
 #include <string>
 #include <set>
 #include <map>
 #include <queue>
 #include <algorithm>
 #include <string.h>
 #include <math.h>
 #include <fstream>
 #include <iostream>
 #include <ctime>
 using namespace std;
 #define mod 1000000007
 #define N 7
 int m[N][N], r, c, di[]={-1, 1, 0, 0}, dj[]={0, 0, -1, 1};
 int w[1000][N][N], a;
 bool pos()
 {
 	int i, j, k;
 	for(i=0; i<r; i++)
 		for(j=0; j<c; j++)
 			if(m[i][j])
 			{
 				int t=0, z=0;
 				for(k=0; k<4; k++)
 				{
 					int ii=i+di[k];
 					int jj=(j+dj[k]+c)%c;
 					if(ii>=0 && ii<r)
 					{
 						if(m[ii][jj]==m[i][j]) t++;
 						if(m[ii][jj]==0) z++;
 					}
 				}
 				if(t>m[i][j] || t+z<m[i][j]) return 0;
 			}
 	return 1;
 }
 void rec(int i, int j)
 {
 	if(!pos()) return;
 	if(i==r)
 	{
 		int l;
 		for(l=0; l<a; l++)
 		{
 			int h;
 			for(h=0; h<c; h++)
 			{
 				int f=1;
 				for(i=0; i<r; i++)
 					for(j=0; j<c; f&=m[i][(j+h)%c]==w[l][i][j], j++);
 				if(f) break;
 			}
 			if(h<c) break;
 		}
 		if(l==a)
 		{
 			for(i=0; i<r; i++)
 				for(j=0; j<c; w[a][i][j]=m[i][j], j++);
 			a++;
 		}
 	}
 	else if(j==c) rec(i+1, 0);
 	else
 	{
 		for(m[i][j]=1; m[i][j]<=3; rec(i, j+1), m[i][j]++);
 		m[i][j]=0;
 	}
 }
 void solve()
 {
 	scanf("%d%d", &r, &c);
 	a=0;
 	rec(0, 0);
 	printf("%d\n", a);
 }
 int main()
 {
 	int tst;
 	scanf("%d", &tst);
 	for(int ts=1; ts<=tst; ts++)
 	{
 		printf("Case #%d: ", ts);
 		solve();
 	}
 	return 0;
 }