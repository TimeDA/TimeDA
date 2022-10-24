
 #include <cstdio>
 #include <iostream>
 #include <sstream>
 #include <string>
 #include <cstring>
 #include <cctype>
 #include <algorithm>
 #include <vector>
 #include <map>
 #include <queue>
 #include <set>
 #include <list>
 #include <cmath>
 #include <complex>
 #include <numeric>
 #include <cassert>
 using namespace std;
 
 #define REP(i,n) for(int i = 0; i < (int)(n); ++i)
 #define FOR(i,s) for(__typeof((s).begin()) i = (s).begin(); i != (s).end(); ++i)
 #define ALLOF(s) ((s).begin()), ((s).end())
 
 typedef long long ll;
 
 
 inline ll worstRank(ll nTeams, ll rank) {
   if(rank == 0 || nTeams == 1) return 0;
   ll nextRank = (rank - 1) / 2;
   return worstRank(nTeams / 2, nextRank) + nTeams / 2;
 }
 
 inline ll getAlways(ll n, ll p) {
   ll left = 0; // OK
   ll right = 1LL << n; // NG
   while(left + 1 < right){
     ll med = (left + right) / 2;
     if(worstRank(1LL << n, med) < p){
       left = med;
     }else{
       right = med;
     }
   }
   return left;
 }
 
 inline ll bestRank(ll nTeams, ll rank) {
   if(rank == nTeams - 1) return rank;
   ll nextRank = (rank + 1) / 2;
   return bestRank(nTeams / 2, nextRank);
 }
 
 inline ll getSometimes(ll n, ll p) {
   ll left = 0; // OK
   ll right = 1LL << n; // NG
   while(left + 1 < right){
     ll med = (left + right) / 2;
     if(bestRank(1LL << n, med) < p){
       left = med;
     }else{
       right = med;
     }
   }
   return left;
 }
 
 
 int main(void) {
   int nCases;
   cin >> nCases;
   REP(iCase, nCases) {
     ll n, p;
     cin >> n >> p;
     ll a = getAlways(n, p);
     ll b = getSometimes(n, p);
     
     cout << "Case #" << (iCase+1) << ": " << a << " " << b << endl;;
   }
   
   return 0;
 }
