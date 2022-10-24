#include <cstdio>
 #include <cstring>
 #include <vector>
 #include <string>
 #include <queue>
 #include <algorithm>
 
 using namespace std;
 
 #define MAXN (16)
 #define MAX2N (1 << 15)
 
 typedef long long ll;
 typedef pair <int, int> PII;
 typedef pair <ll, PII> PIP;
 typedef vector <PII> VP;
 
 int T;
 int N;
 
 int act[MAXN];
 int person[MAXN];
 
 int V[MAXN][MAX2N];
 int dp[MAXN][MAX2N];
 int rit;
 
 int rec(int id, int b)
 {
 	int &res = dp[id][b];
 	if(V[id][b] != rit)
 	{
 		V[id][b] = rit;
 
 		if(id == N)
 		{
 			res = 0;
 			int a = b;
 			while(a > 0)
 			{
 				a ^= a & -a;
 				++res;
 			}
 		}
 		else
 		{
 			res = -1;
 
 			if(person[id] == 0)
 			{
 				int i;
 				for(i = 0; i < 15; ++i)
 				{
 					int &p = i;
 					if(act[id] ^ ((b >> p) & 1))
 					{
 						int r1 = rec(id + 1, b ^ (1 << p));
 						if(r1 != -1 && (res == -1 || res > r1))
 							res = r1;
 					}
 				}
 			}
 			else
 			{
 				int p = person[id] - 1;
 				if(act[id] ^ ((b >> p) & 1))
 					res = rec(id + 1, b ^ (1 << p));
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
 		int i, j;
 
 		scanf("%d", &N);
 		for(i = 0; i < N; ++i)
 		{
 			char s[4];
 			int p;
 			scanf("%s %d", s, &p);
 			act[i] = (s[0] == 'E');
 			person[i] = p;
 		}
 
 		for(i = 1; 1; ++i)
 		{
 			int minp = -1;
 			for(j = 0; j < N; ++j)
 			{
 				if(person[j] >= i && (minp == -1 || minp > person[j]))
 					minp = person[j];
 			}
 
 			if(minp == -1)
 				break;
 
 			for(j = 0; j < N; ++j)
 			{
 				if(person[j] == minp)
 					person[j] = i;
 			}
 		}
 
 		int sol = -1;
 		int N2 = 1 << N;
 		++rit;
 
 		for(i = 0; i < N2; ++i)
 		{
 			int res = rec(0, i);
 			if(res != -1 && (sol == -1 || sol > res))
 			{
 				sol = res;
 				continue;
 
 				int c = 0;
 				int a = i;
 				while(a > 0)
 				{
 					a ^= a & -a;
 					++c;
 				}
 
 				if(sol == -1 || sol > c)
 					sol = c;
 			}
 		}
 
 		printf("Case #%d: ", TT);
 		if(sol == -1)
 			printf("CRIME TIME\n");
 		else
 			printf("%d\n", sol);
 	}
 
 	return 0;
 }
