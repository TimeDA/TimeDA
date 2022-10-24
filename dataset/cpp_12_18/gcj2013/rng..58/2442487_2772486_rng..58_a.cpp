#include <iostream>
 #include <sstream>
 #include <fstream>
 #include <string>
 #include <vector>
 #include <deque>
 #include <queue>
 #include <stack>
 #include <set>
 #include <map>
 #include <algorithm>
 #include <functional>
 #include <utility>
 #include <bitset>
 #include <cmath>
 #include <cstdlib>
 #include <ctime>
 #include <cstdio>
 
 using namespace std;
 
 #define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
 #define snuke(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
 
 typedef long long ll;
 #define MOD 1000002013ll
 
 int N,M;
 int a[1010],b[1010]; // <= 1000
 ll p[1010]; // <= 10^9
 vector <pair <pair <int, int>, ll> > v; // coord, type (0:enter 1:leave), p
 vector <pair <int, ll> > freq; // coord, p
 
 ll tri(ll d){
 	return (d * (d-1) / 2) % MOD;
 }
 
 void main2(void){
 	int i,j,x;
 	
 	cin >> N >> M;
 	REP(i,M) cin >> a[i] >> b[i] >> p[i];
 	
 	ll small = 0;
 	REP(i,M) small = (small + tri(b[i]-a[i]) * p[i]) % MOD;
 	
 	ll big = 0;
 	
 	v.clear();
 	REP(i,M) v.push_back(make_pair(make_pair(a[i], 0), p[i]));
 	REP(i,M) v.push_back(make_pair(make_pair(b[i], 1), p[i]));
 	sort(v.begin(),v.end());
 	
 	freq.clear();
 	REP(i,v.size()){
 		int x = v[i].first.first, type = v[i].first.second;
 		ll p = v[i].second;
 		
 		if(type == 0){
 			freq.push_back(make_pair(x, p));
 		} else {
 			for(j=freq.size()-1;j>=0;j--){
 				ll tmp = min(p, freq[j].second);
 				freq[j].second -= tmp;
 				p -= tmp;
 				big = (big + tri(x-freq[j].first) * tmp) % MOD;
 			}
 		}
 	}
 	
 	ll ans = (big - small + MOD) % MOD;
 	cout << ans << endl;
 }
 
 int main(void){
 	int TC,tc;
 	cin >> TC;
 	REP(tc,TC){
 		printf("Case #%d: ", tc+1);
 		main2();
 	}
 	return 0;
 }
