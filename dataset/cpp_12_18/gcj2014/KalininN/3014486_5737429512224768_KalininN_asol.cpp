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
 
 const int maxn = 10004;
 
 int a[maxn];
 int n, X;
 
 int main()
 {
 	int NT = 0;
 	scanf("%d", &NT);
 	for (int T = 1; T <= NT; T++)
 	{
 		printf("Case #%d:", T);
 		
 		scanf("%d%d", &n, &X);
 		for (int i = 0; i < n; i++) scanf("%d", &a[i]);
 		sort(a, a + n);
 		int cur = 0;
 		for (int i = n - 1; i >= cur; i--)
 		{
 			if (cur < i && a[i] + a[cur] <= X) cur++;
 		}
 		printf(" %d\n", n - cur);
 		
 		fprintf(stderr, "%d/%d cases done!\n", T, NT);
 	}
 	return 0;
 }
