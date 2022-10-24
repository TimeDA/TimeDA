#include <bits/stdc++.h>
 using namespace std;
 #define int long long
 const int mod = 1000000000+7;
 const long double pi = 3.1415926535897932384626433832795028841971;
 
 
 double calc(double target,vector<double> X,double u){
 	for(int j = 0 ; j < X.size() ; j++){
 		double use = max(target-X[j],0.0);
 		u -= use;
 		X[j] += use;
 	}
 	return u;
 }
 
 signed main(){
 	int T;
 	cin >> T;
 	int t = 1;
 	while(T--){
 		int N,K;
 		cin >> N >> K;
 		double U;
 		cin >> U;
 		vector<double> P(N);
 		for(int i = 0 ; i < N ; i++) cin >> P[i];
 		double l = 0, r = 1.0;
 		for(int i = 0 ; i < 128 ; i++){
 			double m = (l+r) / 2;
 			if( calc(m,P,U) < 0 ){
 				r = m;
 			}else{
 				l = m;
 			}
 		}
 		double ans = 1.0;
 		for(int i = 0 ; i < N ; i++){
 			ans *= max(l,P[i]);
 		}
 		printf("Case #%lld: %.10lf\n",t++,ans);
 	}
 }
