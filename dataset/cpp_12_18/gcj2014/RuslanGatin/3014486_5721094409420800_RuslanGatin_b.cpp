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
 	freopen("b-small.in", "r", stdin);
 	freopen("b-small.out", "w", stdout);
 	//freopen("-large.in", "r", stdin);
 	//freopen("-large.out", "w", stdout);
 }
 
 int n;
 vector<int> a;
 
 void read()
 {
 	n = ni();
 	a.resize(n);
 	fi(n)
 		a[i] = ni();
 }
 
 int calc(vector<int> v, bool gg) {
 	int res = 0;
 	fi(sz(v)) {
 		fj(sz(v)) {
 			if (i < j) {
 				if (gg && v[i] > v[j] ||
 					!gg && v[i] < v[j]) {
 					res++;
 				}
 			}
 		}
 	}
 	return res;
 }
 
 int calc(int mid) {
 	vector<int> v, w;
 	fi(mid)
 		v.pb(a[i]);
 	fo(i, mid, n)
 		w.pb(a[i]);
 	int res = calc(v, true);
 	int res2 = calc(w, false);
 	return res + res2;
 }
 
 void solve(int test_num)
 {
 	//cerr << test_num << endl;
 	printf("Case #%d: ", test_num);
 	int res = 0;
 	fi(n) {
 		int c = 0, p = 0;
 		fj(i) {
 			if (a[j] > a[i])
 				c++;
 		}
 		fo(j, i + 1, n) {
 			if (a[j] > a[i])
 				p++;
 		}
 		res += min(c, p);
 	}
 
 	printf("%d\n", res);
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