#include <vector>
 #include <list>
 #include <map>
 #include <set>
 #include <deque>
 #include <queue>
 #include <stack>
 #include <bitset>
 #include <algorithm>
 #include <functional>
 #include <numeric>
 #include <utility>
 #include <sstream>
 #include <iostream>
 #include <iomanip>
 #include <string>
 #include <complex>
 #include <cstdio>
 #include <cmath>
 #include <cstdlib>
 #include <cctype>
 #include <cstring>
 #include <climits>
 #include <ctime>
 
 #include<unordered_map>
 #include<unordered_set>
 using namespace std;
 
 int main(int __an, char **__ag)
 {	
 	int Case, cases = 0;
 	scanf("%d" , &Case);
 	while (Case--)	
 	{
 		long long n, k; scanf("%lld%lld" , &n, &k);
 		long long cur = 1;
 		map<long long, long long>  cnt;
 		++cnt[n];
 
 		while (cur < k)
 		{
 			map<long long, long long>  next;
 			for (auto iter = cnt.begin(); iter != cnt.end(); ++iter)
 			{
 				int f = iter->first/2;
 				next[f] += iter->second;
 				if (iter->first%2 == 0)
 					--f;
 				next[f] += iter->second;
 			}
 			cnt = next;
 			k-=cur;
 			cur*=2;
 		}
 		
 		printf("Case #%d: " , ++cases);
 		//cur -= (cur/2);
 		long long ans = 0;
 		for (auto iter = cnt.rbegin(); iter != cnt.rend(); ++iter)
 		{
 			if (iter->second < k)
 				k -= iter->second;
 			else
 			{
 				ans = iter->first; break;
 			}
 		}
 		if (ans == 0) ans = 1;
 		printf("%lld %lld\n" , ans/2, (ans/2) -(ans%2?0:1) );
 
 	}
 
 	return 0;
 }
 
