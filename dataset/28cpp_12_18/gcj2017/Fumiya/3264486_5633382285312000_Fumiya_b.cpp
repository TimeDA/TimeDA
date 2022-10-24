#include <iostream>
 #include <vector>
 #include <cstdio>
 
 using namespace std;
 
 int main(){
 	int T; cin >> T;
 	vector<long long> p1(19);
 	p1[0] = 1;
 	for(int i=1;i<p1.size();i++) p1[i] = 10 * p1[i-1] + 1;
 	for(int t=1;t<=T;t++){
 		long long N; cin >> N;
 		int cnt = 0;
 		long long res = 0;
 		for(int i=18;i>=0;i--){
 			while(res + p1[i] <= N && cnt < 9){
 				res += p1[i];
 				++cnt;
 			}
 		}
 		printf("Case #%d: %lld\n", t, res);
 	}
 }
