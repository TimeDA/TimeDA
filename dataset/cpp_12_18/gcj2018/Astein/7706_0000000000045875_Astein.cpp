#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

#define MAXN 101
#define MAXM 101

int N, M;
vector<int> graph[MAXN];

int match1[MAXN];
int match2[MAXM];
char check[MAXM];

bool extendMatch(int a) 
{
	for (int i = 0; i < graph[a].size(); i++) 
	{
		int b = graph[a][i];
		if (check[b]) continue;

		if (match2[b] == -1) {
			match1[a] = b;
			match2[b] = a;
			return true;
		}
	}

	for (int i = 0; i < graph[a].size(); i++) {
		int b = graph[a][i];
		if (check[b]) continue;

		check[b] = 1;
		if (extendMatch(match2[b])) {
			match1[a] = b;
			match2[b] = a;
			return true;
		}
	}
	return false;
}

int maxMatch() {
	memset(match1, -1, N * sizeof(int));
	memset(match2, -1, M * sizeof(int));

	int cnt = 0;
	for (int i = 0; i < N; i++) {
		memset(check, 0, M);
		if (extendMatch(i))
			cnt++;
	}

	return cnt;
}


int main()
{
	int T;
	scanf("%d", &T);

	for (int cn = 1; cn <= T; ++cn)
	{
		printf("Case #%d: ", cn);

		int n;
		scanf("%d", &n);

		vector<vector<int>> a(n, vector<int>(n, 0));
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				scanf("%d", &a[i][j]);

		N = M = n;
		int ret = n * n;
		for (int idx = -n; idx <= n; ++idx)
		{
			for (int i = 0; i < n; ++i)
				graph[i].clear();

			for (int i = 0; i < n; ++i)
				for (int j = 0; j < n; ++j)
					if (a[i][j] == idx)
					{
						graph[i].push_back(j);
					}
			ret -= maxMatch();
		}
		printf("%d\n", ret);
	}
}
