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

int a[100005];
void solve() {
	int n;
	vector<int> b[2];
	scanf("%d", &n);
	for(int i=0;i<n;i++) {
		scanf("%d", &a[i]);
		b[i%2].push_back(a[i]);
	}
	sort(b[0].begin(), b[0].end());
	sort(b[1].begin(), b[1].end());
	sort(a, a+n);
	reverse(b[0].begin(), b[0].end());
	reverse(b[1].begin(), b[1].end());
	vector<int> c;
	for(int i=0;i<n;i++) {
		c.push_back(b[i%2].back());
		b[i%2].pop_back();
	}
	int bad = -1;
	for(int i=0;i<n;i++) {
		if(a[i] != c[i]) {
			bad=i;
			break;
		}
	}
	
	static int cs = 0;
	printf("Case #%d: ", ++cs);
	if(bad==-1) puts("OK");
	else printf("%d\n", bad);
		
}

int main(void) {
	int T;
	scanf("%d", &T);
	while(T--) solve();
  return 0;
}
