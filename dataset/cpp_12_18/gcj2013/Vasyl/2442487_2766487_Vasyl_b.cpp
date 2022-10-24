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
 
 Int f(int n, Int p)
 {
 	Int all = 1LL << n;
 	if(p == all)
 		return all - 1;
 	if(p == 1)
 		return 0;
 
 	Int mask = 0;
 	int cnt = 0;
 	int i;
 	RFOR(i, n, 0)
 		if(p & (1LL << i))
 		{
 			mask |= 1LL << i;
 			++cnt;
 		}
 		else
 		{
 			if(mask != p)
 				++cnt;
 
 			break;
 		}
 
 	return (1LL << cnt) - 2;
 }
 
 Int g(int n, Int p)
 {
 	Int all = 1LL << n;
 	if(p == all)
 		return all - 1;
 	if(p == 0)
 		return 0;
 
 	Int res = f(n, all - p);
 	return all - res - 2;
 }
 
 int SolveTest(int test)
 {
 	int n;
 	Int p;
 	scanf("%d%lld", &n, &p);
 
 	printf("Case #%d: %lld %lld\n", test + 1, f(n, p), g(n, p));
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
