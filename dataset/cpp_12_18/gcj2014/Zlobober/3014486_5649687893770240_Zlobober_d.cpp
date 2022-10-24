#include <cstdio>
 #include <string>
 #include <vector>
 #include <set>
 #include <iostream>
 using namespace std;
 
 int trie(vector<string> V)
 {
     set<string> S;
     for (string s : V)
         for (int i = 0; i <= s.size(); i++)
             S.insert(s.substr(0, i));
     return S.size();
 }
 
 char buf[10000];
 
 void solve(int cs)
 {
     int n, m;
     scanf("%d %d ", &n, &m);
     vector<int> to(n, 0);
     vector<string> S;
     for (int i = 0; i < n; i++)
     {
         gets(buf);
         S.push_back(buf);
     }
     int mx = -1, cnt = 0;
     while (true)
     {
         vector<vector<string> > T(m);
         for (int i = 0; i < n; i++)
             T[to[i]].push_back(S[i]);
         int ans = 0;
         for (auto V : T)
             ans += trie(V);
         if (ans > mx)
             mx = ans, cnt = 0;
         if (ans == mx)
             cnt++;
         bool bad = false;
         for (int i = 0; i < n; i++)
         {
             to[i]++;
             if (to[i] == m)
                 bad = (i == n - 1), to[i] = 0;
             else
                 break;
         }
         if (bad)
             break;
     }
     printf("Case #%d: %d %d\n", cs, mx, cnt);
 }
 
 int main()
 {
     int T;
     scanf("%d", &T);
     for (int i = 0; i < T; i++)
         solve(i + 1), fflush(stdout);
 }
 
