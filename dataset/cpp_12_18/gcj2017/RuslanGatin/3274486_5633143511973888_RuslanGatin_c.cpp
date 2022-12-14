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
 	freopen("c-small1.in", "r", stdin);
 	freopen("c-small1.out", "w", stdout);
 	//freopen("-large.in", "r", stdin);
 	//freopen("-large.out", "w", stdout);
 }
 
 const int maxn = 55;
 
 int n, m;
 int u, p[maxn], b[maxn];
 double res;
 
 void read()
 {
 	n = ni();
 	m = ni();
 	u = (int)(nf() * 10000 + eps);
 	fi(n)
 		p[i] = (int)(nf() * 10000 + eps);
 }
 
 void rec(int id, int v, double cur)
 {
 	if (cur < res)
 		return;
 	if (id >= n)
 		res = max(res, cur);
 	double res = 0;
 	fd(i, v, 0)
 		rec(id + 1, v - i, cur * (p[id] + i) / 10000.0);
 }
 
 double get(int mid)
 {
 	int v = u;
 	fi(n)
 	{
 		b[i] = p[i];
 		if (b[i] < mid)
 		{
 			int d = min(v, mid - b[i]);
 			b[i] += d;
 			v -= d;
 		}
 	}
 	double res = 1;
 	fi(n)
 		res *= b[i] / 10000.;
 	return res;
 }
 
 void solve(int test_num)
 {
 	//cerr << test_num << endl;
 	printf("Case #%d: ", test_num);
 	sort(p, p + n);
 	//reverse(p, p + n);
 	//rec(0, u, 1);
 	double res = 0;
 	double s = 0;
 	fi(n)
 	{
 		s += p[i];
 	}
 	s += u;
 	s /= n;
 	s /= 10000.0;
 	res = 1;
 	fi(n)
 		res *= s;
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