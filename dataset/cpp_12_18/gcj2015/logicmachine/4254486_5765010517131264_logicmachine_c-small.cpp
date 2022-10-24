#include <iostream>
 #include <iomanip>
 #include <string>
 #include <vector>
 #include <algorithm>
 #include <utility>
 #include <cstdlib>
 
 using namespace std;
 typedef pair<double, int> pdi;
 const double INF = 1e200;
 
 double solve(
 	int d, double y, double c, double t, int remains,
 	const vector<double> &p, const vector<double> &s)
 {
 	const int n = p.size();
 	if(remains == (1 << n) - 1){ return t; }
 	double answer = INF;
 	if(d < 0){
 		// left 
 		vector<pdi> qs;
 		for(int i = 0; i < n; ++i){
 			if(remains & (1 << i)){ continue; }
 			if(p[i] > 0.0){ continue; }
 			const double b = p[i] - s[i] * t;
 			qs.push_back(pdi((c - b) / (y - s[i]), i));
 		}
 		sort(qs.begin(), qs.end());
 		for(const auto &q : qs){
 			remains |= (1 << q.second);
 			answer = min(answer, solve(
 				1 - d, y, c - y * q.first, t + q.first, remains, p, s));
 		}
 	}else{
 		// right
 		vector<pdi> qs;
 		for(int i = 0; i < n; ++i){
 			if(remains & (1 << i)){ continue; }
 			if(p[i] < 0.0){ continue; }
 			const double b = p[i] + s[i] * t;
 			qs.push_back(pdi((c - b) / (s[i] - y), i));
 		}
 		sort(qs.begin(), qs.end());
 		for(const auto &q : qs){
 			remains |= (1 << q.second);
 			answer = min(answer, solve(
 				-1 - d, y, c + y * q.first, t + q.first, remains, p, s));
 		}
 	}
 	return answer;
 }
 
 int main(){
 	ios_base::sync_with_stdio(false);
 	cout << setiosflags(ios::fixed) << setprecision(10);
 	int T;
 	cin >> T;
 	for(int case_num = 1; case_num <= T; ++case_num){
 		int y, n;
 		cin >> y >> n;
 		vector<double> p(n), s(n);
 		for(int i = 0; i < n; ++i){ cin >> p[i]; }
 		for(int i = 0; i < n; ++i){ cin >> s[i]; }
 		const double answer = min(
 			solve(-1, y, 0, 0, 0, p, s), solve(1, y, 0, 0, 0, p, s));
 		cout << "Case #" << case_num << ": " << answer << endl;
 	}
 	return 0;
 }
 
