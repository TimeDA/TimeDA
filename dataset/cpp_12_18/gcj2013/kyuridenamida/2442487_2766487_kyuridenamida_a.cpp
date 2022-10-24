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
 static const long double EPS = 1e-20;
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
 
 int N;
 int NN;
 int P;
 int wins[1024] = {};
 
 void doit(vector<int> v){
 	vector< pair<int, pair<int,int> > > r;
 	for(int i = 0 ; i < NN ; i++){
 		r.push_back(make_pair(0,mp(i,v[i])));
 	}
 	for(int i = 0 ; i < N ; i++){
 		vector< pair<int, pair<int,int> > > w;
 		for(int j = 0 ; j < NN ; j+=(1<<(i+1))){
 			for(int k = 0 ; k < (1<<(i+1)) ; k+=2){
 				int l1 = (r[j+k].second.second>r[j+k+1].second.second);
 				int l2 = (r[j+k].second.second<r[j+k+1].second.second);
 				//cout << r[j+k].second.second << "(" << l1 << ")" << " vs " << r[j+k+1].second.second << "(" << l2 << ")" << endl;
 				w.push_back(make_pair(r[j+k].first*2+l1,make_pair(r[j+k].second.first,r[j+k].second.second)));
 				w.push_back(make_pair(r[j+k+1].first*2+l2,make_pair(r[j+k+1].second.first,r[j+k+1].second.second)));
 			}
 		}
 		r = w;
 		sort(r.begin(),r.end());
 		//rep(j,NN)
 		//	cout << j << "th" << " " << r[j].second.second << "(" << r[j].first << ")" << endl;
 	}
 	for(int i = 0 ; i < NN ; i++){
 		
 		//cout << i << "th" << " " << r[i].second.second << "(" << r[i].first << ")" << endl;
 		if( i < P ){
 			wins[r[i].second.second]++;
 		}
 	}
 }
 
 int worstCase(int x){
 	vector<int> v;
 	v.push_back(x);
 	for(int i = NN - 1 ; i >= 0 ; i--){
 		if( x != i ) v.push_back(i);
 	}
 	doit(v);
 }
 
 int goodCase(int x){
 	vector<int> v;
 	for(int i = 0 ; i < NN ; i++){
 		v.push_back((x-i+NN)%NN);
 	}
 	doit(v);
 }
 int main(){
 	int T;
 	cin >> T;
 	while(T--){
 		memset(wins,0,sizeof(wins));
 		cin >> N >> P;
 		NN = 1<<N;
 		vector<int> p;
 		for(int i = 0 ; i < NN ; i++){
 			p.push_back(i);
 		}
 		int fc = 0;
 		for(int i = 0 ; i < NN ; i++){
 			worstCase(i);
 			goodCase(i);
 			fc += 2;
 		}
 		int zettaiwin = -1; 
 		int maybewin = -1;
 		for(int i = 0 ; i < NN ; i++){
 			//cout << wins[i] << " " << endl;
 			if( fc == wins[i] ) zettaiwin = max(i,zettaiwin);
 			if( wins[i] ) maybewin = max(i,maybewin);
 		}
 		putCase();
 		
 		cout << zettaiwin << " " << maybewin << endl;
 		
 	}
 }