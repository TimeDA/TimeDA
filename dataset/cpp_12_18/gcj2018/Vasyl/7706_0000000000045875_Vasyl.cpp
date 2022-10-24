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

int A[128][128];
int E[256][256];
int B[256];
int gN;
int gMark;

int dfs(int a)
{
	if (a == gN - 1) return 1;
	B[a] = gMark;
	int i;
	FOR(i, 0, gN)
		if(B[i] != gMark && E[a][i] > 0 && dfs(i) != 0)
		{
			--E[a][i];
			++E[i][a];
			return 1;
		}

	return 0;
}

int SolveTest(int test)
{
	int N;
	scanf("%d", &N);

	int i, j, k;
	FOR(i, 0, N)
		FOR(j, 0, N)
		scanf("%d", &A[i][j]);

	CLEAR(B, 0);
	gMark = 0;
	int res = N*N;
	FOR(k, -N, N + 1)
	{
		CLEAR(E, 0);
		FOR(i, 0, N)
			FOR(j, 0, N)
			if (A[i][j] == k)
				E[i][N + j] = 1;

		FOR(i, 0, N)
			E[N + N][i] = 1;
		FOR(i, 0, N)
			E[N + i][N + N + 1] = 1;
		gN = N + N + 2;
		int flow = 0;
		FOR(i, 0, N)
			FOR(j, 0, N)
				if(E[i][N + j] > 0 && E[gN - 2][i] > 0 && E[N + j][gN - 1] > 0)
				{
					++flow;
					--E[i][N + j];
					++E[N + j][i];
					--E[gN - 2][i];
					++E[i][gN - 2];
					--E[N + j][gN - 1];
					++E[gN - 1][N + j];
				}

		while(true)
		{
			++gMark;
			if (dfs(N + N) == 0) break;
			++flow;
		}
		res -= flow;
	}

	printf("Case #%d: %d\n", test + 1, res);
	return 0;
}

int main()
{
	int T, t;
	char buf[1 << 7];
	fgets(buf, 1 << 7, stdin);
	sscanf(buf, "%d", &T);
	FOR(t, 0, T)
		SolveTest(t);

	return 0;
};
