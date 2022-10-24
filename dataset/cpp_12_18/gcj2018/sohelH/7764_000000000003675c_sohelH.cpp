#include<bits/stdc++.h>

using namespace std;

int main() {
	int test;
	cin >> test;
	for (int cases = 1; cases <= test; cases++) {
		int n;
		vector<int> va, vb;
		vector<int> v;
		cin >> n;
		for (int i = 0; i < n; i++) {
			int a, b;
			cin >> a >> b;
			if ( (a == (i + 1)) || (b == (i + 1)) ) {
				a = 0;
				b = 0;
			}
			va.push_back(a - 1);
			vb.push_back(b - 1);
		}
		for (int i = 0; i < n; i++) {
			int a; cin >> a; v.push_back(a);
		}

		int res = v[0];
		v[0] = 0;
		int cnt = 0;
		for (int i = 1; i <= 1000; i++) {
			vector<int> vv = v;
			if (va[0] == -1) break;
			vv[ va[0] ] -= i;
			vv[ vb[0] ] -= i;
			//cerr << i << endl;
			bool yes = false;
			while (true) {
				bool done = true;
				for (int j = 1; j < n; j++)
					if (vv[j] < 0)
						done = false;
				if (done) {
					yes = true;
					break;
				}
				//cerr << "done: " << done << endl;

				bool change = false;
				for (int j = 0; j < n; j++) {
					if (vv[j] < 0) {
						int a = va[j];
						int b = vb[j];
						if (a < 0) continue;
						if (vv[a] <= 0 && vv[b] <= 0) {
							continue;
						}

						vv[j]++;
						vv[a]--;
						vv[b]--;
						change = true;
						break;
					}
				}
				if (!change) break;
			}
			if (!yes) {
				break;
			}
			cnt = i;
		}
		printf("Case #%d: %d\n", cases, res + cnt);

	}
	return 0;
}
