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
 
 string s1[3] = {"oqa zoo ejp mysljylc kd kxveddknmc re jsicpdrysi", "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd", "de kr kd eoya kw aej tysr re ujdr lkgc jv"};
 string s2[3] = {"kzy qee our language is impossible to understand", "there are twenty six factorial possibilities", "so it is okay if you want to just give up"};
 
 char get(char c) {
 	rep(i, 3)
 	rep(j, sz(s1[i]))
 	if (s1[i][j] == c)
 		re s2[i][j];
 	re c;
 }
 
 int main() {
 #ifdef LOCAL_BOBER
 	freopen("input.txt", "r", stdin);
 	freopen("output.txt", "w", stdout);
 #else
 #endif
 
 	int tc;
 	cin >> tc;
 	char s[100500];
 	gets(s);
 
 	rep(tt, tc) {
 		cout << "Case #" << tt + 1 << ": ";
 		gets(s);
 		n = strlen(s);
 		rep(i, n)
 			cout << get(s[i]);
 		cout << endl;
 	}
 
 	re 0;
 }
