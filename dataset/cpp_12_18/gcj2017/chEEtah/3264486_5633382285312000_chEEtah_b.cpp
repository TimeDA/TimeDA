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
 char s[1000];
 
 int main()
 {
 	int nt;
 	scanf("%d", &nt);
 	for(int tt = 1; tt <= nt; tt++)
 	{
 		fprintf(stderr, "test = %d\n", tt);
 		printf("Case #%d: ", tt);
 
         scanf("%s", s);
         bool tidy = true;
         for(int i = 1; s[i]; i++) if (s[i - 1] > s[i]) tidy = false;
 
         if (tidy)
         {
             puts(s);
             continue;
         }
 
         int pos = -1;
         if (s[0] > '1') pos = 0;
         for(int i = 1; s[i]; i++)
         {
             if (s[i - 1] > s[i]) break;
             if (s[i - 1] < s[i]) pos = i;
         }
 
         if (pos == -1)
         {
             for(int i = 1; s[i]; i++) printf("9");
             puts("");
             continue;
         }
         for(int i = 0; i < pos; i++) printf("%c", s[i]);
         printf("%c", s[pos] - 1);
         for(int i = pos + 1; s[i]; i++) printf("9");
         puts("");
 	}
 	return 0;
 }
