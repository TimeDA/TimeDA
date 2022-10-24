#include <cstdio>
 #include <cstring>
 #include <vector>
 #include <string>
 #include <queue>
 #include <algorithm>
 
 using namespace std;
 
 #define MAXN (102)
 #define MAXA (12)
 #define MAXUA (1024)
 
 typedef long long ll;
 typedef pair <int, int> PII;
 typedef pair <ll, PII> PIP;
 typedef vector <PII> VP;
 
 int T;
 int N, P, Q;
 int H[MAXN];
 int G[MAXN];
 
 int rit;
 int V[2][MAXN][MAXA][MAXA][MAXUA][2];
 int dp[2][MAXN][MAXA][MAXA][MAXUA][2];
 
 int rec(int pl, int id, int a, int b, int ua, int start)
 {
 	if(id >= N)
 		return 0;
 
 	int &res = dp[pl][id][a][b][ua][start];
 
 	if(V[pl][id][a][b][ua][start] != rit)
 	{
 		V[pl][id][a][b][ua][start] = rit;
 		res = 0;
 
 		int i;
 
 		if(start)
 		{
 			for(i = 0; (i - 1) * P < H[id] && i <= ua; ++i)
 			{
 				if(i * P >= H[id])
 					res = max(res, rec(pl, id + 1, 0, 0, ua - i, 1) + G[id]);
 				else
 					res = max(res, rec(pl, id,     i, 0, ua - i, 0));
 			}
 		}
 		else
 		{
 			if(pl == 0) // main
 			{
 				if((a + 1) * P + b * Q >= H[id])
 					res = max(res, rec(1, id + 1, 0, 0, ua, 1) + G[id]);
 				else
 					res = max(res, rec(1, id, a + 1, b, ua, 0));
 
 				res = max(res, rec(1, id, a, b, ua + 1, 0));
 			}
 			else // tower
 			{
 				if(a * P + (b + 1) * Q >= H[id])
 					res = rec(0, id + 1, 0, 0, ua, 1);
 				else
 					res = rec(0, id, a, b + 1, ua, 0);
 			}
 		}
 	}
 
 	return res;
 }
 
 int main()
 {
 	scanf("%d", &T);
 	for(int TT = 1; TT <= T; ++TT)
 	{
 		int i;
 
 		scanf("%d %d %d", &P, &Q, &N);
 		for(i = 0; i < N; ++i)
 			scanf("%d %d", H + i, G + i);
 
 		++rit;
 		int sol = rec(0, 0, 0, 0, 0, 1);
 
 		printf("Case #%d: %d\n", TT, sol);
 	}
 
 	return 0;
 }
