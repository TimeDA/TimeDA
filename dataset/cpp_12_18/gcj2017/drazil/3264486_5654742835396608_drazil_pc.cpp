#include <bits/stdc++.h>
 
 using namespace std;
 
 long long n, m;
 
 int main() {
 	int tc;
 	scanf("%d", &tc);
 	for (int t = 1; t <= tc; ++t) {
 		scanf("%lld%lld", &n, &m);
 		if (n == m) {
 			printf("Case #%d: 0 0\n", t);
 		} else {
 			map<long long, long long> arr;
 			arr[n] = 1;
 			--m;
 			while(m > 0) {
 				auto it = arr.rbegin();
 				//printf("=>%lld %lld\n", it->first, it->second);
 				if (it->second == 0) {
 					arr.erase(it->first);
 					continue;
 				}
 				long long rem = min(it->second, m);
 				//printf("rem %lld\n", rem);
 				m -= rem;
 				it->second -= rem;
 				if (it->first % 2 == 1) {
 					arr[it->first / 2] += rem * 2;
 				} else {
 					arr[it->first / 2] += rem;
 					arr[it->first / 2 - 1] += rem;
 				}
 			}
 			while (true) {
 				auto it = arr.rbegin();
 				if (it->second == 0) {
 					arr.erase(it->first);
 				} else {
 					break;
 				}
 			}
 			auto it = arr.rbegin();
 			long long a, b;
 			if (it->first % 2 == 1) a = b = it->first / 2;
 			else {
 				a = it->first / 2;
 				b = it->first / 2 - 1;
 			}
 			printf("Case #%d: %lld %lld\n", t, a, b);
 		}
 	}
 	return 0;
 }
 
