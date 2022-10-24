#include <cstdio>
 #include <cstdlib>
 #include <cstring>
 #include <cctype>
 #include <iostream>
 #include <cmath>
 #include <cassert>
 #include <sstream>
 #include <functional>
 #include <algorithm>
 #include <map>
 #include <string>
 #include <vector>
 #include <set>
 #include <queue>
 
 using namespace std;
 
 int nt;
 int n, m;
 
 const int MOD = 1000000007;
 
 string s[10];
 
 int resMax = 0, resCnt = 0;
 
 vector<string> sel[10];
 
 bool used[10];
 int nused;
 
 void go()
 {
 	int cur = 0;
 	for(int i = 0; i < n; i++)
 	{
 		//printf("\nserver = %d\n", i);
 		set<string> S;
 		S.clear();
 		S.insert("");
 		for(int j = 0; j < sel[i].size(); j++)
 		{
 			string x = "";
 			//printf("%s, ", sel[i][j].c_str());
 
 			for(int k = 0; k < sel[i][j].size(); k++)
 			{
 				x += sel[i][j][k];
 				S.insert(x);
 			}
 		}
 		cur += S.size();
 	}
 	if (cur == resMax) resCnt = (resCnt + 1) % MOD;
 	else
 		if (cur > resMax)
 		{
 			resMax = cur;
 			resCnt = 1;
 		}
 }
 
 void rec(int id, int server)
 {
 	if (server == n)
 	{
 		if (nused == m) go();
 		return;
 	}
 
 	if (id == m)
 	{
 		if (sel[server].size() != 0) rec(0, server + 1);
 		return;
 	}
 
 	if (!used[id])
 	{
 		used[id] = true;
 		sel[server].push_back(s[id]);
 		nused++;
 		rec(id + 1, server);
 		sel[server].pop_back();
 		nused--;
 		used[id] = false;
 	}
 
 	rec(id + 1, server);
 }
 
 int main()
 {
 	int nt;
 	scanf("%d", &nt);
 	for(int tt = 1; tt <= nt; tt++)
 	{
 		fprintf(stderr, "test = %d\n", tt);
 		printf("Case #%d: ", tt);
 
 		scanf("%d %d ", &m, &n);
 
 		for(int i = 0; i < m; i++) cin >> s[i];
 
 		resMax = 0;
 		resCnt = 0;
 		nused = 0;
 		rec(0, 0);
 		printf("%d %d\n", resMax, resCnt);
 	}
 	return 0;
 }
