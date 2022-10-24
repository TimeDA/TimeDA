#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstdio>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#include <cmath>
#include <ctime>
#include <cstring>
#pragma comment (linker, "/STACK:256000000")


const int MAXN = 500;

int n;
int a[MAXN];
int l[MAXN];
bool b[MAXN];

void solve()
{
	std::cin >> n;
	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));
	for (int i = 1; i <= n; ++i)
	{
		int d;
		std::cin >> d;
		if (d == -1) exit(0);
		for (int i = 1; i <= d; ++i)
			std::cin>> l[i];
		for (int i = 1; i <= d; ++i)
			++a[l[i]];
		int ret = -1;
		for (int i = 1; i <= d; ++i)
		if (!b[l[i]])
		{
			if (ret == -1)
				ret = l[i];
			else
				if (a[l[i]] < a[ret])
				ret = l[i];
		}
		if (ret != -1) b[ret] = true;
		std::cout << ret << std::endl;
	}
}

int main(int argc, char* argv[]) 
{
	int tt;
	std::cin >> tt;
	while (tt--)
		solve();
	exit(0);
	return 0;
}