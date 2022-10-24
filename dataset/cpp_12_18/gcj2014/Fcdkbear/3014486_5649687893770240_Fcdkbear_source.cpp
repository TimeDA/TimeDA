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
 
 vector<string> a,b;
 int to[15];
 int t[110][30];
 int tot;
 
 int res1, res2;
 int add(string s)
 {
 	int v = 0;
 	int res = 0;
 	FOR(i, 0, s.size())
 	{
 		int c = s[i] - 'A';
 		if (t[v][c] != -1)
 		{
 			v = t[v][c];
 		}
 		else
 		{
 			tot++;
 			res++;
 			t[v][c] = tot;
 			v = t[v][c];
 		}
 	}
 	return res;
 }
 
 
 int calc()
 {
 	tot = 0;
 	int res = 1;
 	MEMS(t, -1);
 	FOR(i, 0, a.size())
 	{
 		res += add(a[i]);
 	}
 	return res;
 }
 
 void r(int N, int M, int p, int mask)
 {
 	if (p == M)
 	{
 		if (mask + 1 != (1 << N))
 			return;
 		int now = 0;
 		FOR(i, 0, N)
 		{
 			a.clear();
 			FOR(j, 0, M)
 			{
 				if (to[j] == i)
 					a.push_back(b[j]);
 			}
 			now += calc();
 		}
 		if (now > res1)
 		{
 			res1 = now;
 			res2 = 1;
 		}
 		else
 		if (now == res1)
 			res2++;
 		return;
 	}
 	FOR(i, 0, N)
 	{
 		to[p] = i;
 		r(N, M, p + 1, mask | (1 << i));
 	}
 }
 
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
 		res1 = 0;
 		res2 = 0;
 		int N, M;
 		cin >> M >> N;
 		b.clear();
 		b.resize(M);
 		FOR(i, 0, M)
 			cin >> b[i];
 		r(N, M, 0, 0);
 		printf("Case #%d: %d %d\n", test, res1, res2);
 	}
 	
 #ifdef Fcdkbear
 	double end = clock();
 	fprintf(stderr, "*** Total time = %.3lf ***\n", (end - beg) / CLOCKS_PER_SEC);
 #endif
 	return 0;
 }