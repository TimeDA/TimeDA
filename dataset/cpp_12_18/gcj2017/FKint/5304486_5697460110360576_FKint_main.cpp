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
 #include <numeric>
 #include <iterator>
 using namespace std;
 
 #define MAXR 1000000
 
 int main(){
 	std::ios::sync_with_stdio(false);
 	int nb_test_cases; cin >> nb_test_cases;
 	for(int test_case_id = 1; test_case_id <= nb_test_cases; ++test_case_id){
 		int N, P; cin >> N >> P;
 		vector<long long> requirements(N);
 		for(int i = 0; i < N; ++i){
 			cin >> requirements[i];
 		}
 		vector<vector<long long>> packages(N, vector<long long>(P));
 		for(int i = 0; i < N; ++i){
 			for(int j = 0; j < P; ++j){
 				cin >> packages[i][j];
 			}
 			sort(packages[i].begin(), packages[i].end());
 		}
 		vector<int> package_pointers(N, 0);
 		int nb_kits = 0;
 		for(int i = 1; i <= MAXR; ++i){
 			while(true){
 				bool possible = true;
 				for(int j = 0; j < N; ++j){
 					long long lower = 90 * requirements[j] * i;
 					long long upper = 110 * requirements[j] * i;
 					while(package_pointers[j] < P){
 						long long current_package_size = packages[j][package_pointers[j]] * 100;
 						if(current_package_size < lower){
 							++package_pointers[j];
 						}else{
 							break;
 						}
 					}
 					if(package_pointers[j] >= P){
 						possible = false;
 						break;
 					}
 					long long current_package_size = packages[j][package_pointers[j]] * 100;
 					if(current_package_size > upper){
 						possible = false;
 						break;
 					}
 				}
 				if(!possible)
 					break;
 				++nb_kits;
 				for(int j = 0; j < N; ++j){
 					++package_pointers[j];
 				}
 			}
 		}
 
 		cout << "Case #" << test_case_id << ": ";
 		cout << nb_kits;
 		cout << endl;
 	}
     return 0;
 }
