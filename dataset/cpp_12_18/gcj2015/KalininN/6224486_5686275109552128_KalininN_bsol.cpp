#include <iostream>
 #include <algorithm>
 #include <cmath>
 #include <cstring>
 #include <cstdlib>
 #include <string>
 #include <vector>
 #include <cstdio>
 #include <cassert>
 #include <queue>
 
 using namespace std;
 
 typedef long long ll;
 typedef long double ld;
 
 #ifdef WIN32
 	#define LLD "%I64d"
 #else
 	#define LLD "%lld"
 #endif
 
 const int maxn = 1005;
 const int MAX = 1005;
 
 int x[maxn];
 int n;
 
 int main()
 {
     int NT = 0;
     scanf("%d", &NT);
     for (int T = 1; T <= NT; T++)
     {
         printf("Case #%d: ", T);
 
 		scanf("%d", &n);
 		for (int i = 0; i < n; i++)
 		{
 			scanf("%d", &x[i]);
 		}
 		int answer = MAX;
 		for (int i = 1; i <= MAX; i++)
 		{
 			int kv = 0;
 			for (int j = 0; j < n; j++) kv += (x[j] - 1) / i;
 			answer = min(answer, kv + i);
 		}
 		printf("%d\n", answer);
 
         fprintf(stderr, "%d/%d cases done!\n", T, NT);
     }
     return 0;
 }
