#include <iostream>
 #include <string>
 #include <vector>
 #include <map>
 #include <algorithm>
 
 using namespace std;
 using ll = long long;
 
 int main(){
 	ios_base::sync_with_stdio(false);
 	int T;
 	cin >> T;
 	for(int case_num = 1; case_num <= T; ++case_num){
 		ll n, k;
 		cin >> n >> k;
 		map<ll, ll> segments;
 		segments.emplace(n, 1);
 		ll last = 0;
 		while(true){
 			const auto it = std::prev(segments.end());
 			const ll w = it->first;
 			const ll m = it->second;
 			if(k <= m){
 				last = w;
 				break;
 			}else{
 				segments.erase(it);
 				segments[w / 2] += m;
 				segments[(w - 1) / 2] += m;
 				k -= m;
 			}
 		}
 		const ll maxval = last / 2, minval = (last - 1) / 2;
 		cout << "Case #" << case_num << ": " << maxval << " " << minval << endl;
 	}
 	return 0;
 }
 
