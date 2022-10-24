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
 
 int main()
 {
     int NT = 0;
     scanf("%d", &NT);
     for (int T = 1; T <= NT; T++)
     {
         printf("Case #%d: ", T);
         
 		int x, r, c;
 		scanf("%d%d%d", &x, &r, &c);
 		if (r < c) swap(r, c);
 		bool can = false;
 		if (x == 1) can = true;
 		if (x == 2) can = (r * c) % x == 0;
 		if (x == 3) can = (r * c) % x == 0 && r >= 2 && c >= 2;
 		if (x == 4) can = (r * c) % x == 0 && r == 4 && c >= 3;
 		printf("%s\n", (can ? "GABRIEL" : "RICHARD"));
 		
         fprintf(stderr, "%d/%d cases done!\n", T, NT);
     }
     return 0;
 }
