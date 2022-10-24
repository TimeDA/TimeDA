#include <iostream>
 #include <cstdio>
 
 using namespace std;
 
 long long getMin(long long v){
 	return (v-1)/2;
 }
 
 long long getMax(long long v){
 	return v - getMin(v) - 1;
 }
 
 int main(){
 	int T; cin >> T;
 	for(int t=1;t<=T;t++){
 		long long N, K; cin >> N >> K;
 		long long n = N, p0 = 1, p1 = 0;
 		printf("Case #%d:", t);
 		while(K > 0){
 			if(p1 >= K){
 				printf(" %lld %lld\n", getMax(n+1), getMin(n+1));
 				break;
 			}
 			K -= p1;
 			if(p0 >= K){
 				printf(" %lld %lld\n", getMax(n), getMin(n));
 				break;
 			}
 			K -= p0;
 			if(n%2 == 1){
 				p0 = 2*p0 + p1;
 			} else {
 				p1 = p0 + 2*p1;
 			}
 			n = (n-1)/2;
 		}
 	}
 }
 
