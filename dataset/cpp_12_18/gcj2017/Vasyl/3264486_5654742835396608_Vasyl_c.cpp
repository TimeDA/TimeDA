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
 	Int N, K;
 	scanf("%lld%lld", &N, &K);
 
 	map<Int, Int> m;
 	queue<Int> q;
 	q.push(N);
 	m[N] = 1;
 	Int mn = -1, mx = -1;
 	while(true)
 	{
 		Int a = q.front();
 		q.pop();
 
 		mn = (a - 1) / 2;
 		mx = a - 1 - mn;
 		Int c = m[a];
 		K -= c;
 		if (K <= 0) break;
 
 		if (m.count(mx) == 0) q.push(mx);
 		m[mx] += c;
 		if (m.count(mn) == 0) q.push(mn);
 		m[mn] += c;
 	}
 
 	printf("Case #%d: %lld %lld\n", test + 1, mx, mn);
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
