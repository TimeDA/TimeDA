#include <cstdio>
 #include <cstdlib>
 #include <cmath>
 #include <climits>
 #include <cfloat>
 #include <map>
 #include <utility>
 #include <ctime>
 #include <set>
 #include <iostream>
 #include <memory>
 #include <string>
 #include <cstring>
 #include <vector>
 #include <algorithm>
 #include <functional>
 #include <fstream>
 #include <sstream>
 #include <complex>
 #include <stack>
 #include <queue>
 #include <cstring>
 #include <numeric>
 #include <cassert>
 using namespace std;
 static const double EPS = 1e-10;
 typedef long long ll;
 #define rep(i,n) for(int i=0;i<n;i++)
 #define rev(i,n) for(int i=n-1;i>=0;i--)
 #define all(a) a.begin(),a.end()
 #define mp(a,b) make_pair(a,b)
 #define pb(a) push_back(a)
 #define SS stringstream
 #define DBG1(a) rep(_X,sz(a)){printf("%d ",a[_X]);}puts("");
 #define DBG2(a) rep(_X,sz(a)){rep(_Y,sz(a[_X]))printf("%d ",a[_X][_Y]);puts("");}
 #define bitcount(b) __builtin_popcount(b)
 #define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
 
 #define delete(a,n) a.erase(remove(all(a),n),a.end())
 template<typename T, typename S> vector<T>& operator<<(vector<T>& a, S b) { a.push_back(b); return a; }
 template<typename T> void operator>>(vector<T>& a, int b) {while(b--)if(!a.empty())a.pop_back();}
 bool isprime(int n){ if(n<2)return false;  for(int i=2;i*i<=n;i++)if(n%i==0)return false;  return true;} 
 ll b_pow(ll x,ll n){return n ? b_pow(x*x,n/2)*(n%2?x:1) : 1ll;}
 string itos(int n){stringstream ss;ss << n;return ss.str();}
 
 void putCase(){
 	static int x = 1;
 	cout << "Case #" << x++ << ": ";
 }
 #define MOD (1000002013ll)
 
 long long N,M;
 long long cost(long long x){
 	return ((N*x%MOD-x*(x-1)/2%MOD)%MOD+MOD)%MOD;
 }
 
 
 int main(){
 	int T;
 	cin >> T;
 	while(T--){
 		cin >> N >> M;
 		long long sum = 0;
 		vector<long long> P(M),O(M),E(M);
 		rep(i,M){
 			cin >> O[i] >> E[i] >> P[i];
 			//cout <<O[i] << " " << E[i] << " " <<  cost(E[i]-O[i]) << endl;
 			sum += cost(E[i]-O[i])*P[i]%MOD;
 			sum %= MOD;
 		}
 		while(1){
 			rep(i,M){
 				rep(j,M){
 					if( O[i] < O[i+1] ){
 						swap(O[i],O[j]);
 						swap(E[i],P[j]);
 						swap(P[i],P[j]);
 						
 					}
 				}
 			}
 			int flag = 0;
 			rep(i,P.size()){
 				if( P[i] == 0 ) continue;
 				rep(j,P.size()){
 					if( P[j] == 0 ) continue;
 					if( !(E[j] < O[i] || E[i] < O[j]) ){
 						if( cost(E[i]-O[i])+cost(E[j]-O[j]) > cost(E[j]-O[i]) + cost(E[i]-O[j]) ){
 							int r = min(P[i],P[j]);
 							P[i] -= r;
 							P[j] -= r;
 							P.push_back(r);
 							O.push_back(O[j]);
 							E.push_back(E[i]);
 							P.push_back(r);
 							O.push_back(O[i]);
 							E.push_back(E[j]);
 							flag = 1;
 						}
 					}
 				}
 			}
 			for(int i = 0 ; i < P.size() ; i++){
 				if( P[i] == 0 ){
 					swap(P[i],P.back());
 					swap(O[i],O.back());
 					swap(E[i],E.back());
 					P.pop_back();
 					O.pop_back();
 					E.pop_back();
 				}
 			}
 			if(!flag) break;
 		}
 		rep(i,P.size()){
 			sum -= cost(E[i]-O[i])*P[i]%MOD;
 			sum %= MOD;
 		}
 		sum += MOD;
 		sum %= MOD;
 		putCase();
 		cout << sum << endl;
 		
 	}
 }