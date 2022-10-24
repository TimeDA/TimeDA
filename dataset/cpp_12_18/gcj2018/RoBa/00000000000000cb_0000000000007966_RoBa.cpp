#include <cstdio>
#include <cstring>
using namespace std;

char buf[110];

int calc(char *buf) {
	int s = 1, res = 0;
	for (int i = 0 ; buf[i] ; ++i) {
		if (buf[i] == 'C') s *= 2;
		else res += s;
	}
	return res;
}

int main() {
	int T;
	scanf("%d",&T);
	for (int ca = 1 ; ca <= T ; ++ca) {
		int d, ans = 0;
		scanf("%d%s",&d,buf);
		int len = strlen(buf);
		bool solved = false;
		while (1) {
			if (calc(buf) <= d) {
				solved = true;
				break;
			}
			bool found = false;
			for (int i = len-1 ; i > 0 ; --i) {
				// CS => SC
				if (buf[i-1] == 'C' && buf[i] == 'S') {
					buf[i-1] = 'S'; buf[i] = 'C';
					found = true;
					++ans;
					break;
				}
			}
			if (!found) break; 
		}
		printf("Case #%d: ", ca);
		if (!solved) printf("IMPOSSIBLE\n");
		else printf("%d\n", ans);
	}
	return 0;
}
