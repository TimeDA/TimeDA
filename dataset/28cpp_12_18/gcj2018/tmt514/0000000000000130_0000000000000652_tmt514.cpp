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

#include <map>
void solve() {
	LL n, k;
	cin >> n >> k;
	map<LL, LL> s;
	s[n] = 1;
	--k;
	while(true) {
		while(s.rbegin()->second == 0) {
			s.erase(s.find(s.rbegin()->first));
		}
		if(k < s.rbegin()->second) break;
		auto x = *s.rbegin();
		k -= x.second;
		LL g = x.second;
		LL v = x.first;
		LL l = (v-1)/2, r=v/2;
		s.erase(s.find(v));
		if(l) s[l] += g;
		if(r) s[r] += g;
	}
	auto x = *s.rbegin();
	LL v = x.first;
	LL l = (v-1)/2, r=v/2;
	
	static int cs = 0;
	printf("Case #%d: ", ++cs);
	cout << r << " " << l << endl;
}

int main(void) {
	int T;
	scanf("%d", &T);
	while(T--) solve();
  return 0;
}
