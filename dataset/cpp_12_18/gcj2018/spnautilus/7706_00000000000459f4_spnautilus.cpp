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

int main()
{
	IO;
	cint(TT);
	FOR(T, 1, TT + 1)
	{
		cint(R, C);
		vector<string> B(R);
		FOR(i, 0, R) cin >> B[i];

		int sol {0};
		FOR(rn, 1, 3) FOR(cn, 1, 3)
		{
			const int sz {rn * cn};
			vector<string> X(rn, string(cn, ' '));
			FOR(bit, 0, 1 << sz)
			{
				static constexpr array<char, 2> colors {'B', 'W'};

				FOR(i, 0, sz) X[i / cn][i % cn] = colors[(bit >> i) & 1];
				const auto found_pattern = [&]() noexcept -> bool
				{
					FOR(r, 0, R - rn + 1) FOR(c, 0, C - cn + 1)
					{
						const auto found_sub = [&]() noexcept -> bool
						{
							FOR(rr, 0, rn) FOR(cc, 0, cn)
							{
								if (B[r + rr][c + cc] != X[rr][cc])
									return false;
							}
							return true;
						}();
						if (found_sub) return true;
					}
					return false;
				}();

				if (found_pattern)
				{
					vector<VI> G(R, VI(C));
					const auto check_G = [&]() noexcept
					{
						static constexpr array<PII, 4> D {PII {0, 1}, {1, 0}, {0, -1}, {-1, 0}};
						queue<PII> Q;
						const auto push = [&](int r, int c) noexcept
						{
							if (r >= 0 and r < R and c >= 0 and c < C and mina(G[r][c], 0))
								Q.emplace(r, c);
						};
						FOR(i, 0, R) FOR(j, 0, C) if (G[i][j])
						{
							push(i, j);
							int res {0};
							while (not Q.empty())
							{
								int r, c;
								tie(r, c) = Q.front();
								Q.pop();
								++res;
								for (auto d : D) push(r + d._1, c + d._2);
							}

							maxa(sol, res);
						}
					};

					const int r1_min {(rn == 2) ? (1) : (R)};
					const int r1_max {(rn == 2) ? (R) : (R + 1)};
					const int c1_min {(cn == 2) ? (1) : (C)};
					const int c1_max {(cn == 2) ? (C) : (C + 1)};

					FOR(r1, r1_min, r1_max) FOR(c1, c1_min, c1_max)
					{
						FOR(i, 0, R) FOR(j, 0, C) G[i][j] = B[i][j] == X[i >= r1][j >= c1];
						check_G();
					}
				}
			}
		}

		cout << "Case #" << T << ": " << sol << nl;
	}

	return 0;
}