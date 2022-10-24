#include <iostream>
 #include <vector>
 #include <queue>
 #include <algorithm>
 #include <utility>
 
 using namespace std;
 
 int main(){
 	ios_base::sync_with_stdio(false);
 	int T;
 	cin >> T;
 	for(int caseNum = 1; caseNum <= T; ++caseNum){
 		int N;
 		cin >> N;
 		vector<int> A(N), B(N);
 		for(int i = 0; i < N; ++i){ cin >> A[i]; }
 		for(int i = 0; i < N; ++i){ cin >> B[i]; }
 		vector< vector<int> > conn(N);
 		vector<int> incr_map(N + 1, -1);
 		incr_map[1] = 0;
 		for(int i = 1; i < N; ++i){
 			if(incr_map[A[i]] >= 0){
 				conn[incr_map[A[i]]].push_back(i);
 			}
 			if(A[i] > 1){
 				conn[i].push_back(incr_map[A[i] - 1]);
 			}
 			incr_map[A[i]] = i;
 		}
 		vector<int> decr_map(N + 1, -1);
 		decr_map[1] = N - 1;
 		for(int i = N - 2; i >= 0; --i){
 			if(decr_map[B[i]] >= 0){
 				conn[decr_map[B[i]]].push_back(i);
 			}
 			if(B[i] > 1){
 				conn[i].push_back(decr_map[B[i] - 1]);
 			}
 			decr_map[B[i]] = i;
 		}
 		vector<int> in_degrees(N);
 		for(int i = 0; i < N; ++i){
 			for(int j = 0; j < conn[i].size(); ++j){
 				++in_degrees[conn[i][j]];
 			}
 		}
 		vector<int> sorted;
 		priority_queue<int> pq;
 		for(int i = 0; i < N; ++i){
 			if(in_degrees[i] == 0){ pq.push(i); }
 		}
 		while(!pq.empty()){
 			int n = pq.top();
 			pq.pop();
 			sorted.push_back(n);
 			for(int i = 0; i < conn[n].size(); ++i){
 				if(--in_degrees[conn[n][i]] == 0){ pq.push(conn[n][i]); }
 			}
 		}
 		vector<int> answer(N);
 		for(int i = 0; i < sorted.size(); ++i){
 			answer[sorted[i]] = N - i;
 		}
 		cout << "Case #" << caseNum << ":";
 		for(int i = 0; i < N; ++i){ cout << " " << answer[i]; }
 		cout << endl;
 	}
 	return 0;
 }
 
