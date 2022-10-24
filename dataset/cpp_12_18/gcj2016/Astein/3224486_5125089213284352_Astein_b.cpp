#include <string>
 #include <cstdio>
 #include <ctime>
 #include <cstdlib>
 #include <vector>
 #include <cstring>
 
 using namespace std;
 
 char s[105];
 char cool[5][25];
 vector<int> graph[105];
 vector<int> init, vv;
 int accept[5], pos[5];
 int pre[105], coolls[5];
 int check[105];
 
 int main()
 {
   srand(time(0));
   int T;
   scanf("%d", &T);
   for (int cn = 1; cn <= T; ++cn)
   {
     int N, M;
     scanf("%d", &N);
     for (int i = 0; i < N; ++i)
       graph[i].clear();
     init.clear();
 
     for (int i = 0; i < N; ++i)
     {
       scanf("%d", &pre[i]);
       pre[i]--;
       init.push_back(i);
     }
     scanf("%s", s);
     scanf("%d", &M);
     for (int i = 0; i < M; ++i)
     {
       scanf("%s", cool[i]);
       coolls[i] = strlen(cool[i]);
       accept[i] = 0;
     }
     for (int i = 0; i < N; ++i)
       check[i] = -1;
     for (int tries = 0; tries < 30000; ++tries)
     {
       vv = init;
       string ss;
       while (!vv.empty())
       {
         int r = rand() % vv.size();
         int idx = vv[r];
 //        printf("idx = %d\n", idx);
         if (pre[idx] != -1)
         {
           while (pre[idx] != -1 && check[pre[idx]] != tries)
           {
             idx = pre[idx];
           }
         }
         for (int i = 0; i < vv.size(); ++i)
           if (vv[i] == idx)
           {
             swap(vv[i], vv[vv.size() - 1]);
             vv.pop_back();
             break;
           }
 
         check[idx] = tries;
         ss += s[idx];
       }
       for (int i = 0; i < M; ++i)
         if (ss.find(cool[i]) != string::npos) accept[i]++;
     }
     
     printf("Case #%d:", cn);
     for (int i = 0; i < M; ++i)
       printf(" %.6lf", accept[i] / 30000.0);
     printf("\n");
   }
 }
 
