#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
using namespace std;
typedef long long ll;
#define MAXN 102

int a[MAXN],b[MAXN];
ll G[MAXN], H[MAXN], tmp[MAXN];
bool stupid[MAXN];
void main2 () {
	int M;
	scanf("%d",&M);
	for (int i=1;i<=M;++i) {
		scanf("%d %d",&a[i],&b[i]);
		if (a[i] == i || b[i] == i) stupid[i] = 1;
		else stupid[i] = 0;
	}
	ll sm = 0;
	for (int i=1;i<=M;++i) scanf("%lld",&tmp[i]), sm += tmp[i];
	ll l = 0, r = sm;
	while (l < r) {
		for (int i=1;i<=M;++i) G[i] = tmp[i];
		ll m = (l+r+1)/2;
		G[1] -= m;
		int times = M;
		for (int z=1;z<=10000;++z) {
			for (int i=1;i<=M;++i) H[i] = G[i];
			for (int i=1;i<=M;++i) if (G[i] < 0 && !stupid[i]) H[i] -= G[i], H[a[i]] += G[i], H[b[i]] += G[i];
			ll sm2 = 0;
			for (int i=1;i<=M;++i) {
				G[i] = H[i];
				sm2 += G[i];
			}
			if (sm2 < -1000000000LL) break;
		}
		bool ok = 1;
		for (int i=1;i<=M;++i) if (G[i] < 0) {
			ok = 0;
			break;
		}
		if (ok) l = m;
		else r = m-1;
	}
	printf("%lld\n",l);
}

int main () {
	int T;
	scanf("%d",&T);
	for (int z=1;z<=T;++z) {
		printf("Case #%d: ", z);
		main2();
	}
	return 0;
}
