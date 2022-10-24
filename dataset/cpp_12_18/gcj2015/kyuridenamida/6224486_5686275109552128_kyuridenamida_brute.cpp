#include <bits/stdc++.h>
 using namespace std;
 
 
 map< vector<int> , int> memo;
 int dfs(vector<int> p){
 	if( memo.count(p) ) return memo[p];
 	p[0] = 0;
 	if( count(p.begin(),p.end(),0) == p.size() ) return 0;
 	int answer = 1e9;
 	vector<int> t = p;
 	for(int i = 0 ; i+1 < p.size() ; i++){
 		t[i] = t[i+1];
 	}
 	t[p.size()-1] = 0;
 	answer = min(answer,dfs(t)+1);
 	for(int i = 1 ; i < p.size() ; i++){
 		if( p[i] ){
 			for(int j = 1 ; j < i ; j++){
 				vector<int> t2 = p;
 				t2[i]--;
 				t2[j]++;
 				t2[i-j]++;
 				
 				answer = min(answer,dfs(t2)+1);
 			}
 		}
 	}
 	return memo[p] = answer;
 }
 int main(){
 	int T;
 	int t=0;
 	cin >> T;
 	while(T--){
 		t++;
 		int n;
 		cin >> n;
 		vector<int> p(10);
 		for(int i = 0 ; i < n ; i++){
 			int t;
 			cin >> t;
 			p[t]++;
 		}
 		int answer = dfs(p);
 		cout << "Case #" << t << ": " << answer << endl;
 		ex:;
 	}
 }