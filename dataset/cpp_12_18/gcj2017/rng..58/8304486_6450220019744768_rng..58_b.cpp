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
 
 int N,M;
 int a[2010],b[2010],c[2010];
 vector <pair <int, pair <int, int> > > graph[2010]; // to, id, rev?
 
 int depth[2010];
 bool vis[2010];
 vector <pair <int, int> > forest;
 
 bool f_edge[2010];
 
 void construct(void){
 	int i,j;
 	int F = forest.size();
 	
 	REP(i,M) f_edge[i] = false;
 	REP(i,F) f_edge[forest[i].first] = true;
 	
 	REP(i,M) if(!f_edge[i]){
 		if(depth[a[i]] < depth[b[i]]){
 			c[i] = -1;
 		} else {
 			c[i] = 1;
 		}
 	}
 	
 	for(i=F-1;i>=0;i--){
 		int id = forest[i].first;
 		int rev = forest[i].second;
 		
 	//	cerr << "forest: " << id << ' ' << rev << endl;
 		
 		int p = a[id];
 		int q = b[id];
 		if(rev) swap(p, q);
 		
 		int q_in = 0, q_out = 0;
 		REP(j,M){
 			if(a[j] == q) q_out += c[j];
 			if(b[j] == q) q_in += c[j];
 		}
 		
 		int tmp = q_out - q_in;
 		if(rev) tmp = -tmp;
 		c[id] = tmp;
 	}
 }
 
 void dfs(int x, int d){ // cerr << "dfs: " << x << ' ' << d << endl;
 	int i;
 	
 	vis[x] = true;
 	depth[x] = d;
 	
 	REP(i,graph[x].size()){
 		int y = graph[x][i].first;
 		int id = graph[x][i].second.first;
 		int rev = graph[x][i].second.second;
 		
 		if(!vis[y]){
 			forest.push_back(make_pair(id, rev));
 			dfs(y, d+1);
 		}
 	}
 }
 
 void main2(void){
 	int i;
 	
 	cin >> N >> M;
 	REP(i,M){
 		cin >> a[i] >> b[i];
 		a[i]--; b[i]--;
 	}
 	
 	REP(i,M) c[i] = 0;
 	
 	REP(i,N) graph[i].clear();
 	REP(i,M){
 		graph[a[i]].push_back(make_pair(b[i], make_pair(i, 0)));
 		graph[b[i]].push_back(make_pair(a[i], make_pair(i, 1)));
 	}
 	
 	REP(i,N) vis[i] = false;
 	REP(i,N) depth[i] = 0;
 	forest.clear();
 	REP(i,N) if(!vis[i]) dfs(i, 0);
 	
 	construct();
 	
 	bool good = true;
 	REP(i,M) if(c[i] == 0) good = false;
 	
 	if(good){
 		REP(i,M) cout << ' ' << c[i];
 		cout << endl;
 	} else {
 		cout << " IMPOSSIBLE" << endl;
 	}
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
