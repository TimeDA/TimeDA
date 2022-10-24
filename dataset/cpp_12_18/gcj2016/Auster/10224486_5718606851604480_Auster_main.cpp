#pragma comment(linker, "/STACK:134217728")
 #define _CRT_SECURE_NO_WARNINGS
 
 #include <cstdio>
 #include <algorithm>
 #include <iostream>
 #include <vector>
 #include <queue>
 #include <map>
 #include <set>
 #include <string>
 #include <numeric>
 #include <complex>
 #include <functional>
 #include <cmath>
 #include <time.h>
 #include <memory.h>
 
 using namespace std;
 
 typedef long long LL;
 
 int T, n, r, p, s;
 
 bool can(int r, int p, int s)
 {
 	int m = max(r, max(s, p));
 	if (m > r + p + s - m)
 		return 0;
 	return 1;
 }
 
 
 int main()
 {
 #ifndef _DEBUG
 	freopen("A-small-attempt0.in", "r", stdin);
 	freopen("A-small-attempt0.out", "w", stdout);
 #endif
 
 	scanf("%d", &T);
 	for (int test = 1; test <= T; ++test)
 	{
 		scanf("%d%d%d%d", &n, &r, &p, &s);
 		printf("Case #%d: ", test);
 
 		vector<pair<string, char>> a;
 		for (int i = 0; i < p; ++i)
 			a.push_back(make_pair("P", 'P'));
 		for (int i = 0; i < r; ++i)
 			a.push_back(make_pair("R", 'R'));
 		for (int i = 0; i < s; ++i)
 			a.push_back(make_pair("S", 'S'));
 
 		bool bad = 0;
 
 		while (a.size() > 1)
 		{
 
 			vector<pair<string, char>> next;
 
 			vector<pair<string, char>> P;
 			vector<pair<string, char>> R;
 			vector<pair<string, char>> S;
 
 			for (int i = 0; i < a.size(); ++i)
 			{
 				if (a[i].second == 'P')
 					P.push_back(a[i]);
 				if (a[i].second == 'R')
 					R.push_back(a[i]);
 				if (a[i].second == 'S')
 					S.push_back(a[i]);
 			}
 
 			if (!can(P.size(), R.size(), S.size()))
 			{
 				bad = 1;
 				break;
 			}
 
 			int pr = (int)a.size() / 2 - (int)S.size();
 			int ps = (int)P.size() - pr;
 			int rs = (int)R.size() - pr;
 
 			int pi = 0;
 			int ri = 0;
 			int si = 0;
 
 			for (int i = 0; i < pr; ++i)
 			{
 				string s = min(P[pi].first + R[ri].first, R[ri].first + P[pi].first);
 				pair<string, char> add = make_pair(s, 'P');
 				next.push_back(add);
 				pi++;
 				ri++;
 			}
 			for (int i = 0; i < ps; ++i)
 			{
 				string s = min(P[pi].first + S[si].first, S[si].first + P[pi].first);
 				pair<string, char> add = make_pair(s, 'S');
 				next.push_back(add);
 				pi++;
 				si++;
 			}
 			for (int i = 0; i < rs; ++i)
 			{
 				string s = min(R[ri].first + S[si].first, S[si].first + R[ri].first);
 				pair<string, char> add = make_pair(s, 'R');
 				next.push_back(add);
 				ri++;
 				si++;
 			}
 
 			sort(next.begin(), next.end());
 			a = next;
 
 		}
 
 		if (bad)
 		{
 			printf("IMPOSSIBLE\n");
 			continue;
 		}
 		
 		printf("%s\n", a[0].first.c_str());
 	}
 	return 0;
 }