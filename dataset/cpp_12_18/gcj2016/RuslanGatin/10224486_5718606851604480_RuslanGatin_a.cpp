#define _CRT_SECURE_NO_DEPRECATE
 #pragma comment (linker, "/stack:256000000")
 
 #include <iostream>
 #include <cstdio>
 #include <sstream>
 #include <vector>
 #include <string>
 #include <algorithm>
 #include <cmath>
 #include <queue>
 #include <deque>
 #include <set>
 #include <bitset>
 #include <map>
 #include <memory.h>
 #undef NDEBUG
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
 typedef vector<int> VI;
 typedef vector<string> VS;
 typedef pair<int, int> pii;
 
 const int INF = 1000000000;
 const lint LINF = 4000000000000000000LL;
 const double eps = 1e-9;
 
 int ni() { int a; scanf( "%d", &a ); return a; }
 double nf() { double a; scanf( "%lf", &a ); return a; }
 char sbuf[100005]; string ns() { scanf( "%s", sbuf ); return sbuf; }
 long long nll() { long long a; scanf( "%lld", &a ); return a; }
 
 void prepare()
 {
 	freopen("input.txt", "r", stdin);
 	freopen("a-small.in", "r", stdin);
 	freopen("a-small.out", "w", stdout);
 	//freopen("-large.in", "r", stdin);
 	//freopen("-large.out", "w", stdout);
 }
 
 int n, r, p, s;
 
 void read()
 {
 	n = ni();
 	r = ni();
 	p = ni();
 	s = ni();
 }
 
 string go(char winner)
 {
 	string s;
 	s.pb(winner);
 	fi(n)
 	{
 		string t;
 		fj(sz(s))
 		{
 			switch (s[j])
 			{
 			case 'P':
 				t.pb('P');
 				t.pb('R');
 				break;
 			case 'R':
 				t.pb('R');
 				t.pb('S');
 				break;
 			case 'S':
 				t.pb('P');
 				t.pb('S');
 				break;
 			}
 		}
 		s = t;
 	}
 	int _2n = 1 << n;
 	fi(n)
 	{
 		int q = 1 << i;
 		for (int j = 0; j < _2n; j += q * 2)
 		{
 			string t1 = s.substr(j, q);
 			string t2 = s.substr(j + q, q);
 			if (t2 < t1)
 			{
 				fk(q)
 				{
 					s[j + k] = t2[k];
 					s[j + q + k] = t1[k];
 				}
 			}
 		}
 	}
 	return s;
 }
 
 bool check(string &t)
 {
 	int cp = 0, cr = 0, cs = 0;
 	fi(sz(t))
 	{
 		switch (t[i])
 		{
 		case 'P':
 			cp++;
 			break;
 		case 'R':
 			cr++;
 			break;
 		case 'S':
 			cs++;
 			break;
 		}
 	}
 	return cp == p && cr == r && cs == s;
 }
 
 void solve(int test_num)
 {
 	cerr << test_num << endl;
 	printf("Case #%d: ", test_num);
 	string r1 = go('P');
 	string r2 = go('R');
 	string r3 = go('S');
 	if (!check(r1))
 		r1 = "Z";
 	if (!check(r2))
 		r2 = "Z";
 	if (!check(r3))
 		r3 = "Z";
 	string mn = min(min(r1, r2), r3);
 	if (mn == "Z")
 		mn = "IMPOSSIBLE";
 	printf("%s\n", mn.c_str());
 }
 
 int main()
 {
 	prepare();
 	int number_of_tests;
 	scanf("%d\n", &number_of_tests);
 	fi(number_of_tests)
 	{
 		read();
 		solve(i + 1);
 	}
 	return 0;
 }