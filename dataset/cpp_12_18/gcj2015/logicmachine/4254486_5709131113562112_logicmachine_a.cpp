#include <iostream>
 #include <iomanip>
 #include <string>
 #include <vector>
 #include <queue>
 #include <algorithm>
 #include <utility>
 
 using namespace std;
 typedef long long ll;
 typedef pair<int, int> pii;
 
 int main(){
 	ios_base::sync_with_stdio(false);
 	cout << setiosflags(ios::fixed) << setprecision(10);
 	int T;
 	cin >> T;
 	for(int case_num = 1; case_num <= T; ++case_num){
 		int n, d;
 		cin >> n >> d;
 		vector<int> s(n), parent(n);
 		int as, cs, rs, am, cm, rm;
 		cin >> s[0] >> as >> cs >> rs;
 		cin >> parent[0] >> am >> cm >> rm;
 		for(int i = 1; i < n; ++i){
 			s[i] = (static_cast<ll>(s[i - 1]) * as + cs) % rs;
 			parent[i] = (static_cast<ll>(parent[i - 1]) * am + cm) % rm;
 		}
 		for(int i = 1 ; i < n; ++i){ parent[i] %= i; }
 		vector<int> ss = s;
 		sort(ss.begin(), ss.end());
 		ss.erase(unique(ss.begin(), ss.end()), ss.end());
 		const int m = ss.size();
 		vector<int> ancestor_min(n, s[0]);
 		vector<int> ancestor_max(n, s[0]);
 		for(int i = 1; i < n; ++i){
 			const int p = parent[i];
 			ancestor_min[i] = min(ancestor_min[p], s[i]);
 			ancestor_max[i] = max(ancestor_max[p], s[i]);
 		}
 		priority_queue<pii, vector<pii>, greater<pii>> hi_pq;
 		for(int i = 0; i < n; ++i){
 			hi_pq.push(pii(ancestor_max[i], ancestor_min[i]));
 		}
 		priority_queue<int, vector<int>, greater<int>> lo_pq;
 		int answer = 1;
 		for(int i = 0; i < m; ++i){
 			const int lo = ss[i], hi = ss[i] + d + 1;
 			const int j = lower_bound(ss.begin(), ss.end(), hi) - ss.begin();
 			while(!hi_pq.empty()){
 				if(hi_pq.top().first >= hi){ break; }
 				lo_pq.push(hi_pq.top().second);
 				hi_pq.pop();
 			}
 			while(!lo_pq.empty()){
 				if(lo_pq.top() >= lo){ break; }
 				lo_pq.pop();
 			}
 			if(s[0] < lo || hi <= s[0]){ continue; }
 			answer = max<int>(answer, lo_pq.size());
 		}
 		cout << "Case #" << case_num << ": " << answer << endl;
 	}
 	return 0;
 }
 
