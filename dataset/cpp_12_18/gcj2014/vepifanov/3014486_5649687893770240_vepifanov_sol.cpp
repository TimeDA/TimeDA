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
 #define next NEXT
 
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
 int m;
 
 int next[10][1000][26];
 //int fin[1000];
 int o[10];
 int g[10];
 int ans, cnt;
 string s[1000];
 
 int add (int t, string s) {
 	if (o[t] == 0) o[t]++;
 	int x = 0;
 	for (int i = 0; i < sz (s); i++) {
 		int c = s[i] - 'A';
 		int y = next[t][x][c];
 		if (y == 0)
 			y = next[t][x][c] = o[t]++;
 		x = y;
 	}
 //	fin[x]++;
 	re 0;
 }
 
 int gen (int i) {
 	if (i == n) {
 		for (int j = 0; j < m; j++) {
 			for (int k = 0; k < o[j]; k++)
 				memset (next[j][k], 0, sizeof (next[j][k]));
 			o[j] = 0;
 		}
 		for (int j = 0; j < n; j++)
 			add (g[j], s[j]);
 		int cur = 0;
 		for (int j = 0; j < m; j++) cur += o[j];
 		if (cur > ans) { ans = cur; cnt = 1; } else
 		if (cur == ans) cnt++; 
 		re 0;
 	}
 	for (int j = 0; j < m; j++) {
 		g[i] = j;
 		gen (i + 1);
 	}
 	re 0;
 }
 
 int main () {
 	int tt;
 	cin >> tt;
 	for (int it = 1; it <= tt; it++) {
 		cin >> n >> m;
 		for (int i = 0; i < n; i++) cin >> s[i];
 		ans = 0;
 		cnt = 0;
 		gen (0);	
 		cout << "Case #" << it << ": " << ans << " " << cnt;
 		cout << endl;
 		fprintf (stderr, "%d / %d = %.2f | %.2f\n", it, tt, (double)clock () / CLOCKS_PER_SEC, ((double)clock () / it * tt) / CLOCKS_PER_SEC);
 	}
 	return 0;
 }