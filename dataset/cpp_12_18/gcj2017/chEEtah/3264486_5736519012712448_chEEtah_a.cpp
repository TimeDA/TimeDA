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
 
 void flip(char &c)
 {
     if (c == '+') c = '-'; else c = '+';
 }
 
 int main()
 {
 	int nt;
 	scanf("%d", &nt);
 	for(int tt = 1; tt <= nt; tt++)
 	{
 		fprintf(stderr, "test = %d\n", tt);
 		printf("Case #%d: ", tt);
 
         char s[1001];
 		int n, K;
 		scanf("%s %d", s, &K);
         n = strlen(s);
 
 		int res = 0;
 
         for(int i = 0; i < n; i++)
         if (s[i] == '-')
         {
             res++;
             if (i + K > n) { res = -1; break; }
             for(int j = 0; j < K; j++) flip(s[i + j]);
         }
 
 		if (res == -1) puts("IMPOSSIBLE"); else printf("%d\n", res);
 	}
 	return 0;
 }
