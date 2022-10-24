#include<cstdio>
 #include<cstring>
 #include<queue>
 #include<utility>
 #include<algorithm>
 
 using namespace std;
 
 int w, h, b;
 int x0[1100];
 int x1[1100];
 int y0[1100];
 int y1[1100];
 bool totheleft[1100];
 int queuea[1100];
 int qsize;
 int qpos;
 
 int main()
 {
     int t, teste;
     int i, j;
     scanf("%d\n", &teste);
     for (int t = 0; t < teste; t++)
     {
         scanf("%d %d %d\n", &w, &h, &b);
         for (i = 0; i < b; i++)
         {
             scanf("%d %d %d %d\n", &x0[i], &y0[i], &x1[i], &y1[i]);
             totheleft[i] = false;
         }
 
         int ans;
         for (ans = 0; ans < w; ans++)
         {
             qsize = 0;
             for (i = 0; i < b; i++)
             {
                 if (totheleft[i])
                 {
                     for (j = 0; j < b; j++)
                     {
                         if (totheleft[j] == false)
                         {
                             if (x0[j] > x1[i] + 1) continue;
                             if (y0[j] > y1[i] + 1) continue;
                             if (y1[j] < y0[i] - 1) continue;
                             totheleft[j] = true;
                             queuea[qsize++] = j;
                         }
                     }
                 }
                 else if (x0[i] <= ans)
                 {
                     totheleft[i] = true;
                     queuea[qsize++] = i;
                 }
             }
             qpos = 0;
             while (qpos < qsize)
             {
                 i = queuea[qpos];
                 for (j = 0; j < b; j++)
                 {
                     if (totheleft[j] == false)
                     {
                         if (x0[j] > x1[i] + 1) continue;
                         if (y0[j] > y1[i] + 1) continue;
                         if (y1[j] < y0[i] - 1) continue;
                         totheleft[j] = true;
                         queuea[qsize++] = j;
                     }
                 }
                 qpos++;
             }
             for (i = 0; i < b; i++)
             {
                 if (totheleft[i])
                 {
                     if (x1[i] == w - 1)
                         break;
                     x0[i] = 0;
                     x1[i]++;
                     y0[i]--;
                     y1[i]++;
                 }
             }
             if (i < b)
                 break;
         }
 
         printf("Case #%d: %d\n", t + 1, ans);
     }
     return 0;
 }
