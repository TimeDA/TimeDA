#include <iostream>
 #include <vector>
 #include <string>
 #include <algorithm>
 #include <cmath>
 #include <cstring>
 #include <cstdio>
 
 using namespace std;
 
 const double eps = 1e-12;
 
 void solveSmall(int test, double V, double X, vector< pair<long double, long double> >& W){
 	if(W.size() == 1){
 		if(abs(W[0].first - X) < eps){
 			printf("Case #%d: %.10Lf\n", test, V/W[0].second);
 		} else {
 			printf("Case #%d: IMPOSSIBLE\n", test);
 		}
 	} else {
 		if(abs(W[0].first - W[1].first) < eps){
 			if(abs(W[0].first - X) < eps){
 				printf("Case #%d: %.10Lf\n", test, V/(W[0].second+W[1].second));
 			} else {
 				printf("Case #%d: IMPOSSIBLE\n", test);
 			}
 		} else {
 			long double V1 = V*(X-W[1].first)/(W[0].first - W[1].first);
 			long double V2 = V-V1;
 			if(V1 < -eps || V2 < -eps){
 				printf("Case #%d: IMPOSSIBLE\n", test);
 			} else {
 				printf("Case #%d: %.10Lf\n", test, max(V1/W[0].second, V2/W[1].second));
 			}
 		}
 	}
 }
 
 int main(){
 	int T; cin >> T;
 	for(int test=1;test<=T;test++){
 		int N; cin >> N;
 		double V, X; cin >> V >> X;
 		vector< pair<long double, long double> > W(N);
 		long double minC = 1e12, maxC = 0.0;
 		for(int i=0;i<N;i++){
 			cin >> W[i].second >> W[i].first;
 			minC = min(minC, W[i].first);
 			maxC = max(maxC, W[i].first);
 		}
 		sort(W.begin(), W.end());
 		solveSmall(test, V, X, W);
 		/*
 		for(int i=0;i<W.size();i++){
 			while(true){
 				if(i+1 == W.size()) break;
 				if(abs(W[i].second
 			}
 		}
 		*/
 		/*
 		if(W.back().first < X-eps || X+eps < W[0].first){
 			printf("Case #%d: IMPOSSIBLE\n", test);
 			continue;
 		}
 		long double low = 0, high = 1e8;
 		for(int _=0;_<1000;_++){
 			long double mid = 0.5*(low+high);
 			long double minT = 0, maxT = 0;
 			long double rest = V;
 			for(int i=0;i<W.size();i++){
 				long double add = min(rest, W[i].second * mid);
 				minT += add * W[i].first;
 				rest -= add;
 			}
 			if(rest > 0){
 				low = mid;
 				continue;
 			}
 			rest = V;
 			for(int i=W.size()-1;i>=0;i--){
 				long double add = min(rest, W[i].second * mid);
 				maxT += add * W[i].first;
 				rest -= add;
 			}
 			if(minT-eps <= V*X && V*X <= maxT+eps){
 				high = mid;
 			} else {
 				low = mid;
 			}
 		}
 		printf("Case #%d: %.10Lf\n", test, 0.5*(low+high));
 		*/
 	}
 }
