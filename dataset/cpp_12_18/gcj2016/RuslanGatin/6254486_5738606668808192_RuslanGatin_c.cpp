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
 	//freopen("-small.in", "r", stdin);
 	//freopen("a-small.out", "w", stdout);
 	//freopen("-large.in", "r", stdin);
 	freopen("a-large.out", "w", stdout);
 }
 
 int n, m;
 int primes[] = {2, 3, 5, 7};
 
 void read()
 {
 	n = ni();
 	m = ni();
 }
 
 string toString(int mask)
 {
 	string ret = "1";
 	fi(n - 2)
 	{
 		ret.pb('0' + (mask & 1));
 		mask >>= 1;
 	}
 	ret.pb('1');
 	return ret;
 }
 
 bool check2(string &s, int v, int d)
 {
 	int res = 0;
 	for (int i = 0; i < sz(s); i++)
 		res = (res * v + (s[i] - '0')) % d;
 	return res == 0;
 }
 
 bool check(int mask, vector<int> &v)
 {
 	v.clear();
 	string s = toString(mask);
 	for (int i = 2; i <= 10; i++)
 	{
 		bool ok = false;
 		for (int j = 0; j < 4; j++)
 		{
 			if (check2(s, i, primes[j]))
 			{
 				v.pb(primes[j]);
 				ok = true;
 				break;
 			}
 		}
 		if (!ok)
 			return false;
 	}
 	return true;
 }
 
 void solve(int test_num)
 {
 	//cerr << test_num << endl;
 	printf("Case #%d:\n", test_num);
 	int nn = n - 2, _2nn = 1 << nn;
 	for (int mask = 0; mask < _2nn && m > 0; mask++)
 	{
 		vector<int> v;
 		if (check(mask, v))
 		{
 			printf("%s", toString(mask).c_str());
 			for (int i = 0; i < sz(v); i++)
 				printf(" %d", v[i]);
 			printf("\n");
 			m--;
 		}
 	}
 	cerr << m << endl;
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