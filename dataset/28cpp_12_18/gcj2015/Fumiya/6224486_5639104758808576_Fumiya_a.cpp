#include <iostream>
 #include <string>
 #include <cstdio>
 
 using namespace std;
 
 int main(){
 	int T; cin >> T;
 	for(int t=1;t<=T;t++){
 		int Smax;
 		string s;
 		cin >> Smax >> s;
 		int sum = 0;
 		int res = 0;
 		for(int i=0;i<s.size();i++){
 			if(sum < i){
 				res += i-sum;
 				sum += i-sum;
 			}
 			sum += s[i]-'0';
 		}
 		printf("Case #%d: %d\n", t, res);
 	}
 }
