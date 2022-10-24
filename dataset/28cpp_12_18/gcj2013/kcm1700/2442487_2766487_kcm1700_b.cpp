#include <stdio.h>
 #include <algorithm>
 #include <vector>
 #include <set>
 #include <map>
 
 using namespace std;
 
 int main()
 {
 	int T;
 	scanf("%d",&T);
 	for(int testcase = 1; testcase <= T; testcase++)
 	{
 		int n;
 		long long p;
 		scanf("%d%lld",&n,&p);
 
 		long long ans1, ans2;
 		{
 			ans1 = 1;
 			if (p == (1ull << n))
 			{
 				ans1 = (1ull << n) - 1;
 			}
 			else{
 				for(int i = n - 1; i >= 0; i--)
 				{
 					if ((p-1) & (1ull << i)) {
 						ans1 <<= 1;
 						ans1 |= 1;
 					} else {
 						break;
 					}
 				}
 				ans1--;
 			}
 		}
 		{
 			int cnt = 0;
 			ans2 = 0;
 			for(int i = n; i >= 0; i--)
 			{
 				cnt++;
 				if (p & (1ull << i)) {
 					break;
 				}
 			}
 			for(int i = 0; i < n+1-cnt; i++)
 			{
 				ans2 |= (1ull << (n-i-1));
 			}
 		}
 
 		printf("Case #%d: %lld %lld\n",testcase, ans1, ans2);
 	}
 	return 0;
 }