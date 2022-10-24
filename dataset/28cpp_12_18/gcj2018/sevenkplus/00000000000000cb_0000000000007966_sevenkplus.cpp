#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

int val(string s) {
	int S = 0;
	int n = (int) s.length();
	int T = 1;
	for (int i = 0; i < n; i ++)
		if (s[i] == 'C') T *= 2;
		else S += T;
	return S;
}

int main() {
	int _; cin >> _;
	for (int __ = 1; __ <= _; __ ++) {
		int m;
		string s;
		cin >> m >> s;
		int S = 0;
		while (val(s) > m) {
			int p = s.length()-2;
			while (p >= 0) {
				if (s[p] == 'C' && s[p+1] == 'S') break;
				p--;
			}
			if (p < 0) {
				S = -1;
				break;
			}
			S++;
			swap(s[p], s[p+1]);
		}
		printf ("Case #%d: ", __);
		if (S == -1) puts ("IMPOSSIBLE");
		else printf ("%d\n", S);
	}
	return 0;
}