
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
 
 const int START = 0;
 const int GOAL = 1;
 const int INF = 1050000000;
 
 int nNodes;
 int nEdges;
 int nPath;
 
 struct Edge {
   int id;
   int a, b;
   int lb, ub;
 };
 
 struct E {
   int pos;
   int cost;
 };
 bool operator>(const E& a, const E& b) {
   return a.cost > b.cost;
 }
 
 Edge edges[2010];
 int paths[600];
 bool used[2010];
 vector<int> g[2010];
 
 
 int dist[2010];
 int worst[2010];
 bool visited[2010];
 int trace[2010];
 
 int main(void) {
   int nCases;
   scanf("%d", &nCases);
   REP(iCase, nCases) {
     scanf("%d%d%d", &nNodes, &nEdges, &nPath);
     REP(i, nNodes)
       g[i].clear();
     REP(iEdge, nEdges){
       Edge& e = edges[iEdge];
       e.id = iEdge;
       scanf("%d%d%d%d", &e.a, &e.b, &e.lb, &e.ub);
       e.a--;
       e.b--;
       g[e.a].push_back(e.id);
     }
     
     REP(iPath, nPath){
       scanf("%d", &paths[iPath]);
       paths[iPath]--;
     }
     
     int ans = -1;
     REP(iPath, nPath){
       int cost1, cost2;
       priority_queue<E, vector<E>, greater<E> > q;
       int iniCost = 0;
       int iniNode = START;
       memset(used, 0, sizeof used);
       REP(i, iPath+1){
 	used[paths[i]] = true;
 	iniCost += edges[paths[i]].lb;
 	iniNode = edges[paths[i]].b;
       }
 
       fill(worst, worst + nNodes, INF);
       memset(visited, 0, sizeof visited);
       q.push((E){START, 0});
       worst[START] = 0;
       while(!q.empty()){
 	E cur = q.top(); q.pop();
 	if(visited[cur.pos])
 	  continue;
 	visited[cur.pos] = true;
 	REP(i, g[cur.pos].size()){
 	  const Edge& e = edges[g[cur.pos][i]];
 	  int cost = used[e.id] ? e.lb : e.ub;
 	  if(!visited[e.b] && worst[cur.pos] + cost < worst[e.b]) {
 	    worst[e.b] = worst[cur.pos] + cost;
 	    trace[e.b] = e.id;
 	    q.push((E){e.b, worst[e.b]});
 	  }
 	}
       }
 //       cost1 = dist[GOAL];
       
       q = priority_queue<E, vector<E>, greater<E> >();
       fill(dist, dist + nNodes, INF);
       memset(visited, 0, sizeof visited);
       q.push((E){iniNode, iniCost});
       dist[iniNode] = iniCost;
       bool ok = false;
       while(!q.empty()){
 	E cur = q.top(); q.pop();
 	if(visited[cur.pos])
 	  continue;
 	visited[cur.pos] = true;
 	cerr << cur.pos << " : " << worst[cur.pos] << " " <<  dist[cur.pos] << endl;
 	if(worst[cur.pos] < dist[cur.pos])
 	  continue;
 	if(cur.pos == GOAL){
 	  ok = true;
 	  break;
 	}
 	REP(i, g[cur.pos].size()){
 	  const Edge& e = edges[g[cur.pos][i]];
 	  int cost = e.lb;
 	  if(!visited[e.b] && dist[cur.pos] + cost < dist[e.b]){
 	    dist[e.b] = dist[cur.pos] + cost;
 	    q.push((E){e.b, dist[e.b]});
 	  }
 	}
       }
       if(!ok){
 	ans = iPath;
 	break;
       }
     }
     
     cout << "Case #" << (iCase+1) << ": ";
     if(ans < 0){
       cout << "Looks Good To Me" << endl;
     }else{
       cout << paths[ans]+1 << endl;
     }
     cerr << endl;
   }
   
   return 0;
 }
