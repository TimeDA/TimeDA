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
 
 const double PI_2 = acos(0.0); // PI / 2, i.e. 90 degree
 const double PI = 2 * PI_2;
 
 
 double dp[1024][1024]; //cur, chosn
 
 double area(pair<double, double> a)
 {
 	return 2.0*a.first*a.second ;
 }
 
 double face(pair<double, double> a)
 {
 	return a.first*a.first;
 }
 
 double re(vector< pair<double, double> > in, int k)
 {
 	vector<int> a(in.size());
 	for (int i = 0; i < a.size(); ++i)
 		a[i] = i;
 
 	double ans = 0;
 	do
 	{
 		double s = area(in[a[0]]) + face(in[a[0]]);
 		for (int i = 1; i < k; ++i)
 			s += area(in[a[i]]);
 		ans = max(ans, s);
 	} while (next_permutation(a.begin(), a.end()));
 	return ans;
 }
 
 int main(int __an, char **__ag)
 {	
 	int Case, cases = 0;
 	scanf("%d" , &Case);
 	while (Case--)	
 	{
 		int n, k;
 		cin >> n >> k;
 		vector< pair<double, double> > in(n);
 		for (int i = 0; i < n; ++i)
 		{
 			cin >> in[i].first >> in[i].second;			
 		}
 
 		sort(in.begin(), in.end());
 		double bbb = re(in, k);
 
 		reverse(in.begin(), in.end());
 		memset(dp, 0, sizeof(dp));
 
 		for (int i = 0; i < n; ++i)
 			dp[i][1] = area(in[i]) + face(in[i]);
 
 		for (int cur = 2; cur <= k; ++cur)
 		{
 			for (int i = 0; i < n; ++i)
 			{
 				for (int j = 0; j < n; ++j)
 				{
 					if (j == i || in[i].first < in[j].first)
 						continue;
 
 					dp[i][cur] = max(dp[i][cur],
 						dp[i][cur - 1] +
 						area(in[j])
 					);
 				}
 			}
 		}
 
 
 		printf("Case #%d: " , ++cases);
 		double ans = 0;
 		for (int i = 0; i < n; ++i)
 			ans = max(ans, dp[i][k]);
 		printf("%0.8lf\n", bbb*PI);
 	//	if (ans != bbb)
 		//	puts("...");
 
 
 
 
 	}
 
 	return 0;
 }
 
