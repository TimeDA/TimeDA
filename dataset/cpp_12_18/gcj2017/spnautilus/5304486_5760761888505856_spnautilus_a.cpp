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
 
 #define MAXN (32)
 
 char B[MAXN][MAXN];
 int V[MAXN][MAXN];
 
 int main()
 {
 	cint1(TT);
 	FOR(T,1,TT+1)
 	{
 		cint2(R,C);
 		FOR(i,0,R) cin >> B[i];
 
 		MSET(V,0);
 		FOR(i,0,R) FOR(j,0,C) if(!V[i][j] && B[i][j] != '?')
 		{
 			int l = j;
 			while(l > 0 && B[i][l-1] == '?') --l;
 			int r = j;
 			while(r < C-1 && B[i][r+1] == '?') ++r;
 
 			int u = i;
 			while(u > 0)
 			{
 				int c = 0;
 				FOR(k,l,r+1) c += B[u-1][k] != '?';
 				if(c > 0) break;
 				--u;
 			}
 
 			int d = i;
 			while(d < R-1)
 			{
 				int c = 0;
 				FOR(k,l,r+1) c += B[d+1][k] != '?';
 				if(c > 0) break;
 				++d;
 			}
 
 			FOR(x,u,d+1) FOR(y,l,r+1)
 			{
 				V[x][y] = 1;
 				B[x][y] = B[i][j];
 			}
 		}
 
 		printf("Case #%d:\n", T);
 		FOR(i,0,R) printf("%s\n", B[i]);
 	}
 
 	return 0;
 }