#include <vector>
 #include <map>
 #include <set>
 #include <iostream>
 #include <iomanip>
 #include <queue>
 #include <string>
 #include <stack>
 #include <list>
 #include <algorithm>
 #include <functional>
 #include <utility>
 #include <random>
 #include <cmath>
 #include <cstdio>
 using namespace std;
 
 int main(){
 	std::ios::sync_with_stdio(false);
 	int T; cin >> T;
 	for(int case_nb = 1; case_nb <= T; ++case_nb){
 		cout << "Case #" << case_nb << ": ";
 	   
 		string S;
 		int K;
 		cin >> S >> K;
 		int nb_flips = 0;
 		for(int i = 0; i <= S.length() - K; ++i){
 			if(S[i] == '-'){
 				++nb_flips;
 				for(int j = i; j < i + K; ++j){
 					S[j] = (S[j] == '-')?'+':'-';
 				}
 			}
 		}
 		bool all_good = true;
 		for(int i = 0; i < S.length(); ++i){
 			if(S[i] != '+')
 				all_good = false;
 		}
 		if(all_good){
 			cout << nb_flips;
 		}else{
 			cout << "IMPOSSIBLE";
 		}
 		cout << endl;
 	}
     return 0;
 }
