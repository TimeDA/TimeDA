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
const int W=510;
double v[N*W], x[N];
int a[N], b[N];
void Solve()
{
	int n, p, l;
	scanf("%d%d", &n, &p);
	l=0;
	for(int i=0; i<n; scanf("%d%d", &a[i], &b[i]), l+=(a[i]+b[i])*2, i++);
	p-=l;
	for(int i=0; i<n; x[i]=sqrt(a[i]*a[i]+b[i]*b[i])*2, a[i]=min(a[i], b[i])*2, i++);
	for(int j=0; j<n*W; v[j]=-1E20, j++);
	v[0]=0;
	for(int i=0; i<n; i++)
		for(int j=n*W; j>=a[i]; v[j]=max(v[j], v[j-a[i]]+x[i]-a[i]), j--);
	double z=0;
	for(int j=0; j<n*W && j<=p; j++)
		if(v[j]>0)
			if(j+v[j]>=p) z=p;
			else z=max(z, j+v[j]);
	printf("%.13lf\n", l+z);
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