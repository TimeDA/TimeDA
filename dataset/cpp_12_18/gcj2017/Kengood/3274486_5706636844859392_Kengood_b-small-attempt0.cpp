#include <vector>
 #include <list>
 #include <map>
 #include <set>
 #include <deque>
 #include <queue>
 #include <stack>
 #include <bitset>
 #include <algorithm>
 #include <functional>
 #include <numeric>
 #include <utility>
 #include <sstream>
 #include <iostream>
 #include <iomanip>
 #include <string>
 #include <complex>
 #include <cstdio>
 #include <cmath>
 #include <cstdlib>
 #include <cctype>
 #include <cstring>
 #include <climits>
 #include <ctime>
 
 #include<unordered_map>
 #include<unordered_set>
 using namespace std;
 
 
 vector < pair<int, int>>  makefree(int c, vector < pair<int, int>> ac)
 {
 	vector < pair<int, int>> acf;
 	int cur = 0;
 	for (int i = 0; i < c; ++i)
 	{
 		if (cur >= ac[i].first)
 			cur = ac[i].first + 1;
 		else
 		{
 			acf.push_back({ cur, ac[i].first });
 			cur = ac[i].second;
 		}
 	}
 	if (cur < 1440)
 		acf.push_back({ cur, 1440 });
 
 	return acf;
 }
 
 
 int main(int __an, char **__ag)
 {	
 	int Case, cases = 0;
 	scanf("%d" , &Case);
 	while (Case--)	
 	{
 		int c, j;
 		cin >> c >> j;
 		vector < pair<int, int>> ac(c);
 		vector < pair<int, int>> aj(j);
 
 		for (int i = 0; i < c; ++i)
 			cin >> ac[i].first >> ac[i].second;
 		for (int i = 0; i < j; ++i)
 			cin >> aj[i].first >> aj[i].second;
 
 		sort(ac.begin(), ac.end());
 		sort(aj.begin(), aj.end());
 
 	
 		vector < pair<int, int>> acf = makefree(c, ac);
 		vector < pair<int, int>> ajf = makefree(j, aj);
 
 		if (ajf.size() < acf.size())
 			swap(ajf, acf);
 		int ans = 4;
 		if (acf.size() == 1)
 		{
 			vector<int> dff;
 			for (int i = 0; i < ajf.size(); ++i)
 			{
 				dff.push_back(ajf[i].second - ajf[i].first);
 				if (dff.back() >= 720)
 				{
 					ans = 2;
 					goto hell;
 				}
 			}
 			sort(dff.begin(), dff.end());
 			int aa = 0, cc = 1;
 			for (int i = dff.size(); i--;)
 			{
 				aa += dff[i];
 				if (aa >= 720) break;
 				++cc;
 			}
 			ans = cc + 1;
 		}
 		else if (acf.size() == 2)
 		{
 			vector<int> dff1, dff2;
 			for (int i = 0; i < ajf.size(); ++i)
 			{
 				dff1.push_back(ajf[i].second - ajf[i].first);
 			}
 
 
 			for (int i = 0; i < acf.size(); ++i)
 			{
 				dff2.push_back(acf[i].second - acf[i].first);
 			}
 
 			if ((dff1[0] >= 720 && dff2[1] >= 720) ||
 				(dff2[0] >= 720 && dff1[1] >= 720)
 				)
 				ans = 2;
 			else
 				ans = 4;
 
 		}
 		else
 		{
 			cerr << "...";
 		}
 	hell:;
 
 		printf("Case #%d: " , ++cases);
 		printf("%d\n", ans);
 
 
 
 	}
 
 	return 0;
 }
 
