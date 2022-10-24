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
 
 double A[256];
 double B[256];
 double R[256][256];
 
 double f(double *A, int n)
 {
 	int i, j;
 	CLEAR(R, 0);
 	R[0][0] = 1;
 	FOR(i, 1, n + 1)
 		FOR(j, 0, i + 1)
 		{
 			R[i][j] = R[i - 1][j] * (1 - A[i - 1]);
 			if (j != 0) R[i][j] += R[i - 1][j - 1] * A[i - 1];
 		}
 
 	return R[n][n / 2];
 }
 
 int SolveTest(int test)
 {
 	int N, K;
 	scanf("%d%d", &N, &K);
 
 	int i, j;
 	FOR(i, 0, N)
 		scanf("%lf", &A[i]);
 
 	sort(A, A + N);
 
 	double res = 0;
 	FOR(i, K, N + 1)
 		res = max(res, f(A + i - K, K));
 
 	FOR(i, 0, K + 1)
 	{
 		FOR(j, 0, i)
 			B[i] = A[i];
 		FOR(j, 0, K - i)
 			B[i + j] = A[N - 1 - j];
 
 		res = max(res, f(B, K));
 	}
 
 	printf("Case #%d: %.11lf\n", test + 1, res);
 	return 0;
 }
 
 int main()
 {
 	freopen("b.in", "r", stdin);
 	freopen("b.out", "w", stdout);
 
 	int T, t;
 	char buf[1 << 7];
 	fgets(buf, 1 << 7, stdin);
 	sscanf(buf, "%d", &T);
 	FOR(t, 0, T)
 	{
 		fprintf(stderr, "Solving %d/%d\n", t + 1, T);
 		SolveTest(t);
 	}
 
 	return 0;
 };
