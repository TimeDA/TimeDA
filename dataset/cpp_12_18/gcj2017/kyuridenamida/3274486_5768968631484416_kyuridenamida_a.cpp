#include <bits/stdc++.h>
 using namespace std;
 #define int long long
 const int mod = 1000000000+7;
 const long double pi = 3.1415926535897932384626433832795028841971;
 
 void put_case(){
 	static int t = 1;
 	cout << "Case #" << t++ << ": ";
 }
 
 signed main(){
 	int T;
 	cin >> T;
 	while(T--){
 		int K,N;
 		cin >> N >> K;
 		vector< pair<int,int> > v;
 		for(int i = 0 ; i < N ; i++){
 			int a,b;
 			cin >> a >> b;
 			v.push_back({b,a});
 		}
 
 		long double ans = 0;
 		for(int i = 0 ; i < N ; i++){
 			long double anss = v[i].second * v[i].second * pi + 2.0 * v[i].second * pi * v[i].first;
 			auto w = v;
 			w.erase(w.begin()+i);
 			sort(w.rbegin(),w.rend(),[&](pair<int,int> a,pair<int,int> b){
 				return a.first * a.second < b.first * b.second; 
 			});
 			int k = K-1;
 			for(int j = 0 ; j < w.size() ; j++){
 				if( k <= 0 ) break;
 				if( w[j].second > v[i].second ){
 					continue;
 				}
 				anss += 2.0 * w[j].second * pi * w[j].first;
 				k--;
 			}
 			if( k == 0 ){
 				ans = max(anss,ans);
 			}
 		}
 		put_case();
 		printf("%.10Lf\n",ans);
 	}
 }
