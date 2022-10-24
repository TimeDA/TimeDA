//spnauT14
#ifndef SPNAUT
#include<bits/stdc++.h>
#else
#include<spnaut>
#endif
#define FOR(i,a,b)for(int i##_=(b),i=(a);i<i##_;++i)
#define ROF(i,b,a)for(int i##_=(a),i=(b);i>i##_;--i)
#define REP2(a,b)a##b
#define REP1(n,c)for(int REP2(rep_,c)=n;REP2(rep_,c)--;)
#define REP(n)REP1((n),__COUNTER__)
#define _1 first
#define _2 second
#define PB push_back
#define EB emplace_back
#define SZ(x)int((x).size())
#define ALL(x)begin(x),end(x)
#define MSET(m,v)memset(m,v,sizeof(m))
#define MAX_PQ(T)priority_queue<T>
#define MIN_PQ(T)priority_queue<T,vector<T>,greater<>>
#define IO do{ios_base::sync_with_stdio(0);cin.tie(nullptr);}while(0)
#define cint(...)cintype(int,__VA_ARGS__)
#define cintype(T,...)T __VA_ARGS__;cinln(__VA_ARGS__)
using namespace std;constexpr char nl{'\n'};using PII=pair<int,int>;
using LL=int64_t;using VI=vector<int>;using VL=vector<LL>;using VP=vector<PII>;
template<class A,class B>bool mina(A&x,B&&y){return y<x?x=forward<B>(y),1:0;}
template<class A,class B>bool maxa(A&x,B&&y){return x<y?x=forward<B>(y),1:0;}
void coutln1(int){}template<class B,class...A>void coutln1(int n,B&& b,A&&...a)
{(n?(cout<<' '):cout)<<b;coutln1(1,forward<A>(a)...);}template<class...A>
void coutln(A&&...a){coutln1(0,forward<A>(a)...);cout<<nl;}void cinln(){}
template<class B,class...A> void cinln(B& b,A&...a){cin>>b;cinln(a...);}

class BipartiteGraph1
{
private:
	int U, V, N, M;
	int en, rit;
	vector<VI> E;
	VI eu, dep, Q, S;
	VI ea, eb, vst;

	int dfs(int x)
	{
		if(eu[x] == -1 && x < U) return 1;
		vst[x] = rit;
		static int y;

		if(x >= U) { // x in V
			for(int e: E[x]) if(e != eu[x]) {
				y = ea[e];
				if(vst[y] == rit-1 && dep[y] == dep[x]-1 && dfs(y)) {
					eu[x] = eu[ea[e]] = e; return 1;
				}
			}
		} else { // x in U and eu[x] != -1
			y = eb[eu[x]];
			if(vst[y] == rit-1 && dep[y] == dep[x]-1 && dfs(y)) return 1;
		}
		return 0;
	}

#define FG3_C1(e) {int y = adj((e), x); if(vst[y] != rit) {vst[y] = rit; dep[y] = dep[x] + 1; Q[tail++] = y;}}

	int bfs()
	{
		++rit;
		int sn = 0;
		int head = 0, tail = 0;
		FOR(i,0,U) if(eu[i] == -1)
		{
			dep[i] = 0;
			vst[i] = rit;
			Q[tail++] = i;
		}
		while(head < tail)
		{
			int x = Q[head];
			if(eu[x] == -1 && x >= U)
			{
				FOR(i,head,tail) if(eu[Q[i]] == -1) S[sn++] = Q[i];
				break;
			}
			++head;
			if(x < U)
			{
				for(int e: E[x]) if(e != eu[x]) FG3_C1(e)
			}
			else FG3_C1(eu[x]) // x in V and eu[x] != -1
		}
		return sn;
	}

public:
	BipartiteGraph1(int u, int v, int m)
	{
		U = u; V = v; N = u+v; M = m; en = 0, rit = 0;
		E.resize(N); eu.resize(N, -1); ea.resize(m); eb.resize(m);
		vst.resize(N, 0); dep.resize(N); Q.resize(N); S.resize(v);
	}
	int adj(int e, int a) const {return a ^ ea[e] ^ eb[e];}
	void addEdge(int a, int b)
	{
		E[a].PB(en);
		E[b+U].PB(en);
		ea[en] = a;
		eb[en] = b+U;
		++en;
	}
	int matching()
	{
		int res = 0, sn;
		while((sn = bfs()) > 0)
		{
			++rit;
			FOR(i,0,sn) res += dfs(S[i]);
		}
		return res;
	}
	VP getPairs()
	{
		int n = 0;
		FOR(i,0,U) n += eu[i] != -1;
		VP P(n);
		n = 0;
		FOR(i,0,U) if(eu[i] != -1) P[n++] = PII(i, adj(eu[i], i)-U);
		return P;
	}
};

const int MAX_N {};

int main()
{
	IO;
	cint(TT);
	FOR(T, 1, TT + 1)
	{
		cint(N);
		vector<VP> costumes(2 * N);
		FOR(i, 0, N) FOR(j, 0, N)
		{
			cint(a);
			costumes[(a > 0) ? (a - 1) : (-a - 1 + N)].EB(i, j);
		}

		int sol {N * N};
		for (const auto& dancers : costumes)
		{
			BipartiteGraph1 G {N, N, SZ(dancers)};
			for (const auto p : dancers)
				G.addEdge(p._1, p._2);
			sol -= G.matching();
		}

		cout << "Case #" << T << ": " << sol << nl;
	}

	return 0;
}