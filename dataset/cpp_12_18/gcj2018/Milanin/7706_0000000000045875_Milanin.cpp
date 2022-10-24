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
template <int N>
class Hng
{
public:
	int n, i, j;
	int a[N+1][N+1], r;
	int p[N+1];
	Hng() {}
	int hng()
	{
		int M=1000000000;
		char f[N+1];
		int w[N+1];
		int mv[N+1], u[N+1], v[N+1];
		for(i=0; i<=n; u[i]=0, v[i]=0, p[i]=0, i++);
		for(i=1; i<=n; i++)
		{
			p[0]=i;
			int j0=0;
			for(j=0; j<=n; mv[j]=M, f[j]=0, j++);
			for(; ; )
			{
				f[j0]=1;
				int i0=p[j0], j1;
				int d=M;
				for(j=1; j<=n; j++)
					if(!f[j])
					{
						int c=a[i0][j]-u[i0]-v[j];
						if(c<mv[j]) { mv[j]=c; w[j]=j0; }
						if(mv[j]<d) { d=mv[j]; j1=j; }
					}
				for(j=0; j<=n; j++)
					if(f[j]) { u[p[j]]+=d; v[j]-=d; }
					else mv[j]-=d;
				j0=j1;
				if(!p[j0]) break;
			}
			for(; ; )
			{
				int j1=w[j0];
				p[j0]=p[j1];
				j0=j1;
				if(!j0) break;
			}
		}
        for(r=0, i=1; i<=n; r+=a[p[i]][i], i++);
		return r;
    }
};

int a[N][N];
Hng <N> h;
void Solve()
{
	int n;
	scanf("%d", &n);
	for(int i=0; i<n; i++)
		for(int j=0; j<n; scanf("%d", &a[i][j]), j++);
	int r=n*n;
	h.n=n;
	for(int z=1; z>=-1; z-=2)
	{
		for(int k=1; k<=n; k++)
		{
			for(int i=0; i<n; i++)
				for(int j=0; j<n; j++)
					if(a[i][j]==k*z) h.a[i+1][j+1]=-1;
					else h.a[i+1][j+1]=0;
			r+=h.hng();
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
