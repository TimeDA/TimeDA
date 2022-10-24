#include <iostream>
 #include <vector>
 #include <map>
 #include <queue>
 #include <algorithm>
 
 using namespace std;
 typedef long long ll;
 typedef pair<ll, ll> pll;
 const int MOD = 1000002013;
 
 ll calc(ll N, ll len){
 	return ((len * N) - (len * (len + 1)) / 2) % MOD;
 }
 
 int main(){
 	ios_base::sync_with_stdio(false);
 	int T;
 	cin >> T;
 	for(int caseNum = 1; caseNum <= T; ++caseNum){
 		ll N, M;
 		cin >> N >> M;
 		ll expected = 0;
 		map<ll, ll> mp;
 		for(int i = 0; i < M; ++i){
 			ll o, e, p;
 			cin >> o >> e >> p;
 			expected = (expected + p * calc(N, e - o)) % MOD;
 			mp[o] += p;
 			mp[e] -= p;
 		}
 		priority_queue< pll, vector<pll>, less<pll> > pq;
 		ll actual = 0;
 		for(map<ll, ll>::iterator it = mp.begin(); it != mp.end(); ++it){
 			ll s = it->first, p = it->second;
 			if(p < 0){
 				p = -p;
 				while(p > 0){
 					pll e = pq.top();
 					pq.pop();
 					if(p >= e.second){
 						actual = (actual + e.second * calc(N, s - e.first)) % MOD;
 						p -= e.second;
 					}else{
 						actual = (actual + p * calc(N, s - e.first)) % MOD;
 						e.second -= p;
 						pq.push(e);
 						p = 0;
 					}
 				}
 			}else if(p > 0){
 				pq.push(pll(s, p));
 			}
 		}
 		ll answer = (expected - actual + MOD) % MOD;
 		cout << "Case #" << caseNum << ": " << answer << endl;
 	}
 	return 0;
 }
 
