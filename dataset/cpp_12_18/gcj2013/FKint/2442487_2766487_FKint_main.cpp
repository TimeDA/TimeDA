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
 long long power2(int p){
 	return ((long long)1) << p;
 }
 int log2(long long v){
 	if(v==0)
 		return 0;
 	if(v==1)
 		return 1;
 	int left = 0;
 	int right = 52;
 	while(left != right){
 		int mid = (left+right)/2;
 		long long res = power2(mid);
 		if(res < v){
 			left = mid+1;
 		}else{
 			right = mid;
 		}
 	}
 	return right;
 }
 int log2_b(long long v){
 	int left = 0;
 	int right = 52;
 	while(left != right){
 		int mid = right-(right-left)/2;
 		long long res = power2(mid);
 		if(res<=v){
 			left = mid;
 		}else{
 			right = mid-1;
 		}
 	}
 	return left;
 }
 
 long long get_certain_prize(long long N, long long P){
 	long long left = 0;
 	long long right = power2(N)-1;
 	while(left != right){
 		long long mid = right-(right-left)/2;
 		int one_amount = log2_b(mid+1);
 		long long worst_place = power2(one_amount)-1;
 		worst_place <<= (N-one_amount);
 		if(worst_place < P){
 			left = mid;
 		}else{
 			right = mid-1;
 		}
 	}
 	return left;
 }
 long long get_maybe_prize(long long N, long long P){
 	long long left = 0;
 	long long right = power2(N)-1;
 	while(left != right){
 		long long mid = left+(right-left)/2;
 		int zero_amount = log2_b(mid+1);
 		long long best_place = power2(N-zero_amount)-1;
 		if(best_place < P){
 			right = mid;
 		}else{
 			left = mid+1;
 		}
 	}
 	return power2(N)-1-left;
 }
 int main(){
 	int T;
 	scanf("%d", &T);
 	for(int curr_case = 1; curr_case <= T; ++curr_case){
 		long long N, P;
 		scanf("%lld%lld", &N, &P);
 		//certainly prize
 		long long certain = get_certain_prize(N, P);
 		//maybe prize
 		long long maybe = get_maybe_prize(N, P);
 		printf("Case #%d: %lld %lld\n", curr_case, certain, maybe);
 	}
     return 0;
 }
