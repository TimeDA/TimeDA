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
 
 int min1[110];
 int max1[110];
 int min2[110];
 int max2[110];
 char a[110][110];
 
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
 	FOR(testNumber, 1, tests + 1)
 	{
 		int res = 0;
 		bool possible = true;
 		FOR(i, 0, 110)
 		{
 			min1[i] = min2[i] = 110;
 			max1[i] = max2[i] = -1;
 		}
 		int n, m;
 		scanf("%d%d", &n, &m);
 		FOR(i, 0, n)
 			scanf("%s", a[i]);
 		FOR(i, 0, n)
 		{
 			FOR(j, 0, m)
 			{
 				if (a[i][j] != '.')
 				{
 					min1[i] = MIN(min1[i], j);
 					max1[i] = MAX(max1[i], j);
 					min2[j] = MIN(min2[j], i);
 					max2[j] = MAX(max2[j], i);
 				}
 			}
 		}
 		FOR(i, 0, n)
 		{
 			FOR(j, 0, m)
 			{
 				if (a[i][j] == '.')
 				{
 					continue;
 				}
 				bool hasNeighbour = ((min1[i]<j) || (max1[i]>j) || (min2[j]<i) || (max2[j]>i));
 				if (!hasNeighbour)
 				{
 					possible = false;
 					continue;
 				}
 				if ((a[i][j] == '^') && (min2[j] >= i))
 					res++;
 				if ((a[i][j] == '>') && (max1[i] <= j))
 					res++;
 				if ((a[i][j] == 'v') && (max2[j] <= i))
 					res++;
 				if ((a[i][j] == '<') && (min1[i] >= j))
 					res++;
 			}
 		}
 		printf("Case #%d: ", testNumber);
 		if (!possible)
 			printf("IMPOSSIBLE\n");
 		else
 			printf("%d\n", res);
 	}
 	return 0;
 
 #ifdef Fcdkbear
 	double end = clock();
 	fprintf(stderr, "*** Total time = %.3lf ***\n", (end - beg) / CLOCKS_PER_SEC);
 #endif
 	return 0;
 }