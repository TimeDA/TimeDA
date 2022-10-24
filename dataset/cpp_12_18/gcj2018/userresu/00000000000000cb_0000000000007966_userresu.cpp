#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;

char s[102];
int cnt[50];

ll compute_number() {
	ll ret = 0, mul = 1;
	for (int i=0;i<30;++i,mul*=2) ret += mul * cnt[i];
	return ret;
}

int main () {
	int T;
	scanf("%d",&T);
	for (int z=1;z<=T;++z) {
		int D;
		scanf("%d %s",&D, s);
		for (int i=0;i<50;++i) cnt[i] = 0;
		int n = strlen(s);
		int tot = 0, cur = 0;
		for (int i=0;i<n;++i) {
			if (s[i] == 'C') ++cur;
			else {
				++tot;
				++cnt[cur];
			}
		}
		printf("Case #%d: ", z);
		if (tot > D) {
			printf("IMPOSSIBLE\n");
			continue;
		}
		int pr = 0;
		while (compute_number() > D) {
			if (cnt[cur]) {
				--cnt[cur];
				++cnt[cur-1];
				++pr;
			}
			else --cur;
		}
		printf("%d\n",pr);
	}
	return 0;
}
