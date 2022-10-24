#include <iostream>
 #include <string>
 #include <vector>
 #include <algorithm>
 #include <utility>
 
 using namespace std;
 typedef pair<int, int> pii;
 
 pii recur(int depth, int n, vector<int> &mapping, const vector<string> &s){
 	const int m = mapping.size();
 	if(depth == m){
 		int occur = 0;
 		for(int i = 0; i < m; ++i){ occur |= (1 << mapping[i]); }
 		if(occur != (1 << n) - 1){ return pii(0, 0); }
 		vector<int> prev(n, -1);
 		int answer = 0;
 		for(int i = 0; i < m; ++i){
 			const int t = mapping[i];
 			if(prev[t] < 0){
 				answer += s[i].size();
 			}else{
 				const string &ps = s[prev[t]];
 				int len = 0;
 				for(; len < s[i].size() && len < ps.size(); ++len){
 					if(s[i][len] != ps[len]){ break; }
 				}
 				answer += s[i].size() - len;
 			}
 			prev[t] = i;
 		}
 		return pii(answer + n, 1);
 	}
 	pii answer(0, 0);
 	for(int i = 0; i < n; ++i){
 		mapping[depth] = i;
 		const pii p = recur(depth + 1, n, mapping, s);
 		if(p.first > answer.first){
 			answer = p;
 		}else if(p.first == answer.first){
 			answer.second += p.second;
 		}
 	}
 	return answer;
 }
 
 int main(){
 	ios_base::sync_with_stdio(false);
 	int T;
 	cin >> T;
 	for(int caseNum = 1; caseNum <= T; ++caseNum){
 		int n, m;
 		cin >> m >> n;
 		vector<string> s(m);
 		for(int i = 0; i < m; ++i){ cin >> s[i]; }
 		sort(s.begin(), s.end());
 		vector<int> work(m);
 		const pii p = recur(0, n, work, s);
 		cout << "Case #" << caseNum << ": " << p.first << " " << p.second << endl;
 	}
 	return 0;
 }
 
