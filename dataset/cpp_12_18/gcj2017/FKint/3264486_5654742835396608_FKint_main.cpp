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
 		unsigned long long N, K;
 		cin >> N >> K;
 
 		map<unsigned long long, unsigned long long> nb_gaps;
 		priority_queue<unsigned long long> biggest_gaps;
 		biggest_gaps.push(N);
 		nb_gaps[N] = 1;
 
 		unsigned long long last_gap_size = N;
 		while(true){
 			unsigned long long gap_size = biggest_gaps.top();
 			biggest_gaps.pop();
 			unsigned long long gap_count = nb_gaps[gap_size];
 			//cerr << "Gap size: " << gap_size << " (amount: " << gap_count << ")" << endl;
 			last_gap_size = gap_size;
 			if(K <= gap_count){
 				break;
 			}
 			K -= gap_count;
 			unsigned long long left_gap_size = (gap_size - 1)/2;
 			unsigned long long right_gap_size = gap_size - 1 - left_gap_size;
 			if(!nb_gaps.count(left_gap_size)){
 				biggest_gaps.push(left_gap_size);
 			}
 			nb_gaps[left_gap_size] += gap_count;
 			if(!nb_gaps.count(right_gap_size)){
 				biggest_gaps.push(right_gap_size);
 			}
 			nb_gaps[right_gap_size] += gap_count;
 		}
 
 		cout << "Case #" << case_nb << ": ";
 		unsigned long long min_dist = (last_gap_size - 1) / 2;
 		unsigned long long max_dist = (last_gap_size - 1) - min_dist;
 		cout << max_dist << " " << min_dist;
 		cout << endl;
 	}
     return 0;
 }
