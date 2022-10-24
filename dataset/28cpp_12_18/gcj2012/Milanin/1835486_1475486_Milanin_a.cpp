#include <stdio.h>
 #include <algorithm>
 #include <set>
 #include <map>
 #include <vector>
 #include <string>
 #include <queue>
 #include <math.h>
 using namespace std;
 #define N 1010
 struct T
 {
 	int t, p, i;
 };
 bool operator <(T a, T b) { return a.t*b.p<a.p*b.t; }
 T m[N];
 int main()
 {
 	int n, i, ts, tst;
 	for(scanf("%d", &tst), ts=1; ts<=tst; ts++)
 	{
 		printf("Case #%d:", ts);
 		for(scanf("%d", &n), i=0; i<n; scanf("%d", &m[i].t), m[i].i=i, i++);
 		for(i=0; i<n; scanf("%d", &m[i].p), i++);
 		sort(m, m+n);
 		for(i=0; i<n; printf(" %d", m[i].i), i++);
 		printf("\n");
 	}
 	return 0;
 }