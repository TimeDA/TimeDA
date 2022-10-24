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
 
 bool before[200][200];
 
 int base_order[100];
 const int SAMPLES = 2000;
 const int MUTATIONS = 35000;
 
 char letters[200];
 
 char buf[200];
 int M;
 string cool[100];
 
 int order[100];
 
 int found[200];
 
 double x[1000], y[1000], z[1000];
 double d[1000][1000];
 list<int> adj[1000];
 bool visited[1000];
 
 void scase() {
   int N, S;
   scanf("%d%d", &N, &S);
   double a, b, c;
   REP(i,N) {
     scanf("%lf%lf%lf%lf%lf%lf", &x[i], &y[i], &z[i], &a, &b, &c);
   }
 
   REP(i,N)REP(j,N) {
     d[i][j] = sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]) + (z[i] - z[j]) * (z[i] - z[j])); 
   }
 
   double l = 0.0, r = 1e9;
   REP(ii, 200) {
     double m = (l + r) / 2;
     REP(i,N) adj[i].clear();
     REP(i,N)REP(j,N) if (d[i][j] < m) adj[i].pb(j);
 
     REP(i,N) visited[i] = false;
     visited[0] = true;
     queue<int> Q;
     Q.push(0);
     while (!Q.empty()) {
       int k = Q.front();
       Q.pop();
       FOREACH(it, adj[k]) if (!visited[*it]) {
         visited[*it] = true;
         Q.push(*it);
       }
     }
     if (visited[1]) r = m; else l = m;
   }
   
   printf("%0.9lf\n", l);
 }
 
 int main() {
 //  REP(i, R) randomized[i] = rand();
 
     int C;
     scanf("%d",&C);
     FOR(i,1,C+1) {
         printf("Case #%d: ", i);
         scase();
     }
 } 
 
