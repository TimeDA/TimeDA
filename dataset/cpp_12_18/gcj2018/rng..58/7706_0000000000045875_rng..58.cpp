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

typedef int F;
#define F_INF (1<<29)
#define MAXV 210
#define MAXE 100000 // E*2!

F cap[MAXE],flow[MAXE];
int to[MAXE],_prev[MAXE],last[MAXV],used[MAXV],level[MAXV];

struct MaxFlow{
	int V,E;

	MaxFlow(int n){
		int i;
		V = n; E = 0;
		REP(i,V) last[i] = -1;
	}

	void add_edge(int x, int y, F f){
		cap[E] = f; flow[E] = 0; to[E] = y; _prev[E] = last[x]; last[x] = E; E++;
		cap[E] = 0; flow[E] = 0; to[E] = x; _prev[E] = last[y]; last[y] = E; E++;
	}

	bool bfs(int s, int t){
		int i;
		REP(i,V) level[i] = -1;
		queue <int> q;
		q.push(s); level[s] = 0;
		while(!q.empty()){
			int x = q.front(); q.pop();
			for(i=last[x];i>=0;i=_prev[i]) if(level[to[i]] == -1 && cap[i] > flow[i]) {q.push(to[i]); level[to[i]] = level[x] + 1;}
		}
		return (level[t] != -1);
	}

	F dfs(int v, int t, F f){
		int i;
		if(v == t) return f;
		for(i=used[v];i>=0;used[v]=i=_prev[i]) if(level[to[i]] > level[v] && cap[i] > flow[i]){
			F tmp = dfs(to[i],t,min(f,cap[i]-flow[i]));
			if(tmp > 0) {flow[i] += tmp; flow[i^1] -= tmp; return tmp;}
		}
		return 0;
	}

	F maxflow(int s, int t){
		int i;
		while(bfs(s,t)){
			REP(i,V) used[i] = last[i];
			while(dfs(s,t,F_INF) != 0);
		}
		F ans = 0;
		for(i=last[s];i>=0;i=_prev[i]) ans += flow[i];
		return ans;
	}

};
	
int color[110][110];
	
void main2(void){
	int N,i,j;
	
	cin >> N;
	REP(i,N) REP(j,N) scanf("%d", &color[i][j]);
	
	int keep = 0;
	for(int c=-N;c<=N;c++){
		MaxFlow mf(2*N+2);
		REP(i,N) mf.add_edge(2*N, i, 1);
		REP(i,N) mf.add_edge(N+i, 2*N+1, 1);
		REP(i,N) REP(j,N) if(color[i][j] == c) mf.add_edge(i, N+j, 1);
		keep += mf.maxflow(2*N, 2*N+1);
	}
	
	cout << N * N - keep << endl;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main(void){
	int TC,tc;
	cin >> TC;
	REP(tc,TC){
		printf("Case #%d: ", tc + 1);
		main2();
	}
	return 0;
}
