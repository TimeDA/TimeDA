#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:100000000")
#include <stdio.h>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <queue>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <fstream>
#include <iostream>
#include <ctime>
using namespace std;

const int N=50;
char u[N][N];
int y;
void proc(int a, int& i, int& j)
{
	i+=rand()%3-1;
	j+=rand()%3-1;
	if(!u[i][j]) y++;
	if(y==a) { i=-1; j=-1; }
}
void run()
{
	int a;
	scanf("%d", &a);
	y=0;
	for(int i=0; i<N; i++)
		for(int j=0; j<N; u[i][j]=0, j++);
	int r, c;
	if(a==20) { r=4; c=5; }
	else { r=14; c=15; }
	for(; ; )
	{
		int bi, bj, bx=10;
		for(int i=1; i<r-1; i++)
			for(int j=1; j<c-1; j++)
			{
				int x=0;
				for(int ii=i-1; ii<=i+1; ii++)
					for(int jj=j-1; jj<=j+1; x+=u[ii][jj], jj++);
				if(x<bx) { bx=x; bi=i; bj=j; }
			}
		//proc(a, bi, bj);
		printf("%d %d\n", bi+1, bj+1);
		fflush(stdout);
		scanf("%d%d", &bi, &bj); bi--; bj--;
		if(bi==-1 && bj==-1) break;
		u[bi][bj]=1;
	}
}
int main()
{
	int tst;
	scanf("%d", &tst);
	for(int t=1; t<=tst; t++)
	{
		run();
	}
    return 0;
}
