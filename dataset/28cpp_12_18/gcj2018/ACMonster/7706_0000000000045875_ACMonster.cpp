//Problem C

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#include<set>

using namespace std;

int get() {
	char c;
	while (c = getchar(), c != '-' && (c < '0' || c > '9'));
	bool flag = (c == '-');
	if (flag)
		c = getchar();
	int x = 0;
	while (c >= '0' && c <= '9') {
		x = x * 10 + c - '0';
		c = getchar();
	}
	return flag ? -x : x;
}

const int MAXN = 100;

int a[MAXN][MAXN];
vector<int> g[MAXN];
int peer[MAXN];
bool flag[MAXN];

bool dfs(int x) {
	if (x == -1)
		return true;
	if (flag[x])
		return false;
	flag[x] = true;
	for (int i = 0; i < g[x].size(); i++) {
		int y = g[x][i];
		if (dfs(peer[y])) {
			peer[y] = x;
			return true;
		}
	}
	return false;
}

int main() {
	int totalTest = get();
	for (int test = 1; test <= totalTest; test++) {
		int n = get();
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				a[i][j] = get();
		int ans = 0;
		for (int c = -n; c <= n; c++) {
			for (int i = 0; i < n; i++)
				g[i].clear();
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					if (a[i][j] == c) {
						ans++;
						g[i].push_back(j);
					}
			memset(peer, -1, sizeof(peer));
			for (int i = 0; i < n; i++) {
				memset(flag, 0, sizeof(flag));
				if (dfs(i))
					ans--;
			}
		}
		printf("Case #%d: %d\n", test, ans);
	}
	return 0;
}
