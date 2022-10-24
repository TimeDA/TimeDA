#include <cstdio>
 #include <vector>
 #include <cmath>
 #include <set>
 #include <map>
 #include <algorithm>
 #include <cstring>
 #include <string>
 #include <iostream>
 #include <cassert>
 #include <memory.h>
 using namespace std;
 
 #define forn(i, n) for (int i = 0; i < (int)(n); i++)
 #define foreach(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
 #define pb push_back
 typedef long long ll;
 typedef pair<int, int> pii;
 typedef long double ld;
 
 int row[2], a[2][4][4];
 
 void solve() {
 	vector<int> inrow;
 	forn(q, 2) {
 		scanf("%d", &row[q]);
 		row[q]--;
 		forn(i, 4) forn(j, 4) scanf("%d", &a[q][i][j]);
 		forn(j, 4) inrow.pb(a[q][row[q]][j]);
 	}
 
 	sort(inrow.begin(), inrow.end());
 	vector<int> ans;
 	forn(i, inrow.size() - 1)
 		if (inrow[i] == inrow[i+1]) ans.pb(inrow[i]);
 
 	if (ans.empty()) printf("Volunteer cheated!\n");
 	else if (ans.size() > 1) printf("Bad magician!\n");
 		 else printf("%d\n", ans[0]);
 }
 
 int main() {
 	int tc;
 	scanf("%d", &tc);
 	for (int q = 1; q <= tc; q++) {
 		printf("Case #%d: ", q);
 		solve();
 		fprintf(stderr, "Case %d done.\n", q);
 	}
 	return 0;
 }
