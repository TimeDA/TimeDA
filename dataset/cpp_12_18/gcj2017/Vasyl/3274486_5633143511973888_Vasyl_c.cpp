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
 
 double P[64];
 
 int SolveTest(int test)
 {
 	int n, k;
 	double u;
 	scanf("%d%d%lf", &n, &k, &u);
 	int i, j;
 	FOR(i, 0, n) scanf("%lf", &P[i]);
 
 	sort(P, P + n);
 	FOR(i, 0, n)
 	{
 		double t = u / (i + 1);
 		if(i != n - 1) t = min(t, P[i + 1] - P[i]);
 		u -= t*(i + 1);
 		FOR(j, 0, i + 1)
 			P[j] += t;
 	}
 
 	double res = 1;
 	FOR(i, 0, n) res *= P[i];
 	printf("Case #%d: %.11lf\n", test + 1, res);
 	return 0;
 }
 
 int main()
 {
 	freopen("", "r", stdin);
 	freopen("", "w", stdout);
 
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
