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
 	freopen("d-small.in", "r", stdin);
 	freopen("d-small.out", "w", stdout);
 	//freopen("-large.in", "r", stdin);
 	//freopen("-large.out", "w", stdout);
 }
 
 const int maxn = 10;
 
 int n;
 int a[maxn][maxn], b[maxn][maxn];
 
 void read()
 {
 	n = ni();
 	string s;
 	getline(cin, s);
 	fi(n)
 	{
 		getline(cin, s);
 		fj(n)
 			a[i][j] = s[j] - '0';
 	}
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
 
 int tt;
 int used[maxn];
 int p[maxn];
 
 bool allUsed()
 {
 	fi(n)
 	{
 		if (used[i] != tt)
 			return false;
 	}
 	return true;
 }
 
 bool rec(int cur)
 {
 	if (cur >= n)
 		return true;
 	int id = p[cur];
 	bool ok = false;
 	fi(n)
 	{
 		if (used[i] == tt || !b[id][i])
 			continue;
 		used[i] = tt;
 		if (!rec(cur + 1))
 			return false;
 		used[i] = 0;
 		ok = true;
 	}
 	return ok;
 }
 
 bool check()
 {
 	fi(n)
 		p[i] = i;
 	do
 	{
 		tt++;
 		if (!rec(0))
 			return false;
 	}
 	while (next_permutation(p, p + n));
 	return true;
 }
 
 void solve(int test_num)
 {
 	//cerr << test_num << endl;
 	printf("Case #%d: ", test_num);
 	int res = INF;
 	int _2n = 1 << (n * n);
 	fo(mask, 0, _2n)
 	{
 		int bc = bitCount(mask);
 		if (bc >= res)
 			continue;
 		int ix = 0;
 		bool ok = true;
 		fi(n)
 		{
 			fj(n)
 			{
 				b[i][j] = a[i][j];
 				if (bit(mask, ix))
 				{
 					if (b[i][j])
 						ok = false;
 					b[i][j] = 1;
 				}
 				ix++;
 			}
 		}
 		if (!ok)
 			continue;
 		if (check())
 			res = bc;
 	}
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