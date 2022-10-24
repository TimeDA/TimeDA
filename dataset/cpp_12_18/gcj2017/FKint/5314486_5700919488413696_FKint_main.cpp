#include <bits/stdc++.h>
 using namespace std;
 
 
 
 int main(){
 	std::ios::sync_with_stdio(false);
 	int nb_test_cases; cin >> nb_test_cases;
 	for(int test_case_id = 1; test_case_id <= nb_test_cases; ++test_case_id){
 		int N; cin >> N;
 		int P; cin >> P;
 		map<int, int> groups;
 		for(int i = 0; i < N; ++i){
 			int t; cin >> t;
 			groups[t % P]++;
 		}
 		int result = groups[0];
 		if(P == 2){
 			result += (groups[1] + 1) / 2;
 		}else if(P == 3){
 			int combos = min(groups[1], groups[2]);
 			result += combos;
 			groups[1] -= combos;
 			groups[2] -= combos;
 			result += (groups[1] + groups[2] + 2) / 3;
 		}else{
 			int combos2 = groups[2] / 2;
 			result += combos2;
 			groups[2] -= combos2 * 2;
 			int combos3 = min(groups[1], groups[3]);
 			result += combos3;
 			groups[1] -= combos3;
 			groups[3] -= combos3;
 			if(groups[2] == 0){
 				result += (groups[1] + groups[3] + 3) / 4;
 			}else{
 				result += 1;
 				int rem3 = groups[1] + groups[3];
 				rem3 -= 2;
 				if(rem3 > 0){
 					result += (rem3 + 3) / 4;
 				}
 			}
 		}
 		cout << "Case #" << test_case_id << ": " ;
 		cout << result;
 		cout << endl;
 	}
     return 0;
 }
