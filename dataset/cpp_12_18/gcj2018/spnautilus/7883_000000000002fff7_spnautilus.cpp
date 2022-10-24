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

using LD = long double;
constexpr int MAX_N {104};

template <typename T>
class IntervalSet
{
public:
	typedef pair<T,T> PT;
	set <PT> S;
	T eps, total;

	IntervalSet(T e) {init(e);}
	IntervalSet(T e, set<PT> &s) {init(e); for(PT p: s) add(p);}
	IntervalSet(T e, vector<PT> s) {init(e); for(PT p: s) add(p);}

private:
	void init(T e) {eps = e; total = 0;}
	void add1(PT p) {T l = p._2 - p._1; total += l; S.insert(p);}
	void remove1(PT p) {T l = p._2 - p._1; total -= l; S.erase(p);}
	PT unionOverlap(PT a, PT b) {return PT(min<T>(a._1, b._1), max<T>(a._2, b._2));}

public:
	void add(PT p)
	{
		assert(p._1 <= p._2);
		if(!S.empty())
		{
			auto sa = S.lower_bound(PT(p._1-eps, p._1-eps));
			if(sa != S.begin())
			{
				auto sa1 = sa; --sa1;
				if(sa1->_2 + eps >= p._1) --sa;
			}
			auto sb = S.lower_bound(PT(p._2+eps, p._2+eps));
			if(sb != S.end() && sb->_1 <= p._2+eps) ++sb;

			for(auto si = sa; si != sb; )
			{
				PT p1 = *si; ++si;
				p = unionOverlap(p, p1);
				remove1(p1);
			}
		}
		add1(p);
	}

	void subtract(PT p)
	{
		assert(p._1 <= p._2);
		if(!S.empty())
		{
			PT p0 = p;
			auto sa = S.lower_bound(PT(p._1, p._1));
			if(sa != S.begin())
			{
				auto sa1 = sa; --sa1;
				if(sa1->_2 >= p._1) --sa;
			}
			auto sb = S.lower_bound(PT(p._2, p._2));
			if(sb != S.end() && sb->_1 <= p._2) ++sb;

			for(auto si = sa; si != sb; )
			{
				PT p1 = *si; ++si;
				p = unionOverlap(p, p1);
				remove1(p1);
			}
			if(p._1 < p0._1) add1(PT(p._1, p0._1));
			if(p0._2 < p._2) add1(PT(p0._2, p._2));
		}
	}

	void clear()
	{
		S.clear();
		total = 0;
	}

	T totalLength() const {return total;}
};

LD solve() noexcept
{
	cint2(N,P);
	using T3 = tuple<int,int,double>;
	vector<T3> cookies;
	int P0 {0};
	cookies.reserve(N);
	REP(N)
	{
		cint2(a,b);
		if (a > b) swap(a,b);
		cookies.EB(a, b, sqrt(a*a + b*b) / a);
		const auto perim = 2 * (a + b);
		P -= perim;
		P0 += perim;
	}
	sort(ALL(cookies), [](const T3& x, const T3& y)
	{
		return get<2>(x) > get<2>(y);
	});

	IntervalSet<LD> curr {1e-8};
	curr.add({0,0});
	for (const auto& t: cookies)
	{
		int a, b;
		tie(a,b,ignore) = t;
		const LD min_cut {static_cast<LD>(2 * a)};
		const LD max_cut {2 * sqrtl(a * a + b * b)};

		const auto temp = curr;
		for (const auto p : temp.S)
		{
			const auto y = min<LD>(P, p._2 + max_cut);
			const auto x = p._1 + min_cut;

			if (x - 1e-8 < P) curr.add({x, y});
			if (y + 1e-8 > P) break;
		}
//		curr.subtract({P, 1e20});
	}

	assert(SZ(curr.S) > 0);
	return (--curr.S.end())->_2 + P0;
}

int main()
{
	IO;
	cint1(TT);
	cout << fixed << setprecision(9);
	FOR(T,1,TT+1)
	{
		const auto sol = solve();
		cout << "Case #" << T << ": " << sol << nl;
	}

	return 0;
}
