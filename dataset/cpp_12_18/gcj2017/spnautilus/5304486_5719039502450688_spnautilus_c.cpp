// spnauT
 //
 #include <bits/stdc++.h>
 using namespace std;
 #define FOR(i,a,b) for(int _b=(b),i=(a);i<_b;++i)
 #define ROF(i,b,a) for(int _a=(a),i=(b);i>_a;--i)
 #define REP(n) for(int _n=(n);_n--;)
 #define _1 first
 #define _2 second
 #define PB(x) push_back(x)
 #define SZ(x) int((x).size())
 #define ALL(x) (x).begin(),(x).end()
 #define MSET(m,v) memset(m,v,sizeof(m))
 #define MAX_PQ(T) priority_queue<T>
 #define MIN_PQ(T) priority_queue<T,vector<T>,greater<T>>
 #define IO(){ios_base::sync_with_stdio(0);cin.tie(0);}
 #define nl '\n'
 #define cint1(a) int a;cin>>a
 #define cint2(a,b) int a,b;cin>>a>>b
 #define cint3(a,b,c) int a,b,c;cin>>a>>b>>c
 typedef long long LL;typedef pair<int,int> PII;
 typedef vector<int>VI;typedef vector<LL>VL;typedef vector<PII>VP;
 template<class A,class B>inline bool mina(A &x,const B &y){return(y<x)?(x=y,1):0;}
 template<class A,class B>inline bool maxa(A &x,const B &y){return(x<y)?(x=y,1):0;}
 
 #define MAXN (104)
 
 int N, P;
 int V[MAXN][MAXN][MAXN][MAXN];
 int rit;
 
 typedef tuple<int,int,int,int,int> T5;
 
 int main()
 {
 	cint1(TT);
 	FOR(T,1,TT+1)
 	{
 		cint2(Hd,Ad);
 		cint2(Hk,Ak);
 		cint2(B,D);
 
 		int sol = -1;
 		++rit;
 		queue<T5> Q;
 		auto f = [&](int d, int hd, int ad, int hk, int ak)
 		{
 			if(maxa(V[hd][ad][hk][ak], rit)) Q.push(T5(d,hd,ad,hk,ak));
 		};
 
 		f(0,Hd,Ad,Hk,Ak);
 
 		while(!Q.empty())
 		{
 			int d,hd,ad,hk,ak;
 			tie(d,hd,ad,hk,ak) = Q.front();
 			Q.pop();
 			++d;
 
 			// Attack
 			if(hk <= ad)
 			{
 				sol = d;
 				break;
 			}
 			if(hd > ak) f(d, hd-ak, ad, hk-ad, ak);
 
 			// Buff
 			if(hd > ak) f(d, hd-ak, min(ad+B,Hk), hk, ak);
 
 			// Cure
 			if(Hd > ak) f(d, Hd-ak, ad, hk, ak);
 
 			// Debuff
 			int akd = max(ak-D, 0);
 			if(hd > akd) f(d, hd-akd, ad, hk, akd);
 		}
 
 		printf("Case #%d: ", T);
 		if(sol == -1) printf("IMPOSSIBLE\n");
 		else printf("%d\n", sol);
 	}
 
 	return 0;
 }