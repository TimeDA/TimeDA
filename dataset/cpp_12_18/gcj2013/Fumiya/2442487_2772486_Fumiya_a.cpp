#include <iostream>
 #include <vector>
 #include <algorithm>
 #include <map>
 #include <cstdio>
 
 using namespace std;
 
 const int MOD = 1000002013;
 
 int main(){
 	int T; cin >> T;
 	int N, M;
 	for(int test=1;test<=T;test++){
 		cin >> N >> M;
 		map< int, pair<long long, long long> > mp;
 		long long origSum = 0;
 		for(int i=0;i<M;i++){
 			int o, e, p;
 			cin >> o >> e >> p;
 			int cost = ((2LL*N-(e-o)+1)*(e-o)/2)%MOD;
 			origSum += (p*cost)%MOD;
 			origSum %= MOD;
 			if(mp.count(o)) mp[o].first += p;
 			else            mp[o] = make_pair(p, 0);
 			if(mp.count(e)) mp[e].second += p;
 			else            mp[e] = make_pair(0, p);
 		}
 		long long decSum = 0;
 		int prev = -1;
 		vector< pair<long long, long long> > vp;
 		for(map< int, pair<long long, long long> >::iterator it=mp.begin();it!=mp.end();it++){
 			int idx = it->first;
 			for(int i=0;i<vp.size();i++){
 				int cost = ((2LL*vp[i].first-(idx-prev)+1)*(idx-prev)/2)%MOD;
 				decSum += (vp[i].second*cost)%MOD;
 				decSum %= MOD;
 				vp[i].first -= (idx-prev);
 			}
 			if(it->second.first > 0){
 				vp.push_back(make_pair(N, it->second.first));
 				sort(vp.rbegin(), vp.rend());
 			}
 			int exitNum = it->second.second;
 			for(int i=0;i<vp.size();i++){
 				if(exitNum == 0) break;
 				if(vp[i].second < exitNum){
 					exitNum -= vp[i].second;
 					vp[i].second = 0;
 				} else {
 					vp[i].second -= exitNum;
 					exitNum = 0;
 				}
 			}
 			prev = idx;
 		}
 		int res = (origSum-decSum+MOD)%MOD;
 		printf("Case #%d: %d\n", test, res);
 	}
 }
