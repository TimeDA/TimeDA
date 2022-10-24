#include <iostream>
 #include <vector>
 #include <string>
 #include <sstream>
 #include <algorithm>
 #include <cstring>
 #include <cstdio>
 #include <map>
 
 using namespace std;
 
 int main(){
 	int T; cin >> T;
 	for(int test=1;test<=T;test++){
 		int N; cin >> N;
 		string str;
 		getline(cin, str);
 		map<string, int> S;
 		int idx = 0;
 		vector< vector<int> > dic(N);
 		for(int i=0;i<N;i++){
 			 getline(cin, str);
 			 istringstream iss(str);
 			 string s;
 			 while(iss >> s){
 				 if(S.count(s)){
 					 dic[i].push_back(S[s]);
 				 } else {
 					 S[s] = idx;
 					 dic[i].push_back(idx);
 					 ++idx;
 				 }
 			 }
 		}
 		int res = 100000000;
 		for(int i=2;i<(1<<N);i+=4){
 			vector<int> mask(idx, 0);
 			for(int j=0;j<N;j++){
 				for(int k=0;k<dic[j].size();k++){
 					mask[dic[j][k]] |= (i&(1<<j)) ? 1 : 2;
 				}
 			}
 			int cnt = 0;
 			for(int j=0;j<mask.size();j++){
 				if(mask[j] == 3) cnt++;
 			}
 			res = min(res, cnt);
 		}
 		printf("Case #%d: %d\n", test, res);
 	}
 }
