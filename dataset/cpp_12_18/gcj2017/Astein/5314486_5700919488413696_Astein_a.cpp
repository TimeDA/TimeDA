#include <cstdio>
 #include <vector>
 #include <cstring>
 #include <algorithm>
 
 using namespace std;
 int table3[105][105];
 int table4[105][105][105];
 
 int solve3(int mod1, int mod2)
 {
 	if (table3[mod1][mod2] != -1)
 		return table3[mod1][mod2];
 
 	int ret = (mod1 + mod2 > 0) ? 1 : 0;
 
 	if (mod1 >= 1 && mod2 >= 1)
 		ret = max(ret, solve3(mod1 - 1, mod2 - 1) + 1);
 	if (mod1 >= 0 && mod2 >= 3)
 		ret = max(ret, solve3(mod1 - 0, mod2 - 3) + 1);
 	if (mod1 >= 3 && mod2 >= 0)
 		ret = max(ret, solve3(mod1 - 3, mod2 - 0) + 1);
 
 	return table3[mod1][mod2] = ret;
 }
 
 int solve4(int mod1, int mod2, int mod3)
 {
 	if (table4[mod1][mod2][mod3] != -1)
 		return table4[mod1][mod2][mod3];
 
 	int ret = (mod1 + mod2 + mod3 > 0) ? 1 : 0;
 
 	if (mod1 >= 4 && mod2 >= 0 && mod3 >= 0)
 		ret = max(ret, solve4(mod1 - 4, mod2 - 0, mod3 - 0) + 1);
 	if (mod1 >= 2 && mod2 >= 1 && mod3 >= 0)
 		ret = max(ret, solve4(mod1 - 2, mod2 - 1, mod3 - 0) + 1);
 	if (mod1 >= 1 && mod2 >= 0 && mod3 >= 1)
 		ret = max(ret, solve4(mod1 - 1, mod2 - 0, mod3 - 1) + 1);
 	if (mod1 >= 0 && mod2 >= 2 && mod3 >= 0)
 		ret = max(ret, solve4(mod1 - 0, mod2 - 2, mod3 - 0) + 1);
 	if (mod1 >= 0 && mod2 >= 1 && mod3 >= 2)
 		ret = max(ret, solve4(mod1 - 0, mod2 - 1, mod3 - 2) + 1);
 	if (mod1 >= 0 && mod2 >= 0 && mod3 >= 4)
 		ret = max(ret, solve4(mod1 - 0, mod2 - 0, mod3 - 4) + 1);
 
 	return table4[mod1][mod2][mod3] = ret;
 }
 
 
 int solve(vector<int> a, int p)
 {
 	int n = a.size();
 	vector<int> mod(p, 0);
 	for (int i = 0; i < n; ++i)
 	{
 		mod[a[i] % p]++;
 	}
 
 	if (p == 2)
 	{
 		return mod[0] + (mod[1] + 1) / 2;
 	}
 	else if (p == 3)
 	{
 		return mod[0] + solve3(mod[1], mod[2]);
 	}
 	else if (p == 4)
 	{
 		return mod[0] + solve4(mod[1], mod[2], mod[3]);
 	}
 	return -1;
 }
 
 int main()
 {
 	freopen("A-small-attempt0.in", "r", stdin);
 	freopen("A-small-attempt0.out", "w", stdout);
 
 	memset(table3, -1, sizeof(table3));
 	memset(table4, -1, sizeof(table4));
 
 	int T;
 	scanf("%d", &T);
 	for (int cn = 1; cn <= T; ++cn)
 	{
 		int N, P;
 		scanf("%d%d", &N, &P);
 		vector<int> a(N);
 		for (int i = 0; i < N; ++i)
 			scanf("%d", &a[i]);
 		printf("Case #%d: %d\n", cn, solve(a, P));
 	}
 }