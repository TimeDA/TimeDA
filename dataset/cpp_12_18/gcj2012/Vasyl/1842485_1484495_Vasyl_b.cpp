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
 
 int R[1 << 10];
 PII P[1 << 10];
 int X[1 << 10];
 int Y[1 << 10];
 
 double dist(double x, double y){ return sqrt(x*x + y*y); }
 
 int SolveTest(int test)
 {
 	int n, w, l;
 	scanf("%d%d%d", &n, &w, &l);
 
 	int i, j;
 	FOR(i, 0, n)
 		scanf("%d", &R[i]);
 
 	FOR(i, 0, n)
 		P[i] = PII(R[i] + R[i], i);
 
 	sort(P, P + n);
 
 	if(test == 3)
 		test = test;
 
 	vector<PII> v;
 	v.PB(PII(0, 0));
 	v.PB(PII(l + 1, w + 1));
 	RFOR(i, n, 0)
 	{
 		int pos = 0;
 		FOR(j, 0, SIZE(v))
 			if(v[pos].second > v[j].second)
 				pos = j;
 
 		X[ P[i].second ] = v[pos].second;
 		Y[ P[i].second ] = v[pos].first;
 
 		if(X[ P[i].second ] > w)
 			throw 0;
 
 		int left = max(0, v[pos].first - P[i].first);
 		int right = min(l + 1, v[pos].first + P[i].first);
 
 		vector<PII> u;
 		int isLeft = 0;
 		int isRight = 0;
 		int curr = 0;
 		FOR(j, 0, SIZE(v))
 		{
 			if(v[j].first >= left && isLeft == 0)
 			{
 				isLeft = 1;
 				if(v[j].first > left)
 					u.PB(PII(left, curr));
 			}
 
 			if(v[j].first >= right && isRight == 0)
 			{
 				isRight = 1;
 				if(v[j].first > right)
 					u.PB(PII(right, curr));
 			}
 
 			u.PB(v[j]);
 			curr = v[j].second;
 		}
 
 		FOR(j, 0, SIZE(u))
 			if(left <= u[j].first && u[j].first < right)
 				u[j].second = max(u[j].second, min(w + 1, v[pos].second + P[i].first));
 
 		v = u;
 	}
 
 	FOR(i, 0, n)
 		FOR(j, 0, i)
 			if(dist(X[i] - X[j], Y[i] - Y[j]) < R[i] + R[j])
 				throw 0;
 
 	printf("Case #%d:", test + 1);
 	FOR(i, 0, n)
 		printf(" %d %d", X[i], Y[i]);
 
 	printf("\n");
 	return 0;
 }
 
 int main()
 {
 	freopen("b.in", "r", stdin);
 	freopen("b.out", "w", stdout);
 
 	int T, t;
 	char buf[1 << 7];
 	gets(buf);
 	sscanf(buf, "%d", &T);
 	FOR(t, 0, T)
 	{
 		fprintf(stderr, "Solving %d/%d\n", t + 1, T);
 		SolveTest(t);
 	}
 
 	return 0;
 };
