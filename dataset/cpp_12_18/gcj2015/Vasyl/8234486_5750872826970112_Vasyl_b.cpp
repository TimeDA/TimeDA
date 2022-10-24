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
 
 #define EPS 0
 #define MAX 128
 
 pair<double, double> A[1 << 10];
 
 double f(int n, double need, double time)
 {
 	double volume = 0;
 	double sum = 0;
 
 	int i;
 	FOR(i, 0, n)
 	{
 		double v = time * A[i].second;
 		volume += v;
 		sum += v * A[i].first;
 	}
 
 	int left = 0;
 	int right = n - 1;
 
 	while (true)
 	{
 		if (left == n || right == -1)
 			break;
 
 		if (volume * need + EPS < sum)
 		{
 			double v = time * A[right].second;
 			if ((volume - v) * need < sum - v * A[right].first)
 			{
 				volume -= v;
 				sum -= v * A[right].first;
 				--right;
 				continue;
 			}
 
 			v = (sum - volume * need) / (A[right].first - need);
 			volume -= v;
 			sum -= v * A[right].first;
 			break;
 		}
 		else if (volume * need > sum + EPS)
 		{
 			double v = time * A[left].second;
 			if ((volume - v) * need > sum - v * A[left].first)
 			{
 				volume -= v;
 				sum -= v * A[left].first;
 				++left;
 				continue;
 			}
 
 			v = (sum - volume * need) / (A[left].first - need);
 			volume -= v;
 			sum -= v * A[left].first;
 			break;
 		}
 		else
 			break;
 	}
 
 	return volume;
 }
 
 int SolveTest(int test)
 {
 	int N;
 	double V, X;
 	scanf("%d%lf%lf", &N, &V, &X);
 
 	int i, j;
 	FOR(i, 0, N)
 	{
 		double r, c;
 		scanf("%lf%lf", &r, &c);
 		A[i].first = c;
 		A[i].second = r;
 	}
 
 	sort(A, A + N);
 
 	if (X < A[0].first || A[N - 1].first < X)
 	{
 		printf("Case #%d: IMPOSSIBLE\n", test + 1);
 		return 0;
 	}
 
 	double Min = 0, Max = 1e9;
 	FOR(i, 0, MAX)
 	{
 		double Mid = (Max + Min) / 2;
 
 		if (f(N, X, Mid) < V)
 			Min = Mid;
 		else
 			Max = Mid;
 	}
 
 	printf("Case #%d: %.11lf\n", test + 1, Max);
 	return 0;
 }
 
 int main()
 {
 	freopen("b.in", "r", stdin);
 	freopen("b.out", "w", stdout);
 
 	int T, t;
 	char buf[1 << 7];
 	gets(buf);
 	sscanf(buf, "%d", &T);
 	FOR(t, 0, T)
 	{
 		fprintf(stderr, "Solving %d/%d\n", t + 1, T);
 		SolveTest(t);
 	}
 
 	return 0;
 };
