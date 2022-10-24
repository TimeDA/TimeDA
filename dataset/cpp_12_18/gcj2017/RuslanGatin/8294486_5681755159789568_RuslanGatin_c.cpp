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
 	freopen("c-small.in", "r", stdin);
 	freopen("c-small.out", "w", stdout);
 	//freopen("c-large.in", "r", stdin);
 	//freopen("c-large.out", "w", stdout);
 }
 
 const int maxn = 110;
 
 int n;
 double e[maxn], s[maxn], dd[maxn][maxn], d[maxn];
 set < pair<double, pii> > q;
 int qcount;
 pair<int, int> query[maxn];
 
 void read()
 {
 	n = ni();
 	qcount = ni();
 	fi(n)
 	{
 		e[i] = nf();
 		s[i] = nf();
 	}
 	fi(n)
 	{
 		fj(n)
 			dd[i][j] = nf();
 	}
 	fi(qcount)
 	{
 		query[i].first = ni() - 1;
 		query[i].second = ni() - 1;
 	}
 }
 
 //void add(int id, int hid, double nd)
 //{
 //	if (d[id][hid] > nd)
 //	{
 //		q.erase(mp(d[id][hid], mp(id, hid)));
 //		d[id][hid] = nd;
 //		q.insert(mp(d[id][hid], mp(id, hid)));
 //	}
 //}
 
 bool used[maxn];
 double dij(int from, int to)
 {
 	fi(n)
 		d[i] = 1e20;
 	__(used);
 	d[from] = 0;
 	while (true)
 	{
 		int id = -1;
 		fi(n)
 		{
 			if (!used[i] && (id < 0 || d[id] > d[i]))
 			{
 				id = i;
 			}
 		}
 		if (id < 0)
 			break;
 		used[id] = true;
 		fi(n)
 		{
 			if (dd[id][i] < 0 || dd[id][i] > e[id])
 				continue;
 			double t = dd[id][i] / s[id];
 			d[i] = min(d[i], d[id] + t);
 		}
 	}
 	return d[to];
 }
 
 void solve(int test_num)
 {
 	//cerr << test_num << endl;
 	printf("Case #%d: ", test_num);
 	fk(n)
 	{
 		fi(n)
 		{
 			fj(n)
 			{
 				if (dd[i][k] >= 0 && dd[k][j] >= 0 && (dd[i][j] < 0 || dd[i][j] > dd[i][k] + dd[k][j]))
 					dd[i][j] = dd[i][k] + dd[k][j];
 			}
 		}
 	}
 	fi(qcount)
 		printf("%.10lf ", dij(query[i].first, query[i].second));
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