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
 
 char s[10000];
 pair<int, char> a[3];
 
 int main()
 {
 	int nt;
 	scanf("%d", &nt);
 	for(int tt = 1; tt <= nt; tt++)
 	{
 		fprintf(stderr, "test = %d\n", tt);
 		printf("Case #%d: ", tt);
 
         int N, R, O, Y, G, B, V;
         scanf("%d %d %d %d %d %d %d", &N, &R, &O, &Y, &G, &B, &V);
 
         B -= O; N -= 2 * O;
         R -= G; N -= 2 * G;
         Y -= V; N -= 2 * V;
 
         a[0] = make_pair(B, 'B');
         a[1] = make_pair(R, 'R');
         a[2] = make_pair(Y, 'Y');
         sort(a, a + 3);
 
         if (B < 0 || R < 0 || Y < 0 || a[2].first > N / 2) { puts("IMPOSSIBLE"); continue; }
 
         int pos = 0;
         for(int i = 2; i >= 0; i--)
         {
             for(int j = 0; j < a[i].first; j++)
             {
                 s[pos] = a[i].second;
                 if (s[pos] == 'B' && O > 0) { s[pos] = 'O'; O--; }
                 if (s[pos] == 'R' && G > 0) { s[pos] = 'G'; G--; }
                 if (s[pos] == 'Y' && V > 0) { s[pos] = 'V'; V--; }
                 pos += 2;
                 if (pos >= N) pos = 1;
             }
         }
         for(int i = 0; i < N; i++)
             if (s[i] == 'O') printf("BOB");
             else
             if (s[i] == 'G') printf("RGR");
             else
             if (s[i] == 'V') printf("YVY");
             else putchar(s[i]);
 
         puts("");
 	}
 	return 0;
 }
