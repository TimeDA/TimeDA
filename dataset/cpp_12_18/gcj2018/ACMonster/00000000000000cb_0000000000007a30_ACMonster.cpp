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

bool b[100][100];

void work(int n, int m) {
	memset(b, 0, sizeof(b));
	while (true) {
		int best = 9, i0, j0;
		for (int i = 1; i + 1 < n; i++)
			for (int j = 1; j + 1 < m; j++) {
				int sum = 0;
				for (int x = -1; x <= 1; x++)
					for (int y = -1; y <= 1; y++)
						sum += b[i + x][j + y];
				if (sum < best) {
					best = sum;
					i0 = i;
					j0 = j;
				}
			}
		printf("%d %d\n", i0 + 1, j0 + 1);
		fflush(stdout);
		int i1, j1;
		scanf("%d%d", &i1, &j1);
		if (!i1 && !j1)
			break;
		b[i1 - 1][j1 - 1] = true;
	}
}

int main() {
	int test;
	scanf("%d", &test);
	while (test--) {
		int a;
		scanf("%d", &a);
		if (a == 20)
			work(4, 5);
		else if(a == 200)
			work(10, 20);
	}
	return 0;
}
