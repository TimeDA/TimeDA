#include <cstdio>
 #include <numeric>
 #include <iostream>
 #include <vector>
 #include <set>
 #include <cstring>
 #include <string>
 #include <map>
 #include <cmath>
 #include <ctime>
 #include <algorithm>
 #include <bitset>
 #include <queue>
 #include <sstream>
 #include <deque>
 
 using namespace std;
 
 #define mp make_pair
 #define pb push_back
 #define rep(i,n) for(int i = 0; i < (n); i++)
 #define re return
 #define fi first
 #define se second
 #define sz(x) ((int) (x).size())
 #define all(x) (x).begin(), (x).end()
 #define sqr(x) ((x) * (x))
 #define sqrt(x) sqrt(abs(x))
 #define y0 y3487465
 #define y1 y8687969
 #define fill(x,y) memset(x,y,sizeof(x))
 #define prev PREV
                          
 typedef vector<int> vi;
 typedef long long ll;
 typedef long double ld;
 typedef double D;
 typedef pair<int, int> ii;
 typedef vector<ii> vii;
 typedef vector<string> vs;
 typedef vector<vi> vvi;
 
 template<class T> T abs(T x) { re x > 0 ? x : -x; }
 
 int n;
 int c;
 int m;
 int sum[1001];
 int cnt[1001][1001];
 
 int main () {
 	int tt;
 	cin >> tt;
 	for (int it = 1; it <= tt; it++) {
 		memset (cnt, 0, sizeof (cnt));
 		memset (sum, 0, sizeof (sum));
 		scanf ("%d%d%d", &n, &c, &m);		
 		for (int i = 0; i < m; i++) {
 			int a, b;
 			scanf ("%d%d", &a, &b); a--; b--;
 			sum[b]++;
 			cnt[a][b]++;
 		}
 		int ans = max (sum[0], sum[1]);
 		int ans2 = 0;
 		if (cnt[0][0] - (sum[1] - cnt[0][1]) > 0 && cnt[0][1] - (sum[0] - cnt[0][0]) > 0)
 			ans = cnt[0][0] + cnt[0][1];
 		else {
 			for (int i = 0; i < n; i++)
 				if (cnt[i][0] + cnt[i][1] > ans)
 					ans2 += (cnt[i][0] + cnt[i][1] - ans);
 /*				for (int j = 1; j <= n && cnt[i][0] > 0; j++) {
 					int tmp = min (cnt[i][0], cnt[(i + j) % n][1]);
 					cnt[i][0] -= tmp;
 					cnt[(i + j) % n][1] -= tmp;
 					if (j == n) ans2 += tmp;
 				}*/
 		}
 		cout << "Case #" << it << ": " << ans << " " << ans2;
 		cout << endl;
 		fprintf (stderr, "%d / %d = %.2f | %.2f\n", it, tt, (double)clock () / CLOCKS_PER_SEC, ((double)clock () / it * tt) / CLOCKS_PER_SEC);
 	}
 	return 0;
 }