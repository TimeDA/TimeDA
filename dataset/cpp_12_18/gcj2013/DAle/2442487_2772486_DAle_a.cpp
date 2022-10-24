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
 #include <iostream>
 #include <set>
 
 using namespace std;
 
 const long long M = 1000002013LL;
 int n;
 
 long long cost(int a, int b, long long cnt)
 {
 	long long k = b-a;
 	long long d = n*k - k*(k-1)/2;
 	return ((d % M) * (cnt % M)) % M;
 }
 
 int main()
 {
 	ifstream ifs("a.in");
 	ofstream ofs("a.out");
 	int t;
 	ifs >> t;
 	for (int test = 0; test < t; ++test)
 	{
 		int m;
 		ifs >> n >> m;
 		vector<int> o(m), e(m), cnt(m);
 		for (int i =0; i < m; ++i)
 			ifs >> o[i] >> e[i] >> cnt[i];
 
 		map<int, long long> plus, minus;
 		for (int i = 0; i < m; ++i)
 		{
 			plus[o[i]] += cnt[i];
 			minus[o[i]] += 0;
 			minus[e[i]] += cnt[i];
 			plus[e[i]] += 0;
 		}
 		long long init = 0;
 		for (int i = 0; i < m; ++i)
 		{
 			init = (init + cost(o[i], e[i], cnt[i])) % M;
 		}
 
 		long long res = 0;
 		stack<pair<int,long long> > s;
 		for (map<int, long long>::iterator mi = plus.begin(); mi != plus.end(); ++mi) 
 		{
 			int j = mi->first;
 			if (plus[j] > 0)
 				s.push(make_pair(j, plus[j]));
 
 			long long need = minus[j];
 			while (need > 0) 
 			{
 				int pos = s.top().first;
 				long long cur = min(need, s.top().second);
 				if (cur == s.top().second) s.pop();
 				else 
 					s.top().second -= cur;
 				res = (res + cost(pos, j, cur)) % M;
 				need -= cur;
 			}
 		}
 		ofs << "Case #" << test+1 << ": " << (init+M-res)%M << endl;
 	}
 	return 0;
 }
