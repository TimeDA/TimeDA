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
 
 int m, n;
 string s[20];
 
 set<string> sets[256];	
 int way[10];
 int maxN = 0, cntN = 0;
 
 
 void Go(int step)
 {
 	if (step == m)
 	{
 		set<int> st;
 		for (int i = 0; i < m; ++i)
 			st.insert(way[i]);
 		if (st.size() == n)
 		{
 			int masks[4] = {0};
 			for (int i = 0; i < m; ++i)
 			{
 				masks[way[i]] |= (1<<i);
 			}
 			int r  =0;
 			for (int i = 0; i < n; ++i)
 			{
 				r += sets[masks[i]].size();				
 			}
 			if (r > maxN)
 			{
 				maxN = r;
 				cntN = 1;
 			} else if (r == maxN) {
 				cntN++;
 			}
 		}
 		return;
 	}
 	for (int i = 0; i < n; ++i)
 	{
 		way[step] = i;
 		Go(step+1);
 	}
 }
 
 int main()
 {
 	ifstream ifs("d.in");
 	ofstream ofs("d.out");
 	int t;
 	ifs >> t;
 	for (int test = 0; test < t; ++test)
 	{
 		maxN = 0;
 		ifs >> m >> n;
 		for (int i = 0 ; i < m; ++i)
 			ifs >> s[i];
 		for (int mask = 0; mask < (1<<m); ++mask)
 		{
 			set<string> ts;
 			for (int j = 0; j < m; ++j)
 				if (mask & (1<<j))
 				{
 					for (int i = 0; i <= s[j].size(); ++i)
 					{
 						ts.insert(s[j].substr(0, i));
 					}
 				}
 			sets[mask] = ts;
 		}
 		Go(0);
 		ofs << "Case #" << test+1 << ": " << maxN << ' ' << cntN << endl;
 	}
 	return 0;
 }
