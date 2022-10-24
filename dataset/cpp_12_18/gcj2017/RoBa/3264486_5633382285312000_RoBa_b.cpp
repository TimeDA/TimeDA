#include <cstdio>
 #include <cstring>
 
 char buf[32];
 char ans[32];
 
 int main() {
     int T;
     scanf("%d",&T);
     for (int ca = 1 ; ca <= T ; ++ca) {
         scanf("%s", buf);
         int len = strlen(buf);
         memset(ans, 0, sizeof(ans));
         for (int i = 0 ; i < len ; ++i) {
             // try min fill
             ans[i] = buf[i];
             for (int j = i + 1 ; j < len ; ++j)
                 ans[j] = ans[i];
             if (strcmp(ans, buf) <= 0) continue;
             ans[i] = buf[i]-1;
             for (int j = i + 1 ; j < len ; ++j)
                 ans[j] = '9';
             break;
         }
         printf("Case #%d: ", ca);
         if (ans[0] == '0') printf("%s\n", ans+1);
         else printf("%s\n", ans);
     }
     return 0;
 }
