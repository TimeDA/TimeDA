#include <algorithm>
 #include <cstdio>
 #include <cstdlib>
 #include <list>
 #include <map>
 #include <queue>
 #include <set>
 #include <stack>
 #include <vector>
 #include <cstring>
 #include <string>
 #include <iostream>
 using namespace std;
  
 typedef long long LL;
 typedef long double LD;
 typedef vector<int> VI;
 typedef pair<int,int> PII;
  
 #define REP(i,n) for(int i=0;i<(n);++i)
 #define SIZE(c) ((int)((c).size()))
 #define FOR(i,a,b) for (int i=(a); i<(b); ++i)
 #define FOREACH(i,x) for (__typeof((x).begin()) i=(x).begin(); i!=(x).end(); ++i)
 #define FORD(i,a,b) for (int i=((int)(a))-1; i>=(b); --i)
  
 #define pb push_back
 #define mp make_pair
 #define st first
 #define nd second
 
 LL INF = 1000000000LL * 1000000000LL;
 
 struct Food {
   LL ti;
   LL mo;
 };
 
 bool cmp(Food a, Food b) {
   if (a.ti != b.ti) return a.ti < b.ti;
   return a.mo > b.mo;
 }
 
 void scase(int CID) {
   long long M, F;
   int N;
   scanf("%lld%lld%d",&M,&F,&N);
   Food T[N];
   REP(i,N) scanf("%lld%lld",&T[i].mo, &T[i].ti);
   sort(T, T+N, cmp);
   
   vector<Food> V;
   REP(i,N) {
     while (!V.empty() && V.back().mo >= T[i].mo)
       V.pop_back();
     V.push_back(T[i]);
   }
   
   vector<LL> daysOnFood;
   LL q = -1;
   REP(i, V.size()) {
     daysOnFood.push_back(V[i].ti - q);
     q = V[i].ti;
   }
     
   LL best = 0;  
   FOR(tours,1,M+1) {
     cerr << CID << " " << tours << endl;
     LL M2 = M;
     M2 -= tours * F;
     if (M2 <= 0) break;
     LL result = 0;
     REP(i,V.size()) {
       LL tmp = min(daysOnFood[i] * tours, M2 / V[i].mo);
       result += tmp;
       M2 -= V[i].mo * tmp;
     }
     best = max(best, result);
   }
   
   printf("Case #%d: %lld\n", CID, best);
   /*vector<pair<LL,LL> > packages;
   LL days = 0;
   REP(i,N) {
     LL mdays = T[i].first - days;
     
     
     days = T[i].first;
   }*/
   
   /*
   LL DP[M+1];
   REP(i,M+1) DP[i] = -INF;
   DP[0] = 0;
   REP(i,N)
     FOR(j,T[i].second,M+1)
       DP[j] = 
   */
 }
 
 int main() {
   int Z;
   scanf("%d",&Z);
   FOR(z,1,Z+1) scase(z);
 }
