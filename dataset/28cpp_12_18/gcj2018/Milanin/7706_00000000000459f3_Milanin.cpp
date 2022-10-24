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
const int N=510;
const int K=35;
short d[K][K][N][N];
void Solve()
{
	int a, b;
	scanf("%d%d", &a, &b);
	if(a<b) swap(a, b);
	for(int i=0; i*(i+1)/2<=a; i++)
		for(int j=0; j*(j+1)/2<=b; j++)
			for(int k=0; k<=a; k++)
				for(int l=0; l<=b; d[i][j][k][l]=-N, l++);
	for(int j=0; j*(j+1)/2<=b; d[0][j][0][j*(j+1)/2]=j, j++);
	int r=0;
	for(int i=0; i*(i+1)/2<=a; i++)
		for(int j=0; j*(j+1)/2<=b; j++)
			for(int k=0; k<=a; k++)
				for(int l=0; l<=b; l++)
					if(d[i][j][k][l]>=0)
					{
						int d0=d[i][j][k][l];
						r=max(r, d0);
						for(int t=0; t<=j && k+(i+1)*(t+1)<=a && t*(t+1)/2+l<=b; t++)
						{
							short& d1=d[i+1][t][k+(i+1)*(t+1)][t*(t+1)/2+l];
							d1=max((int)d1, d0+t+1);
						}
					}
	printf("%d\n", r);
}
int main()
{
	int ts;
	scanf("%d", &ts);
	for(int t=1; t<=ts; t++)
	{
		printf("Case #%d: ", t);
		Solve();
	}
	return 0;
}
