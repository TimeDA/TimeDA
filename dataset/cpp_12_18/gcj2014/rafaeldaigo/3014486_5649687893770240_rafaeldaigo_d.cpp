#include<cstdio>
 #include<cstring>
 #include<queue>
 #include<utility>
 #include<algorithm>
 
 using namespace std;
 
 int n, m;
 char words[10][12];
 int worst;
 int wcount;
 int server[10][10];
 int servercount[10];
 int wordlen[10];
 int common[10][10];
 
 void check()
 {
     int i;
     for (i = 0; i < n; i++)
     {
         if (servercount[i] == 0) return;
     }
     int candidate = n;
     for (i = 0; i < n; i++)
     {
         int j;
         for (j = 0; j < servercount[i]; j++)
         {
             int bestcommon = 0;
             int k;
             for (k = 0; k < j; k++)
             {
                 if (bestcommon < common[server[i][j]][server[i][k]])
                     bestcommon = common[server[i][j]][server[i][k]];
             }
             candidate += wordlen[server[i][j]] - bestcommon;
         }
     }
     if (candidate > worst)
     {
         worst = candidate;
         wcount = 1;
     }
     else if (candidate == worst)
     {
         wcount++;
     }
 }
 
 void rec(int pos)
 {
     if (pos == m)
     {
         check();
         return;
     }
     for (int i = 0; i < n; i++)
     {
         server[i][servercount[i]] = pos;
         servercount[i]++;
         rec(pos+1);
         servercount[i]--;
     }
 }
 
 int main()
 {
     int t, teste;
     int i, j, k;
     int a, b;
     scanf("%d\n", &teste);
     for (int t = 0; t < teste; t++)
     {
         scanf("%d %d\n", &m, &n);
         for (i = 0; i < m; i++)
             scanf("%s", words[i]);
         for (i = 0; i < n; i++)
             servercount[i] = 0;
 
         for (i = 0; i < m; i++)
         {
             wordlen[i] = strlen(words[i]);
         }
         for (i = 0; i < m; i++)
         {
             a = wordlen[i];
             for (j = 0; j < i; j++)
             {
                 b = wordlen[j];
                 for (k = 0; k < a && k < b; k++)
                 {
                     if (words[i][k] != words[j][k])
                     {
                         break;
                     }
                 }
                 common[i][j] = common[j][i] = k;
             }
         }
 
         worst = 0;
         wcount = 0;
         rec(0);
 
         printf("Case #%d: %d %d\n", t + 1, worst, wcount);
     }
     return 0;
 }
