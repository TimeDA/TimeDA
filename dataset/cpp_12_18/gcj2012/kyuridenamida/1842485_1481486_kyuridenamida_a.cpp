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
 
 
 int pos[10000] , len[10000];
 
 string solve(){
 	int n;
 	cin >> n;
 	for(int i = 0 ; i < n ; i++){
 		cin >> pos[i] >> len[i];
 	}
 	int D;
 	cin >> D;
 	if( pos[0] > len[0] ){
 		return "NO";
 	}
 	int memo[10010]={};
 	queue< pair<int,int> > Q;
 	Q.push(make_pair(pos[0],pos[0]));
 	map< pair<int,int> , bool > abnormal;
 	while( Q.size() ){
 		pair<int,int> q = Q.front(); Q.pop();
 		int current = q.first;
 		int move = q.second;
 		if( current+move >= D ) return "YES";
 		if( abnormal[make_pair(current,move)] ) continue;
 		else abnormal[make_pair(current,move)] = true;
 		
 		
 		for(int i = 0 ; i < n ; i++){
 			if( current <= pos[i] && pos[i] <= current + move ){
 				int canmove = min( pos[i] - current , len[i]);
 				int good = pos[i] + canmove;
 				Q.push(make_pair(pos[i],canmove));
 			}
 		}
 	}
 	
 	return "NO";
 }
 
 int main(){
 	ios_base::sync_with_stdio(false);
 	int T;
 	cin >> T;
 	for(int i = 1 ; i <= T ; i++){
 		cout << "Case #" << i << ": " << solve() << endl;
 	}
 }