#include <cstdio>
 #include <cstring>
 #include <vector>
 #include <string>
 #include <queue>
 #include <algorithm>
 
 using namespace std;
 
 #define MAXN (1005)
 
 typedef long long ll;
 typedef pair <int, int> PII;
 typedef pair <ll, PII> PIP;
 typedef vector <PII> VP;
 
 int T;
 int N;
 int A[MAXN];
 
 int main()
 {
 	scanf("%d", &T);
 	for(int TT = 1; TT <= T; ++TT)
 	{
 		int i, j;
 
 		scanf("%d", &N);
 		for(i = 0; i < N; ++i)
 			scanf("%d", A + i);
 
 		int sol = 0;
 		for(i = N; i >= 1; --i)
 		{
 			int mini = 0;
 			int mina = A[0];
 			for(j = 1; j < i; ++j)
 			{
 				if(mina > A[j])
 				{
 					mina = A[j];
 					mini = j;
 				}
 			}
 
 //			printf("%d %d\n", mini, mina);
 
 			sol += min <int> (mini, i - mini - 1);
 
 			for(j = mini; j + 1 < i; ++j)
 				A[j] = A[j + 1];
 		}
 
 		printf("Case #%d: %d\n", TT, sol);
 	}
 
 	return 0;
 }
