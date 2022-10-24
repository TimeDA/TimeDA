#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

#define N 100010
int n, a[N], b[N], c[N];

int main() {
	int _; cin >> _;
	for (int __ = 1; __ <= _; __ ++) {
		cin >> n;
		for (int i = 0; i < n; i ++) {
			cin >> a[i];
			if (i&1) c[i/2] = a[i];
			else b[i/2] = a[i];
		}
		sort(a, a+n);
		sort(b, b+(n+1)/2);
		sort(c, c+n/2);
		int S = -1;
		for (int i = 0; i < n; i ++) {
			int p;
			if (i&1) p = c[i/2];
			else p = b[i/2];
			if (a[i] != p) {
				S = i;
				break;
			}
		}
		printf ("Case #%d: ", __);
		if (S == -1) puts ("OK");
		else printf ("%d\n", S);
	}
	return 0;
}