#include <iostream>
 #include <algorithm>
 #include <cmath>
 #include <cstring>
 #include <cstdlib>
 #include <string>
 #include <vector>
 #include <cstdio>
 #include <cassert>
 
 using namespace std;
 
 typedef long long ll;
 typedef long double ld;
 
 #ifdef WIN32
 #define LLD "%I64d"
 #else
 #define LLD "%lld"
 #endif
 
 const int maxn = 1005;
 
 int a[maxn], b[maxn];
 int n;
 
 int main()
 {
 	int NT = 0;
 	scanf("%d", &NT);
 	for (int T = 1; T <= NT; T++)
 	{
 		printf("Case #%d:", T);
 		
 		scanf("%d", &n);
 		for (int i = 0; i < n; i++)
 		{
 			scanf("%d", &a[i]);
 			b[i] = a[i];
 		}
 		sort(b, b + n);
 		int left = 0;
 		int right = n - 1;
 		int answer = 0;
 		for (int i = 0; i < n; i++)
 		{
 			int cur = -1;
 			for (int j = left; j <= right; j++) if (a[j] == b[i]) cur = j;
 			assert(cur != -1);
 // 			cout << b[i] << ' ' << a[cur] << endl;
 // 			cout << i << ' ' << cur << ' ' << left << ' ' << right << endl;
 			if (cur - left < right - cur)
 			{
 				answer += cur - left;
 				rotate(a + left, a + cur, a + cur + 1);
 				left++;
 			} else
 			{
 				answer += right - cur;
 				rotate(a + cur, a + cur + 1, a + right + 1);
 				right--;
 			}
 		}
 		printf(" %d\n", answer);
 		fprintf(stderr, "%d/%d cases done!\n", T, NT);
 	}
 	return 0;
 }
