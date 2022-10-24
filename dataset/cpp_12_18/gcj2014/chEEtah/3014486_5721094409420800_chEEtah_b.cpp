#include <cstdio>
 #include <cstdlib>
 #include <cstring>
 #include <cctype>
 #include <cmath>
 #include <cassert>
 #include <sstream>
 #include <functional>
 #include <algorithm>
 #include <map>
 #include <string>
 #include <vector>
 #include <set>
 #include <queue>
 
 using namespace std;
 
 int nt;
 int a[1000];
 
 int invL[1000], invR[1000];
 
 int main()
 {
 	scanf("%d", &nt);
 	for(int tt = 1; tt <= nt; tt++)
 	{
 		fprintf(stderr, "test = %d\n", tt);
 		printf("Case #%d: ", tt);
 
 		int n;
 		scanf("%d", &n);
 		for(int i = 0; i < n; i++) scanf("%d", &a[i]);
 
 		/*int res = n * n;
 
 		for(int i = 0; i < n; i++)
 		{
 			invL[i] = 0;
 			for(int j = 0; j < i; j++) if (a[j] > a[i]) invL[i]++;
 			if (i) invL[i] += invL[i - 1];
 		}
 
 		for(int i = n - 1; i >= 0; i--)
 		{
 			invR[i] = 0;
 			for(int j = i + 1; j < n; j++) if (a[i] < a[j]) invR[i]++;
 			if (i != n - 1) invR[i] += invR[i + 1];
 		}
 
 		for(int i = 0; i < n; i++)
 		{
 			int cur = invL[i];
 			if (i != n - 1) cur += invR[i + 1];
 			res = min(res, cur);
 		}*/
 
 		int res = 0;
 		for(int i = 0; i < n; i++)
 		{
 			int L = 0, R = 0;
 			for(int j = 0; j < i; j++) if (a[j] > a[i]) L++;
 			for(int j = i + 1; j < n; j++) if (a[i] < a[j]) R++;
 			res += min(L, R);
 		}
 
 		printf("%d\n", res);
 	}
 	return 0;
 }
