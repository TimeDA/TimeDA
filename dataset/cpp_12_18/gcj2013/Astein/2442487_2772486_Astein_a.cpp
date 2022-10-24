#include <vector>
 #include <algorithm>
 #include <cstdio>
 #include <iostream>
 
 using namespace std;
 
 int T, N, M;
 
 const long long MOD = 1000002013;
 
 int main()
 {
 	scanf("%d", &T);
 	for (int cn = 1; cn <= T; ++cn)
 	{
 		scanf("%d%d", &N, &M);
 		long long ret1 = 0, ret2 = 0;
 		vector<pair<int, int> > v;
 
 		for (int i = 0; i < M; ++i)
 		{
 			int s, e, p;
 			scanf("%d%d%d", &s, &e, &p);
 			int k = e - s;
 			ret1 += p * (k * N - k * (k - 1) / 2);
 			for (int j = 0; j < p; ++j)
 			{
 				v.push_back(make_pair(s, 0));
 				v.push_back(make_pair(e, 1));
 			}
 		}
 		sort(v.begin(), v.end());
 		vector<int> stack;
 		for (int i = 0; i < v.size(); ++i)
 		{
 			if (v[i].second == 0)
 			{
 				stack.push_back(v[i].first);
 			} 
 			else 
 			{
 				int k = v[i].first - stack.back();
 				
 				ret2 += (k * N - k * (k - 1) / 2);
 				stack.pop_back();
 			}
 		}
 		cout << "Case #" << cn << ": " << (ret1 - ret2) << endl;
 	}
 }
 
