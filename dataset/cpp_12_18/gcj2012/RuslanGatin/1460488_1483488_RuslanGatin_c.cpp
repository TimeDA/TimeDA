#define _CRT_SECURE_NO_DEPRECATE
 
 #include <iostream>
 #include <vector>
 #include <string>
 #include <algorithm>
 #include <cmath>
 #include <queue>
 #include <stack>
 #include <set>
 #include <map>
 #include <memory.h>
 #include <cassert>
 
 using namespace std;
 
 #define fo(a,b,c) for (int a = (b); a < (c); a++)
 #define fr(a,b) fo(a, 0, (b))
 #define fi(n) fr(i, (n))
 #define fj(n) fr(j, (n))
 #define fk(n) fr(k, (n))
 #define fd(a,b,c) for (a = (b); a >= (c); a--)
 #define all(a) (a).begin(), (a).end()
 #define rall(a) (a).rbegin(), (a).rend()
 #define _(a,b) memset((a), (b), sizeof(a))
 #define __(a) memset((a), 0, sizeof(a))
 #define sz(a) (int)(a).size()
 #define mp make_pair
 #define pb push_back
 
 typedef long long lint;
 typedef unsigned long long ull;
 typedef vector<int> VI;
 typedef vector<string> VS;
 typedef pair<int, int> PII;
 
 const int INF = 1 << 30;
 const double eps = 1e-9;
 
 void prepare()
 {
 	freopen("c-small.in", "r", stdin);
 	freopen("c-small.out", "w", stdout);
 }
 
 void panic(bool expression = false)
 {
 	if (!expression)
 	{
 		cerr << "PANIC!" << endl;
 		assert(false);
 	}
 }
 
 vector<pair<int, int> > pre;
 
 int getLen(int x)
 {
 	char buf[20];
 	sprintf(buf, "%d", x);
 	return strlen(buf);
 }
 
 int shift(int x, int len)
 {
 	int p = 1;
 	for (int i = 1; i < len; i++)
 		p *= 10;
 	return (x % 10) * p + x / 10;
 }
 
 void get(int x, int r)
 {
 	int z = x;
 	int len = getLen(x);
 	do
 	{
 		z = shift(z, len);
 		if (z > x && z <= r)
 			pre.pb(mp(x, z));
 	}
 	while (z != x);
 }
 
 void precalc()
 {
 	for (int i = 1; i <= 2000000; i++)
 		get(i, 2000000);
 }
 
 void solve(int test_num)
 {
 	//cerr << test_num << endl;
 	printf("Case #%d: ", test_num);
 	int a, b, res = 0;
 	scanf("%d%d", &a, &b);
 	fi(sz(pre))
 		res += (pre[i].first >= a && pre[i].second <= b);
 	printf("%d\n", res);
 }
 
 int main()
 {
 	prepare();
 	precalc();
 	int number_of_tests;
 	cin >> number_of_tests;
 	fi(number_of_tests)
 		solve(i + 1);
 	return 0;
 }