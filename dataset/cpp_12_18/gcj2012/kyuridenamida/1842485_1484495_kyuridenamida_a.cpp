#include <cstdio>
 #include <cstdlib>
 #include <cmath>
 #include <climits>
 #include <cfloat>
 #include <map>
 #include <utility>
 #include <set>
 #include <iostream>
 #include <memory>
 #include <string>
 #include <vector>
 #include <algorithm>
 #include <functional>
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
 typedef complex<double> P;
 
 
 int N,W,H;
 int r[10];
 
 
 void fix(vector<P> &g){
 	while(1){
 		bool f = true;
 			
 		for(int i = 0 ; i < g.size() ; i++)
 			for(int j = i+1 ; j < g.size() ; j++){
 				double A = abs(g[i]-g[j]);
 				if( A < r[i]+r[j]){
 					double d = r[i]+r[j] - abs(g[i]-g[j]);
 					d /= 2;
 					g[i] += (g[j]-g[i]) * (d / A);
 					g[j] += (g[i]-g[j]) * (d / A);
 					f = false;
 				}			
 			}
 		if(f) break;
 	}
 }
 
 vector<P> randomw(){
 	vector<P> w;
 	for(int i = 0 ; i < N ; i++) w.push_back(P(rand()%(W+1),rand()%(H+1)));
 	return w;
 }
 bool valid(vector<P> &g){
 	double x = 1e9 , X = -1e9;
 	double y = 1e9 , Y = -1e9;
 	for(int i = 0 ; i < g.size() ; i++){
 		x = min(x,g[i].real());
 		X = max(X,g[i].real());
 		y = min(y,g[i].imag());
 		Y = max(Y,g[i].imag());
 	}
 	for(int i = 0 ; i < g.size() ; i++)
 		g[i] -= P(x,y);
 	
 	return X-x <= W && Y-y <= H;
 }
 
 vector<P>  solve(){
 	cin >> N >> W >> H;
 	for(int i = 0 ; i < N ; i++){
 		cin >> r[i];
 	}
 	while(1){
 		vector<P> get = randomw();
 		fix(get);
 		if( valid(get) ){
 			
 			return get;
 		}
 	}
 }
 #include <ctime>
 int main(){
 	srand(time(NULL));
 	//ios_base::sync_with_stdio(false);
 	int T;
 	cin >> T;
 	for(int i = 1 ; i <= T ; i++){
 		vector<P> res = solve();
 		cout << "Case #" << i << ":";
 		for(int j = 0 ; j < res.size() ; j++){
 			printf(" %.10lf %.10lf",res[j].real(),res[j].imag());
 		}
 		cout << endl;
 	}
 }