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
const int N=110;
char m[N][N];
int a[N], b[N];
void Solve()
{
	int n;
	scanf("%d", &n);
	for(int i=0; i<n; scanf("%d", &a[i]), i++);
	if(a[0]==0 || a[n-1]==0) { printf("IMPOSSIBLE\n"); return; }
	a[0]--;
	a[n-1]--;
	int k=0;
	for(int i=0; i<n; i++)
		for(; a[i]--; b[k++]=i);
	for(int i=0; i<=n; m[i][n]=0, i++)
		for(int j=0; j<n; m[i][j]='.', j++);
	k=0;
	int r=1;
	for(int i=1; i<n-1; k++, i++)
		if(b[k]<i)
		{
			r=max(r, i-b[k]+1);
			for(int j=i; j>b[k]; m[i-j][j]='/', j--);
		}
		else if(b[k]>i)
		{
			r=max(r, b[k]-i+1);
			for(int j=i; j<b[k]; m[j-i][j]='\\', j++);
		}
	printf("%d\n", r);
	for(int i=0; i<r; printf("%s\n", m[i]), i++);
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
