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

const int maxn = 4;

int n;
int a[maxn][maxn], b[maxn][maxn];

void read()
{
	n = ni();
	fi(n)
		fj (n)
		a[i][j] = ni();
}

int bitCount(int mask)
{
	int ret = 0;
	while (mask)
	{
		ret++;
		mask &= mask - 1;
	}
	return ret;
}

bool rep(int color, int row, int col, int drow, int dcol)
{
	int x = row, y = col;
	while (x < n && y < n)
	{
		if (b[x][y] == color)
			return true;
		x += drow;
		y += dcol;
	}
	return false;
}

bool repH(int cl, int x, int y)
{
	return rep(cl, x, 0, 0, 1);
}

bool repV(int cl, int x, int y)
{
	return rep(cl, 0, y, 1, 0);
}

bool rep(int x, int y)
{
	if (b[x][y] == INF)
		return false;
	b[x][y] = INF;
	bool ok = repH(a[x][y], x, y) || repV(a[x][y], x, y);
	b[x][y] = a[x][y];
	return ok;
}

int bit(int mask, int x)
{
	return (mask >> x) & 1;
}

bool good(int mask)
{
	memcpy(b, a, sizeof(b));
	fi(n)
	{
		fj(n)
		{
			if (bit(mask, i * n + j))
				b[i][j] = INF;
		}
	}
	fi(n)
	{
		fj(n)
		{
			if (rep(i, j))
				return false;
		}
	}
	return true;
}

void solve(int test_num)
{
	//cerr << test_num << endl;
	printf("Case #%d: ", test_num);
	int _2n = 1 << (n * n);
	int ans = INF;
	fo(mask, 0, _2n)
	{
		if (good(mask))
			ans = min(ans, bitCount(mask));
	}
	assert(ans != INF);
	printf("%d\n", ans);
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