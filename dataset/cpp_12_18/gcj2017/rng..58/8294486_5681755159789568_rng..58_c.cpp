#include <iostream>
 #include <sstream>
 #include <fstream>
 #include <string>
 #include <vector>
 #include <deque>
 #include <queue>
 #include <stack>
 #include <set>
 #include <map>
 #include <algorithm>
 #include <functional>
 #include <utility>
 #include <bitset>
 #include <cmath>
 #include <cstdlib>
 #include <ctime>
 #include <cstdio>
 
 using namespace std;
 
 #define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
 #define snuke(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
 
 typedef long long ll;
 #define INF (1ll<<60)
 
 int N,Q;
 ll maxdist[110];
 double speed[110];
 ll graph[110][110];
 int qu[110],qv[110];
 double dist[110][110];
 
 void main2(void){
 	int i,j,k;
 	
 	cin >> N >> Q;
 	REP(i,N) cin >> maxdist[i] >> speed[i];
 	REP(i,N) REP(j,N) cin >> graph[i][j];
 	REP(i,Q){
 		cin >> qu[i] >> qv[i];
 		qu[i]--; qv[i]--;
 	}
 	
 	REP(i,N) graph[i][i] = 0;
 	REP(i,N) REP(j,N) if(graph[i][j] == -1) graph[i][j] = INF;
 	REP(k,N) REP(i,N) REP(j,N) graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
 	
 	REP(i,N) REP(j,N) dist[i][j] = INF;
 	REP(i,N) dist[i][i] = 0.0;
 	REP(i,N) REP(j,N) if(graph[i][j] <= maxdist[i]) dist[i][j] = (double)graph[i][j] / speed[i];
 	REP(k,N) REP(i,N) REP(j,N) dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
 	
 	REP(i,Q) printf(" %.9f", dist[qu[i]][qv[i]]);
 	printf("\n");
 }
 
 ////////////////////////////////////////////////////////////////////////////////////////////////////
 
 int main(void){
 	int TC,tc;
 	cin >> TC;
 	REP(tc,TC){
 		printf("Case #%d:", tc + 1);
 		main2();
 	}
 	return 0;
 }
