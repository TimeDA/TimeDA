#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
typedef double db;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pct __builtin_popcount

#define N 110
int n, a[N];
string s[N];

int main() {
	int _; cin >> _;
	for (int __ = 1; __ <= _; __ ++) {
		cin >> n;
		for (int i = 0; i < n; i ++) cin >> a[i];
		printf ("Case #%d: ", __);
		if (a[0] == 0 || a[n-1] == 0) {
			puts ("IMPOSSIBLE");
			continue;
		}
		for (int i = 0; i < n; i ++) s[i] = string(n, '.');
		int h = 0;
		int nw = 0;
		for (int i = 0; i < n; i ++) {
			while (a[nw] == 0) nw ++;
			a[nw]--;
			h = max(h, abs(i-nw));
			if (i > nw) {
				for (int j = 0; j < i-nw; j ++)
					s[j][i-j] = '/';
			} else
			if (i < nw) {
				for (int j = 0; j < nw-i; j ++)
					s[j][i+j] = '\\';
			}
		}
		printf ("%d\n", h+1);
		for (int i = 0; i <= h; i ++)
			cout << s[i] << endl;
	}
	return 0;
}
