#include <iostream>
 #include <string>
 #include <cstdio>
 
 using namespace std;
 
 int solve(string s, int K){
 	int res = 0;
 	int n = s.size();
 	for(int i=0;i+K<=n;i++){
 		if(s[i] == '+') continue;
 		++res;
 		for(int j=0;j<K;j++) s[i+j] = ('+'+'-'-s[i+j]);
 	}
 	for(int i=0;i<n;i++){
 		if(s[i] == '-') return -1;
 	}
 	return res;
 }
 
 int main(){
 	int T; cin >> T;
 	for(int t=1;t<=T;t++){
 		string s; int K;
 		cin >> s >> K;
 		int res = solve(s, K);
 		printf("Case #%d: ", t);
 		if(res == -1){
 			printf("IMPOSSIBLE\n");
 		} else {
 			printf("%d\n", res);
 		}
 	}
 }
 
