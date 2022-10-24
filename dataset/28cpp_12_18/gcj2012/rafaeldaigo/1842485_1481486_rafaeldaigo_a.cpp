#include<cstdio>
 #include<cstring>
 #include<queue>
 #include<utility>
 
 using namespace std;
 
 int bestSwing[11000];
 bool valid[11000];
 int pos[11000];
 int len[11000];
 
 int main()
 {
     int t, teste;
     int n, m;
     int i, j;
     scanf("%d\n", &teste);
     for (int t = 0; t < teste; t++)
     {
         scanf("%d", &n);
         for (i = 0; i < n; i++)
         {
             scanf("%d %d", &pos[i], &len[i]);
         }
         scanf("%d", &pos[n]);
         len[n] = 0;
         priority_queue<pair<int, int>,vector<pair<int, int> >, greater<pair<int, int> > > invalid;
         invalid.push(make_pair(2 * pos[0], 0));
         int firstvalid = 0;
         for (i = 0; i <= n; i++)
         {
             valid[i] = false;
             bestSwing[i] = -1;
         }
         valid[0] = true;
         bestSwing[0] = pos[0];
 
         for (i = 1; i <= n; i++)
         {
             while(true)
             {
                 if (invalid.size() == 0) break;
                 pair<int, int> event = invalid.top();
                 if (event.first >= pos[i]) break;
                 valid[event.second] = false;
                 invalid.pop();
             }
             while (valid[firstvalid] == false)
             {
                 firstvalid++;
                 if (firstvalid == i)
                 {
                     firstvalid = -1;
                     break;
                 }
             }
             if (firstvalid == -1) break;
             valid[i] = true;
             int swing = pos[i] - pos[firstvalid];
             if (swing > len[i]) swing = len[i];
             bestSwing[i] = swing;
             invalid.push(make_pair(pos[i] + bestSwing[i], i));
         }
 
         if (bestSwing[n] >= 0)
             printf("Case #%d: YES\n", t + 1);
         else
             printf("Case #%d: NO\n", t + 1);
     }
     return 0;
 }
