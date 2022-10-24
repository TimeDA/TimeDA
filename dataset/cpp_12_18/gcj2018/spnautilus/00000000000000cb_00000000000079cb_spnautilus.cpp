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


const int MAX_N {};

int main()
{
	IO;
	cint1(TT);
	FOR(T,1,TT+1)
	{
		cint1(N);
		array<VI,2> A;
		FOR(i,0,N)
		{
			cint1(a);
			A[i&1].PB(a);
		}
		FOR(i,0,2) sort(ALL(A[i]));

		VI B(N);
		FOR(i,0,N) B[i] = A[i&1][i>>1];
		int sol {-1};
		FOR(i,0,N-1) if (B[i] > B[i+1])
		{
			sol = i;
			break;
		}

		cout << "Case #" << T << ": ";
		if (sol == -1)
			cout << "OK";
		else
			cout << sol;
		cout << nl;
	}

	return 0;
}