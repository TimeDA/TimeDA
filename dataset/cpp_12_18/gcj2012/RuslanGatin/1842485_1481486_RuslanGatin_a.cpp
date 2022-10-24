#pragma comment (linker, "/stack:128000000")
 #define _CRT_SECURE_NO_DEPRECATE
 
 #include <iostream>
 #include <cstdio>
 #include <vector>
 #include <string>
 #include <algorithm>
 #include <cmath>
 #include <queue>
 #include <deque>
 #include <set>
 #include <map>
 #include <memory.h>
 #include <cassert>
 #include <ctime>
 
 using namespace std;
 
 #define fo(a,b,c) for (int a = (b); a < (c); a++)
 #define fr(a,b) fo(a, 0, (b))
 #define fi(n) fr(i, (n))
 #define fj(n) fr(j, (n))
 #define fk(n) fr(k, (n))
 #define fd(a,b,c) for (int a = (b); a >= (c); a--)
 #define all(a) (a).begin(), (a).end()
 #define rall(a) (a).rbegin(), (a).rend()
 #define _(a,b) memset((a), (b), sizeof(a))
 #define __(a) memset((a), 0, sizeof(a))
 #define sz(a) (int)(a).size()
 #define mp make_pair
 #define pb push_back
 
 typedef long long lint;
 typedef unsigned long long ull;
 
 const int INF = 1000000000;
 const lint LINF = 4000000000000000000LL;
 const double eps = 1e-9;
 
 void prepare()
 {
 #ifdef _DEBUG
 	freopen("input.txt", "r", stdin);
 #else
 	freopen("a-small.in", "r", stdin);
 	freopen("a-small.out", "w", stdout);
 	//freopen("-large.in", "r", stdin);
 	//freopen("-large.out", "w", stdout);
 #endif
 }
 
 void panic(bool expression = false)
 {
 	if (!expression)
 	{
 		cerr << "PANIC!" << endl;
 		assert(false);
 	}
 }
 
 const int maxn = 10005;
 
 int n;
 int d[maxn], len[maxn];
 int dp[maxn];
 
 void read()
 {
 	scanf("%d", &n);
 	fi(n)
 	{
 		scanf("%d%d", &d[i], &len[i]);
 	}
 	scanf("%d", &d[n]);
 	len[n] = 0;
 }
 
 void solve(int test_num)
 {
 	//cerr << test_num << endl;
 	printf("Case #%d: ", test_num);
 	
 	read();
 	_(dp, 127);
 	dp[n] = 0;
 	fd(i, n - 1, 0)
 	{
 		fo(j, i + 1, n + 1)
 		{
 			if (len[i] < d[j] - d[i])
 				break;
 			int razgon = min(d[j] - d[i], len[j]);
 			if (razgon >= dp[j])
 			{
 				dp[i] = d[j] - d[i];
 				break;
 			}
 		}
 	}
 
 	printf(dp[0] <= d[0] ? "YES" : "NO");
 
 	printf("\n");
 }
 
 int main()
 {
 	prepare();
 	int number_of_tests;
 	scanf("%d\n", &number_of_tests);
 	fi(number_of_tests)
 		solve(i + 1);
 	return 0;
 }