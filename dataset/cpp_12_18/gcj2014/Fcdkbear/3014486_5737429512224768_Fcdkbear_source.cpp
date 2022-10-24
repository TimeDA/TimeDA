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
 
 using namespace std;
 
 #define ABS(a) ((a>0)?a:-(a))
 #define MIN(a,b) ((a<b)?(a):(b))
 #define MAX(a,b) ((a<b)?(b):(a))
 #define FOR(i,a,n) for (int i=(a);i<(n);++i)
 #define FI(i,n) for (int i=0; i<(n); ++i)
 #define pnt pair <int, int>
 #define mp make_pair
 #define PI 3.14159265358979
 #define MEMS(a,b) memset(a,b,sizeof(a))
 #define LL long long
 #define U unsigned
 
 multiset<int> s;
 
 int main()
 {
 #ifdef Fcdkbear
 	freopen("in.txt", "r", stdin);
 	freopen("out.txt","w",stdout);
 	double beg = clock();
 #else
 	freopen("in.txt", "r", stdin);
 	freopen("out.txt","w",stdout);
 #endif
 
 	int t;
 	scanf("%d", &t);
 	FOR(test, 1, t + 1)
 	{
 		int n, x;
 		scanf("%d%d", &n, &x);
 		FOR(i, 0, n)
 		{
 			int v;
 			scanf("%d", &v);
 			s.insert(v);
 		}
 		int res = 0;
 		while (s.size())
 		{
 			res++;
 			multiset<int>::iterator it= s.end();
 			it--;
 			int v = *it;
 			s.erase(it);
 			if (!s.size())
 				break;
 			multiset<int>::iterator it1 = s.upper_bound(x - v);
 			if (it1 != s.begin())
 			{
 				it1--;
 				s.erase(it1);
 			}
 		}
 		printf("Case #%d: %d\n", test, res);
 	}
 	
 #ifdef Fcdkbear
 	double end = clock();
 	fprintf(stderr, "*** Total time = %.3lf ***\n", (end - beg) / CLOCKS_PER_SEC);
 #endif
 	return 0;
 }