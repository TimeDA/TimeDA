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
 
 bool cmp(pair<pair<int,int>, int> a, pair<pair<int,int>, int> b) {
 //  if (a.second > b.second) return (a != b && !cmp(b,a));
   if (a.first.first * b.first.second != a.first.second * b.first.first)
     return a.first.first * b.first.second > a.first.second * b.first.first;
 
   return a.second < b.second;
 }
 
 void scase(int CID) {
   int N;
   scanf("%d",&N);
   pair<pair<int,int>, int> T[N];
   REP(i,N) T[i].second = i;
   REP(i,N) scanf("%d", &T[i].first.first);
   REP(i,N) {
     int p;
     scanf("%d", &p);
     p = 1 - p;
     T[i].first.second = p;p*p - p;
   }
   sort(T, T+N, cmp);
   printf("Case #%d:", CID);
   REP(i,N) printf(" %d",T[i].second);
   printf("\n");
 }
 
 int main() {
   int Z;
   scanf("%d",&Z);
   FOR(z,1,Z+1) scase(z);
 }
