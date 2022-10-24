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
	//freopen("input.txt", "r", stdin);
	//freopen("-small.in", "r", stdin);
	//freopen("-small.out", "w", stdout);
	//freopen("-large.in", "r", stdin);
	//freopen("-large.out", "w", stdout);
#endif
}

int a;
bool b[200][200];

void read()
{
	scanf("%d", &a);
	cerr << a << endl;
}

bool check(int x, int y)
{
	for (int i = -1; i <= 1; i++)
	{
		for (int j = -1; j <= 1; j++)
		{
			if (!b[x + i][y + j])
				return false;
		}
	}
	return true;
}

void solve(int test_num)
{
	cerr << "Test: " << test_num << endl;
	__(b);
	int res = 0;
	int len = (a + 2) / 3;
	for (int i = 1; i <= len + 3; i += 3)
	{
		if (i + 1 >= len)
			i = len - 2;
		while (!check(1, i))
		{
			printf("%d %d\n", 2, i + 1);
			fflush(stdout);
			int x, y;
			scanf("%d%d", &x, &y);
			if (x <= 0)
			{
				cerr << "res = " << res << endl;
				return;
			}
			b[x - 1][y - 1] = true;
			res++;
		}
	}
}

int main()
{
	prepare();
	int number_of_tests;
	scanf("%d", &number_of_tests);
	fi(number_of_tests)
	{
		read();
		solve(i + 1);
	}
	return 0;
}