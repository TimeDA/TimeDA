//#pragma comment(linker, "/STACK:134217728")

#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
using namespace std;

typedef long long Int;
typedef pair<int,int> PII;
typedef vector<int> VInt;

#define FOR(i, a, b) for(i = (a); i < (b); ++i)
#define RFOR(i, a, b) for(i = (a) - 1; i >= (b); --i)
#define CLEAR(a, b) memset(a, b, sizeof(a))
#define SIZE(a) int((a).size())
#define ALL(a) (a).begin(),(a).end()
#define PB push_back
#define MP make_pair

int SolveTest(int test)
{
	int N;
	scanf("%d", &N);

	int i;
	VInt v[2];
	FOR(i, 0, N)
	{
		int a;
		scanf("%d", &a);
		v[i & 1].push_back(a);
	}

	FOR(i, 0, 2) sort(ALL(v[i]));
	VInt w(N);
	FOR(i, 0, N) w[i] = v[i & 1][i >> 1];
	FOR(i, 1, N)
		if (w[i] < w[i - 1])
			break;

	if (i == N) printf("Case #%d: OK\n", test + 1);
	else printf("Case #%d: %d\n", test + 1, i - 1);
	return 0;
}

int main()
{
	int T, t;
	char buf[1 << 7];
	fgets(buf, 1 << 7, stdin);
	sscanf(buf, "%d", &T);
	FOR(t, 0, T) SolveTest(t);
	return 0;
};
