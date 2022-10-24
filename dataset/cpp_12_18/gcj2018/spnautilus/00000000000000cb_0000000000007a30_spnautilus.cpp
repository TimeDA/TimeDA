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

void solve()
{
	cint1(A);
	constexpr int offset {100};
	constexpr int R {15};
	constexpr int C {14};

	const auto output = [offset] (int r, int c)
	{
		cout << r + offset << ' ' << c + offset << endl;
	};
	const auto in = [R, C] (int r, int c)
	{
		return 1 <= r and r <= R-2 and 1 <= c and c <= C-2;
	};

	enum class Phase {corner_tl, corner_tr, corner_bl, corner_br, inner};
	Phase state {Phase::corner_tl};
	int corner_count {4};
	int max_remain {9};
	array<array<bool,C>,R> prepared {};
	array<array<int,C>,R> unprepared_9;
	for(auto& row : unprepared_9) row.fill(9);

	array<set<PII>,10> class_cells;
	FOR(r,1,R-1) FOR(c,1,C-1) class_cells[9].emplace(r,c);

	while (true)
	{
		switch (state)
		{
		case Phase::corner_tl: output(1,1);     break;
		case Phase::corner_tr: output(1,C-2);   break;
		case Phase::corner_bl: output(R-2,1);   break;
		case Phase::corner_br: output(R-2,C-2); break;
		default:
			while (max_remain >= 0)
			{
				assert(max_remain > 0);
				auto bi = cbegin(class_cells[max_remain]);
				if (bi != cend(class_cells[max_remain]))
				{
					output(bi->_1, bi->_2);
					break;
				}
				--max_remain;
			}
			break;
		}

		cint2(r,c);
		if (r == 0) return; // passed sub test
		if (r == -1) exit(1); // failed test set
		r -= offset;
		c -= offset;

		const auto check_to_next =
			[r, c, &state, &corner_count, &prepared] (bool cond, Phase next)
		{
			if (cond and not prepared[r][c]) if (--corner_count == 0)
			{
				corner_count = 4;
				state = next;
			}
		};

		switch (state)
		{
		case Phase::corner_tl: check_to_next(r <= 1 and c <= 1, Phase::corner_tr);   break;
		case Phase::corner_tr: check_to_next(r <= 1 and c >= C-2, Phase::corner_bl); break;
		case Phase::corner_bl: check_to_next(r >= R-2 and c <= 1, Phase::corner_br); break;
		case Phase::corner_br: check_to_next(r >= R-2 and c >= C-2, Phase::inner);   break;
		default:
			break;
		}

		if (maxa(prepared[r][c], true))
		{
			FOR(dr,-1,2) FOR(dc,-1,2)
			{
				const auto rr = r + dr;
				const auto cc = c + dc;
				if (in(rr,cc))
				{
					auto& remain = unprepared_9[rr][cc];
					class_cells[remain].erase(class_cells[remain].find({rr,cc}));
					--remain;
					if (remain > 0) class_cells[remain].emplace(rr,cc);
				}
			}
		}
	}
}

int main()
{
	cint1(T);
	REP(T) solve();

	return 0; // correct!
}