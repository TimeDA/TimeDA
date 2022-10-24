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
 	freopen("c-small-1.in", "r", stdin);
 	freopen("c-small-1.out", "w", stdout);
 	//freopen("-large.in", "r", stdin);
 	//freopen("-large.out", "w", stdout);
 }
 
 lint n, m;
 map<lint, lint, greater<lint> > cnt;
 
 void read()
 {
 	n = nll();
 	m = nll();
 }
 
 void solve(int test_num)
 {
 	//cerr << test_num << endl;
 	printf("Case #%d: ", test_num);
 	cnt.clear();
 	cnt[n] = 1;
 	while (true)
 	{
 		pair<lint, lint> c = *cnt.begin();
 		m -= c.second;
 		if (m <= 0)
 			break;
 		cnt.erase(cnt.begin());
 		lint l = c.first / 2;
 		lint r = (c.first - 1) / 2;
 		cnt[l] += c.second;
 		cnt[r] += c.second;
 	}
 	lint q = cnt.begin()->first;
 	printf("%lld %lld\n", q / 2, (q - 1) / 2);
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