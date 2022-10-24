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

const int N=100100;
void run()
{
	int n;
	scanf("%d", &n);
	vector <int> a, b, c;
	for(int i=0; i<n; i++)
	{
		int x;
		scanf("%d", &x);
		if(i%2==0) a.push_back(x);
		else b.push_back(x);
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	for(int i=0; i<n; i++)
	{
		if(i<a.size()) c.push_back(a[i]);
		if(i<b.size()) c.push_back(b[i]);
	}
	int x=-1;
	for(int i=0; i+1<c.size(); i++)
		if(c[i]>c[i+1]) { x=i; break; }
	if(x==-1) printf("OK\n");
	else printf("%d\n", x);
}
int main()
{
	int tst;
	scanf("%d", &tst);
	for(int t=1; t<=tst; t++)
	{
		printf("Case #%d: ", t);
		run();
	}
    return 0;
}
