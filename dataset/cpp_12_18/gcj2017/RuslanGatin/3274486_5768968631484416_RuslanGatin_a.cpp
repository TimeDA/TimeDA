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
 
 const int maxn = 1010;
 const double pi = acos(-1.0);
 
 int n, m;
 pii p[maxn];
 
 void read()
 {
 	n = ni();
 	m = ni();
 	fi(n)
 	{
 		p[i].second = ni();
 		p[i].first = ni();
 	}
 }
 
 vector<pii> get(int id)
 {
 	vector<pii> ret;
 	ret.pb(p[id]);
 	fi(n)
 	{
 		if (i == id)
 			continue;
 		if (sz(ret) >= m)
 			return ret;
 		if (p[i].second <= p[id].second)
 			ret.pb(p[i]);
 	}
 	return ret;
 }
 
 double calc(vector<pii> &v)
 {
 	double ret = 0;
 	fd(i, sz(v) - 1, 0)
 	{
 		ret += 2.0 * pi * (double)v[i].second * (double)v[i].first;
 	}
 	return ret;
 }
 
 double sq(double r)
 {
 	return pi * r * r;
 }
 
 int bit(int mask, int id)
 {
 	return (mask >> id) & 1;
 }
 
 double stupid()
 {
 	double res = 0;
 	fo(mask, 0, 1 << n)
 	{
 		int c = 0;
 		fi(n)
 		{
 			if (bit(mask, i))
 				c++;
 		}
 		if (c != m)
 			continue;
 		double cur = 0, maxR = 0;
 		fi(n)
 		{
 			if (bit(mask, i))
 			{
 				maxR = max(maxR, (double)p[i].second);
 				cur += 2.0 * pi * (double)p[i].second * p[i].first;
 			}
 		}
 		res = max(res, cur + pi * maxR * maxR);
 	}
 	return res;
 }
 
 bool cmp(const pii &a, const pii &b)
 {
 	lint s1 = (lint)a.first * a.second;
 	lint s2 = (lint)b.first * b.second;
 	return s1 < s2;
 }
 
 void solve(int test_num)
 {
 	//cerr << test_num << endl;
 	printf("Case #%d: ", test_num);
 	sort(p, p + n, cmp);
 	reverse(p, p + n);
 	double res = 0;
 	fi(n)
 	{
 		vector<pii> top = get(i);
 		if (sz(top) < m)
 			continue;
 		res = max(res, calc(top) + sq(p[i].second));
 	}
 	printf("%.10lf", res);
 	printf("\n");
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