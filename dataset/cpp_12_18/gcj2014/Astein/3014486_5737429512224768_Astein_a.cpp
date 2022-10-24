#include <vector>
 #include <algorithm>
 #include <cstdio>
 
 using namespace std;
 
 int main()
 {
 	int T;
 	scanf("%d", &T);
 	for (int cn = 1; cn <= T; ++cn)
 	{
 		int n, x;
 		scanf("%d%d", &n, &x);
 		vector<int> s(n);
 		for (int i = 0; i < n; ++i)
 			scanf("%d", &s[i]);
 		sort(s.begin(), s.end());
 		
 		int ret = 0;
 		int left = 0, right = s.size() - 1;
 		while (true) {
 			if (left > right) break;
 			if (left == right)
 			{
 				ret++;
 				break;
 			}
 			if (s[left] + s[right] <= x)
 			{
 				left++;
 				right--;
 				ret++;
 			}
 			else if (s[left] + s[right] > x)
 			{
 				right--;
 				ret++;
 			}
 		}
 		printf("Case #%d: %d\n", cn, ret);
 	}
 }
 
