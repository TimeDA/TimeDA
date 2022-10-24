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
 
 bool eq(double a, double b) {
 	return abs(a-b) < 1e-10;
 }
 
 void out(ofstream& ofs, double res)
 {
 	ofs << fixed << setprecision(15) << res << endl;
 }
 
 int main()
 {
 	ifstream ifs("b.in");
 	ofstream ofs("b.out");
 	int t;
 	ifs >> t;
 	for (int test = 0; test < t; ++test)
 	{
 		int n;
 		double v, x;
 		ifs >> n >> v >> x;
 		vector<double> r(n);
 		vector<double> c(n); 
 		ofs << "Case #" << test+1 << ": ";
 		for (int i = 0; i < n; ++i)
 		{
 			ifs >> r[i] >> c[i];
 		}
 		if (n == 1)
 		{
 			if (eq(x, c[0])) {
 				out(ofs, v / r[0]);
 			}
 			else ofs << "IMPOSSIBLE\n";
 		}
 		else if (n == 2)
 		{
 			if (x < min(c[0], c[1])-1e-12 || x > max(c[0], c[1])+1e-12)
 			{
 				ofs << "IMPOSSIBLE\n";
 			}
 			else {
 				if (eq(c[0], c[1])) {
 					out(ofs, v / (r[0]+r[1]));
 				}
 				else {
 					double v0 = (x - c[1])*v / (c[0] - c[1]);
 					double v1 = v - v0;
 					out(ofs, max(v0 / r[0], v1 / r[1]));
 				}
 			}
 		}
 	}
 	return 0;
 }
