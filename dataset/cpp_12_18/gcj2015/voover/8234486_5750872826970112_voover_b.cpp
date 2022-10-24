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
 
   
 double V, X;
 vector<pair<double, double> > sources;
 
 bool can(double t) {
   double curV = 0.0, curE = 0.0;
   bool safeT = (sources.begin()->st == sources.rbegin()->st);
   
   FOREACH(it, sources) {
     double take = min(V - curV, t * it->nd);
     curV += take;
     curE += take * it->st;
   }
   if (curV < V || (!safeT && curE > V * X)) return false;
   
   curV = 0.0, curE = 0.0;
   for(vector<pair<double, double> >::reverse_iterator it = sources.rbegin(); it != sources.rend(); ++it) {
     double take = min(V - curV, t * it->nd);
     curV += take;
     curE += take * it->st;
   }
   return safeT || curE >= V * X;
 }
 
 void scase() {
   sources.clear();
 
   int N;
   scanf("%d%lf%lf", &N, &V, &X);
   REP(i,N) {
     double R, C;
     scanf("%lf%lf", &R, &C);
     sources.push_back(mp(C,R));
   }
   sort(sources.begin(), sources.end());
   if (X < sources[0].st || X > sources[N-1].st) {
     printf("IMPOSSIBLE\n");
     return;
   }
   
   double L = 0.0, R = 10001 * V;
   while (L + 1e-9 < R) {
     double S = (L + R) / 2;
     if (can(S)) R = S;
     else L = S;
   }
   printf("%0.8lf\n", L);
 }
 
 int main() {
   int Z;
   scanf("%d", &Z);
   REP(z,Z) {
     printf("Case #%d: ", z+1);
     scase();
   }
 }    
