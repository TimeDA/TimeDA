#include <cstdio>
 #include <vector>
 #include <string>
 #include <map>
 using namespace std;
 
 int wpt = 0;
 
 map<string, int> words;
 
 char buf[20];
 
 int word()
 {
     string word = buf;
     if (words.find(word) == words.end())
         words[word] = wpt++;
     return words[word];
 }
 
 const int L = 30 * 1000;
 char line[L];
 
 void solve(int cs)
 {
     int n;
     scanf("%d ", &n);
     wpt = 0;
     words.clear();
     vector<vector<int> > S;
     for (int i = 0; i < n; i++)
     {
         gets(line);
         int bytes;
         int pos = 0; 
         vector<int> seq;
         int val;
         while (-1 != sscanf(line + pos, " %s %n", buf, &bytes))
             pos += bytes, seq.push_back(word());
         S.push_back(seq);
     }
     int best = 1000 * 1000;
     vector<char> was[2];
     was[0].resize(wpt);
     was[1].resize(wpt);
     vector<int> T(n);
     for (int msk = 0; msk < (1 << (n - 2)); msk++)
     {
         T[0] = 0;
         T[1] = 1;
         for (int i = 0; i < n - 2; i++)
             T[i + 2] = (msk >> i) & 1;
         for (int i = 0; i < wpt; i++)
             was[0][i] = was[1][i] = 0;
         for (int i = 0; i < n; i++)
         {
             for (int x : S[i])
                 was[T[i]][x] = true;
         }
         int ans = 0;
         for (int i = 0; i < wpt; i++)
             ans += was[0][i] && was[1][i];
         best = min(best, ans);
     }    
     printf("Case #%d: %d\n", cs, best);
     fflush(stdout);
     fprintf(stderr, "%d\n", cs);
 }
 
 int main()
 {
     int T;
     scanf("%d", &T);
     for (int i = 0; i < T; i++)
         solve(i + 1);
 }
