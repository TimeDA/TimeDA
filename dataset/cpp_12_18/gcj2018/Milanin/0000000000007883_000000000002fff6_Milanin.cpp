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
const int N=1100;
int m[N], s[N], p[N];
long long v[N];
void Solve()
{
	int r, b, c;
	scanf("%d%d%d", &r, &b, &c);
	for(int i=0; i<c; scanf("%d%d%d", &m[i], &s[i], &p[i]), i++);
	long long L=0, R=1000000000000000000ll;
	for(; L<R; )
	{
		long long t=(L+R)/2;
		for(int i=0; i<c; i++)
			if(t>=p[i]) v[i]=min((t-p[i])/s[i], (long long)m[i]);
			else v[i]=0;
		sort(v, v+c);
		long long z=0;
		for(int i=0; i<r; z+=v[c-i-1], i++);
		if(z>=b) R=t;
		else L=t+1;
	}
	printf("%lld\n", R);
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