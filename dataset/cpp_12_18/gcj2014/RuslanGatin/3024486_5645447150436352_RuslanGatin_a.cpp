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
 	freopen("a-small.in", "r", stdin);
 	freopen("a-small.out", "w", stdout);
 	//freopen("-large.in", "r", stdin);
 	//freopen("-large.out", "w", stdout);
 }
 
 const int maxn = 1 << 20;
 
 int n, p, q, r, s;
 int a[maxn];
 lint sum[maxn];
 lint res;
 
 void read()
 {
 	scanf("%d%d%d%d%d", &n, &p, &q, &r, &s);
 	fi(n)
 		a[i] = ((long long)i * p + q) % r + s;
 }
 
 lint g(int l, int r)
 {
 	if (l > r)
 		return 0;
 	lint ret = sum[r];
 	if (l)
 		ret -= sum[l - 1];
 	return ret;
 }
 
 void check(int l, int r)
 {
 	if (l <= 0 || l > r)
 		return;
 	res = max(res, sum[n] - max(max(g(1, l - 1), g(r + 1, n)), g(l, r)));
 }
 
 void go1(int x)
 {
 	int lb = 0, rb = x + 1;
 	while (rb - lb > 1)
 	{
 		int mid = (lb + rb) / 2;
 		if (g(mid, x) > g(x + 1, n))
 			lb = mid;
 		else
 			rb = mid;
 	}
 	check(lb, x);
 	check(rb, x);
 }
 
 void go2(int x)
 {
 	int lb = 0, rb = x + 1;
 	while (rb - lb > 1)
 	{
 		int mid = (lb + rb) / 2;
 		if (g(mid, x) > g(1, mid - 1))
 			lb = mid;
 		else
 			rb = mid;
 	}
 	check(lb, x);
 	check(rb, x);
 }
 
 void go3(int x)
 {
 	int lb = 0, rb = x + 1;
 	while (rb - lb > 1)
 	{
 		int mid = (lb + rb) / 2;
 		if (g(mid, x) < g(x + 1, n) || g(mid, x) < g(1, mid - 1))
 			rb = mid;
 		else
 			lb = mid;
 	}
 	check(lb, x);
 }
 
 void solve(int test_num)
 {
 	//cerr << test_num << endl;
 	printf("Case #%d: ", test_num);
 	sum[0] = 0;
 	fi(n)
 		sum[i + 1] = sum[i] + a[i];
 	res = 0;
 	//fi(n + 1) if (i)
 	//{
 	//	fj(i + 1) if (j)
 	//	{
 	//		check(j, i);
 	//		if (res == 1429)
 	//		{
 	//			int q = 2;
 	//		}
 	//	}
 	//}
 	fi(n + 1) if (i)
 	{
 		go1(i);
 		go2(i);
 		go3(i);
 	}
 	printf("%.10lf\n", (double)res / sum[n]);
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