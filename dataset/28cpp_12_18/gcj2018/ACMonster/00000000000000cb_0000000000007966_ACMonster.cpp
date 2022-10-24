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

int damage(string s) {
	int ans = 0, cur = 1;
	for (int i = 0; i < s.size(); i++)
		if (s[i] == 'S')
			ans += cur;
		else
			cur *= 2;
	return ans;
}

int main() {
	int totalTest = get();
	for (int test = 1; test <= totalTest; test++) {
		int m = get();
		string s;
		cin >> s;
		int n = s.size(), ans = 0;
		while (damage(s) > m) {
			int p = n - 1;
			while (p > 0 && (s[p] == 'C' || s[p - 1] == 'S'))
				p--;
			if (!p) {
				ans = -1;
				break;
			}
			ans++;
			swap(s[p], s[p - 1]);
		}
		printf("Case #%d: ", test);
		if (ans == -1)
			printf("IMPOSSIBLE\n");
		else
			printf("%d\n", ans);
	}
	return 0;
}
