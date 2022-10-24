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
 	freopen("c-small.in", "r", stdin);
 	freopen("c-small.out", "w", stdout);
 	//freopen("-large.in", "r", stdin);
 	//freopen("-large.out", "w", stdout);
 }
 
 const int maxn = 200100;
 
 struct R {
 	int xl, yl, xr, yr;
 	void read() {
 		yl = ni();
 		xl = ni();
 		yr = ni();
 		xr = ni();
 	}
 };
 
 int n, m, c;
 R r[maxn];
 int dx[] = {-1, 0, 1, 0};
 int dy[] = {0, 1, 0, -1};
 
 struct Edge
 {
 	int a, b, cap, id;
 	Edge(int a, int b, int cap, int id): a(a), b(b), cap(cap), id(id) {}
 };
 
 int S, T;
 vector<Edge> e;
 vector<int> g[maxn];
 int ptr[maxn], dist[maxn], q[maxn], sq;
 
 void clear() {
 	e.clear();
 	fi(T + 1)
 		g[i].clear();
 }
 
 void adde(int a, int b, int cap)
 {
 	g[a].pb(sz(e));
 	e.pb(Edge(a, b, cap, sz(e)));
 	g[b].pb(sz(e));
 	e.pb(Edge(b, a, 0, sz(e)));
 }
 
 bool bfs()
 {
 	memset(dist, -1, sizeof(dist[0]) * (T + 1));
 	dist[S] = 0;
 	sq = 0;
 	q[sq++] = S;
 	for (int i = 0; i < sq; i++)
 	{
 		int id = q[i];
 		for (int j = 0; j < sz(g[id]); j++)
 		{
 			Edge &t = e[g[id][j]];
 			if (t.cap > 0 && dist[t.b] < 0)
 			{
 				dist[t.b] = dist[t.a] + 1;
 				q[sq++] = t.b;
 			}
 		}
 	}
 	return dist[T] >= 0;
 }
 
 int dfs(int id, int exp)
 {
 	if (exp == 0 || id == S)
 		return exp;
 	for (int &i = ptr[id]; i < sz(g[id]); i++)
 	{
 		Edge &t = e[g[id][i] ^ 1];
 		if (dist[t.b] == dist[t.a] + 1)
 		{
 			int push = dfs(t.a, min(exp, t.cap));
 			if (push)
 			{
 				t.cap -= push;
 				e[t.id ^ 1].cap += push;
 				return push;
 			}
 		}
 	}
 	return 0;
 }
 
 void init()
 {
 	for (int i = 0; i < sz(e); i += 2)
 	{
 		e[i].cap += e[i ^ 1].cap;
 		e[i ^ 1].cap = 0;
 	}
 }
 
 int flow()
 {
 	int f = 0;
 	while (bfs())
 	{
 		memset(ptr, 0, sizeof(ptr[0]) * (T + 1));
 		int x;
 		while (x = dfs(T, INF))
 			f += x;
 	}
 	return f;
 }
 
 void read()
 {
 	m = ni();
 	n = ni();
 	c = ni();
 	fi(c)
 		r[i].read();
 }
 
 bool ins(int x, int l, int r) {
 	return l <= x && x <= r;
 }
 
 bool check(int x, int y) {
 	if (x < 0 || y < 0 || x >= n || y >= m)
 		return false;
 	fi(c) {
 		if (ins(x, r[i].xl, r[i].xr) && ins(y, r[i].yl, r[i].yr))
 			return false;
 	}
 	return true;
 }
 
 int getId(int x, int y) {
 	return x * m + y;
 }
 
 void solve(int test_num)
 {
 	cerr << test_num << endl;
 	printf("Case #%d: ", test_num);
 	int nm = n * m;
 	S = n * m * 2;
 	T = S + 1;
 	fi(n) {
 		fj(m) {
 			if (!check(i, j))
 				continue;
 			fk(4) {
 				int x = i + dx[k];
 				int y = j + dy[k];
 				if (!check(x, y))
 					continue;
 				adde(getId(i, j) + nm, getId(x, y), 1);
 			}
 			adde(getId(i, j), getId(i, j) + nm, 1);
 			if (i == 0)
 				adde(S, getId(i, j), 1);
 			if (i == n - 1)
 				adde(getId(i, j) + nm, T, 1);
 		}
 	}
 	printf("%d\n", flow());
 	clear();
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