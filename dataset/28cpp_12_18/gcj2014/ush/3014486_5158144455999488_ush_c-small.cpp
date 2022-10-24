
 #include <cstdio>
 #include <cstdlib>
 #include <cstring>
 #include <cctype>
 #include <cmath>
 #include <cassert>
 #include <iostream>
 #include <sstream>
 #include <string>
 #include <algorithm>
 #include <vector>
 #include <map>
 #include <queue>
 #include <set>
 #include <list>
 #include <complex>
 #include <numeric>
 using namespace std;
 
 #define REP(i,n) for(int i = 0; i < (int)(n); ++i)
 #define FOR(i,s) for(__typeof((s).begin()) i = (s).begin(); i != (s).end(); ++i)
 #define ALLOF(s) ((s).begin()), ((s).end())
 
 unsigned myrand() {
   static unsigned x = 123456789, y = 362436069, z = 521288629, w = 88675123;
   unsigned t = (x ^ (x << 11)); x = y; y = z; z = w;
   return (w = (w ^ (w >> 19)) ^ (t ^ (t >> 8)));
 }
 
 typedef long long ll;
 
 // const int DI[4] = {0, 1, 0, -1};
 // const int DJ[4] = {1, 0, -1, 0};
 
 
 ll x1s[1010];
 ll y1s[1010];
 ll x2s[1010];
 ll y2s[1010];
 
 struct K {
   int v, c;
 };
 bool operator>(const K& a, const K& b) {
   return a.c > b.c;
 }
 
 ll dist[1010];
 bool visited[1010];
 
 ll g[1010][1010];
 
 ll calcDist(int i, int j) {
   if(x2s[j] < x1s[i])
     return calcDist(j, i);
   if(x2s[i] < x1s[j]){
     ll res = x1s[j] - x2s[i] - 1;
     if(y2s[i] < y1s[j]){
       return max(res, y1s[j] - y2s[i] - 1);
     }else if(y2s[j] < y1s[i]){
       return max(res, y1s[i] - y2s[j] - 1);
     }else{
       return res;
     }
     
   }else{
     if(y2s[i] < y1s[j]){
       return y1s[j] - y2s[i] - 1;
     }else{
       assert(y2s[j] < y1s[i]);
       return y1s[i] - y2s[j] - 1;
     }
   }
 }
 
 const ll INF = 0x1fffffffffffffffLL;
 
 
 int main(void) {
   int nCases;
   cin >> nCases;
   REP(iCase, nCases) {
     int w, h;
     int n;
     cin >> w >> h >> n;
     int LEFT = n;
     int RIGHT = n+1;
     memset(g, 0x1f, sizeof g);
     g[LEFT][LEFT] = 0;
     g[RIGHT][RIGHT] = 0;
     g[LEFT][RIGHT] = g[RIGHT][LEFT] = w;
     
     REP(i, n){
       cin >> x1s[i] >> y1s[i] >> x2s[i] >> y2s[i];
       g[LEFT][i] = g[i][LEFT] = x1s[i];
       g[RIGHT][i] = g[i][RIGHT] = x2s[i];
       g[i][i] = 0;
       REP(j, i){
 	g[i][j] = g[j][i] = calcDist(i, j);
       }
       g[LEFT][i] = g[i][LEFT] = x1s[i];
       g[RIGHT][i] = g[i][RIGHT] = w-1 - x2s[i];
     }
     
     memset(visited, 0, sizeof visited);
     fill(dist, dist + 1010, INF);
     
     dist[LEFT] = 0;
     for(;;){
       int cur = n+2;
       REP(i, n+2)
 	if(!visited[i] && dist[i] < dist[cur])
 	  cur = i;
       if(cur == n+2)
 	break;
       visited[cur] = true;
       for(int v = 0; v < n+2; ++v){
 	if(!visited[v] && dist[cur] + g[cur][v] < dist[v]){
 	  dist[v] = dist[cur] + g[cur][v];
 	}
       }
     }
     printf("Case #%d: %lld\n", iCase+1, dist[RIGHT]);
   }
   return 0;
 }
