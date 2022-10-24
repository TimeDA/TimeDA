#include <stdio.h>
 #include <algorithm>
 #include <vector>
 #include <set>
 #include <map>
 
 long long mod = 1000002013;
 
 using namespace std;
 
 struct pass
 {
 	int s,e;
 	int cnt;
 };
 
 int n;
 
 long long cost(long long s, long long e)
 {
 	e -= s;
 	// n + (n-1) + ... (n - (e-1))
 	return n * e - e*(e-1)/2;
 }
 
 int main()
 {
 	int T;
 	scanf("%d",&T);
 	for(int testcase = 1; testcase <= T; testcase++)
 	{
 		vector<pass> dat;
 		vector<int> events;
 		int m;
 		scanf("%d%d",&n,&m);
 
 		long long original = 0;
 		for(int i = 0; i < m; i++)
 		{
 			int a,b,c;
 			scanf("%d%d%d",&a,&b,&c);
 			pass p;
 			p.s = a;
 			p.e = b;
 			p.cnt = c;
 			original += c * (long long)cost(a,b) % mod;
 			original %= mod;
 			events.push_back(a);
 			events.push_back(b);
 			dat.push_back(p);
 		}
 		vector<pass> bys(dat), bye(dat);
 		sort(bys.begin(), bys.end(), [](const pass &a, const pass &b){return a.s < b.s;});
 		sort(bye.begin(), bye.end(), [](const pass &a, const pass &b){return a.e < b.e;});
 		sort(events.begin(), events.end());
 		events.erase(unique(events.begin(),events.end()),events.end());
 		int i = 0, j = 0;
 		map<int,long long> values;
 		long long actual = 0;
 
 		for(int k = 0; k < events.size(); k++)
 		{
 			int cur = events[k];
 			while(i < m && bys[i].s == cur){
 				values[-n] += bys[i].cnt;
 				i++;
 			}
 			while(j < m && bye[j].e == cur){
 				for(auto I = values.begin(); I != values.end();)
 				{
 					if (I->second > bye[j].cnt) {
 						I->second -= bye[j].cnt;
 						break;
 					} else {
 						bye[j].cnt -= I->second;
 						I = values.erase(I);
 						if (bye[j].cnt == 0) break;
 					}
 				}
 				j++;
 			}
 			if( k + 1 < events.size())
 			{
 				int gap = events[k+1] - cur;
 				long long sum = 0;
 				long long count = 0;
 				for(auto I = values.begin(); I != values.end(); ++I)
 				{
 					sum += ((-I->first) * (long long)I->second) % mod;
 					count += I->second;
 					const_cast<int &>(I->first) += gap;
 				}
 				sum %= mod;
 				count %= mod;
 				actual += sum * gap % mod - count * (gap * (long long)(gap-1) / 2 % mod) % mod;
 				actual %= mod;
 			}
 		}
 		long long ans = (original - actual) % mod;
 		ans = (ans%mod + mod) % mod;
 		printf("Case #%d: %d\n", testcase, (int)ans);
 	}
 	return 0;
 }