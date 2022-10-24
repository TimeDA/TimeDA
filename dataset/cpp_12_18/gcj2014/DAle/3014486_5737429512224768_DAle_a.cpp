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
 		int n, x;
 		ifs >> n >> x;
 		vector<int> a;
 		for (int i =0; i< n; ++i)
 		{
 			int j;
 			ifs >> j;
 			a.push_back(j);
 		}
 		sort(a.begin(), a.end());
 		vector<int> was(n, 0);
 		int res = n;
 		for (int i = n-1; i >= 0; --i)
 			if (was[i] == 0)
 				for (int j = i-1; j >= 0; --j)
 					if (was[j] == 0)
 						if (a[i] + a[j] <= x)
 						{
 							was[j] = 1;
 							was[i] = 1;
 							--res;
 							break;
 						}
 		ofs << "Case #" << test+1 << ": " << res << endl;
 	}
 	return 0;
 }
