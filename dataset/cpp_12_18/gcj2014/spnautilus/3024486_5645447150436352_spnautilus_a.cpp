#include <cstdio>
 #include <cstring>
 #include <vector>
 #include <string>
 #include <queue>
 #include <algorithm>
 
 using namespace std;
 
 #define MAXN (1000005)
 
 typedef long long ll;
 typedef pair <int, int> PII;
 typedef pair <ll, PII> PIP;
 typedef vector <PII> VP;
 
 int T;
 int N;
 ll P, Q, R, S;
 ll A[MAXN];
 
 int main()
 {
 	scanf("%d", &T);
 	for(int TT = 1; TT <= T; ++TT)
 	{
 		int i, j;
 
 		scanf("%d", &N);
 		scanf("%I64d %I64d %I64d %I64d", &P, &Q, &R, &S);
 
 		ll all = 0;
 		for(i = 0; i < N; ++i)
 		{
 			A[i] = (i * P + Q) % R + S;
 			all += A[i];
 		}
 
 		ll lo = 0;
 		ll hi = all;
 		ll res = all;
 
 //		printf("all %I64d\n", all);
 
 		while(lo <= hi)
 		{
 			ll mid = (lo + hi) / 2;
 
 			i = 0;
 			for(j = 0; j < 3 && i < N; ++j)
 			{
 				ll sum = 0;
 				while(1)
 				{
 					if(i == N || sum + A[i] > mid)
 						break;
 					sum += A[i++];
 				}
 			}
 
 //			printf("lo %I64d  hi %I64d   mid %I64d i %d N %d\n", lo, hi, mid, i, N);
 
 			if(i == N)
 			{
 				res = mid;
 				hi = mid - 1;
 			}
 			else
 				lo = mid + 1;
 		}
 
 		double sol = 1e0 - double(res) / all;
 
 		printf("Case #%d: %.12lf\n", TT, sol);
 	}
 
 	return 0;
 }
