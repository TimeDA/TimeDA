#define _CRT_SECURE_NO_WARNINGS
 
 #include <queue>
 #include <cstdio>
 #include <vector>
 #include <algorithm>
 
 using namespace std;
 
 vector<int> getSeq(int N)
 {
 	vector<int> ret;
 	int a, b, c, d;
 	scanf("%d%d%d%d", &a, &b, &c, &d);
 	ret.push_back(a);
 	for (int i = 1; i < N; ++i)
 	{
 		a = (a * b + c) % d;
 		ret.push_back(a);
 	}
 	return std::move(ret);
 }
 
 vector<int> child[1005];
 
 int main()
 {
 	int T;
 	scanf("%d", &T);
 	for (int cn = 1; cn <= T; ++cn)
 	{
 		int N, D;
 		scanf("%d%d", &N, &D);
 		for (int i = 0; i < N; ++i)
 			child[i].clear();
 
 		vector<int> S, M;
 
 		S = getSeq(N);
 		M = getSeq(N);
 
 		M[0] = -1;
 		for (int i = 1; i < N; ++i)
 		{
 			M[i] = M[i] % i;
 			child[M[i]].push_back(i);
 		}
 		
 		int ret = 0;
 
 		for (int cost = 0;; ++cost)
 		{
 			queue<int> Q;
 			if (cost != 0 && cost + D > 1000) break;
 			if (cost <= S[0] && S[0] <= cost + D); else continue;
 			Q.push(0);
 
 			int cnt = 0;
 			while (!Q.empty())
 			{
 				cnt++;
 				int now = Q.front(); Q.pop();
 				for (int i = 0; i < child[now].size(); ++i)
 				{
 					if (cost <= S[child[now][i]] && S[child[now][i]] <= cost + D)
 					{
 						Q.push(child[now][i]);
 					}
 				}
 			}
 			if (ret < cnt) ret = cnt;
 		}
 		printf("Case #%d: %d\n", cn, ret);
 	}
 	return 0;
 }