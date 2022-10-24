#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

bool F[20][1000];

int main() {
	int _;
	cin >> _;
	while (_--) {
		int a;
		cin >> a;
		int x = 10, y = 10;
		memset(F, 0, sizeof F);
		int p = 0;
		while (true) {
			if (p == 9) {
				y += 3;
				p = 0;
			}
			printf ("%d %d\n", x, y);
			fflush(stdout);
			int xx, yy;
			cin >> xx >> yy;
			if (xx == 0 && yy == 0) break;
			if (!F[xx][yy]) p++;
			F[xx][yy] = true;
		}
	}
	return 0;
}