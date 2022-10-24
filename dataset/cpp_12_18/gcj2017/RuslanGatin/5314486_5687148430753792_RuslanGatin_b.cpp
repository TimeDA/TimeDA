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
 
 const int maxn = 1010;
 
 int n, c, m;
 pii p[maxn];
 int cnt[maxn];
 
 void read()
 {
 	scanf("%d%d%d", &n, &c, &m);
 	fi(m)
 	{
 		p[i].first = ni() - 1;
 		p[i].second = ni() - 1;
 	}
 }
 
 int moveG(int g, int bound)
 {
 	while (cnt[g] >= bound)
 		g++;
 	return g;
 }
 
 int calc(int bound)
 {
 	__(cnt);
 	int res = 0, g = 0;
 	fi(m)
 	{
 		int seat = p[i].first;
 		if (cnt[seat] < bound)
 			cnt[seat]++;
 		else
 		{
 			g = moveG(g, bound);
 			if (g >= seat)
 				return -1;
 			cnt[g]++;
 			res++;
 		}
 	}
 	return res;
 }
 
 void solve(int test_num)
 {
 	//cerr << test_num << endl;
 	printf("Case #%d: ", test_num);
 	sort(p, p + m);
 	__(cnt);
 	fi(m)
 	{
 		cnt[p[i].second]++;
 	}
 	int mx = *max_element(cnt, cnt + n);
 	int lb = mx - 1, rb = m;
 	while (rb - lb > 1)
 	{
 		int mid = (lb + rb) / 2;
 		int g = calc(mid);
 		if (g < 0)
 			lb = mid;
 		else
 			rb = mid;
 	}
 	printf("%d %d\n", rb, calc(rb));
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