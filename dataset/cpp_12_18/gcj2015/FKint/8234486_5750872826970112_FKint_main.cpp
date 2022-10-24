#include <bits/stdc++.h>
 #include <cstdio>
 using namespace std;
 #define EPS .000001
 
 bool equal(double a, double b){
 	return abs(a-b) < EPS;
 }
 
 int main(){
 	std::ios::sync_with_stdio(false);
 	int nb_test_cases;
 	cin >> nb_test_cases;
 	for(int current_test_case = 1; current_test_case <= nb_test_cases; ++ current_test_case){
 		//ONLY SMALL TEST CASE
 		double X, V;
 		int n;
 		cin >> n;
 		cin >> V >> X;
 		vector<pair<double, double> > sources;
 		for(int i = 0; i < n; ++i){
 			double rate, temperature;
 			cin >> rate >> temperature;
 			sources.push_back(make_pair(rate, temperature));
 		}
 
 		cout << "Case #" << current_test_case << ": ";
 		cout.precision(15);
 		cout << fixed;
 		if(n == 1){
 			if(equal(sources[0].second, X)){
 				cout << V / sources[0].first;
 			}else{
 				cout << "IMPOSSIBLE";
 			}
 		}else if(n == 2){
 			if(equal(sources[0].second, X) && equal(sources[1].second, X)){
 				cout << V / (sources[0].first + sources[1].first);
 			}else if(equal(sources[0].second, X)){
 				cout << V / sources[0].first;
 			}else if(equal(sources[1].second, X)){
 				cout << V / sources[1].first;
 			}else if(equal(sources[1].second, sources[0].second) || (sources[1].second-X)*(sources[0].second-X) > 0){
 				cout << "IMPOSSIBLE";
 			}else{
 				double t1 = (X*V - V*sources[1].second) / (sources[0].first * (sources[0].second - sources[1].second));
 				double t2 = (V - t1 * sources[0].first) / sources[1].first;
 				cout << max(t1, t2);
 			}
 		}else{
 			cout << "NOT SMALL";
 		}
 		cout << endl;
 	}
     return 0;
 }
