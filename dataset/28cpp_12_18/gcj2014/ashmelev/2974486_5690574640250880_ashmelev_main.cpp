#include <iostream>
 #include <cstdio>
 #include <cmath>
 #include <algorithm>
 #include <vector>
 #include <map>
 #include <set>
 #include <bitset>
 #include <queue>
 #include <stack>
 #include <sstream>
 #include <cstring>
 #include <numeric>
 #include <ctime>
 
 #define re return
 #define fi first
 #define se second
 #define mp make_pair
 #define pb push_back
 #define all(x) (x).begin(), (x).end()
 #define sz(x) ((int) (x).size())
 #define rep(i, n) for (int i = 0; i < (n); i++)
 #define rrep(i, n) for (int i = (n) - 1; i >= 0; i--)
 #define y0 y32479
 #define y1 y95874
 #define fill(x, y) memset(x, y, sizeof(x))
 #define sqr(x) ((x) * (x))
 #define sqrt(x) sqrt(abs(x))
 #define unq(x) (x.resize(unique(all(x)) - x.begin()))
 #define spc(i,n) " \n"[i == n - 1]
 
 using namespace std;
 
 typedef vector<int> vi;
 typedef vector<vi> vvi;
 typedef pair<int, int> ii;
 typedef vector<ii> vii;
 typedef vector<string> vs;
 typedef double D;
 typedef long double LD;
 typedef long long ll;
 typedef pair<ll, ll> pll;
 typedef vector<ll> vll;
 
 template<class T> T abs(T x) { return x > 0 ? x : -x;}
 
 int m;
 int n;
 
 int matr[5][5];
 int w[5][5];
 
 
 int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
 int dy[8] = {0, 1, 0, -1, 1, -1, 1, -1};
 
 int good(int x, int y) {
 	re x >= 0 && x < n && y >= 0 && y < m;
 }
 
 int zer(int x, int y) {
 	rep(i, 8) {
 		int nx = x + dx[i];
 		int ny = y + dy[i];
 		if (good(nx, ny) && matr[nx][ny])
 			re 0;
 	}
 	re 1;
 }
 
 void go(int x, int y) {
 	w[x][y] = 1;
 	if (zer(x, y)) {
 		rep(i, 8) {
 			int nx = x + dx[i];
 			int ny = y + dy[i];
 			if (good(nx, ny) && !w[nx][ny])
 				go(nx, ny);
 		}
 	}
 }
 
 int check(int x, int y) {
 	if (matr[x][y])
 		re 0;
 	fill(w, 0);
 	go(x, y);
 	rep(i, n) rep(j, m)
 		if (matr[i][j] == 0 && !w[i][j])
 			re 0;
 	re 1;
 }
 
 int main() {
 
 #ifdef LOCAL_BOBER
 	freopen("input.txt", "r", stdin);
 	freopen("output.txt", "w", stdout);
 #endif
 
 	int tc;
 	cin >> tc;
 	rep(tt, tc) {
 		cout << "Case #" << tt + 1 << ":" << endl;
 
 		int k;
 		cin >> n >> m >> k;
 		int g = 0;
 		rep(o, 1 << (n * m)) {
 			if (__builtin_popcount(o) != k)
 				continue;
 			rep(i, n) rep(j, m)
 				matr[i][j] = ((1 << (i * m + j)) & o) > 0;
 			int f = 0;
 			int ai, aj;
 			rep(i, n)  {
 				if (f)
 					break;
 				rep(j, m)
 					if (check(i, j)) {
 						f = 1;
 						ai = i;
 						aj = j;
 						break;
 					}
 			}
 			if (f) {
 				rep(i, n) {
 					rep(j, m) {
 						if (i == ai && j == aj)
 							cout << 'c';
 						else
 						if (matr[i][j])
 							cout << '*';
 						else
 							cout << '.';
 					}
 					cout << endl;
 				}
 				g = 1;
 				break;
 			}
 		}
 		if (!g)
 			cout << "Impossible" << endl;
 	}
 
 
 	re 0;
 }
 
