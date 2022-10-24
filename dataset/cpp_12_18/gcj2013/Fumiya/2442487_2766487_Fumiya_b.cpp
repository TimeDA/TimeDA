#include <iostream>
 #include <vector>
 #include <cstdio>
 #include <algorithm>
 
 using namespace std;
 
 long long solveWin(int N, long long P){
 	long long L = 0, R = 1LL<<N;
 	while(R-L>1){
 		long long mid = (L+R)/2;
 		long long win = mid;
 		long long rank = 0;
 		for(int i=N-1;i>=0;i--){
 			if(win > 0){
 				rank += (1LL<<i);
 				win = (win-1)/2;
 			} else {
 				break;
 			}
 		}
 		if(rank < P) L = mid;
 		else         R = mid;
 	}
 	return L;
 }
 
 long long solveLose(int N, long long P){
 	long long L = 0, R = 1LL<<N;
 	while(R-L>1){
 		long long mid = (L+R)/2;
 		long long lose = (1LL<<N)-mid-1;
 		long long rank = 0;
 		for(int i=N-1;i>=0;i--){
 			if(lose > 0){
 				lose = (lose-1)/2;
 			} else {
 				rank = (1LL<<(i+1))-1;
 				break;
 			}
 		}
 		if(rank < P) L = mid;
 		else         R = mid;
 	}
 	return L;
 }
 
 int main(){
 	int T; cin >> T;
 	int N; long long P;
 	for(int test=1;test<=T;test++){
 		cin >> N >> P;
 		printf("Case #%d: %lld %lld\n", test, solveWin(N, P), solveLose(N, P));
 	}
 }