#include <iostream>
 #include <memory.h>
 #include <vector>
 #include <cassert>
 #include <cstdio>
 #include <string>
 using namespace std;
 
 const int C = 128;
 int A[C][C];
 vector<char> eq[C];
 int in[C], out[C];
 
 void init()
 {
     for (int i = 0; i < 128; i++)
         eq[i].push_back(i);
     string ch = "o0i1e3a4s5t7b8g9";
     for (int i = 0; i < ch.size(); i += 2)
         eq[ch[i]].push_back(ch[i + 1]), eq[ch[i + 1]].push_back(ch[i]);
 }
 
 void solve(int Case)
 {
     memset(A, 0, sizeof(A));
     memset(in, 0, sizeof(in));
     memset(out, 0, sizeof(out));
     int k;
     scanf("%d", &k);
     string s;
     cin >> s;
     assert(k == 2);
     int n = s.size();
     int m = 0;
     for (int i = 0; i < n - 1; i++)
     {
         for (char a : eq[s[i]])
             for (char b : eq[s[i + 1]])
                 if (!A[a][b])
                     m++, A[a][b] = 1, in[b]++, out[a]++;
     }
     int bad = 0;
     for (int i = 0; i < C; i++)
         bad += abs(in[i] - out[i]);
     assert(bad % 2 == 0);
     /*for (char a = 0; a < C; a++)
         for (char b = 0; b < C; b++)
         {
             if (A[a][b])
                 printf("%c %c\n", a, b);
         }*/
     m += max(0, (bad - 2) / 2);
     printf("Case #%d: %d\n", Case, m + 1);
 }
 
 int main()
 {
     init();
     int T;
     scanf("%d", &T);
     for (int i = 0; i < T; i++)
         solve(i + 1);
 }
