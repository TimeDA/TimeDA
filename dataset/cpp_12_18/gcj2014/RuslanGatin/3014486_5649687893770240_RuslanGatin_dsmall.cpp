#define _CRT_SECURE_NO_DEPRECATE
 #pragma comment (linker, "/stack:256000000")
 
 #include <iostream>
 #include <cstdio>
 #include <sstream>
 #include <vector>
 #include <string>
 #include <algorithm>
 #include <cmath>
 #include <queue>
 #include <deque>
 #include <set>
 #include <bitset>
 #include <map>
 #include <memory.h>
 #undef NDEBUG
 #include <cassert>
 #include <ctime>
 
 using namespace std;
 
 #define fo(a,b,c) for (int a = (b); a < (c); a++)
 #define fr(a,b) fo(a, 0, (b))
 #define fi(n) fr(i, (n))
 #define fj(n) fr(j, (n))
 #define fk(n) fr(k, (n))
 #define fd(a,b,c) for (int a = (b); a >= (c); a--)
 #define all(a) (a).begin(), (a).end()
 #define rall(a) (a).rbegin(), (a).rend()
 #define _(a,b) memset((a), (b), sizeof(a))
 #define __(a) memset((a), 0, sizeof(a))
 #define sz(a) (int)(a).size()
 #define mp make_pair
 #define pb push_back
 
 typedef long long lint;
 typedef unsigned long long ull;
 typedef vector<int> VI;
 typedef vector<string> VS;
 typedef pair<int, int> pii;
 
 const int INF = 1000000000;
 const lint LINF = 4000000000000000000LL;
 const double eps = 1e-9;
 
 int ni() { int a; scanf( "%d", &a ); return a; }
 double nf() { double a; scanf( "%lf", &a ); return a; }
 char sbuf[100005]; string ns() { scanf( "%s", sbuf ); return sbuf; }
 long long nll() { long long a; scanf( "%lld", &a ); return a; }
 
 void prepare()
 {
 	freopen("input.txt", "r", stdin);
 	freopen("d-small.in", "r", stdin);
 	freopen("d-small.out", "w", stdout);
 	//freopen("-large.in", "r", stdin);
 	//freopen("-large.out", "w", stdout);
 }
 
 int n, m;
 string s[10];
 vector<string> w[4];
 set<ull> se;
 
 void read()
 {
 	n = ni();
 	m = ni();
 	fi(n)
 		s[i] = ns();
 }
 
 int calc(const vector<string> &w) {
 	if (w.empty())
 		return 0;
 	se.clear();
 	fi(sz(w)) {
 		ull h = 0;
 		fj(sz(w[i])) {
 			h = h * 3137 + w[i][j];
 			se.insert(h);
 		}
 	}
 	return sz(se) + 1;
 }
 
 void solve(int test_num)
 {
 	cerr << test_num << endl;
 	printf("Case #%d: ", test_num);
 	int cnt = 0, res = 0;
 	int x = 0;
 	fi(1 << (n * 2)) {
 		fj(4)
 			w[j].clear();
 		fj(n) {
 			w[(i >> (j * 2)) & 3].pb(s[j]);
 		}
 		bool ok = true;
 		fj(4) {
 			if (j >= m && !w[j].empty())
 				ok = false;
 		}
 		if (!ok)
 			continue;
 		int cur = 0;
 		fj(m)
 			cur += calc(w[j]);
 		if (res < cur) {
 			res = cur;
 			cnt = 1;
 		} else if (res == cur) {
 			cnt++;
 		}
 		x++;
 	}
 	printf("%d %d\n", res, cnt);
 }
 
 int main()
 {
 	prepare();
 	int number_of_tests;
 	scanf("%d\n", &number_of_tests);
 	fi(number_of_tests)
 	{
 		read();
 		solve(i + 1);
 	}
 	return 0;
 }