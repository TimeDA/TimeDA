#define push_back pb
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
 //#define pb push_back
 
 typedef long long lint;
 typedef unsigned long long ull;
 typedef vector<int> VI;
 typedef vector<string> VS;
 typedef pair<int, int> pii;
 
 const int INF = 1000000000;
 const lint LINF = 4000000000000000000LL;
 const double eps = 1e-9;
 
 int ni() { int a; scanf("%d", &a); return a; }
 double nf() { double a; scanf("%lf", &a); return a; }
 char sbuf[100005]; string ns() { scanf("%s", sbuf); return sbuf; }
 long long nll() { long long a; scanf("%lld", &a); return a; }
 
 void prepare()
 {
 	freopen("input.txt", "r", stdin);
 	freopen("a-small.in", "r", stdin);
 	freopen("a-small.out", "w", stdout);
 	//freopen("-large.in", "r", stdin);
 	//freopen("-large.out", "w", stdout);
 }
 
 const int maxn = 100100;
 
 int n;
 double d;
 double start[maxn], speed[maxn];
 
 void read()
 {
 	d = nf();
 	n = ni();
 	fi(n)
 	{
 		start[i] = nf();
 		speed[i] = nf();
 	}
 }
 
 bool eq(double a, double b)
 {
 	return a - b <= eps && b - a <= eps;
 }
 
 bool check(double s)
 {
 	fi(n)
 	{
 		double x;
 		if (speed[i] >= s - eps)
 		{
 			x = 1e12;
 		}
 		else
 		{
 			double t = start[i] / (s - speed[i]);
 			x = s * t;
 		}
 		if (x < d)
 			return false;
 	}
 	return true;
 }
 
 void solve(int test_num)
 {
 	//cerr << test_num << endl;
 	printf("Case #%d: ", test_num);
 	double lb = 0, rb = 1e12;
 	fi(200)
 	{
 		double mid = (lb + rb) * 0.5;
 		if (check(mid))
 			lb = mid;
 		else
 			rb = mid;
 	}
 	printf("%.10lf\n", lb);
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