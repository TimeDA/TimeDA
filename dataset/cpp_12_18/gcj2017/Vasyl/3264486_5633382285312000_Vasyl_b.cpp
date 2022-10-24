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
 
 int A[32];
 
 int SolveTest(int test)
 {
 	Int n;
 	scanf("%lld", &n);
 
 	++n;
 	int i, j;
 	FOR(i, 0, 32)
 	{
 		A[i] = n % 10;
 		n /= 10;
 	}
 
 	FOR(i, 0, 32)
 	{
 		if (A[i] == 0) continue;
 		--A[i];
 		FOR(j, i + 1, 32)
 			if (A[j - 1] < A[j])
 				break;
 
 		if(j == 32)
 		{
 			FOR(j, 0, i) A[j] = 9;
 			break;
 		}
 		++A[i];
 	}
 
 	Int res = 0;
 	RFOR(i, 32, 0)
 	{
 		res *= 10;
 		res += A[i];
 	}
 
 	printf("Case #%d: %lld\n", test + 1, res);
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
