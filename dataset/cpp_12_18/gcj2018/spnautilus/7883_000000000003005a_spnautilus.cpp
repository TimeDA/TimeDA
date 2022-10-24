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

const int MAX_N {104};

array<string,MAX_N> S;
array<array<int,MAX_N>,MAX_N> sum;

bool possible() noexcept
{
	cint2(R,C);
	cint2(H,V);

	FOR(i,0,R) cin >> S[i];

	FOR(i,0,R)
	{
		FOR(j,0,C) sum[i+1][j+1] = sum[i+1][j] + (S[i][j] == '@');
		FOR(j,0,C) sum[i+1][j+1] += sum[i][j+1];
	}

	const auto total = sum[R][C];
	if (total == 0) return true;

	const auto diners = (H + 1) * (V + 1);
	if (total % diners) return false;

	const auto needed_each = total / diners;
//	cerr << needed_each << nl;

//	FOR(i,0,R+1)
//	{
//		FOR(j,0,C+1) cerr << sum[i][j] << ' ';
//		cerr << nl;
//	}

	VI H_cuts {0};
	{
		const auto needed = needed_each * (V + 1);
		int curr {0};
		FOR(i,1,R+1)
		{
			curr += sum[i][C] - sum[i-1][C];
//			cerr << i << " -> " << curr << nl;
			if (curr > needed)
			{
				return false;
			}
			else if (curr == needed)
			{
				curr = 0;
				H_cuts.EB(i);
//				cerr << "H - " << i << nl;
			}
		}
//		cerr << "H sz " << SZ(H_cuts) << nl;
		if (curr != 0 or SZ(H_cuts) != H + 2) return false;
	}

	VI V_cuts {0};
	{
		const auto needed = needed_each * (H + 1);
		int curr {0};
		FOR(j,1,C+1)
		{
			curr += sum[R][j] - sum[R][j-1];
			if (curr > needed)
			{
				return false;
			}
			else if (curr == needed)
			{
				curr = 0;
				V_cuts.EB(j);
//				cerr << "V - " << j << nl;
			}
		}
		if (curr != 0 or SZ(V_cuts) != V + 2) return false;
	}

	const auto calc = [&](int r1, int c1, int r2, int c2) noexcept
	{
		return sum[r2][c2] + sum[r1][c1] - sum[r1][c2] - sum[r2][c1];
	};

	FOR(i,1,H+1) FOR(j,1,V+1)
		if (calc(H_cuts[i-1], V_cuts[j-1], H_cuts[i], V_cuts[j]) != needed_each)
			return false;

	return true;
}

int main()
{
	IO;
	cint1(TT);
	FOR(T,1,TT+1)
	{
		cout << "Case #" << T << ": ";
		if (not possible()) cout << "IM";
		cout << "POSSIBLE" << nl;
	}

	return 0;
}
