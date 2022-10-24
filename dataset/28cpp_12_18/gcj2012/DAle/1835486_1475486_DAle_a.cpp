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
 
 struct A {
 	A(int t, int p, int i): t(t), p(p), i(i) { }
 	int t, p, i;
 	bool operator<(const A& rhs) const
 	{
 		return t*rhs.p < rhs.t*p || t*rhs.p == rhs.t*p && i < rhs.i;
 	}
 };
 
 int main()
 {
 	ifstream ifs("a.in");
 	ofstream ofs("a.out");
 	int t;
 	ifs >> t;
 	for (int test = 0; test < t; ++test)
 	{
 		vector<A> v;
 		int n;
 		ifs >> n;
 		vector<int> t(n), p(n);
 		for (int i = 0; i < n; ++i)
 		{
 			ifs >> t[i];
 		}
 		for (int i = 0; i < n; ++i)
 		{
 			ifs >> p[i];
 		}
 		for (int i = 0; i < n; ++i)
 			v.push_back(A(t[i], p[i], i));
 		sort(v.begin(), v.end());
 		ofs << "Case #" << test+1 << ":";
 		for (int i = 0; i < n; ++i)
 			ofs << ' ' << v[i].i;
 		ofs << endl;
 	}
 	return 0;
 }
