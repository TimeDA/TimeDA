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


void solve() {
	int n, p=0;
	int a[30];
	scanf("%d", &n);
	for(int i=0;i<n;i++) {
		scanf("%d", &a[i]);
		p += a[i];
	}
	string s = "";
	while(p>0) {
		int r = max_element(a, a+n) - a;
		a[r]--;
		s += (char)(r+'A');
		--p;
	}
	static int cs=0;
	printf("Case #%d:", ++cs);
	int i=0;
	if(SZ(s)%2) {
		printf(" %c", s[0]);
		i=1;
	}
	for(;i<SZ(s);i+=2) {
		printf(" %c%c", s[i], s[i+1]);
	}
	printf("\n");
}
int main(void) {
	int T;
	scanf("%d", &T);
	while(T--) solve();
  return 0;
}
