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

const int N=100;
char s[N];
int eval()
{
	int x=0, y=1;
	for(int i=0; s[i]; i++)
		if(s[i]=='C') y*=2;
		else x+=y;
	return x;
}
void run(int tst)
{
	printf("Case #%d: ", tst);
	int d;
	scanf("%d%s", &d, s);
	int x=0;
	for(; eval()>d; x++)
	{
		int bi=-1;
		for(int i=0; s[i]; i++)
			if(s[i]=='C' && s[i+1]=='S') bi=i;
		if(bi==-1) { x=-1; break; }
		swap(s[bi], s[bi+1]);
	}
	if(x==-1) printf("IMPOSSIBLE\n");
	else printf("%d\n", x);
}
int main()
{
	int tst;
	scanf("%d", &tst);
	for(int t=1; t<=tst; run(t), t++);
    return 0;
}
