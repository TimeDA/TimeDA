// by tmt514
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#define SZ(x) ((int)(x).size())
#define FOR(it, c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
using namespace std;
typedef long long LL;


char s[1005];

LL getValue() {
	LL v=0, t=1;
	for(int i=0;s[i];i++) {
		if(s[i]=='C') t *= 2;
		if(s[i]=='S') v += t;
	}
	return v;
}

void solve() {
	int D;
	scanf("%d", &D);
	scanf("%s", s);

	static int cs = 0;
	printf("Case #%d: ", ++cs);
	
	int cnt = 0;
	int len = strlen(s);
	while (getValue() > D) {
		int ok = 0;
		for(int i=len-2;i>=0;i--) {
			if(s[i]=='C' && s[i+1] == 'S') {
				swap(s[i], s[i+1]);
				ok = 1;
				break;
			}
		}
		if (!ok) {
			puts("IMPOSSIBLE");
			return;
		}
		++cnt;
	}
	printf("%d\n", cnt);
	
}

int main(void) {
	int T;
	scanf("%d", &T);
	while(T--) solve();
  return 0;
}
