#pragma comment(linker, "/STACK:100000000")
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
using namespace std;
const int N=110;
char m[N][N];
int x[N], y[N];
void Solve()
{
	int r, c, h, v;
	scanf("%d%d%d%d", &r, &c, &h, &v);
	for(int i=0; i<r; scanf("%s", m[i]), i++);
	int k=0;
	for(int i=0; i<r; i++)
		for(int j=0; j<c; k+=m[i][j]=='@', j++);
	if(k%((h+1)*(v+1))!=0) { printf("IMPOSSIBLE\n"); return; }
	k/=(h+1)*(v+1);
	int nx=0, ny=0;
	int t=0;
	x[nx]=0;
	nx++;
	for(int i=0; i<r; i++)
	{
		for(int j=0; j<c; t+=m[i][j]=='@', j++);
		if(t<k*(v+1)) continue;
		if(t>k*(v+1)) { printf("IMPOSSIBLE\n"); return; }
		x[nx]=i+1;
		nx++;
		t=0;
	}
	t=0;
	y[ny]=0;
	ny++;
	for(int j=0; j<c; j++)
	{
		for(int i=0; i<r; t+=m[i][j]=='@', i++);
		if(t<k*(h+1)) continue;
		if(t>k*(h+1)) { printf("IMPOSSIBLE\n"); return; }
		y[ny]=j+1;
		ny++;
		t=0;
	}
	for(int i=0; i+1<nx; i++)
		for(int j=0; j+1<ny; j++)
		{
			int t=0;
			for(int ii=x[i]; ii<x[i+1]; ii++)
				for(int jj=y[j]; jj<y[j+1]; t+=m[ii][jj]=='@', jj++);
			if(t!=k) { printf("IMPOSSIBLE\n"); return; }
		}
	printf("POSSIBLE\n");
}
int main()
{
	int tst;
	scanf("%d", &tst);
	for(int t=1; t<=tst; t++)
	{
		printf("Case #%d: ", t);
		Solve();
	}
	return 0;
}