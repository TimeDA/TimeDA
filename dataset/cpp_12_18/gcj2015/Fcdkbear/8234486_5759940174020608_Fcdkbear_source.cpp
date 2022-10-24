#include <list>
 #include <map>
 #include <set>
 #include <deque>
 #include <stack>
 #include <queue>
 #include <algorithm>
 #include <sstream>
 #include <iostream>
 #include <iomanip>
 #include <cstdio>
 #include <cmath>
 #include <cstdlib>
 #include <memory.h>
 #include <ctime>
 #include <bitset>
 #include <unordered_map>
 #include <unordered_set>
 
 using namespace std;
 
 #define ABS(a) ((a>0)?a:-(a))
 #define MIN(a,b) ((a<b)?(a):(b))
 #define MAX(a,b) ((a<b)?(b):(a))
 #define FOR(i,a,n) for (int i=(a);i<(n);++i)
 #define FI(i,n) for (int i=0; i<(n); ++i)
 #define pnt pair <int, int>
 #define mp make_pair
 #define PI 3.1415926535897
 #define MEMS(a,b) memset(a,b,sizeof(a))
 #define LL long long
 #define U unsigned
 
 int mod1;
 int mod2;
 
 pair<int, int> ghash(string s1)
 {
 	LL p1 = 1;
 	LL p2 = 1;
 	LL h1 = 0;
 	LL h2 = 0;
 	FOR(i, 0, s1.size())
 	{
 		h1 += p1*(s1[i] - 'a' + 1);
 		h2 += p2*(s1[i] - 'a' + 1);
 		h1 %= mod1;
 		h2 %= mod2;
 		p1 *= 29;
 		p1 %= mod1;
 		p2 *= 29;
 		p2 %= mod2;
 	}
 	return mp((int)h1, (int)h2);
 }
 
 vector<pnt > english;
 vector<pnt > french;
 vector<vector<LL > > g;
 string s;
 
 unordered_map<LL, int> mm;
 unordered_set<LL> isIn;
 unordered_map<LL, int> startMM;
 
 int main()
 {
 #ifdef Fcdkbear
 	freopen("in.txt", "r", stdin);
 	freopen("out.txt", "w", stdout);
 	double beg = clock();
 #else
 	freopen("in.txt", "r", stdin);
 	freopen("out.txt", "w", stdout);
 #endif
 
 	int tests;
 	scanf("%d", &tests);
 	mod1 = 1000000007;
 	mod2 = 1000000000+(rand()%100);
 	FOR(testNumber, 1, tests + 1)
 	{
 		int n;
 		scanf("%d", &n);
 		g.clear();
 		g.resize(n);
 		getline(cin, s);
 		FOR(i, 0, n)
 		{
 			getline(cin, s);
 			stringstream tmp;
 			tmp << s;
 			while (tmp >> s)
 			{
 				pnt a = ghash(s);
 				LL val1 = a.first;
 				val1 *= 1100000000;
 				val1 += a.second;
 				g[i].push_back(val1);
 			}
 		}
 		int val = n - 2;
 		int p = (1 << val);
 		int res = 1000000000;
 		isIn.clear();
 		startMM.clear();
 		mm.clear();
 		FOR(i, 2, n)
 		{
 			FOR(j, 0, g[i].size())
 			{
 				isIn.insert(g[i][j]);
 			}
 		}
 		FOR(i, 0, 2)
 		{
 			FOR(j, 0, g[i].size())
 			{
 				if (isIn.find(g[i][j]) != isIn.end())
 				{
 					startMM[g[i][j]] |= (1 << i);
 				}
 				else
 				{
 					mm[g[i][j]] |= (1 << i);
 				}
 			}
 		}
 		int st = 0;
 		for (auto it : mm)
 			st += (it.second == 3);
 		mm.clear();
 		FOR(mask, 0, p)
 		{
 			mm = startMM;
 			FOR(idx, 0, val)
 			{
 				FOR(j, 0, g[idx + 2].size())
 				{
 					if ((mask >> idx) & 1)
 						mm[g[idx+2][j]] |= 1;
 					else
 						mm[g[idx + 2][j]] |= 2;
 				}
 			}
 			int now = 0;
 			for (auto it : mm)
 				now += (it.second == 3);
 			res = MIN(res, now + st);
 		}
 		printf("Case #%d: %d\n", testNumber, res);
 		fprintf(stderr, "DONE %d\n", testNumber);
 	}
 	return 0;
 
 #ifdef Fcdkbear
 	double end = clock();
 	fprintf(stderr, "*** Total time = %.3lf ***\n", (end - beg) / CLOCKS_PER_SEC);
 #endif
 	return 0;
 }