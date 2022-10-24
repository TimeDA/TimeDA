//Problem A

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

int a[MAXN], x[MAXN], y[MAXN];
string board[MAXN + 1];

int main() {
	int totalTest = get();
	for (int test = 1; test <= totalTest; test++) {
		int n = get();
		for (int i = 0; i < n; i++)
			a[i] = get();
		printf("Case #%d: ", test);
		if (!a[0] || !a[n - 1])
			printf("IMPOSSIBLE\n");
		else {
			for (int i = 0; i < n; i++)
				x[i] = 1;
			int ans = 0;
			while (true) {
				bool finish = true;
				for (int i = 0; finish && i < n; i++)
					finish = (x[i] == a[i]);
				if (finish)
					break;
				string row = "";
				memset(y, 0, sizeof(y));
				for (int i = 0; i < n; i++)
					if (!x[i])
						row += '.';
					else {
						int cnt = 1;
						for (int j = 0; j < i; j++)
							cnt += x[j];
						int pos = 0, sum = 0;
						while (true) {
							sum += a[pos];
							if (sum >= cnt)
								break;
							pos++;
						}
						if (pos < i) {
							row += '/';
							y[i - 1] += x[i];
						} else if (pos > i) {
							row += '\\';
							y[i + 1] += x[i];
						} else {
							row += '.';
							y[i] += x[i];
						}
					}
				for (int i = 0; i < n; i++)
					x[i] = y[i];
				board[ans++] = row;
			}
			board[ans] = "";
			for (int i = 0; i < n; i++)
				board[ans] += '.';
			ans++;
			printf("%d\n", ans);
			for (int i = 0; i < ans; i++)
				cout << board[i] << endl;
		}
	}
	return 0;
}
