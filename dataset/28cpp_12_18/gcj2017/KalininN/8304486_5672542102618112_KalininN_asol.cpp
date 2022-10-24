#include <bits/stdc++.h>
 
 using namespace std;
 
 using ll = long long;
 using ld = long double;
 using D = double;
 using uint = unsigned int;
 template<typename T>
 using pair2 = pair<T, T>;
 
 #ifdef WIN32
     #define LLD "%I64d"
 #else
     #define LLD "%lld"
 #endif
 
 #define pb push_back
 #define mp make_pair
 #define all(x) (x).begin(),(x).end()
 #define fi first
 #define se second
 
 const int maxs = 100005;
 
 map<string, int> ids;
 int cntids;
 vector<pair2<string>> edges;
 int was[maxs];
 vector<int> gr[maxs];
 char s[14];
 int n;
 int cntwas;
 int kv[maxs];
 int answer;
 
 int getid()
 {
     auto it = ids.find(string(s, s + n));
     if (it == ids.end()) return -1;
     else return it->second;
 }
 
 void go(int cur)
 {
     if (was[cur] == cntwas)
     {
         answer--;
         return;
     }
     was[cur] = cntwas;
     answer += kv[cur];
 //     cout << "go " << cur << ' ' << kv[cur] << endl;
 //     answer++;
     for (auto t : gr[cur]) go(t);
 }
 
 char curd[15];
 
 int getkv(int len)
 {
     ll curkv = 1;
     for (int i = 0; i < len; i++) curkv *= (i + 1);
     int sum = 0;
     for (int i = 0; i < len; i++)
     {
         sum += curd[i] - '0';
         for (int j = 1; j <= curd[i] - '0'; j++) curkv /= j;
     }
     if (sum > len) curkv = 0;
     for (int j = 1; j <= len - sum; j++) curkv /= j;
     return curkv;
 }
 
 void precalc(int curlen, int cursum, int maxd)
 {
 //     cout << "precalc " << curlen << ' ' << cursum << ' ' << maxd << endl;
     if (curlen >= cursum && maxd <= curlen && cursum > 0)
     {
         string nexts(curlen, '0');
         for (int i = 0; i < curlen; i++) if (curd[i] != '0') nexts[curd[i] - '1']++;
         edges.pb({string(curd, curd + curlen), nexts});
 //         cout << string(curd, curd + curlen) << ' ' << getkv(curlen) << endl;
         kv[cntids] = getkv(curlen);
         ids[string(curd, curd + curlen)] = cntids++;
     }
     if (curlen == 9 || cursum > 9) return;
     for (int i = 0; i <= 9 && i + cursum <= 9; i++)
     {
         curd[curlen] = '0' + i;
         precalc(curlen + 1, cursum + i, max(maxd, i));
     }
 }
 
 void precalc2(int curlen, int cursum, int maxd)
 {
     if (maxd <= curlen)
     {
         string nexts(curlen, '0');
         for (int i = 0; i < curlen; i++) if (curd[i] != '0') nexts[curd[i] - '1']++;
         edges.pb({string(curd, curd + curlen), nexts});
         //         cout << string(curd, curd + curlen) << ' ' << getkv(curlen) << endl;
         kv[cntids] = getkv(curlen);
         ids[string(curd, curd + curlen)] = cntids++;
     }
     if (curlen == 5) return;
     for (int i = 0; i <= 9; i++)
     {
         curd[curlen] = '0' + i;
         precalc2(curlen + 1, cursum + i, max(maxd, i));
     }
 }
 
 int main()
 {
     precalc(0, 0, 0);
     assert(cntids < maxs);
     for (auto t : edges)
     {
 //         cout << t.fi << " --> " << t.se << endl;
         gr[ids[t.se]].pb(ids[t.fi]);
     }
 //     cout << kv[ids["11"]] << endl;
     
     int NT = 0;
     scanf("%d", &NT);
     for (int T = 1; T <= NT; T++)
     {
         printf("Case #%d:", T);
         
         scanf("%s", s);
         n = strlen(s);
         cntwas++;
         answer = 0;
         int curpos = getid();
 //         assert(curpos != -1);
         if (curpos != -1)
         {
             go(curpos);
             answer++;
         } else answer++;
         printf(" %d\n", answer);
 
         fprintf(stderr, "%d/%d cases done!\n", T, NT);
     }
     return 0;
 }
