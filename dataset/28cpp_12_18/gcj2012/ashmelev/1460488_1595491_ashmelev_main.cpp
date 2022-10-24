#ifndef LOCAL_BOBER
 #pragma comment(linker, "/STACK:134217728")
 #endif
 
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
 #define prev prev239
 #define next next239
 #define hash hash239
 #define rank rank239
 #define sqrt(x) sqrt(abs(x))
 #define unq(x) (x.resize(unique(all(x)) - x.begin()))
 
 using namespace std;
 
 typedef vector<int> vi;
 typedef vector<vi> vvi;
 typedef pair<int, int> ii;
 typedef vector<ii> vii;
 typedef vector<string> vs;
 typedef long long ll;
 typedef double D;
 typedef long double LD;
 typedef pair<ll, ll> pll;
 
 template<class T> T abs(T x) {
 	return x > 0 ? x : -x;
 }
 
 int m;
 int n;
 
 int g;
 int t[200];
 
 int table[200][200];
 int w[200][200];
 int ct;
 
 int t2[100][2];
 int w2[100][2];
 
 int get(int val, int f) {
 	if (w2[val][f] == ct)
 		re t2[val][f];
 	w2[val][f] = ct;
 	rep(i, 11) rep(j, 11) {
 		int k = val - i - j;
 		if (k < 0 || k > 10)
 			continue;
 		int mas[3];
 		mas[0] = i;
 		mas[1] = j;
 		mas[2] = k;
 		sort(mas, mas + 3);
 		if (mas[2] - mas[0] > 2)
 			continue;
 		if (mas[2] - mas[0] == 2 && !f)
 			continue;
 		if (mas[2] - mas[0] < 2 && f)
 			continue;
 		if (mas[2] >= g) {
 			t2[val][f] = 1;
 			re 1;
 		}
 	}
 	t2[val][f] = 0;
 	re 0;
 }
 
 int getans(int p, int s) {
 	if (p == n) {
 		if (s == 0)
 			re 0;
 		else
 			re -1005000;
 	}
 	int &ans = table[p][s];
 	if (w[p][s] == ct)
 		re ans;
 	w[p][s] = ct;
 
 	ans = getans(p + 1, s) + get(t[p], 0);
 	if (s)
 		ans = max(ans, getans(p + 1, s - 1) + get(t[p], 1));
 	re ans;
 }
 
 int main() {
 #ifdef LOCAL_BOBER
 	freopen("input.txt", "r", stdin);
 	freopen("output.txt", "w", stdout);
 #else
 #endif
 
 	int tc;
 	cin >> tc;
 	rep(tt, tc) {
 		cout << "Case #" << tt + 1 << ": ";
 		int s;
 		cin >> n >> s >> g;
 		rep(i, n)
 			cin >> t[i];
 		ct++;
 		cout << getans(0, s) << endl;
 	}
 
 	re 0;
 }
