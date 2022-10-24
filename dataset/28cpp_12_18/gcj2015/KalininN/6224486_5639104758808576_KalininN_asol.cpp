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
 
 char s[maxn];
 int n;
 
 int main()
 {
     int NT = 0;
     scanf("%d", &NT);
     for (int T = 1; T <= NT; T++)
     {
         printf("Case #%d: ", T);
         
 		scanf("%d%s", &n, s);
 		n++;
 		int sum = 0;
 		int answer = 0;
 		for (int i = 0; i < n; i++)
 		{
 			answer = max(answer, i - sum);
 			sum += s[i] -'0';
 		}
 		
 		printf("%d\n", answer);
 
         fprintf(stderr, "%d/%d cases done!\n", T, NT);
     }
     return 0;
 }
