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
 		int n, k;
 		cin >> n >> k;
 		double all;
 		cin >> all;
 		vector<double> in(n);
 		double diff = 0 , sum = 0;
 		for (int i = 0; i < n; ++i)
 		{
 			cin >> in[i];
 			diff += 1.0 - in[i];
 			sum += in[i];
 		}
 
 		printf("Case #%d: " , ++cases);
 		double ans;
 		if (diff == all)
 		{
 			ans = 1.0;
 		}
 		else
 		{
 			double sp = (all) / (double)n;
 			double tar = (sum + all) / (double)n;
 			sort(in.begin(), in.end());
 			double ex = 0;
 			int one = 0;
 			for (int i = n; i--;)
 			{
 				if (tar <= in[i])
 				{
 					ex += sp;
 					++one;
 					continue;
 				}
 				double dd = 1.0 - in[i];
 				if (dd >= sp)
 					in[i] += sp;
 				else
 				{
 					ex += sp - dd;
 					in[i] = 1.0;
 					++one;
 				}
 			}
 
 			while (ex != 0)
 			{
 				sp = (ex) / (double)one;
 				sort(in.begin(), in.end());
 				ex = 0;
 				one = 0;
 				for (int i = n; i--;)
 				{
 					if (in[i] >= 1.0) continue;
 					if (tar <= in[i])
 					{
 			
 						continue;
 					}
 
 					double dd = 1.0 - in[i];
 					if (dd >= sp)
 						in[i] += sp;
 					else
 					{
 						ex += sp - dd;
 						in[i] = 1.0;
 						++one;
 					}
 				}
 
 			}
 
 			ans = 1.0;
 				for (int i = n; i--;)
 					ans *= in[i];
 		}
 
 
 
 		printf("%0.8lf\n", ans);
 
 	}
 
 	return 0;
 }
 
