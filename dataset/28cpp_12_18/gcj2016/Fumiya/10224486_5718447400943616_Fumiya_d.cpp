#include <iostream>
 #include <vector>
 #include <string>
 #include <algorithm>
 #include <cstring>
 #include <cstdio>
 
 using namespace std;
 
 int root[100];
 int getRoot(int v){ return root[v] == -1 ? v : root[v] = getRoot(root[v]); }
 
 bool check(const vector<string>& vs, int cur, int work){
 	if(cur == vs.size()) return true;
 	int n = vs.size();
 	bool ok = true;
 	bool sel = false;
 	for(int i=0;i<n;i++){
 		if(work&(1<<i)) continue;
 		if(vs[cur][i] == '0') continue;
 		sel = true;
 		ok &= check(vs, cur+1, work|(1<<i));
 	}
 	return sel && ok;
 }
 
 bool valid(const vector<string>& vs){
 	vector<string> w = vs;
 	sort(w.begin(), w.end());
 	do {
 		if(!check(w, 0, 0)) return false;
 	} while (next_permutation(w.begin(), w.end()));
 	return true;
 }
 
 int main(){
 	int T; cin >> T;
 	for(int t=1;t<=T;t++){
 		int N; cin >> N;
 		vector<string> vs(N);
 		for(int i=0;i<N;i++){
 			cin >> vs[i];
 		}
 		vector<string> test(N, string(N, '.'));
 		int res = N*N;
 		for(int i=0;i<(1<<(N*N));i++){
 			for(int j=0;j<N;j++){
 				for(int k=0;k<N;k++){
 					test[j][k] = ((i&(1<<(j*N+k))) ? '1' : '0');
 				}
 			}
 			bool ok = true;
 			for(int j=0;j<N;j++){
 				for(int k=0;k<N;k++) if(vs[j][k] == '1' && test[j][k] == '0') ok = false;
 			}
 			if(!ok) continue;
 			if(!valid(test)) continue;
 			int cnt = 0;
 			for(int j=0;j<N;j++){
 				for(int k=0;k<N;k++){
 					if(vs[j][k] == '0' && test[j][k] == '1') cnt++;
 				}
 			}
 			res = min(res, cnt);
 		}
 		printf("Case #%d: %d\n", t, res);
 	}
 }
