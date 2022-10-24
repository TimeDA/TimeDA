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
 
 const int MAX_R {204};
 const int MAX_C {204};
 const int MOD {int(1e9+7)};
 const int dr[4] {0, 1, 0, -1};
 const int dc[4] {1, 0, -1, 0};
 
 LL opt[MAX_R][MAX_C];
 
 int main()
 {
 	IO;
 	cint1(TT);
 	FOR(T,1,TT+1)
 	{
 		cint2(R,C);
 		cint2(N,D);
 		fill(opt[0], opt[MAX_R], -1);
 
 		using T3 = tuple<LL,int,int>;
 		bool valid {true};
 		MIN_PQ(T3) Q;
 		auto f = [&](LL b, int r, int c)
 		{
 			if(not (r >= 0 and r < R and c >= 0 and c < C)) return;
 			if(opt[r][c] == -1)
 			{
 				opt[r][c] = b;
 				Q.emplace(b,r,c);
 			}
 			else if(opt[r][c] > b) valid = false;
 		};
 
 		REP(N)
 		{
 			cint3(r,c,b);
 			--r; --c;
 			f(b,r,c);
 		}
 
 		while(not Q.empty() and valid)
 		{
 			LL b;
 			int r, c;
 			tie(b,r,c) = Q.top();
 			Q.pop();
 
 			FOR(i,0,4) f(b+D, r+dr[i], c+dc[i]);
 		}
 
 		cout << "Case #" << T << ": ";
 		if(not valid) cout << "IMPOSSIBLE" << nl;
 		else
 		{
 			LL sol {0};
 			FOR(i,0,R) FOR(j,0,C) sol += opt[i][j];
 			cout << (sol % MOD) << nl;
 		}
 	}
 
 	return 0;
 }