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

const int MAX_N {};

int main()
{
	IO;
	cint(TT);
	FOR(T, 1, TT + 1)
	{
		cint(C);
		VI A(C);
		FOR(i, 0, C) cin >> A[i];

		cout << "Case #" << T << ": ";
		if (A.front() * A.back() == 0)
			cout << "IMPOSSIBLE" << nl;
		else
		{
			vector<string> sol;

			const VI goal(C, 1);
			while (A != goal)
			{
				string s(C, '.');
				VI B {A};
				int sum {0};
				FOR(i, 0, C)
				{
					sum += B[i];
					const int diff = sum - (i + 1);
					if (diff > 0)
					{
						s[i + 1] = '/';
						--A[i];
						++A[i + 1];
					}
					else if (diff < 0)
					{
						s[i] = '\\';
						++A[i];
						--A[i + 1];
					}
				}

				sol.EB(move(s));
			}

			sol.EB(C, '.');
			cout << SZ(sol) << nl;
			for (auto& s : sol) cout << s << nl;
		}
	}

	return 0;
}