#include <iostream>
 #include <vector>
 #include <string>
 #include <algorithm>
 #include <cstring>
 #include <cstdio>
 #include <stack>
 #include <queue>
 
 using namespace std;
 
 int main(){
 	int T; cin >> T;
 	for(int test=1;test<=T;test++){
 		int N, X; cin >> N >> X;
 		vector<int> S(N);
 		for(int i=0;i<N;i++) cin >> S[i];
 		sort(S.rbegin(), S.rend());
 		vector<int> used(N, 0);
 		int res = 0;
 		for(int i=0;i<N;i++){
 			if(used[i]) continue;
 			used[i] = 1;
 			for(int j=i+1;j<N;j++){
 				if(used[j]) continue;
 				if(S[i]+S[j] <= X){
 					used[j] = 1;
 					break;
 				}
 			}
 			res++;
 		}
 		printf("Case #%d: %d\n", test, res);
 	}
 }
