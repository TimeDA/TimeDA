#include <cstdio>
#include <cassert>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 100010;
int c[MAXN];
const int INF = 1e9;

int calc(int x, int N) {
	bool b = (x * 100 % N >= (N + 1) / 2);
	return x * 100 / N + (b ? 1 : 0);
}

int main() {
	int T, ca;
	scanf("%d",&T);
	for (int ca = 1 ; ca <= T ; ++ca) {
		int N, L;
		scanf("%d%d",&N,&L);
		int left = N;
		for (int i = 0 ; i < L ; ++i) {
			scanf("%d",&c[i]);
			left -= c[i];
		}
		vector<int> lt;
		for (int x = 1 ; x <= N ; ++x) {
			bool b = ((x * 100) % N >= (N + 1) / 2);
			if (b) lt.push_back(x);
		}
		
		if (lt.size() == 0) {
			printf("Case #%d: %d\n", ca, 100);
			continue;
		}
/*
		printf("left: %d", left);
		for (int i = 0 ; i < lt.size() ; ++i)
			printf("[%d]", lt[i]);
		printf("\n");
*/
		int ans = 0;

		vector<pair<int,int> > ps;
		for (int i = 0 ; i < L ; ++i) {
			int idx = (int)(lower_bound(lt.begin(), lt.end(), c[i]) - lt.begin());
			int needy = INF;
			if (idx < lt.size()) {
				needy = lt[idx] - c[i];
			}
			ps.push_back(make_pair(needy, c[i]));
		}
		sort(ps.begin(), ps.end());

		for (int i = 0 ; i < L ; ++i) {
			int delta = ps[i].first;
			if (delta < lt[0] && delta <= left) {
				ans += calc(ps[i].second + delta, N);
				left -= delta;
			} else {
				ans += calc(ps[i].second, N);
			}
		}
		/*
		for (int i = 0 ; i < L ; ++i) {
			int idx = (int)(lower_bound(lt.begin(), lt.end(), c[i]) - lt.begin());
			if (lt[idx] == c[i]) {
				ans += calc(c[i], N);
			} else if (idx < lt.size() && lt[idx]-c[i] <= lt[0] && lt[idx]-c[i] <= left) {
				int delta = lt[idx] - c[i];
				ans += calc(lt[idx], N);
				left -= delta;
			} else {
				ans += calc(c[i], N);
			}
			// printf("ans %d after idx %d, left: %d\n", ans, i, left);
		}
		*/
		while (left > 0) {
			// printf("left:%d\n", left);
			int v = min(left, lt[0]);
			ans += calc(v, N);
			left -= v;
			// printf("ans:%d\n", ans);
		}
		printf("Case #%d: %d\n", ca, ans);
	}
	return 0;
}

