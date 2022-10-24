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
 
 int K[1000], S[1000];
 
 int main()
 {
 	int nt;
 	scanf("%d", &nt);
 	for(int tt = 1; tt <= nt; tt++)
 	{
 		fprintf(stderr, "test = %d\n", tt);
 		printf("Case #%d: ", tt);
 
 		int D, N;
 		scanf("%d %d", &D, &N);
         for(int i = 0; i < N; i++) scanf("%d %d", &K[i], &S[i]);
 
         long double res = -1;
         for(int j = 0; j < N; j++)
         {
             long double cur = (long double)D * S[j] / (D - K[j]);
             if (res == -1 || res > cur) res = cur;
         }
         printf("%.8Lf\n", res);
 	}
 	return 0;
 }
