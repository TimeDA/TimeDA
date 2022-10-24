#include <iostream>
 #include <iomanip>
 #include <string>
 #include <vector>
 #include <algorithm>
 #include <utility>
 
 using namespace std;
 typedef pair<long double, long double> pdd;
 static const long double EPS_MULT = 1.0 + 1e-10;
 
 int main(){
 	ios_base::sync_with_stdio(false);
 	cout << setiosflags(ios::fixed) << setprecision(10);
 	int T;
 	cin >> T;
 	for(int case_num = 1; case_num <= T; ++case_num){
 		int n;
 		long double v, x;
 		cin >> n >> v >> x;
 		vector<pdd> s(n);
 		for(int i = 0; i < n; ++i){
 			cin >> s[i].second >> s[i].first;
 		}
 		sort(s.begin(), s.end());
 		if(s[0].first > x || s.back().first < x){
 			cout << "Case #" << case_num << ": IMPOSSIBLE" << std::endl;
 			continue;
 		}
 		long double sum = 0.0, temp = 0.0;
 		for(int i = 0; i < n; ++i){
 			sum += s[i].second;
 			temp += s[i].first * s[i].second;
 		}
 		temp /= sum;
 		if(temp < x / EPS_MULT){
 			for(int i = 0; i < n; ++i){
 				const long double tsum = sum - s[i].second;
 				const long double ttemp =
 					(temp * sum - s[i].first * s[i].second) / tsum;
 				if(ttemp < x / EPS_MULT){
 					sum = tsum;
 					temp = ttemp;
 				}else{
 					long double l = 0.0, r = s[i].second;
 					for(int iter = 0; iter < 500; ++iter){
 						const long double c = (l + r) * 0.5;
 						const long double ssum = sum - c;
 						const long double stemp =
 							(temp * sum - s[i].first * c) / ssum;
 						if(stemp < x){
 							l = c;
 						}else{
 							r = c;
 						}
 					}
 					sum -= l;
 					break;
 				}
 			}
 		}else if(temp > x * EPS_MULT){
 			for(int i = n - 1; i >= 0; --i){
 				const long double tsum = sum - s[i].second;
 				const long double ttemp =
 					(temp * sum - s[i].first * s[i].second) / tsum;
 				if(ttemp > x * EPS_MULT){
 					sum = tsum;
 					temp = ttemp;
 				}else{
 					long double l = 0.0, r = s[i].second;
 					for(int iter = 0; iter < 500; ++iter){
 						const long double c = (l + r) * 0.5;
 						const long double ssum = sum - c;
 						const long double stemp =
 							(temp * sum - s[i].first * c) / ssum;
 						if(stemp > x){
 							l = c;
 						}else{
 							r = c;
 						}
 					}
 					sum -= l;
 					break;
 				}
 			}
 		}
 		cout << "Case #" << case_num << ": " << v / sum << std::endl;
 	}
 	return 0;
 }
 
