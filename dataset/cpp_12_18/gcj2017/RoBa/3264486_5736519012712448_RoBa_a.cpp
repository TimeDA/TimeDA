#include <cstdio>
 #include <cstring>
 
 const int MAXN = 1010;
 char buf[MAXN];
 
 int main() {
     int T, k;
     scanf("%d",&T);
     for (int ca = 1 ; ca <= T ; ++ca) {
         scanf("%s%d",buf,&k);
         int len = strlen(buf);
         int cnt = 0;
         for (int i = 0 ; i + k <= len ; ++i) {
             if (buf[i] == '-') {
                 ++cnt;
                 for (int j = i ; j < i + k ; ++j)
                     if (buf[j] == '-') buf[j] = '+';
                     else buf[j] = '-';
             }
         }
         bool flg = true;
         for (int i = 0 ; i < len ; ++i)
             if (buf[i] == '-') {flg = false; break;}
         printf("Case #%d: ", ca);
         if (!flg) printf("IMPOSSIBLE\n");
         else printf("%d\n", cnt);
     }
     return 0;
 }
 
