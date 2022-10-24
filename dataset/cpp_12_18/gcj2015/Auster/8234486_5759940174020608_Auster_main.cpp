#pragma comment(linker, "/STACK:134217728")
 
 #include <cstdio>
 #include <iostream>
 #include <map>
 #include <set>
 #include <vector>
 #include <queue>
 #include <string>
 #include <algorithm>
 #include <numeric>
 #include <functional>
 #include <cmath>
 #include <complex>
 #include <memory.h>
 #include <time.h>
 
 using namespace std;
 
 typedef long long LL;
 
 int t, n;
 
 
 char buf[1 << 20];
 
 vector<int> C[1 << 8];
 int E[1 << 12], F[1 << 12];
 
 
 int main()
 {
 
 	freopen("C-small-attempt0 (2).in", "r", stdin);
 	freopen("output.txt", "w", stdout);
 
 	cin >> t;
 	for(int test = 1; test <= t; ++test)
 	{
 		map<string, int> M;
 		cin >> n;
 		cin.ignore();
 
 
 		for(int i = 0; i < n; ++i)
 		{
 			C[i].clear();
 			cin.getline(buf, 1 << 20);
 			stringstream ss;
 			ss << string(buf);
 			while (!ss.eof())
 			{
 				string s;
 				ss >> s;
 				if (!M.count(s))
 					M[s] = M.size();
 				C[i].push_back(M[s]);
 			}
 			sort(C[i].begin(), C[i].end());
 			C[i].resize(unique(C[i].begin(), C[i].end()) - C[i].begin());
 		}
 
 		memset(E, 0, sizeof(E));
 		memset(F, 0, sizeof(F));
 		for(int i = 0; i < C[0].size(); ++i)
 			E[C[0][i]] = 1;
 		for(int i = 0; i < C[1].size(); ++i)
 			F[C[1][i]] = 1;
 		int res = (int)1e9;
 		int add = 0;
 		for(int i = 0; i < 1 << 12; ++i)
 			add += E[i] & F[i];
 		for(int i = 0; i < 1 << n; ++i)
 		{
 			if (i & 1)
 				continue;
 			if (!(i & 2))
 				continue;	
 			set<int> e, f;
 
 			for(int j = 0; j < n; ++j)
 			{
 				if (j <= 1)
 					continue;
 				if (i & (1 << j))
 				{
 					for(int k = 0; k < C[j].size(); ++k)
 						f.insert(C[j][k]);
 				}
 				else
 				{
 					for(int k = 0; k < C[j].size(); ++k)
 						e.insert(C[j][k]);
 				}
 			}
 			int now = 0;
 			for(set<int> :: iterator it = e.begin(); it != e.end(); ++it)
 			{
 				if (E[*it] && F[*it])
 					continue;
 				if (f.find(*it) != f.end())
 					now++;
 				else
 				{
 					if (F[*it])
 						now++;
 				}
 			}
 			for(set<int> :: iterator it = f.begin(); it != f.end(); ++it)
 			{
 				if (E[*it] && F[*it])
 					continue;
 				if (e.find(*it) != e.end())
 					continue;
 				if (E[*it])
 					now++;
 			}
 			res = min(res, add + now);
 		}
 
 		cout << "Case #" << test << ": " << res << endl;
 	}
 	return 0;
 }