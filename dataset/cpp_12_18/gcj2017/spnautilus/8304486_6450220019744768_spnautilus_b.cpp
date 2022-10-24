//spnauT
 #include <bits/stdc++.h>
 #define FOR(i,a,b) for(int _=b,i=a;i<_;++i)
 #define ROF(i,b,a) for(int _=a,i=b;i>_;--i)
 #define REP(n) for(int _=(n);_--;)
 #define _1 first
 #define _2 second
 #define PB push_back
 #define SZ(x) int((x).size())
 #define ALL(x) begin(x),end(x)
 #define MSET(m,v) memset(m,v,sizeof(m))
 #define MAX_PQ(T) priority_queue<T>
 #define MIN_PQ(T) priority_queue<T,vector<T>,greater<T>>
 #define IO {ios_base::sync_with_stdio(0);cin.tie(0);}
 #define nl '\n'
 #define cint1(a) int a;cin>>a
 #define cint2(a,b) int a,b;cin>>a>>b
 #define cint3(a,b,c) int a,b,c;cin>>a>>b>>c
 using namespace std;using LL=int64_t;using PII=pair<int,int>;
 using VI=vector<int>;using VL=vector<LL>;using VP=vector<PII>;
 template<class A,class B>bool mina(A&x,B&&y){return y<x?(x=forward<B>(y),1):0;}
 template<class A,class B>bool maxa(A&x,B&&y){return x<y?(x=forward<B>(y),1):0;}
 
 const int MAX_N {1004};
 const int MAX_M {2004};
 
 VP E[MAX_N];
 int A[MAX_M];
 int B[MAX_M];
 
 bool valid;
 bool VV[MAX_N];
 bool EV[MAX_M];
 int sol[MAX_M];
 
 int edge_to(int e)
 {
 	assert(e != 0);
 	if(e > 0) return B[e];
 	else return A[-e];
 }
 void add(int e)
 {
 	assert(e != 0);
 	if(e > 0) ++sol[e];
 	else --sol[-e];
 }
 
 VP stack_edge;
 
 void dfs(int u)
 {
 	// cout << "dfs " << u << endl;
 	VV[u] = true;
 	for(PII e: E[u])
 	{
 		int v, eid;
 		tie(v, eid) = e;
 
 		if(EV[abs(eid)]) continue;
 		EV[abs(eid)] = true;
 
 		// cout << "edge " << eid << " to " << v << endl;
 		if(not VV[v])
 		{
 			stack_edge.PB({u,eid});
 			dfs(v);
 			stack_edge.pop_back();
 		}
 		else
 		{
 			add(eid);
 			int p {SZ(stack_edge) - 1};
 			int x {u};
 			while(x != v)
 			{
 				assert(p >= 0);
 				tie(x, eid) = stack_edge[p--];
 				add(eid);
 			}
 		}
 	}
 }
 
 int main()
 {
 	IO;
 	cint1(TT);
 	FOR(T,1,TT+1)
 	{
 		cint2(N,M);
 		valid = true;
 		FOR(i,0,N)
 		{
 			E[i].clear();
 			VV[i] = false;
 		}
 
 		FOR(i,1,M+1)
 		{
 			cint2(a,b);
 			--a; --b;
 			E[a].PB({b,i});
 			E[b].PB({a,-i});
 			sol[i] = 0;
 			EV[i] = false;
 		}
 
 		if(valid)
 		{
 			FOR(i,0,N) if(not VV[i]) dfs(i);
 			FOR(i,1,M+1) if(sol[i] == 0) valid = false;
 			FOR(i,1,M+1) assert(-N*N <= sol[i] and sol[i] <= N*N);
 		}
 
 		cout << "Case #" << T << ":";
 		if(valid) FOR(i,1,M+1) cout << ' ' << sol[i];
 		else cout << " IMPOSSIBLE";
 		cout << endl;
 	}
 
 	return 0;
 }