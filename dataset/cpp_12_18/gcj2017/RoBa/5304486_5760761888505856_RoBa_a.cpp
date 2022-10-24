#include <cstdio>
 #include <cstring>
 
 char buf[32][32];
 bool emp[32];
 int R, C;
 
 char find_right(int i, int j) {
     for (int t = j + 1 ; t < C ; ++t)
         if (buf[i][t] != '?') return buf[i][t];
     return 0;
 }
 
 char find_left(int i, int j) {
     for (int t = j - 1 ; t >= 0 ; --t)
         if (buf[i][t] != '?') return buf[i][t];
     return 0;
 }
 
 int main() {
     int T;
     scanf("%d",&T);
     for (int ca = 1 ; ca <= T ; ++ca) {
         scanf("%d%d",&R,&C);
         for (int i = 0 ; i < R ; ++i)
             scanf("%s", buf[i]);
 
         memset(emp, 0, sizeof(emp));
         for (int i = 0 ; i < R ; ++i) {
             emp[i] = true;
             for (int j = 0 ; j < C ; ++j)
                 if (buf[i][j] != '?') {emp[i] = false; break;}
             if (emp[i]) continue;
             for (int j = 0 ; j < C ; ++j)
                 if (buf[i][j] == '?') {
                     char c;
                     if (c = find_right(i, j)) {
                        buf[i][j] = c;
                     } else
                        buf[i][j] = find_left(i, j);
                 } 
         }
         for (int i = 0 ; i < R ; ++i) {
             if (!emp[i]) continue;
             int j;
             for (j = i-1 ; j >= 0 ; --j)
                 if (!emp[j]) break;
             if (j == -1) {
                 for (j = i+1 ; j < R ; ++j)
                     if (!emp[j]) break;
             }
             for (int k = 0 ; k < C ; ++k)
                 buf[i][k] = buf[j][k];
         }
         printf("Case #%d:\n", ca);
         for (int i = 0 ; i < R ; ++i)
             printf("%s\n", buf[i]);
     }
     return 0;
 }
 
