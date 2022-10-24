#include <iostream>
 #include <vector>
 #include <string>
 #include <algorithm>
 #include <cstring>
 #include <map>
 #include <cstdio>
 
 using namespace std;
 
 int N;
 int G[100];
 int H[100];
 int P;
 int Q;
 map< vector<int>, int > mp;
 
 int solveSmall(int turn){
 	vector<int> key(N+1); key[N] = turn;
 	for(int i=0;i<N;i++) key[i] = max(0, H[i]);
 	if(mp.count(key)) return mp[key];
 	int res = 0;
 	bool end = true;
 	for(int i=0;i<N;i++){
 		if(H[i] > 0) end = false;
 	}
 	if(end) return mp[key] = 0;
 	if(turn == 0){
 		res = max(res, solveSmall(1));
 		for(int i=0;i<N;i++){
 			if(H[i] > 0){
 				H[i] -= P;
 				res = max(res, (H[i] <= 0 ? G[i] : 0)+solveSmall(1));
 				H[i] += P;
 			}
 		}
 	} else {
 		for(int i=0;i<N;i++){
 			if(H[i] > 0){
 				H[i] -= Q;
 				res = max(res, solveSmall(0));
 				H[i] += Q;
 				break;
 			}
 		}
 	}
 	return mp[key] = res;
 }
 
 int main(){
 	int T; cin >> T;
 	for(int test=1;test<=T;test++){
 		cin >> P >> Q >> N;
 		for(int i=0;i<N;i++) cin >> H[i] >> G[i];
 		mp.clear();
 		printf("Case #%d: %d\n", test, solveSmall(0));
 	}
 }
