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
const int N=10100;
int x[N], y[N];
void solve()
{
	int n;
	scanf("%d", &n);
	for(int i=0; i<n; scanf("%d%d", &x[i], &y[i]), i++);
	sort(x, x+n);
	sort(y, y+n);
	printf("%d\n", max((x[n-1]-x[0]+1)/2, (y[n-1]-y[0]+1)/2));
}
int main()
{
	int tst;
	scanf("%d", &tst);
	for(int t=1; t<=tst; t++)
	{
		printf("Case #%d: ", t);
		solve();
	}
	return 0;
}
