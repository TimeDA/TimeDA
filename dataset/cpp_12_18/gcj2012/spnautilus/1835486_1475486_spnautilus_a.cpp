#include <stdio.h>
 #include <algorithm>
 
 using namespace std;
 
 #define MAXN (1005)
 
 int T;
 
 int N;
 int L[MAXN];
 int P[MAXN];
 
 int ss[MAXN];
 
 bool cmpf(int a, int b)
 {
 	if(P[a] != P[b])
 		return P[b] < P[a];
 	return a < b;
 }
 
 int main()
 {
 	int tt;
 	scanf("%d", &T);
 	for(tt = 1; tt <= T; ++tt)
 	{
 		int i;
 
 		scanf("%d", &N);
 		for(i = 0; i < N; ++i)
 			scanf("%d", &L[i]);
 		for(i = 0; i < N; ++i)
 			scanf("%d", &P[i]);
 		for(i = 0; i < N; ++i)
 			ss[i] = i;
 
 		sort(ss, ss + N, cmpf);
 
 		printf("Case #%d:", tt);
 		for(i = 0; i < N; ++i)
 			printf(" %d", ss[i]);
 		putchar('\n');
 	}
 
 	return 0;
 }
