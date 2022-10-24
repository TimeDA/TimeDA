#include <algorithm>
 #include <cstdio>
 #include <cstdlib>
 #include <list>
 #include <map>
 #include <queue>
 #include <set>
 #include <stack>
 #include <vector>
 #include <cmath>
 #include <cstring>
 #include <string>
 #include <iostream>
 #include <complex>
 #include <sstream>
 using namespace std;
  
 typedef long long LL;
 typedef unsigned long long ULL;
 typedef long double LD;
 typedef vector<int> VI;
 typedef pair<int,int> PII;
  
 #define REP(i,n) for(int i=0;i<(n);++i)
 #define SIZE(c) ((int)((c).size()))
 #define FOR(i,a,b) for (int i=(a); i<(b); ++i)
 #define FOREACH(i,x) for (__typeof((x).begin()) i=(x).begin(); i!=(x).end(); ++i)
 #define FORD(i,a,b) for (int i=(a)-1; i>=(b); --i)
 #define ALL(v) (v).begin(), (v).end()
  
 #define pb push_back
 #define mp make_pair
 #define st first
 #define nd second
 
 void scase() {
   int M, N;
   scanf("%d%d",&M,&N);
   vector<string> strings;
   REP(i,M) {
     string s;
     cin >> s;
     strings.push_back(s);
   }
   
   int best = 0, cnt= 0;
   int settings = 1;
   REP(i,M) settings *= N;
   REP(setting, settings) {
     vector<set<string> > servers;
     REP(i,N) servers.push_back(set<string>());
     
     int tmp = setting;
     REP(j,M) {
       int s = tmp % N;
       tmp /= N;
       
       REP(k, strings[j].size() + 1) {
         servers[s].insert(strings[j].substr(0,k));
       }
     }
     
     tmp = 0;
     REP(k, N) tmp += servers[k].size();
     if (tmp > best) {
       best = tmp;
       cnt = 1;
     } else if (tmp == best) ++cnt;
   }
   
   printf("%d %d\n", best, cnt);
 }
 
 int main() {
   int Z;
   scanf("%d", &Z);
   REP(z,Z) {
     printf("Case #%d: ", z+1);
     scase();
   }
 }    
