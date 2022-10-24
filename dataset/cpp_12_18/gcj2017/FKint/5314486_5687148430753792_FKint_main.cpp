#include <bits/stdc++.h>
 using namespace std;
 
 
 
 int main(){
 	std::ios::sync_with_stdio(false);
 	int nb_test_cases; cin >> nb_test_cases;
 	for(int test_case_id = 1; test_case_id <= nb_test_cases; ++test_case_id){
 		int N; cin >> N;
 		int C; cin >> C;
 		int M; cin >> M;
 		map<int, vector<int> > tickets_per_buyer;
 		map<int, int> buyers_per_seat;
 		for(int i = 0; i < M; ++i){
 			int p, b;
 			cin >> p >> b;
 			tickets_per_buyer[b].push_back(p);
 			buyers_per_seat[p]++;
 		}
 
 		int lower_bound = 0;
 		for(const auto& v : tickets_per_buyer){
 			lower_bound = max(lower_bound, (int)v.second.size());
 		}
 
 		map<int, int> cumsum;
 		cumsum[0] = 0;
 		for(int i = 1; i <= N; ++i){
 			cumsum[i] = cumsum[i-1] + buyers_per_seat[i];
 			lower_bound = max(lower_bound, (cumsum[i] + i - 1) / i);
 		}
 		int nb_promotions = 0;
 		for(int i = 1; i <= N; ++i){
 			if(buyers_per_seat[i] > lower_bound){
 				nb_promotions += buyers_per_seat[i] - lower_bound;
 			}
 		}
 
 		cout << "Case #" << test_case_id << ": " ;
 		cout << lower_bound << " " << nb_promotions;
 		cout << endl;
 	}
     return 0;
 }
