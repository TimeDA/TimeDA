#include <fstream>
 #include <iomanip>
 #include <algorithm>
 #include <numeric>
 #include <vector>
 #include <string>
 #include <map>
 #include <set>
 #include <queue>
 #include <utility>
 #include <cmath>
 #include <functional>
 #include <stack>
 #include <set>
 
 using namespace std;
 
 int main()
 {
 	ifstream ifs("a.in");
 	ofstream ofs("a.out");
 	int t;
 	ifs >> t;
 	for (int test = 0; test < t; ++test)
 	{
 		int n, m;
 		ifs >> n >> m;
 		vector<string> v(n);
 		vector<vector<int>>  cnt(n, vector<int>(m, 0));
 		for (int i = 0; i < n; ++i)
 			ifs >> v[i];
 
 		int res = 0;
 		for (int j = 0; j < m; ++j)
 		{
 			for (int i = 0; i < n; ++i)
 			{
 				if (v[i][j] != '.') {
 					cnt[i][j]++;
 					if (v[i][j] == '^') ++res;
 					break;
 				}
 			}
 		}
 
 		for (int j = 0; j < m; ++j)
 		{
 			for (int i = n-1; i >= 0; --i)
 			{
 				if (v[i][j] != '.') {
 					cnt[i][j]++;
 					if (v[i][j] == 'v') ++res;
 					break;
 				}
 			}
 		}
 
 		for (int i = 0; i < n; ++i)
 		{
 			for (int j = 0; j < m; ++j)
 			{
 				if (v[i][j] != '.') {
 					cnt[i][j]++;
 					if (v[i][j] == '<') ++res;
 					break;
 				}
 			}
 		}
 
 		for (int i = 0; i < n; ++i)
 		{
 			for (int j = m-1; j >= 0; --j)
 			{
 				if (v[i][j] != '.') {
 					cnt[i][j]++;
 					if (v[i][j] == '>') ++res;
 					break;
 				}
 			}
 		}
 
 		bool b = true;
 		for (int i = 0; i < n; ++i)
 			for (int j = 0; j < m; ++j)
 				if (cnt[i][j] == 4) b = false;
 
 		ofs << "Case #" << test+1 << ": ";
 		if (!b)
 		{
 			ofs << "IMPOSSIBLE\n";
 		}
 		else ofs << res << endl;
 	}
 	return 0;
 }
