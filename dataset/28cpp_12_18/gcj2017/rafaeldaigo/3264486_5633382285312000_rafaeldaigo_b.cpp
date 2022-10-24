#include<cstdio>
 #include<cstring>
 #include<queue>
 #include<utility>
 #include<vector>
 #include<algorithm>
 
 using namespace std;
 
 long long solve(long long n)
 {
 	if (n == 0)
 		return 0;
 	long long lastd = n % 10;
 	long long front = n / 10;
 	long long secondlastd = front % 10;
 	if (lastd < secondlastd)
 	{
 		long long fsolve = solve(front - 1);
 		return fsolve * 10 + 9;
 	}
 	else
 	{
 		long long fsolve = solve(front);
 		if (fsolve == front)
 		{
 			return n;
 		}
 		else
 		{
 			return fsolve * 10 + 9;
 		}
 	}
 }
 
 int main()
 {
 	int t, teste;
 	scanf("%d\n", &teste);
 	for (int t = 0; t < teste; t++)
 	{
 		long long n;
 		scanf("%lld\n", &n);
 
 		long long resp = solve(n);
 		printf("Case #%d: %lld\n", t + 1, resp);
 	}
 	return 0;
 }
