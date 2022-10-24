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

int A[128][2];
int C[128];
Int B[128];

int f(int n, Int need)
{
	int i;
	FOR(i, 0, n) B[i] = C[i];
	B[0] -= need;
	Int sum = accumulate(B, B + n, 0LL);
	bool found = true;
	while(found && sum >= 0)
	{
		found = false;
		FOR(i, 0, n)
			if(B[i] < 0)
			{
				found = true;
				Int t = -B[i];
				B[i] += t;
				B[A[i][0]] -= t;
				B[A[i][1]] -= t;
				sum -= t;
				if (sum < 0) break;
			}
	}
	return sum < 0 ? 0 : 1;
}

int SolveTest(int test)
{
	int M;
	scanf("%d", &M);

	int i, j;
	FOR(i, 0, M)
		FOR(j, 0, 2)
		{
			scanf("%d", &A[i][j]);
			--A[i][j];
		}

	FOR(i, 0, M) scanf("%d", &C[i]);

	Int Min = 0, Max = (1LL << 60);
	while(Max - Min > 1)
	{
		Int Mid = (Max + Min) >> 1;
		if (f(M, Mid) == 0)
			Max = Mid;
		else
			Min = Mid;
	}

	printf("Case #%d: %lld\n", test + 1, Min);
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
