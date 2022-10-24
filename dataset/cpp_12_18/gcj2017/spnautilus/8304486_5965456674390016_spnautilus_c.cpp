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
 
 const int MAX_N {16};
 const int MAX_M {32};
 
 bool EV[MAX_M];
 int E[MAX_M];
 int L[MAX_M];
 int D[MAX_M];
 
 int sol;
 
 void rec(int u, int dist, int rem)
 {
 	if(rem == 0) mina(sol, dist);
 	else
 	{
 		int h {dist % 24};
 		for(int e: {2*u, 2*u+1}) if(not EV[e])
 		{
 			EV[e] = true;
 			int d {(L[e] - h + 24) % 24 + dist + D[e]};
 			rec(E[e], d, rem - 1);
 			EV[e] = false;
 		}
 	}
 }
 
 int main()
 {
 	IO;
 	cint1(TT);
 	FOR(T,1,TT+1)
 	{
 		cint1(N);
 		FOR(i,0,2*N)
 		{
 			cint3(e,l,d);
 			--e;
 			E[i] = e;
 			L[i] = l;
 			D[i] = d;
 		}
 
 		sol = 1e9;
 		rec(0, 0, 2*N);
 
 		cout << "Case #" << T << ": " << sol << nl;
 	}
 
 	return 0;
 }