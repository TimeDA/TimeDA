#include <iostream>
 #include <vector>
 #include <string>
 #include <algorithm>
 #include <cstring>
 #include <cstdio>
 #include <stack>
 #include <queue>
 #include <set>
 
 using namespace std;
 
 int getNodeNum(const vector<string>& vs){
 	set<string> S;
 	for(int i=0;i<vs.size();i++){
 		for(int j=1;j<=vs[i].size();j++){
 			S.insert(vs[i].substr(0, j));
 		}
 	}
 	return S.size();
 }
 
 int main(){
 	int T; cin >> T;
 	for(int test=1;test<=T;test++){
 		int N, M; cin >> N >> M;
 		int maxNode = 0;
 		int cnt = 0;
 		vector<string> vs(N);
 		for(int i=0;i<N;i++) cin >> vs[i];
 		for(int i=0;i<(1<<(2*N));i++){
 			vector< vector<string> > v(4);
 			for(int j=0;j<N;j++){
 				v[(i>>(2*j))%4].push_back(vs[j]);
 			}
 			bool valid = true;
 			int sum = 0;
 			for(int j=0;j<4;j++){
 				if(j < M){
 					if(v[j].empty()) valid = false;
 					else sum += getNodeNum(v[j]);
 				} else {
 					if(!v[j].empty()) valid = false;
 				}
 			}
 			if(!valid) continue;
 			if(sum == maxNode){
 				cnt++;
 			}
 			else if(sum > maxNode){
 				maxNode = sum;
 				cnt = 1;
 			}
 		}
 		printf("Case #%d: %d %d\n", test, maxNode+M, cnt);
 	}
 }
