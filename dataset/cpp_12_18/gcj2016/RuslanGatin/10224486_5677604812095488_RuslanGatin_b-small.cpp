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
 
 const int maxn = 20;
 
 int n, m;
 double p[maxn];
 double dp[maxn][maxn][maxn];
 
 void read()
 {
 	n = ni();
 	m = ni();
 	fi(n)
 		p[i] = nf();
 }
 
 int bitCount(int x)
 {
 	int res = 0;
 	while (x)
 	{
 		res++;
 		x &= x - 1;
 	}
 	return res;
 }
 
 int bit(int mask, int id)
 {
 	return (mask >> id) & 1;
 }
 
 void upd(double &d, double nd)
 {
 	d = max(d, nd);
 }
 
 void solve(int test_num)
 {
 	cerr << test_num << endl;
 	printf("Case #%d: ", test_num);
 	int _2n = 1 << n;
 	int m2 = m >> 1;
 	double res = 0;
 	fo(mask, 0, _2n)
 	{
 		if (bitCount(mask) != m)
 			continue;
 		__(dp);
 		dp[0][0][0] = 1;
 		int cr = 0;
 		fi(n)
 		{
 			if (!bit(mask, i))
 				continue;
 			fo(cy, 0, m2 + 1)
 			{
 				fo(cn, 0, m2 + 1)
 				{
 					dp[cr + 1][cy + 1][cn] += dp[cr][cy][cn] * p[i];
 					dp[cr + 1][cy][cn + 1] += dp[cr][cy][cn] * (1.0 - p[i]);
 				}
 			}
 			cr++;
 		}
 		res = max(res, dp[cr][m2][m2]);
 	}
 	printf("%.10lf\n", res);
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