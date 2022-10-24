#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 100010;
int a[MAXN], n;

int main() {
	int T;
	scanf("%d",&T);
	for (int ca = 1 ; ca <= T ; ++ca) {
		scanf("%d",&n);
		for (int i = 0 ; i < n ; ++i)
			scanf("%d",&a[i]);

		vector<int> p1, p2;
		for (int i = 0 ; i < n ; i += 2) {
			p1.push_back(a[i]);
		}
		for (int i = 1 ; i < n ; i += 2) {
			p2.push_back(a[i]);
		}
		sort(p1.begin(), p1.end());
		sort(p2.begin(), p2.end());

		// merge
		vector<int> b;
		for (int i = 0 ; i < p2.size() ; ++i) {
			b.push_back(p1[i]);
			b.push_back(p2[i]);
		}
		if (p1.size() > p2.size())
			b.push_back(p1[p1.size()-1]);

		int ans = -1;
		for (int i = 0 ; i + 1 < b.size() ; ++i)
			if (b[i] > b[i+1]) {ans = i; break;}
		printf("Case #%d: ", ca);
		if (ans == -1) printf("OK\n");
		else printf("%d\n", ans);
	}
	return 0;
}