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
 
 int kv[20];
 
 int main()
 {
 	int NT = 0;
 	scanf("%d", &NT);
 	for (int T = 1; T <= NT; T++)
 	{
 		printf("Case #%d:", T);
 		for (int i = 1; i <= 16; i++) kv[i] = 0;
 		int A;
 		scanf("%d", &A);
 		for (int i = 0; i < 4; i++)
 		{
 			for (int j = 0; j < 4; j++)
 			{
 				int a;
 				scanf("%d", &a);
 				if (i + 1 == A) kv[a]++;
 			}
 		}
 		scanf("%d", &A);
 		for (int i = 0; i < 4; i++)
 		{
 			for (int j = 0; j < 4; j++)
 			{
 				int a;
 				scanf("%d", &a);
 				if (i + 1 == A) kv[a]++;
 			}
 		}
 		int ans = -1;
 		for (int i = 1; i <= 16; i++) if (kv[i] == 2)
 		{
 			if (ans == -1) ans = i;
 			else ans = -2;
 		}
 		if (ans == -2) printf(" Bad magician!\n");
 		else if (ans == -1) printf(" Volunteer cheated!\n");
 		else printf(" %d\n", ans);
 		fprintf(stderr, "%d/%d cases done!\n", T, NT);
 	}
 	return 0;
 }
