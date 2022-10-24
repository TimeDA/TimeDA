#include <cstdio>
 #include <cstring>
 #include <vector>
 #include <string>
 #include <queue>
 #include <algorithm>
 
 using namespace std;
 
 #define MAXN (10005)
 
 typedef long long ll;
 typedef pair <int, int> PII;
 typedef pair <ll, PII> PIP;
 typedef vector <PII> VP;
 
 int T;
 int N, X;
 int A[MAXN];
 
 int main()
 {
 	scanf("%d", &T);
 	for(int TT = 1; TT <= T; ++TT)
 	{
 		int i, j;
 		scanf("%d %d", &N, &X);
 		for(i = 0; i < N; ++i)
 		{
 			scanf("%d", A + i);
 		}
 
 		sort(A, A + N);
 		int sol = 0;
 		j = 0;
 		for(i = N - 1; i > j; --i)
 		{
 			++sol;
 			if(A[i] + A[j] <= X)
 				++j;
 		}
 
 		if(i == j)
 			++sol;
 
 		printf("Case #%d: %d\n", TT, sol);
 	}
 
 	return 0;
 }
