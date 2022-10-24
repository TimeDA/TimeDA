#include <bits/stdc++.h>
 
 using namespace std;
 
 typedef long long ll;
 typedef pair<ll, int> PII;
 
 #define fi first
 #define se second
 #define mp make_pair
 #define pb push_back
 
 #define P 1000000007
 #define N 210
 
 const int dx[4] = {-1, 0, 1, 0};
 const int dy[4] = {0, -1, 0, 1};
 
 int n, m, p, D;
 ll a[N][N];
 
 int main() {
 	int _;
 	cin >> _;
 	for (int __ = 1; __ <= _; __ ++) {
 		cin >> n >> m >> p >> D;
 		memset(a, -1, sizeof a);
 		while (p--) {
 			int x, y, z;
 			cin >> x >> y >> z;
 			x--;
 			y--;
 			a[x][y] = z;
 		}
 		set<PII> A;
 		for (int i = 0; i < n; i ++)
 			for (int j = 0; j < m; j ++)
 				if (a[i][j] != -1) A.insert(mp(a[i][j], i*m+j));
 		while (!A.empty()) {
 			PII _x = *A.begin();
 			A.erase(A.begin());
 			int x = _x.se/m, y = _x.se%m;
 			for (int d = 0; d < 4; d ++) {
 				int x1 = x+dx[d], y1 = y+dy[d];
 				if (x1 < 0 || x1 >= n || y1 < 0 || y1 >= m) continue;
 				if (a[x1][y1] != -1) continue;
 				a[x1][y1] = a[x][y] + D;
 				A.insert(mp(a[x1][y1], x1*m+y1));
 			}
 		}
 		bool F = true;
 		for (int i = 0; i < n; i ++)
 			for (int j = 0; j < m; j ++)
 				for (int d = 0; d < 4; d ++) {
 					int x = i+dx[d], y = j+dy[d];
 					if (x < 0 || x >= n || y < 0 || y >= m) continue;
 					if (abs(a[i][j]-a[x][y]) > D) F = false;
 				}
 		printf ("Case #%d: ", __);
 		if (!F) puts ("IMPOSSIBLE"); else {
 			ll S = 0;
 			for (int i = 0; i < n; i ++)
 				for (int j = 0; j < m; j ++) 
 					S += a[i][j];
 			cout << S%P << endl;
 		}
 	}
 	return 0;
 }