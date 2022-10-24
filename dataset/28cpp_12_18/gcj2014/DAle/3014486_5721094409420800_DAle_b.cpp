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
 	ifstream ifs("b.in");
 	ofstream ofs("b.out");
 	int t;
 	ifs >> t;
 	for (int test = 0; test < t; ++test)
 	{
 		int n;
 		ifs >> n;
 		vector<int> v(n);
 		for (int i = 0; i < n; ++i)
 			ifs >> v[i];
 		int maxp = max_element(v.begin(), v.end()) - v.begin();
 		vector<int> up(n, 0), down(n, 0);
 		for (int i = 0; i < n; ++i) 
 		{
 			if (i != maxp) {
 				for (int j = 0; j < i; ++j)
 					if (j != maxp && v[j] > v[i])
 						up[i]++;
 				for (int j = i+1; j < n; ++j)
 					if (j != maxp && v[j] > v[i])
 						down[i]++;
 			}
 		}
 		int res = n*n*n;
 		for (int i = maxp; i <= maxp; ++i)
 		{
 			int s = 0;
 			s += abs(maxp-i);
 			for (int j = 0; j < n; ++j)
 			{
 				if (j < i && j != maxp)
 					s += up[j];
 				if (j > i && j != maxp)
 					s += down[j];
 			}
 			if (i != maxp)
 				if (i < maxp) s += down[i]; else s += up[i];
 			res = min(res, s);
 		}
 
 
 		ofs << "Case #" << test+1 << ": " << res << endl;
 	}
 	return 0;
 }
 
