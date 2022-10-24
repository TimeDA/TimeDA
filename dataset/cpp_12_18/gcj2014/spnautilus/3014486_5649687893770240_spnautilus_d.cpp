#include <cstdio>
 #include <cstring>
 #include <vector>
 #include <string>
 #include <set>
 #include <algorithm>
 
 using namespace std;
 
 #define MAXM (8)
 #define MAXN (4)
 #define MAXS (16)
 
 typedef long long ll;
 typedef pair <int, int> PII;
 typedef vector <int> VI;
 
 int T;
 int N, M;
 
 string S[MAXM];
 VI server[MAXN];
 char temp[MAXS];
 
 int best;
 int bestn;
 
 bool cmpf(int a, int b)
 {
 	return S[a] < S[b];
 }
 
 int check(int id)
 {
 	int i;
 
 	set <string> s;
 	for(int a : server[id])
 	{
 		int len = S[a].length();
 		for(i = 1; i <= len; ++i)
 		{
 //			printf("%s\n", S[a].substr(0, i).c_str());
 			s.insert(S[a].substr(0, i));
 		}
 	}
 
 //	printf("-> %d\n", s.size());
 
 	return s.size() + 1;
 }
 
 void gen(int id)
 {
 	if(id < M)
 	{
 		int i;
 		for(i = 0; i < N; ++i)
 		{
 			server[i].push_back(id);
 			gen(id + 1);
 			server[i].pop_back();
 		}
 	}
 	else
 	{
 		int i;
 		int sum = 0;
 		for(i = 0; i < N; ++i)
 		{
 			if(server[i].size() == 0)
 				return;
 
 			sum += check(i);
 		}
 
 //		printf("check %d\n", sum);
 
 		if(best < sum)
 		{
 			best = sum;
 			bestn = 0;
 		}
 
 		if(best == sum)
 			++bestn;
 	}
 }
 
 int main()
 {
 	scanf("%d", &T);
 	for(int TT = 1; TT <= T; ++TT)
 	{
 		int i;
 		scanf("%d %d", &M, &N);
 		for(i = 0; i < M; ++i)
 		{
 			scanf("%s", temp);
 			S[i] = temp;
 		}
 
 		best = -1;
 		bestn = 0;
 		gen(0);
 
 		printf("Case #%d: %d %d\n", TT, best, bestn);
 	}
 
 	return 0;
 }
