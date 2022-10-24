#include <iostream>
 #include <vector>
 #include <algorithm>
 #include <queue>
 #include <functional>
 #include <memory.h>
 
 using namespace std;
 
 typedef long long LL;
 
 int T;
 
 int x, n;
 int S[1 << 14];
 int used[1 << 14];
 
 int main()
 {
 	freopen("input.txt", "r", stdin);
 	freopen("output.txt", "w", stdout);
 	scanf("%d", &T);
 	for(int I = 1; I <= T; ++I)
 	{
 		scanf("%d%d", &n, &x);
 		for(int i = 0; i < n; ++i)
 			scanf("%d", &S[i]);
 		sort(S, S + n, greater<int>());
 		priority_queue<int> Q;
 		int res = 0;
 		for(int i = 0; i < n; ++i)
 		{
 			if (Q.empty() || Q.top() < S[i])
 				Q.push(x - S[i]);
 			else
 			{
 				Q.pop();
 				res++;
 			}
 		}
 		res += Q.size();
 		printf("Case #%d: %d\n", I, res);
 	}
 	return 0;
 }