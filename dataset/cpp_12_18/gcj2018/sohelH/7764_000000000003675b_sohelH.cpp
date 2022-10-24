#include<bits/stdc++.h>

using namespace std;

int main() {
	int test;
	cin >> test;
	for (int cases = 1; cases <= test; cases++) {
		vector<int> v1, v2;
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			int a, b, c;
			cin >> a >> b >> c;
			v1.push_back(a + b);
			v2.push_back(a - c);
		}

		vector<int> va, vb;
		map<int, int> ma, mb;
		for (int j = 0; j < n; j++) {
			if (ma[v1[j]] == 0) va.push_back(v1[j]);
			ma[v1[j]]++;

			if (mb[v2[j]] == 0) vb.push_back(v2[j]);
			mb[v2[j]]++;
		}


		int maxi = 0, res = -1;
		for (int i = 0; i < n; i++) {
			int maxCnt = 0;
			for (int a = 0; a < va.size(); a++)
				for (int b = 0; b < vb.size(); b++) {
					int cnt = 0;
					for (int j = i; j < n; j++) {
						if (v1[j] == va[a] || v2[j] == vb[b]) {
							cnt++;
						}
						else break;
					}
					if (cnt > maxCnt) maxCnt = cnt;
				}

			if (maxCnt > maxi) {
				maxi = maxCnt;
				res = 1;
			} else if (maxCnt == maxi) {
				res++;
			}

		}
		printf("Case #%d: %d %d\n", cases, maxi, res);
	}
	return 0;
}
