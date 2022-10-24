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
 
 vector<pair<int,int> > calc(int h, int w, vector<int> rr)
 {
 	int n = rr.size();
 	vector<pair<int,int> > res(n);
 	vector<pair<int, int> > rd;
 	for (int i = 0; i < n; ++i)
 		rd.push_back(make_pair(rr[i], i));
 	sort(rd.begin(), rd.end());
 	reverse(rd.begin(), rd.end());
 	vector<int> was(n, 0);
 	int x = 0;
 	int cnt = 0;
 	while (true) {
 		int i = 0;
 		int y = 0;
 		int maxr = 0;
 		for (int i = 0; i < n; ++i)
 			if (was[i] == 0 && (y == 0 || y + rd[i].first <= w))
 			{
 				if (y == 0) { if (x > 0) x += rd[i].first; if (x > h) break; maxr = rd[i].first; }
 				res[rd[i].second] = make_pair(x, y == 0 ? y : y + rd[i].first);
 				was[i] = 1;
 				++cnt;
 				if (y == 0) y += rd[i].first; else y += 2*rd[i].first;
 			}
 		if (cnt == n) return res;	
 		x += maxr; 
 		if (x > h) break;
 	}
 	return vector<pair<int,int> >(); 
 }
 
 int main()
 {
 	ifstream ifs("b.in");
 	ofstream ofs("b.out");
 	int t;
 	ifs >> t;
 	for (int test = 0; test < t; ++test)
 	{
 		int n, w, h;
 		ifs >> n >> w >> h;
 		vector<int> r(n);
 		for (int i =0; i < n; ++i)
 			ifs >> r[i];
 
 		vector<pair<int,int> > res;
 		if (h >= w) 
 		{
 			res = calc(h, w, r);
 			if (res.empty()) { ofs << "ERROR\n"; continue; }
 		}
 		else {
 			res = calc(w, h, r);
 			if (res.empty()) { ofs << "ERROR\n"; continue; }
 			for (int i = 0; i < n; ++i)
 				swap(res[i].first, res[i].second);
 		}
 		ofs << "Case #" << test+1 << ":"; 
 		for (int i = 0; i < n; ++i)
 			ofs << " " << res[i].second << " " << res[i].first;
 		ofs	<< endl;
 	}
 	return 0;
 }
