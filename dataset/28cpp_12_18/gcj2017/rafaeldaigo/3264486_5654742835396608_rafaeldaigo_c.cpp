#include<cstdio>
 #include<cstring>
 #include<queue>
 #include<utility>
 #include<vector>
 #include<algorithm>
 
 using namespace std;
 
 long long rec(long long n, long long c1, long long c2, long long k)
 {
 	if (k <= c1)
 		return n;
 	if (k <= c1 + c2)
 		return n - 1;
 	long long nk = k - c1 - c2;
 	long long nn = n / 2;
 	long long nc1;
 	long long nc2;
 	if (n % 2 == 0)
 	{
 		nc1 = c1;
 		nc2 = c1 + 2 * c2;
 	}
 	else
 	{
 		nc1 = 2 * c1 + c2;
 		nc2 = c2;
 	}
 	return rec(nn, nc1, nc2, nk);
 }
 
 long long solve(long long n, long long k)
 {
 	return rec(n, 1, 0, k);
 }
 
 int main()
 {
 	int t, teste;
 	scanf("%d\n", &teste);
 
 	for (int t = 0; t < teste; t++)
 	{
 		long long i;
 		int n, k;
 		scanf("%d %d\n", &n, &k);
 
 		long long resp = solve(n, k);
 		printf("Case #%d: %lld %lld\n", t + 1, resp / 2, (resp - 1) / 2);
 	}
 	return 0;
 }
