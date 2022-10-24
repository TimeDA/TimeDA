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
 
 #define MAXN (204)
 
 int N, K;
 double P[MAXN];
 double dp[MAXN];
 
 double calc(const VI &V)
 {
 	assert(SZ(V) == K);
 	FOR(i,1,K+1) dp[i] = 0;
 	dp[0] = 1;
 	FOR(i,0,K)
 	{
 		double p = P[V[i]];
 		ROF(j,i,-1)
 		{
 			dp[j+1] += dp[j] * p;
 			dp[j] *= 1-p;
 		}
 		FOR(j,0,i+1) if(dp[j] < 1e-40) dp[j] = 0;
 	}
 	return dp[K/2];
 }
 
 int main()
 {
 	IO();
 	cint1(TT);
 	cout << fixed << setprecision(9);
 	FOR(T,1,TT+1)
 	{
 		cin >> N >> K;
 		FOR(i,0,N) cin >> P[i];
 		sort(P,P+N);
 
 		double sol = 0;
 		FOR(i,0,N)
 		{
 			VI V(K);
 			FOR(j,0,K) V[j] = (i+j)%N;
 			maxa(sol, calc(V));
 		}
 
 		cout << "Case #" << T << ": " << sol << nl;
 	}
 
 	return 0;
 }