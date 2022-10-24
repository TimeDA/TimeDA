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
 
 vector <ll> decr;
 vector <pair <ll, ll> > inc; // first, cycle
 priority_queue <pair <ll, ll> > q; // -t, group
 vector <pair <ll, int> > v; // 0: plus, 1: minus
 
 void add_people(ll D, ll M){
 	decr.push_back((360 - D) * M);
 	inc.push_back(make_pair((720 - D) * M, 360 * M));
 }
 
 void generate(int S){
 	int i;
 	
 	REP(i,inc.size()) q.push(make_pair(-inc[i].first, inc[i].second));
 	REP(i,S){
 		pair <ll, ll> p = q.top();
 		q.pop();
 		ll t = -p.first;
 		ll d = p.second;
 		q.push(make_pair(-(t+d), d));
 		v.push_back(make_pair(t, 0));
 	}
 	
 	REP(i,S) v.push_back(make_pair(decr[i], 1));
 	
 	sort(v.begin(),v.end());
 }
 
 void main2(void){
 	int N,i,j;
 	
 	decr.clear();
 	inc.clear();
 	while(!q.empty()) q.pop();
 	v.clear();
 	
 	int S = 0;
 	cin >> N;
 	REP(i,N){
 		ll D,H,M;
 		cin >> D >> H >> M;
 		REP(j,H) add_people(D, M+j);
 		S += H;
 	}
 	
 	generate(S);
 	
 	int ans = S, cur = S;
 	REP(i,v.size()){
 		if(v[i].second == 0) cur++; else cur--;
 		ans = min(ans, cur);
 	}
 	
 //	REP(i,v.size()) cout << v[i].first << ' ' << v[i].second << endl;
 	
 	cout << ans << endl;
 
 //	cout << decr[0] << ' ' << decr[1] << endl;
 //	REP(i,2) cout << inc[i].first << ' ' << inc[i].second << endl;
 	
 //	if(inc[1].first > decr[0] && inc[0].first > decr[1]) cout << 0 << endl; else cout << 1 << endl;
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
