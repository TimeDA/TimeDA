#include <iostream>
 #include <vector>
 #include <cstdio>
 
 using namespace std;
 
 int main(){
 	int T; cin >> T;
 	for(int t=1;t<=T;t++){
 		int n; cin >> n;
 		vector<int> d(n);
 		int res = 0;
 		for(int i=0;i<n;i++){
 			cin >> d[i];
 			res = max(res, d[i]);
 		}
 		for(int i=1;i<=1000;i++){
 			int add = 0;
 			for(int j=0;j<n;j++){
 				add += (d[j]-1)/i;
 			}
 			res = min(res, i+add);
 		}
 		printf("Case #%d: %d\n", t, res);
 	}
 }
 
