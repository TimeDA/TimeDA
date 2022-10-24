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
 #include <sstream>
 
 using namespace std;
 
 int main()
 {
 	ifstream ifs("c.in");
 	ofstream ofs("c.out");
 	int t;
 	string s;
 	getline(ifs, s);
 	sscanf(s.c_str(), "%d", &t);
 	for (int test = 0; test < t; ++test)
 	{
 		int n;
 		getline(ifs, s);
 		sscanf(s.c_str(), "%d", &n);
 		vector<vector<int>> v(n);
 		map<string, int> m;
 		int all = 0;
 		for (int i = 0; i < n; ++i)
 		{
 			getline(ifs, s);
 			stringstream str(s);
 			string t;
 			while (str >> t)
 			{
 				if (m.count(t) == 0) 
 					m[t] = all++;
 				v[i].push_back(m[t]);
 			}
 		}
 
 		vector<int> eng(n, 0);
 		eng[0] = 1;
 		int res = 1000000;
 		for (int mask = 0; mask < (1<<(n-2)); ++mask)
 		{
 			for (int j = 0; j < n-2; ++j)
 				if (mask & (1 << j))
 				{
 					eng[2+j] = 1;
 				}
 				else eng[2+j] = 0;
 				vector<int> en(all, 0);
 				vector<int> fr(all, 0);
 				for (int i = 0; i < n; ++i)
 				{
 					vector<int>& x = (eng[i] == 1 ? en : fr);
 					for (int j = 0; j < v[i].size(); ++j)
 						x[v[i][j]] = 1;
 				}
 				int resv = 0;
 				for (int i = 0; i < all; ++i)
 					if (en[i] && fr[i]) ++resv;
 				res = min<int>(res, resv);
 		}
 		
 		ofs << "Case #" << test+1 << ": " << res << endl;
 	}
 	return 0;
 }
 
 
