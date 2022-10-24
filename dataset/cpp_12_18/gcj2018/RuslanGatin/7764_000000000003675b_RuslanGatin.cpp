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

const int maxn = 110;

int n;
int d[maxn], a[maxn], b[maxn];

void read()
{
	scanf("%d", &n);
	fi(n)
		scanf("%d%d%d", &d[i], &a[i], &b[i]);
}

bool check(int x, int y, int start, int len)
{
	fo(q, 0, len)
	{
		int i = start + q;
		if (d[i] + a[i] == x || d[i] - b[i] == y)
			continue;
		if (x != INF && y != INF)
			return false;
		if (x == INF)
			x = d[i] + a[i];
		else if (y == INF)
			y = d[i] - b[i];
	}
	return true;
}

void solve(int test_num)
{
	//cerr << test_num << endl;
	printf("Case #%d: ", test_num);
	int cnt = 0, mx = 0;
	fd(len, n, 1)
	{
		bool ok = false;
		mx = len;
		fo(i, 0, n - len + 1)
		{
			int x = d[i] + a[i];
			int y = d[i] - b[i];
			if (check(x, INF, i, len) || check(INF, y, i, len))
			{
				ok = true;
				cnt++;
			}
		}
		if (ok)
			break;
	}
	printf("%d %d\n", mx, cnt);
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