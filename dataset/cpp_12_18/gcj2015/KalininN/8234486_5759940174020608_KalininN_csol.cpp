#include <iostream>
 #include <algorithm>
 #include <cmath>
 #include <cstring>
 #include <cstdlib>
 #include <string>
 #include <vector>
 #include <cstdio>
 #include <cassert>
 #include <unordered_set>
 
 using namespace std;
 
 typedef long long ll;
 typedef long double ld;
 
 #ifdef WIN32
 #define LLD "%I64d"
 #else
 #define LLD "%lld"
 #endif
 
 #define pb push_back
 #define all(x) x.begin(),x.end()
 
 const int maxlen = 20005;
 const int maxn = 30;
 
 char s[maxlen];
 char w[maxlen];
 vector<ll> words[maxn];
 vector<ll> eng, fr, both;
 unordered_set<ll> eng2, both2;
 int n;
 
 int main()
 {
     int NT = 0;
     scanf("%d", &NT);
     for (int T = 1; T <= NT; T++)
     {
         printf("Case #%d:", T);
         scanf("%d", &n);
         for (int i = 0; i < n; i++)
         {
             scanf(" %[^\n]*", s);
             words[i].clear();
             int kbytes = 0;
             char *t = s;
             while (sscanf(t, "%s%n", w, &kbytes) == 1)
             {
                 ll h = 0;
                 for (int i = 0; i < kbytes; i++) if (t[i] >= 'a' && t[i] <= 'z') h = h * 239 + t[i];
                 words[i].pb(h);
                 t += kbytes;
             }
         }
         int km = 1 << (n - 2);
         int answer = 1e9;
         eng.clear();
         for (auto &word : words[0]) eng.pb(word);
         sort(all(eng));
         eng.resize(unique(all(eng)) - eng.begin());
         fr.clear();
         for (auto &word : words[1]) fr.pb(word);
         sort(all(fr));
         fr.resize(unique(all(fr)) - fr.begin());
         int c1 = 0;
         int c2 = 0;
         both.clear();
         while (c1 < (int)eng.size() && c2 < (int)fr.size())
         {
             if (eng[c1] < fr[c2]) c1++;
             else if (eng[c1] > fr[c2]) c2++;
             else
             {
                 both.pb(eng[c1]);
                 c1++;
                 c2++;
             }
         }
         for (int mask = 0; mask < km; mask++)
         {
             int curans = 0;
             both2.clear();
             eng2.clear();
             for (int i = 0; i < n - 2 && both.size() + both2.size() < answer; i++) if (mask & (1 << i))
             {
                 for (auto &word : words[i + 2])
                 {
                     if (binary_search(all(both), word)) continue;
                     if (both2.count(word)) continue;
                     if (binary_search(all(fr), word))
                     {
                         both2.insert(word);
                     } else
                     {
                         eng2.insert(word);
                     }
                 }
             }
             for (int i = 0; i < n - 2 && both.size() + both2.size() < answer; i++) if (!(mask & (1 << i)))
             {
                 for (auto &word : words[i + 2])
                 {
                     if (binary_search(all(both), word)) continue;
                     if (both2.count(word)) continue;
                     if (binary_search(all(eng), word) || eng2.count(word))
                     {
                         both2.insert(word);
                     }
                 }
             }
             curans = both.size() + both2.size();
             answer = min(answer, curans);
         }
         printf(" %d\n", answer);
         fprintf(stderr, "%d/%d cases done!\n", T, NT);
     }
     return 0;
 }
