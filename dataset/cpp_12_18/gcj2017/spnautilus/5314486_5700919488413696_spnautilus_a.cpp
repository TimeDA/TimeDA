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
 
 const int MAX_N = 104;
 const int MAX_P = 4;
 
 int P;
 int dp[MAX_N][MAX_N][MAX_N][MAX_P];
 int V[MAX_N][MAX_N][MAX_N][MAX_P];
 int rit;
 
 int rec(int n1, int n2, int n3, int d)
 {
 	if(n1 < 0 || n2 < 0 || n3 < 0) return -1000;
 	if(n1 + n2 + n3 == 0) return 0;
 	int &res = dp[n1][n2][n3][d];
 	if(maxa(V[n1][n2][n3][d], rit))
 	{
 		res = -1000;
 		int res0 = !d;
 		maxa(res, res0 + rec(n1 - 1, n2, n3, (d+1)%P));
 		maxa(res, res0 + rec(n1, n2 - 1, n3, (d+2)%P));
 		maxa(res, res0 + rec(n1, n2, n3 - 1, (d+3)%P));
 	}
 	return res;
 }
 
 int main()
 {
 	IO;
 	cint1(TT);
 	FOR(T,1,TT+1)
 	{
 		cint1(N);
 		cin >> P;
 		VI C(4,0);
 		int sol = 0;
 		REP(N)
 		{
 			cint1(a);
 			int d = a % P;
 			if(d == 0) ++sol;
 			else ++C[d - 1];
 		}
 		++rit;
 		sol += rec(C[0], C[1], C[2], 0);
 		cout << "Case #" << T << ": " << sol << nl;
 	}
 
 	return 0;
 }