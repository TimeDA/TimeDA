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
 
 const int maxn = 105;
 
 int p, q, n;
 int h[maxn], g[maxn];
 int dp[maxn][maxn * maxn];
 int v[maxn];
 
 void read()
 {
 	p = ni();
 	q = ni();
 	n = ni();
 	fi(n)
 	{
 		h[i] = ni();
 		g[i] = ni();
 	}
 }
 
 int dv(int x, int y)
 {
 	return (x + y - 1) / y;
 }
 
 void upd(int &d, int nd)
 {
 	d = max(d, nd);
 }
 
 bool get(int id, int z, int &nz)
 {
 	z -= v[id];
 	int o = h[id] - v[id] * p;
 	if (o > 0)
 	{
 		int c = dv(o, q) - 1;
 		z += c;
 		z--;
 	}
 	nz = z;
 	return nz >= 0;
 }
 
 void solve(int test_num)
 {
 	//cerr << test_num << endl;
 	printf("Case #%d: ", test_num);
 
 	fi(n)
 	{
 		v[i] = 21;
 		fj(22)
 		{
 			int o = h[i] - j * p;
 			if (o <= 0)
 			{
 				v[i] = j;
 				break;
 			}
 			int c = dv(o, q) - 1;
 			o -= c * q;
 			if (o <= p)
 			{
 				v[i] = j;
 				break;
 			}
 		}
 	}
 
 	_(dp, -1);
 	dp[0][1] = 0;
 	fi(n)
 	{
 		fj(maxn * maxn)
 		{
 			if (dp[i][j] < 0)
 				continue;
 			int oj;
 			if (get(i, j, oj))
 				upd(dp[i + 1][oj], dp[i][j] + g[i]);
 			upd(dp[i + 1][j + dv(h[i], q)], dp[i][j]);
 		}
 	}
 	int res = 0;
 	fi(maxn * maxn)
 		res = max(res, dp[n][i]);
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