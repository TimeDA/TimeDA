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
 
 char buf[1 << 10];
 
 int SolveTest(int test)
 {
 	int K;
 	scanf("%s%d", buf, &K);
 
 	int len = strlen(buf);
 	int i, j;
 	int res = 0;
 	FOR(i, 0, len - K + 1)
 		if (buf[i] != '+')
 		{
 			++res;
 			FOR(j, i, i + K)
 				buf[j] = buf[j] == '+' ? '-' : '+';
 		}
 
 	FOR(i, 0, len)
 		if (buf[i] != '+')
 			break;
 
 	if (i == len) printf("Case #%d: %d\n", test + 1, res);
 	else printf("Case #%d: IMPOSSIBLE\n", test + 1);
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
