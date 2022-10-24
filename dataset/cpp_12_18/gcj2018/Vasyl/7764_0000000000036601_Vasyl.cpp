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

#define MAX 201
#define INF (1 << 28)

int R[MAX][MAX];

int SolveTest(int test)
{
	int N, L;
	scanf("%d%d", &N, &L);
	int i, j, k;
	int cnt = max(200, L);
	VInt v(cnt, 0);
	FOR(i, 0, L) scanf("%d", &v[i]);



	sort(ALL(v));
	reverse(ALL(v));
	int free = N - accumulate(ALL(v), 0);
	cnt = min(cnt, 200);

	FOR(i, 0, cnt + 1) 
		FOR(j, 0, MAX)
			R[i][j] = INF;

	R[0][0] = 0;

	FOR(i, 0, cnt)
		FOR(j, 0, MAX)
			if(R[i][j] <= free)
				FOR(k, j, MAX)
				{
					int need = ((2 * (k - j) - 1)*N + 199) / 200;
					int t = need <= v[i] ? 0 : need - v[i];
					R[i + 1][k] = min(R[i + 1][k], R[i][j] + t);
				}

	RFOR(i, MAX, 0)
		if (R[cnt][i] <= free)
			break;

	printf("Case #%d: %d\n", test + 1, i);
	return 0;
}

int main()
{
//	freopen("", "r", stdin);
//	freopen("", "w", stdout);

	int T, t;
	char buf[1 << 7];
	fgets(buf, 1 << 7, stdin);
	sscanf(buf, "%d", &T);
	FOR(t, 0, T)
	{
//		fprintf(stderr, "Solving %d/%d\n", t + 1, T);
		SolveTest(t);
	}

	return 0;
};
