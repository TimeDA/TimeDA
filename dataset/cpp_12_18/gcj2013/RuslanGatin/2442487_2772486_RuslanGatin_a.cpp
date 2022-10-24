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
 
 const int maxm = 1010;	
 const lint mod = 1000002013;
 
 struct Event
 {
 	int x, type;
 	lint cnt;
 	Event(int x, int type, int cnt): x(x), type(type), cnt(cnt)
 	{
 		
 	}
 	bool operator < (const Event &ev) const
 	{
 		if (x != ev.x)
 			return x < ev.x;
 		if (type != ev.type)
 			return type < ev.type;
 		return cnt < ev.cnt;
 	}
 };
 
 int nst, m;
 pii p[maxm];
 int cc[maxm];
 map<int, lint> cnt, bc;
 vector<Event> ev;
 
 void read()
 {
 	nst = ni();
 	m = ni();
 	fi(m)
 	{
 		p[i].first = ni();
 		p[i].second = ni();
 		cc[i] = ni();
 	}
 }
 
 lint get(lint n)
 {
 	return n * nst - n * (n - 1) / 2;
 }
 
 void solve(int test_num)
 {
 	//cerr << test_num << endl;
 	printf("Case #%d: ", test_num);
 	ev.clear();
 	lint must = 0;
 	fi(m)
 	{
 		ev.pb(Event(p[i].first, 0, cc[i]));
 		ev.pb(Event(p[i].second, 1, cc[i]));
 		(must += get(p[i].second - p[i].first) * cc[i]) %= mod;
 	}
 	sort(all(ev));
 
 	lint res = 0;
 	cnt.clear();
 	bc.clear();
 	int lastx = ev[0].x;
 	fi(sz(ev))
 	{
 		Event &e = ev[i];
 		if (e.x != lastx)
 		{
 			int dx = e.x - lastx;
 			for (map<int, lint>::iterator it = cnt.begin(); it != cnt.end(); ++it)
 			{
 				if (it->second)
 					bc[it->first + dx] += it->second;
 			}
 			cnt = bc;
 			bc.clear();
 		}
 		if (e.type)
 		{
 			for (map<int, lint>::iterator it = cnt.begin(); it != cnt.end(); ++it)
 			{
 				if (e.cnt == 0)
 					break;
 				lint z = min(e.cnt, it->second);
 				(res += get(it->first) * z) %= mod;
 				e.cnt -= z;
 				it->second -= z;
 			}
 		}
 		else
 		{
 			cnt[0] += e.cnt;
 		}
 		lastx = e.x;
 	}
 	res = (must - res) % mod;
 	res = (res + mod) % mod;
 	cout << res << endl;
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