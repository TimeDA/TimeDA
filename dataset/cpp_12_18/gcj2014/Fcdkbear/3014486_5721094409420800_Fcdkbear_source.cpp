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
 
 unordered_map<int, int> pos;
 int a[1010];
 int b[1010];
 
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
 		pos.clear();
 		int res = 0;
 		int n;
 		scanf("%d", &n);
 		FOR(i, 0, n)
 		{
 			scanf("%d", &a[i]);
 			b[i] = a[i];
 			pos[a[i]] = i;
 		}
 		sort(b, b + n);
 		int l = 0, r = n-1;
 		FOR(i, 0, n - 1)
 		{
 			int v = pos[b[i]];
 			if (v - l <= r - v)
 			{
 				res += v - l;
 				while (v > l)
 				{
 					pos[a[v - 1]] = v;
 					swap(a[v], a[v - 1]);
 					v--;
 				}
 				l++;
 			}
 			else
 			{
 				res += r - v;
 				while (v < r)
 				{
 					pos[a[v + 1]] = v;
 					swap(a[v], a[v + 1]);
 					v++;
 				}
 				r--;
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