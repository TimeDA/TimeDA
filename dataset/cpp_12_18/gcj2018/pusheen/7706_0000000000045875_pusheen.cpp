#include<stdio.h>
#include<math.h>
#include<algorithm>
// Copyright pusheen 2018
#include<queue>
#include<stdio.h>
typedef long long LL;
struct FLOWGRAPH {
	struct edge {
		int to, rev;
		int c, f; // capacity, residual
	};
	int N;
	enum {MAXN=5001};
	std::vector<edge> G[MAXN];
	void init(int NN){
		N=NN;
		for(int i=0; i<N; i++)
			G[i].clear();
	}
	int addedge(int A, int B, int C){
		G[A].push_back((edge){B, G[B].size(), C, C});
		G[B].push_back((edge){A, G[A].size()-1, 0, 0});
		return G[B].back().rev;
	}
};
struct DINICFLOW:FLOWGRAPH {
	int S,T,lev[MAXN],nxt[MAXN],scal;
	enum {soo=1LL<<60};
	void init(int N,int S=0,int T=-1,LL SC=1){
		this->S=(N+S)%N;
		this->T=(N+T)%N;
		scal=SC;
		FLOWGRAPH::init(N);
	}
	LL flood(int scal=1){
		LL flow=0;
		for(int r=scal;r&&r!=!BFS(r);){
			std::fill(nxt,nxt+N,0);
			LL get=DFS(S);
			if (!get) r>>=1;
			else flow+=get;
		}
		return flow;
	}
protected:
	bool BFS(int r=1){
		std::fill(lev,lev+N,-1);
		std::queue<int> q;
		lev[S]=0, q.push(S);
		while(q.size()){
			int i=q.front();
			q.pop();
			for(int j=0; j<(int)G[i].size(); j++)
				if(G[i][j].f>=r && lev[G[i][j].to]==-1)
					lev[G[i][j].to]=lev[i]+1, q.push(G[i][j].to);
		}
		return lev[T]!=-1;
	}
	LL DFS(int i, LL all=soo){
		if(i==T) return all;
		LL rem=all;
		for(; nxt[i]<(int)G[i].size(); nxt[i]++){
			edge &e=G[i][nxt[i]];
			if(e.f&&lev[i]<lev[e.to]){
				LL add=DFS(e.to, std::min(rem, (LL)e.f));
				e.f-=add; G[e.to][e.rev].f+=add;
				rem-=add;
				if(!rem) break;
			}
		}
		return all-rem;
	}
};
int a[501][501];
int solve(){
	int n,m;
	scanf("%d",&n);
	
	// NO RETURN / continue BEFORE input DONE
	
	int i,j,k;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%d",&a[i][j]);
		}
	}
	m=1<<(n*n);
	int best=n*n;
	static int row[101][201], col[101][201];
	for(int s=0;s<m;s++){
		for(j=0;j<n;j++){
			for(i=0;i<=n+n;i++){
				row[j][i]=0;
				col[j][i]=0;
			}
		}
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				if(s&(1<<(i*n+j))){
					row[i][a[i][j]+n]++;
					col[j][a[i][j]+n]++;
				}
			}
		}
		for(j=0;j<n;j++){
			for(i=0;i<=n+n;i++){
				if(col[j][i]>1||row[j][i]>1) break;
			}
			if(i<=n+n) break;
		}
		if(j>=n){
			best=std::min(best, n*n-__builtin_popcount(s));
		}
	}
	return best;
	
	/*static DINICFLOW f;
	f.init(4*n+2);
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			f.addedge(1+i, a[i][j] > 0 ? 1+n+n+(a[i][j]-1) : 1+n+n+n+(-a[i][j]-1), 1);
			f.addedge(a[i][j] > 0 ? 1+n+n+(a[i][j]-1) : 1+n+n+n+(-a[i][j]-1), 1+n+j, 1);
			
		}
	}
	for(i=0;i<n;i++){
		f.addedge(0, 1+i, 1);
	}
	for(j=0;j<n;j++){
		f.addedge(1+n+j, 4*n+1, 1);
	}
	
	return f.flood();*/
	
}
int main(){
	int T,TN;
	scanf("%d",&TN);
	for(T=1;T<=TN;T++){
		printf("Case #%d: ", T);
		printf("%d\n",solve());
	}
}