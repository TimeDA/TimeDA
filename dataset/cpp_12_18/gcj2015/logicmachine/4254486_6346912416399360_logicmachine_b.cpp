#include <iostream>
 #include <iomanip>
 #include <string>
 #include <vector>
 #include <algorithm>
 #include <utility>
 
 using namespace std;
 typedef pair<int, int> pii;
 
 int main(){
 	ios_base::sync_with_stdio(false);
 	cout << setiosflags(ios::fixed) << setprecision(10);
 	int T;
 	cin >> T;
 	for(int case_num = 1; case_num <= T; ++case_num){
 		int n, k;
 		cin >> n >> k;
 		vector<int> s(n - k + 1);
 		for(int i = 0; i < n - k + 1; ++i){ cin >> s[i]; }
 		vector<pii> ranges(k);
 		for(int i = 0; i < k; ++i){
 			int diff_lo = 0, diff_hi = 0, diff = 0;
 			for(int j = i; j + k < n; j += k){
 				diff += s[j + 1] - s[j];
 				diff_lo = min(diff_lo, diff);
 				diff_hi = max(diff_hi, diff);
 			}
 			ranges[i] = pii(-diff_lo, diff_hi - diff_lo);
 		}
 		sort(ranges.begin(), ranges.end(), [](const pii &a, const pii &b) -> bool {
 			return a.second < b.second;
 		});
 		int base_sum = 0, answer = ranges.back().second;
 		for(int i = 0; i < k; ++i){ base_sum += ranges[i].first; }
 		const int limit = ranges.back().second;
 		int remains = ((s[0] - base_sum) + 1000000000ll * k) % k;
 		for(int i = 0; i < k; ++i){
 			const int d = limit - ranges[i].second;
 			if(d >= remains){
 				remains = 0;
 				break;
 			}else{
 				remains -= d;
 			}
 		}
 		if(remains > 0){ ++answer; }
 		cout << "Case #" << case_num << ": " << answer << endl;
 	}
 	return 0;
 }
 
