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
 		string N; cin >> N;
 		while(true){
 			bool non_decreasing = true;
 			for(int i = 1; i < N.length(); ++i){
 				if(N[i] < N[i-1]){
 					--N[i-1];
 					for(int j = i; j < N.length(); ++j){
 						N[j] = '9';
 					}
 					non_decreasing = false;
 					break;
 				}
 			}
 			if(non_decreasing)
 				break;
 		}
 		cout << "Case #" << case_nb << ": ";
 		bool started = false;
 		for(int i = 0; i < N.length(); ++i){
 			if(N[i] != '0')
 				started = true;
 			if(started){
 				cout << N[i];
 			}
 		}
 		cout << endl;
 	}
     return 0;
 }
