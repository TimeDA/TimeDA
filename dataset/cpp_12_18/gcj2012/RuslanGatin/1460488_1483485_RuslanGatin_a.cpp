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
 	freopen("a.in", "r", stdin);
 	freopen("a.out", "w", stdout);
 }
 
 void panic(bool expression = false)
 {
 	if (!expression)
 	{
 		cerr << "PANIC!" << endl;
 		assert(false);
 	}
 }
 
 char a[] = "yhesocvxduiglbkrztnwjpfmaq";
 
 void solve(int test_num)
 {
 	//cerr << test_num << endl;
 	printf("Case #%d: ", test_num);
 	string s;
 	getline(cin, s);
 	fi(sz(s))
 	{
 		if (!isalpha(s[i]))
 			printf("%c", s[i]);
 		else
 			printf("%c", a[s[i] - 'a']);
 	}
 	printf("\n");
 }
 
 int main()
 {
 	prepare();
 	int number_of_tests;
 	string s;
 	cin >> number_of_tests;
 	getline(cin, s);
 	fi(number_of_tests)
 		solve(i + 1);
 	return 0;
 }