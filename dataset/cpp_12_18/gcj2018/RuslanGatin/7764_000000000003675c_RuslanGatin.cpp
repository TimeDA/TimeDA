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
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	//freopen("-small.in", "r", stdin);
	//freopen("-small.out", "w", stdout);
	//freopen("-large.in", "r", stdin);
	//freopen("-large.out", "w", stdout);
#endif
}

const int maxn = 105;

int n;
pii p[maxn];
vector<lint> g, g2;
int T, used[maxn];

void read()
{
	scanf("%d", &n);
	fi(n)
	{
		scanf("%d%d", &p[i].first, &p[i].second);
		p[i].first--;
		p[i].second--;
	}
	g.resize(n);
	fi(n)
		scanf("%lld", &g[i]);
}

bool dfs(int id, lint g)
{
	if (used[id] == T)
		return false;
	used[id] = T;
	if (g2[id] >= g)
	{
		g2[id] -= g;
		used[id] = 0;
		return true;
	}
	lint rem = g - g2[id];
	if (dfs(p[id].first, rem) && dfs(p[id].second, rem))
	{
		used[id] = 0;
		g2[id] = 0;
		return true;
	}
	used[id] = 0;
	return false;
}

void solve(int test_num)
{
	//cerr << test_num << endl;
	printf("Case #%d: ", test_num);
	lint lb = g[0], rb = LINF;
	while (rb - lb > 1)
	{
		lint mid = (rb + lb) >> 1;
		g2 = g;
		T++;
		if (dfs(0, mid))
			lb = mid;
		else
			rb = mid;
	}
	printf("%lld\n", lb);
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