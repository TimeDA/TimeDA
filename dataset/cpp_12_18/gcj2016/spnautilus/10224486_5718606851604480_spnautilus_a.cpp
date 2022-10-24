// predetermined? -> PREDESTINATION (2014)!
 
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
 
 #define MAXN (16)
 
 string dp[MAXN][3];
 
 string f(int n, int a)
 {
 	if(SZ(dp[n][a]) == 0)
 	{
 		if(n == 0) dp[n][a] = "PRS"[a];
 		else
 		{
 			string x = f(n-1,a);
 			string y = f(n-1,(a+1)%3);
 			if(x > y) swap(x,y);
 			dp[n][a] = x+y;
 		}
 	}
 	return dp[n][a];
 }
 
 int main()
 {
 	IO();
 	cint1(TT);
 	FOR(T,1,TT+1)
 	{
 		cint1(N);
 		cint3(R,P,S);
 		string sol;
 
 		FOR(i,0,3)
 		{
 			string res = f(N,i);
 			int p = 0;
 			int r = 0;
 			int s = 0;
 			for(char c: res)
 			{
 				if(c == 'P') ++p;
 				if(c == 'R') ++r;
 				if(c == 'S') ++s;
 			}
 			if(p == P && r == R && s == S && (SZ(sol) == 0 || sol > res)) sol = res;
 		}
 
 		cout << "Case #" << T << ": ";
 		if(SZ(sol) == 0) cout << "IMPOSSIBLE" << nl;
 		else cout << sol << nl;
 	}
 
 	return 0;
 }