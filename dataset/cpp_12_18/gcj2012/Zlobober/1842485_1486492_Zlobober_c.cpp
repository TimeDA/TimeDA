#include <iostream>
 #include <vector>
 #include <cstdio>
 using namespace std;
 
 const int N = 100500;
 
 int E[N];
 
 #define eprintf(...) fprintf(stderr, __VA_ARGS__)
 
 int to[N];
 
 void go(int s, int e, int d)
 {
     vector<int> p;
     if (s == e)
         return;
     while (s != e)
         p.push_back(s), s = to[s];
     for (int i = 0; i < p.size(); i++)
         E[p[i]] = -d * (e - p[i]) + E[e];
     for (int i = 0; i < p.size(); i++)
         go(p[i] + 1, to[p[i]], d + 1);
 }
 
 void solve(int C)
 {
     int n;
     scanf("%d", &n);
     vector<pair<int, int> > V;
     for (int i = 0; i <= n; i++)
         E[i] = 0;
     for (int i = 1; i < n; i++)
     {
         int t;
         scanf("%d", &t);
         to[i] = t;
         V.push_back(make_pair(i, t));
     }
     to[n] = n + 1;
     bool bad = false;
     for (int i = 0; i < V.size(); i++)
         for (int j = 0; j < V.size(); j++)
         {
             if (i == j)
                 continue;
             if (V[i].first < V[j].first && V[j].first < V[i].second && V[i].second < V[j].second)
                 bad = true;
         }
     if (bad)
         printf("Case #%d: Impossible\n", C);
     else
     {
         go(1, n + 1, 0);
         printf("Case #%d: ", C);
         int mn = 0;
         for (int i = 1; i <= n; i++)
             mn = min(mn, E[i]);
         for (int i = 1; i <= n; i++)
             printf("%d ", E[i] - mn);
         printf("\n");
     }
 
     fflush(stdout);
 }
 
 int main()
 {
     int T;
     scanf("%d", &T);
     for (int c = 1; c <= T; c++)
         solve(c);
 }
