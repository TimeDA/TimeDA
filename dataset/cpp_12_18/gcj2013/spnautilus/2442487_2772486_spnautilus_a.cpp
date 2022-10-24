#include <stdio.h>
 #include <algorithm>
 
 using namespace std;
 
 #define MAXM (1005)
 #define MAX2M (2005)
 
 typedef pair <int, int> PII;
 typedef long long ll;
 
 const ll moder = 1000002013;
 
 int T;
 int N, M;
 
 PII P[MAX2M];
 // for "collapsed" traffic
 int ps[MAX2M];
 ll pi[MAX2M];
 
 ll sol;
 
 inline ll f(int n)
 {
 	int l = N - n;
 	return ((N * ll(N + 1) - l * (l + 1)) / 2) % moder;
 }
 
 void rec(int a, int b)
 {
 	if(a > b)
 		return;
 
 	ll min;
 	int i, ii;
 
 	min = pi[a];
 	ii = a;
 	for(i = a; i <= b; ++i)
 	{
 		if(min > pi[i])
 		{
 			min = pi[i];
 			ii = i;
 		}
 	}
 
 	if(min > 0)
 	{
 		for(i = a; i <= b; ++i)
 			pi[i] -= min;
 
 		sol = (sol + (min % moder) * f(ps[b + 1] - ps[a])) % moder;
 	}
 
 //	printf("%d %d : min %I64d, ii %d\n", a, b, min, ii);
 	rec(a, ii - 1);
 	rec(ii + 1, b);
 }
 
 int main()
 {
 	int tt;
 	scanf("%d", &T);
 	for(tt = 1; tt <= T; ++tt)
 	{
 		int i, j;
 
 		scanf("%d %d", &N, &M);
 		int M2 = M+M;
 
 		ll fullSol = 0;
 
 		j = 0;
 		for(i = 0; i < M; ++i)
 		{
 			int a, b, c;
 			scanf("%d %d %d", &a, &b, &c);
 			P[j++] = PII(a, c);
 			P[j++] = PII(b, -c);
 
 			ll l = b - a;
 			fullSol = (fullSol + (c * f(l)) % moder) % moder;
 		}
 
 //		printf("fs %I64d\n", fullSol);
 
 		sort(P, P + M2);
 		P[M2] = PII(N + 1, 0);
 
 		ll p = 0;
 		ll lasts = P[0].first;
 
 		j = 0;
 		for(i = 0; 1; ++i)
 		{
 //			printf("%d : %d %d\n", i + 1, P[i].first, P[i].second);
 
 			if(P[i].first != lasts)
 			{
 				ps[j] = lasts;
 				pi[j] = p;
 
 //				printf("segment %d : %d %I64d\n", j + 1, ps[j], pi[j]);
 				++j;
 			}
 
 			if(i >= M2)
 				break;
 
 			p += P[i].second;
 			lasts = P[i].first;
 //			printf("%+d -> %I64d\n", P[i].second, p);
 		}
 
 //		printf("# segments : %d\n", j);
 
 		sol = 0;
 		rec(0, j - 2);
 
 //		printf("sol %I64d\n", sol);
 
 		sol = (fullSol - sol + moder) % moder;
 		printf("Case #%d: %I64d\n", tt, sol);
 	}
 
 	return 0;
 }
