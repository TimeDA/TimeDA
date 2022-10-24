#include <cstring>
 #include <algorithm>
 #include <cstdlib>
 #include <vector>
 #include <map>
 #include <tuple>
 
 using namespace std;
 
 char str[21000];
 char s[21000], n;
 
 int main() {
     
     int tc;
     scanf("%d", &tc);
     for (int t = 1; t <= tc; t++) {
         scanf("%s", str);
         n = 0;
         int ans = 0;
         for (int i = 0; str[i] != '\0'; i++) {
             if (n > 0 && s[n - 1] == str[i]) {
                 ans += 10;
                 n--;
             } else {
                 s[n++] = str[i];
             }
         }
         printf("Case #%d: %d\n", t, ans + n / 2 * 5);
     }
     
     return 0;
 }
 
