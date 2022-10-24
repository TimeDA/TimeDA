#include<cstdio>
 #include<cstring>
 #include<cmath>
 #include<algorithm>
 #include<vector>
 #include<utility>
 
 using namespace std;
 
 int main()
 {
     int t, teste;
     int i, j;
     scanf("%d\n", &teste);
     for (int t = 0; t < teste; t++)
     {
         int n, m;
         int w, l;
         vector<pair<int, int> > r;
         double px[1100];
         double py[1100];
         int radorig[1100];
         //bool packed[1100];
         scanf("%d %d %d", &n, &w, &l);
         for (i = 0; i < n; i++)
         {
             scanf("%d", &radorig[i]);
             r.push_back(make_pair(radorig[i], i));
             //packed[i] = false;
             px[i] = -1;
             py[i] = -1;
         }
         sort(&r[0], &r[n]);
         reverse(&r[0], &r[n]);
         int lasth = 0;
         int nextline = 0;
         int lastw = 0;
         for (i = 0; i < n; i++)
         {
             int rad = r[i].first;
             int index = r[i].second;
             if (lastw == 0)
             {
                 px[index] = 0;
             }
             else
             {
                 px[index] = lastw + rad;
                 if (px[index] > w)
                 {
                     lastw = 0;
                     lasth = nextline;
                     px[index] = 0;
                 }
             }
             lastw = px[index] + rad;
             if (lasth == 0)
             {
                 py[index] = 0;
             }
             else
             {
                 py[index] = lasth + rad;
             }
             int cand = py[index] + rad;
             if (nextline < cand) nextline = cand;
             if (lasth > l)
             {
                 //printf("Failed\n");
                 break;
             }
         }
 
         printf("Case #%d:", t + 1);
         for (i = 0; i < n; i++)
         {
             printf(" %lf %lf", px[i], py[i]);
         }
         for (i = 0; i < n; i++)
         {
             for (j = 0; j < n; j++)
             {
                 if (i == j) continue;
                 double dist = sqrt((px[i] - px[j]) * (px[i] - px[j]) + (py[i] - py[j]) * (py[i] - py[j]));
                 if (dist < radorig[i] + radorig[j])
                 {
                     printf("\n ERROR %d %d %lf %d\n", i, j, dist, radorig[i] + radorig[j]);
                 }
             }
             if (px[i] > w)
             {
                 printf("\n ERROR X %d %lf %lf\n", i, px[i], py[i]);
             }
             if (py[i] > l)
             {
                 printf("\n ERROR Y %d %lf %lf\n", i, px[i], py[i]);
             }
         }
         printf("\n");
     }
     return 0;
 }
