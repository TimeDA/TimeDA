#include <cstdio>
 #include <cstring>
 using namespace std;
 #define REP(i, n) for(int i = 0; i < (int)(n); ++i)
 
 char buf[2010];
 
 int main(void) {
   int nCase;
   scanf("%d", &nCase);
   REP(iCase, nCase) {
     int k;
     scanf("%s %d", buf, &k);
     int len = strlen(buf);
     int res = 0;
     for(int i = 0; i < len; ++i) {
       if(buf[i] == '-') {
         ++res;
         REP(j, k) {
           if(i+j >= len) {
             res = -1;
             goto OUT;
           }
           buf[i+j] = buf[i+j] == '-' ? '+' : '-';
         }
       }
     }
   OUT:
     if(res < 0) {
       printf("Case #%d: IMPOSSIBLE\n", iCase+1);
     } else {
       printf("Case #%d: %d\n", iCase+1, res);
     }
   }
   return 0;
 }
