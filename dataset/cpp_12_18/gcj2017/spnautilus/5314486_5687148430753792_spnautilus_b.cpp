// spnauT
 //
 #include <bits/stdc++.h>
 using namespace std;
 #define FOR(i,a,b) for(int _b=(b),i=(a);i<_b;++i)
 #define ROF(i,b,a) for(int _a=(a),i=(b);i>_a;--i)
 #define REP(n) for(int _n=(n);_n--;)
 #define _1 first
 #define _2 second
 #define PB push_back
 #define SZ(x) int((x).size())
 #define ALL(x) (x).begin(),(x).end()
 #define MSET(m,v) memset(m,v,sizeof(m))
 #define MAX_PQ(T) priority_queue<T>
 #define MIN_PQ(T) priority_queue<T,vector<T>,greater<T>>
 #define IO {ios_base::sync_with_stdio(0);cin.tie(0);}
 #define nl '\n'
 #define cint1(a) int a;cin>>a
 #define cint2(a,b) int a,b;cin>>a>>b
 #define cint3(a,b,c) int a,b,c;cin>>a>>b>>c
 typedef long long LL;typedef pair<int,int>PII;
 typedef vector<int>VI;typedef vector<LL>VL;typedef vector<PII>VP;
 template<class A,class B>inline bool mina(A &x,const B &y){return(y<x)?(x=y,1):0;}
 template<class A,class B>inline bool maxa(A &x,const B &y){return(x<y)?(x=y,1):0;}
 
 const int MAX_N = 1004;
 const int MAX_C = 1004;
 
 int main()
 {
 	IO;
 	cint1(TT);
 	FOR(T,1,TT+1)
 	{
 		cint3(N,C,M);
 		VI CC(C,0);
 		VI PC(N,0);
 		REP(M)
 		{
 			cint2(p,c);
 			--p; --c;
 			++CC[c];
 			++PC[p];
 		}
 		int sola = 0;
 		int solb = 0;
 		int sum = 0;
 		FOR(i,0,C) maxa(sola, CC[i]);
 		FOR(n,1,N+1)
 		{
 			sum += PC[n - 1];
 			maxa(sola, (sum + n - 1) / n);
 		}
 		sum = 0;
 		FOR(n,1,N+1) solb += max(0, PC[n - 1] - sola);
 
 		cout << "Case #" << T << ": " << sola << ' ' << solb << nl;
 	}
 
 	return 0;
 }