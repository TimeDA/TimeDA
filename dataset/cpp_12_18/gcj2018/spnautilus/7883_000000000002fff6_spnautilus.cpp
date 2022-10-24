//spnauT17
#ifndef SPNAUT
#include<bits/stdc++.h>
#else
#include<spnaut>
#endif
#define FOR(i,a,b)for(int i##_=(b),i=(a);i<i##_;++i)
#define ROF(i,b,a)for(int i##_=(a),i=(b);i>i##_;--i)
#define REP2(a,b) a##b
#define REP1(a,b) REP2(a,b)
#define REP(n)for(int REP1(rep_,__LINE__)=(n);REP1(rep_,__LINE__)--;)
#define _1 first
#define _2 second
#define PB push_back
#define EB emplace_back
#define SZ(x)static_cast<int>((x).size())
#define ALL(x)begin(x),end(x)
#define MSET(m,v)memset(m,v,sizeof(m))
#define MAX_PQ(T)priority_queue<T>
#define MIN_PQ(T)priority_queue<T,vector<T>,greater<T>>
#define IO {ios_base::sync_with_stdio(false);cin.tie(nullptr);}
#define cint1(a)int a;cin>>a
#define cint2(a,b)int a,b;cin>>a>>b
#define cint3(a,b,c)int a,b,c;cin>>a>>b>>c
constexpr char nl {'\n'};
using namespace std;using LL=int64_t;using PII=pair<int,int>;
using VI=vector<int>;using VL=vector<LL>;using VP=vector<PII>;
template<class A,class B>bool mina(A&x,B&&y){return y<x?(x=forward<B>(y),1):0;}
template<class A,class B>bool maxa(A&x,B&&y){return x<y?(x=forward<B>(y),1):0;}

constexpr int MAX_N {1004};

struct Cashier
{
	LL m, s, p;
	constexpr Cashier(LL m_, LL s_, int p_) noexcept : m{m_}, s{s_}, p{p_} {}
};

LL solve() noexcept
{
	cint3(R,B,C);

	vector<Cashier> cashiers;
	cashiers.reserve(C);
	FOR(i,0,C)
	{
		cint3(m,s,p);
		cashiers.EB(m,s,p);
	}

	const auto possible = [&cashiers, R, B, C](LL x) noexcept->bool
	{
		VI max_bits;
		max_bits.reserve(C);

		for (const auto& c: cashiers)
		{
			if (c.s + c.p > x) continue;
			LL num {min<LL>(c.m, (x - c.p) / c.s)};
//			cerr << "+" << num << nl;
			max_bits.PB(static_cast<int>(num));
		}

//		cerr << "# " << SZ(max_bits) << nl;

		sort(ALL(max_bits), greater<int>());
		LL sum {0};
		FOR(i,0,min(R,SZ(max_bits))) sum += max_bits[i];
		return sum >= B;
	};

	LL lo {2};
	LL hi {1LL << 61}; 
	LL sol {hi};

	while (lo <= hi)
	{
		const auto mid = (lo + hi) / 2;
		const auto res = possible(mid);
//		cerr << "res " << mid << " : " << res << nl;
		if (res)
		{
			sol = mid;
			hi = mid - 1;
		}
		else lo = mid + 1;
	}

	return sol;
}

int main()
{
	IO;
	cint1(TT);
	FOR(T,1,TT+1)
	{
		const auto sol = solve();
		cout << "Case #" << T << ": " << sol << nl;
	}

	return 0;
}
