#include <cstdio>
 #include <iostream>
 #include <vector>
 #include <list>
 #include <set>
 #include <map>
 #include <algorithm>
 #include <string>
 #include <sstream>
 #include <cmath>
 #include <stack>
 #include <queue>
 #include <functional>
 
 using namespace std;
 struct stop_amount{
 	stop_amount(int amount, int index){
 		this->amount = amount;
 		this->stop_index = index;
 	}
 	int amount;
 	int stop_index;
 	bool operator<(const stop_amount &s)const{
 		return stop_index < s.stop_index;
 	}
 };
 int N;
 #define MOD 1000002013
 long long calculate_price(long long distance){
 	return distance*(2*N-distance+1)/2;
 }
 long long calculate_price(int from, int to){
 	return calculate_price(to-from);
 }
 int main(){
 	int T;
 	scanf("%d", &T);
 	for(int curr_case = 1; curr_case <= T; ++curr_case){
 		int M;
 		scanf("%d%d", &N, &M);
 		vector<stop_amount> starts;
 		starts.reserve(M);
 		vector<stop_amount> exits;
 		exits.reserve(M);
 		long long actual_price = 0;
 		for(int i = 0; i< M; ++i){
 			int o, e, p;
 			scanf("%d%d%d", &o, &e, &p);
 			starts.push_back(stop_amount(p, o));
 			exits.push_back(stop_amount(p, e));
 			actual_price += p*calculate_price(o, e);
 			actual_price %= MOD;
 		}
 		sort(starts.begin(), starts.end());
 		sort(exits.begin(), exits.end());
 		stack<stop_amount> st;
 		int start_index = 0;
 		int exit_index = 0;
 		long long really_paid = 0;
 		while(start_index < M || exit_index < M){
 			if(start_index < M){
 				if(starts[start_index].stop_index <= exits[exit_index].stop_index){
 					st.push(starts[start_index]);
 					++start_index;
 					continue;
 				}
 			}
 			stop_amount s = exits[exit_index];
 			while(s.amount > 0){
 				if(st.top().amount <= s.amount){
 					really_paid += (st.top().amount*calculate_price(st.top().stop_index, s.stop_index));
 					really_paid %= MOD;
 					s.amount -= st.top().amount;
 					st.pop();
 				}else{
 					really_paid += s.amount*calculate_price(st.top().stop_index, s.stop_index);
 					really_paid %= MOD;
 					st.top().amount -= s.amount;
 					s.amount = 0;
 				}
 			}
 			++exit_index;
 		}
 		if(actual_price < really_paid)
 			actual_price += MOD;
 		printf("Case #%d: %lld\n", curr_case, actual_price-really_paid);
 	}
     return 0;
 }
