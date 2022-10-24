#include<bits/stdc++.h>

using namespace std;

int main() {
	int test;
	cin >> test;
	for (int cases = 1; cases <= test; cases++) {
		int n;
		double p;
		cin >> n >> p;

		double w, h;
		for (int i = 0; i < n; i++) {
			cin >> w >> h;
		}

		double mini = w;
		if (mini > h) mini = h;
		mini *= 2;

		double maxi = sqrt(w * w + h * h);
		maxi *= 2;
		double res;
		double diff = p - 2.0 * (w + h) * n;
		if (maxi * n <= diff) {
			res = 2.0 * (w + h) * n + maxi * n;
		} else {
			res = p;
			if (mini > diff) res = 2 * (w + h) * n;
		}

		printf("Case #%d: %.8lf\n", cases, res);
	}
	return 0;
}
