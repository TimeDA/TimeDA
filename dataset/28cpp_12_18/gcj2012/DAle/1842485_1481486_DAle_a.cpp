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
 		int n;
 		ifs >> n;
 		vector<int> d(n);
 		vector<int> l(n);
 		for (int i = 0; i < n; ++i)
 			ifs >> d[i] >> l[i];
 		int D;
 		ifs >> D;
 
 		vector<int> f(n+5, -1);
 		f[0] = d[0];
 		for (int i = 1; i < n; ++i)
 		{
 			for (int j = 0; j < i; ++j)
 				if (d[i]-d[j] <= f[j])
 				{
 					int k = min(d[i]-d[j], l[i]);
 					if (k > f[i]) f[i] = k;
 				}
 		}
 		bool res = false;
 		for (int i = 0; i < n; ++i)
 			if (f[i] >= D - d[i]) res = true;
 		ofs << "Case #" << test+1 << ": " << (res ? "YES" : "NO") << endl;
 	}
 	return 0;
 }
