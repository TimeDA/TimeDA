#include <cstdio>
 #include <cstring>
 #include <vector>
 #include <algorithm>
 #include <cmath>
 #include <set>
 #include <queue>
 #define SZ(x) ((int)(x).size())
 #define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
 using namespace std;
 
 int d[10005], l[10005];
 int n;
 int mxd[10005];
 
 void solve() {
 	static int cs=0;
 	printf("Case #%d: ", ++cs);
 	scanf("%d", &n);
 	for(int i=0;i<n;i++) scanf("%d%d", &d[i], &l[i]);
 	queue<int> q;
 	q.push(0);
 	q.push(d[0]);
 	for(int i=0;i<n;i++) mxd[i] = 0;
 	mxd[0] = d[0];
 	int ed;
 	scanf("%d", &ed);
 	while(!q.empty()) {
 		int x = q.front(); q.pop();
 		int r = q.front(); q.pop();
 		if (ed <= d[x] + r && ed >= d[x] - r) {
 			puts("YES");
 			return;
 		}
 		for(int i=0;i<n;i++) {
 			if (d[i]<=d[x]+r && d[i]>=d[x]-r) {
 				int y = i, v = min(l[i], abs(d[i]-d[x]));
 				if (mxd[y] < v) {
 					q.push(y);
 					q.push(v);
 					mxd[y] = v;
 				}
 			}
 		}
 	}
 	puts("NO");
 	return;
 }
 
 int main(void) {
 	int T;
 	scanf("%d", &T);
 	while(T--) solve();
 	return 0;
 }
 
