// topcoder.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
 //
 
 #include <stdio.h>
 #include <tchar.h>
 #include <cstdio>
 #include <cstdlib>
 #include <cmath>
 #include <climits>
 #include <cfloat>
 #include <map>
 #include <utility>
 #include <set>
 #include <iostream>
 #include <memory>
 #include <string>
 #include <vector>
 #include <algorithm>
 #include <functional>
 #include <sstream>
 #include <complex>
 #include <stack>
 #include <queue>
 using namespace std;
 
 typedef long long ll;
 
 static const double EPS = 1e-9;
 inline int ROUND(double x) { return (int)(x+0.5); }
 inline bool ISINT(double x) { return fabs(ROUND(x)-x)<EPS; }
 inline bool ISEQUAL(double x,double y) { return fabs(x-y)<EPS; }
 template<class T> void amin(T &a, T v) { if (a > v) a = v; }
 template<class T> void amax(T &a, T v) { if (a < v) a = v; }
 #define INRANGE(x,a,b) ((a)<=(x)&&(x)<=(b))
 #define ARRAY_NUM(a) (sizeof(a)/sizeof(a[0])) 
 #define SZ(a) ((int)a.size())
 #define NG (-1)
 #define BIG (987654321)
 
 
 #if 1
 
 class Dinic
 {
 public:
 	Dinic(int input_maxv) : maxv(input_maxv)
 	{
 		G.resize(input_maxv);
 		level.resize(input_maxv);
 		iter.resize(input_maxv);
 	}
 
 	void add_edge_both(int from, int to, ll cap)
 	{
 		if(cap>0)
 		{
 			// BEGIN CUT HERE
 			cout << " from=" << from << " to=" << to << " cap=" << cap << endl;
 			// END CUT HERE
 
 
 			const int rev_from	= SZ(G[from]);
 			const int rev_to	= SZ(G[to]);
 			G[from].push_back(edge(to,cap,rev_to));
 			G[to].push_back(edge(from,cap,rev_from));
 		}
 	}
 
 	void add_edge(int from, int to, ll cap)
 	{
 		if(cap>0)
 		{
 			const int rev_from	= SZ(G[from]);
 			const int rev_to	= SZ(G[to]);
 			G[from].push_back(edge(to,cap,rev_to));
 			G[to].push_back(edge(from,0,rev_from));
 		}
 	}
 
 	// sからtへの最大流を求める
 	ll max_flow(int s, int t)
 	{
 		ll flow = 0;
 		for(;;)
 		{
 			bfs(s);
 			if(level[t]<0) break;
 			fill(iter.begin(),iter.end(),0);
 			ll f;
 			while( (f=dfs(s,t,DINIC_INF))>0)
 			{
 				flow += f;
 			}
 		}
 
 		return flow;
 	}
 
 	//  ノードsから辿れる範囲を求める（これ以上流せないところcap=0は、リンクがなくなる）
 	// （流し終わったあとsourceからたどれる範囲が、最小カット時のs側。たどれない法がt側。その境界がカットするところ。）
 	vector <bool> get_nodes_in_group(int s)
 	{
 		vector <bool> ret(maxv);
 
 		queue<int> que;
 		que.push(s);
 		while(!que.empty())
 		{
 			int v = que.front();
 			que.pop();
 			ret[v]=true;
 
 			for(int i=0;i<SZ(G[v]);i++)
 			{
 				edge &e = G[v][i];
 				if(e.cap>0 && !ret[e.to])
 				{
 					que.push(e.to);
 				}
 			}
 		}
 		return ret;
 	}
 
 	void disp()
 	{
 		for (int v = 0; v < maxv; v++)
 		{
 			printf("%d:",v);
 			for(int i=0;i<SZ(G[v]);i++)
 			{
 				if(G[v][i].init_cap>0)
 				{
 					printf("->%d(%lld),",G[v][i].to,G[v][i].init_cap);
 				}
 			}
 			printf("\n");
 		}
 	}
 
 private:
 	// sからの最短距離をBFSで計算する
 	void bfs(int s)
 	{
 		fill(level.begin(),level.end(),NG);
 		queue<int> que;
 		level[s]=0;
 		que.push(s);
 		while(!que.empty())
 		{
 			int v = que.front();
 			que.pop();
 			for(int i=0;i<SZ(G[v]);i++)
 			{
 				edge &e = G[v][i];
 				if(e.cap>0 && level[e.to]<0)
 				{
 					level[e.to] = level[v] + 1;
 					que.push(e.to);
 				}
 			}
 		}
 	}
 
 	// 増加パスをDFSで探す
 	ll dfs(int v, int t, ll f)
 	{
 		if(v==t) return f;
 		for (int &i=iter[v];i<SZ(G[v]);i++)
 		{
 			edge& e = G[v][i];
 			if(e.cap>0 && level[v]<level[e.to])
 			{
 				ll d = dfs(e.to, t, min(f, e.cap));
 				if(d>0)
 				{
 					e.cap -= d;
 					G[e.to][e.rev].cap += d;
 					return d;
 				}
 			}
 		}
 		return 0;
 	}
 
 	static const ll DINIC_INF = LLONG_MAX; // 容量をllにしたいときは、ここも変える
 
 	struct edge 
 	{
 		edge(int input_to, ll input_cap, int input_rev) : to(input_to), cap(input_cap), rev(input_rev), init_cap(input_cap) {}
 		int to;		// 行先
 		ll cap;	// 容量
 		int rev;	// 逆辺
 		ll init_cap; // 初期容量（デバッグ用）
 	};
 
 	int	maxv;
 	vector < vector <edge> > G;	// グラフの隣接リスト
 	vector < int > level;		// sからの距離
 	vector < int > iter;		// どこまで調べ終わったか
 };
 
 
 int main() {
 
 	freopen("_google_code_jam_input.txt","r",stdin);
 	freopen("_google_code_jam_output.txt","w",stdout);
 
 	int T;
 	scanf("%d",&T);
 
 	for (int testcase = 1; testcase<=T; ++testcase)
 	{
 		int W,H,B;
 		scanf("%d%d%d",&W,&H,&B);
 
 		vector < vector < int > > field(H,vector <int>(W,1));
 		for (int i = 0; i < B; ++i)
 		{
 			int x0, y0, x1, y1;
 			scanf("%d%d%d%d",&x0,&y0,&x1,&y1);
 			for (int y = y0; y <= y1; ++y)
 			{
 				for (int x = x0; x <= x1; ++x)
 				{
 					field[y][x]=0;
 				}
 			}
 		}
 
 		Dinic* p = new Dinic(2+H*W*2);
 
 		for (int y = 0; y < H; ++y)
 		{
 			for (int x = 0; x < W; ++x)
 			{
 				if(field[y][x])
 				{
 					int i = (y*W+x)*2;
 					int o = i+1;
 					p->add_edge(i,o,1);
 
 					const static int dy[] = {-1, 0, 1, 0}; // U,R,D,L
 					const static int dx[] = { 0, 1, 0,-1};
 					for(int d = 0; d < 4; ++d)
 					{
 						const int ny = y+dy[d]; 
 						const int nx = x+dx[d];
 						if(INRANGE(ny,0,SZ(field)-1)&&INRANGE(nx,0,SZ(field[y])-1)&&field[ny][nx]!=0)
 						{
 							int ni = (ny*W+nx)*2;
 							p->add_edge(o,ni,BIG);
 						}
 					}
 				}
 			}
 		}
 
 		int start = H*W*2;
 		int end   = start+1;
 
 		for (int x = 0; x < W; ++x)
 		{
 			p->add_edge(start,x*2,1);
 			p->add_edge(((H-1)*W+x)*2+1,end,BIG);
 		}
 
 		ll ans = p->max_flow(start, end);
 
 		fprintf(stderr,"Case #%d: %lld\n",testcase,ans);
 		printf("Case #%d: %lld\n",testcase,ans );
 
 		delete p;
 	}
 }
 
 #elif 1
 
 int main() {
 
 	freopen("_google_code_jam_input.txt","r",stdin);
 	freopen("_google_code_jam_output.txt","w",stdout);
 
 	int T;
 	scanf("%d",&T);
 
 	for (int testcase = 1; testcase<=T; ++testcase)
 	{
 		int M,N;
 		scanf("%d %d",&M,&N);
 
 		vector <string> vs;
 		for (int i = 0; i < M; ++i)
 		{
 			char str[10000];
 			scanf("%s",str);
 			vs.emplace_back(str);
 		}
 
 		map < vector < set < string > >, int > patterns;
 
 		for (ll i = 0; i < 1LL<<(M*2); ++i)
 		{
 			vector < set < string > > allservers(N);
 			for (int k = 0; k < M; ++k)
 			{
 				// サーバ番号
 				int no = 0;
 				if (i & (1LL<<(k*2+1))) no += 2;
 				if (i & (1LL<<(k*2))) no += 1;
 
 				if(no<N)
 				{
 
 					for (int x = 0; x <= SZ(vs[k]); ++x)
 					{
 						allservers[no].insert(vs[k].substr(0,x));
 					}
 				}
 			}
 
 			patterns[allservers]++;
 		}
 
 		ll best = 0;
 		for (auto& a: patterns)
 		{
 			const auto& allservers = a.first;
 			ll num = 0;
 			for (int i = 0; i < SZ(allservers); ++i)
 			{
 				num += SZ(allservers[i]);
 			}
 
 			best = max(best,(ll)num);
 		}
 
 		ll onaji = 0;
 		for (auto& a: patterns)
 		{
 			const auto& allservers = a.first;
 			ll num = 0;
 			for (int i = 0; i < SZ(allservers); ++i)
 			{
 				num += SZ(allservers[i]);
 			}
 
 			if(best==num)
 			{
 				onaji++;
 			}
 		}
 
 		onaji %= 1000000007LL;
 
 		fprintf(stderr,"Case #%d: %lld %lld\n",testcase,best,onaji);
 		printf("Case #%d: %lld %lld\n",testcase,best,onaji);
 	}
 }
 
 
 
 #elif 1
 #include <cstdio>
 #include <cstdlib>
 
 int segt[3000000];
 
 void add(int id,int lf,int rg,int plc) {
 	if(lf>plc||rg<plc) return;
 	if(lf==rg&&lf==plc) {
 		segt[id]=1;
 		return;
 	}
 	int hf=(lf+rg)/2;
 	add(id*2+1,lf,hf,plc);
 	add(id*2+2,hf+1,rg,plc);
 	segt[id]=segt[id*2+1]+segt[id*2+2];
 }
 
 int calc(int id,int lf,int rg,int callf,int calrg)
 {
 	if(lf>calrg||rg<callf) return 0;
 	if(callf<=lf&&calrg>=rg) return segt[id];
 	int hf=(lf+rg)/2;
 	return calc(id*2+1,lf,hf,callf,calrg)+calc(id*2+2,hf+1,rg,callf,calrg);
 }
 
 typedef struct 
 {
 	int vl;
 	int plc;
 }plts;
 
 plts plt[300000];
 
 int cmp(const void *ka,const void *kb) 
 {
 	plts *a=(plts *)ka;
 	plts *b=(plts *)kb;
 	if(a->vl!=b->vl) return b->vl-a->vl;
 	return a->plc-b->plc;
 }
 
 
 int main() {
 
 	freopen("_google_code_jam_input.txt","r",stdin);
 	freopen("_google_code_jam_output.txt","w",stdout);
 
 
 	int T;
 	scanf("%d",&T);
 
 	for (int testcase = 1; testcase<=T; ++testcase)
 	{
 		int N;
 		scanf("%d",&N);
 		memset(segt,0,sizeof(segt));
 		memset(plt,0,sizeof(plt));
 		for(int i=0;i<N;i++) 
 		{
 			scanf("%d",&plt[i].vl);
 			plt[i].plc=i+1;
 		}
 		qsort(plt,N,sizeof(plts),cmp);
 
 		ll ans=0;
 		int nw=0;
 		while(nw<N) 
 		{
 			int nvl=plt[nw].vl;
 			int nwb=nw;
 			while(nw<N) 
 			{
 				if(plt[nw].vl!=nvl) break;
 				ans+=min(calc(0,1,N,1,plt[nw].plc),calc(0,1,N,plt[nw].plc,N));
 				nw++;
 			}
 			while(nwb<nw) 
 			{
 				add(0,1,N,plt[nwb].plc);
 				nwb++;
 			}
 		}
 
 		fprintf(stderr,"Case #%d: %d\n",testcase,ans);
 		printf("Case #%d: %d\n",testcase,ans);
 	}
 
 	return 0;
 }
 
 
 #else
 
 class BipartiteMatching
 {
 public:
 	BipartiteMatching(int v) : V(v) 
 	{
 		init();
 	}
 
 	void init()
 	{
 		G.clear();
 		G.resize(V);
 		match.clear();
 		match.resize(V);
 		used.clear();
 		used.resize(V);
 	}
 
 	void add_edge(int u, int v)
 	{
 		G[u].push_back(v);
 		G[v].push_back(u);
 	}
 
 	int run()
 	{
 		int res=0;
 		fill(match.begin(),match.end(),-1);
 		for(int v=0;v<V;v++)
 		{
 			if(match[v]<0)
 			{
 				fill(used.begin(),used.end(),false);
 				if(dfs(v))
 				{
 					res++;
 				}
 			}
 		}
 
 		return res;
 	}
 
 private:
 	const int V;
 	vector < vector <int> > G;
 	vector <int> match;
 	vector <bool> used;
 
 
 	bool dfs(int v)
 	{
 		used[v]=true;
 		for(int i=0;i<SZ(G[v]);i++)
 		{
 			int u=G[v][i];
 			int w=match[u];
 			if(w<0||!used[w]&&dfs(w))
 			{
 				match[v]=u;
 				match[u]=v;
 				return true;
 			}
 		}
 		return false;
 	}
 };
 
 int main(){
 
 	freopen("_google_code_jam_input.txt","r",stdin);
 	freopen("_google_code_jam_output.txt","w",stdout);
 
 	
 	int T;
 	scanf("%d",&T);
 
 	for (int testcase = 1; testcase<=T; ++testcase)
 	{
 		int N, X;
 		scanf("%d %d",&N,&X);
 
 		vector <int> s(N);
 		for (int i = 0; i < N; ++i)
 		{
 			scanf("%d",&s[i]);
 		}
 
 		sort(s.begin(),s.end());
 
 		int i = 0;
 		int k = N-1;
 
 		int ans = N;
 		while(i<k)
 		{
 			if(s[i]+s[k]<=X)
 			{
 				ans--;
 				i++;
 				k--;
 			}
 			else
 			{
 				k--;
 			}
 		}
 
 		fprintf(stderr,"Case #%d: %d\n",testcase,ans);
 		printf("Case #%d: %d\n",testcase,ans);
 	}
 }
 
 #endif