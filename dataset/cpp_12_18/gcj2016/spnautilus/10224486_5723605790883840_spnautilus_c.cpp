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
 
 const int dr[4] = {0, 1, 0, -1};
 const int dc[4] = {1, 0, -1, 0};
 
 #define MAXN (504)
 
 int R, C, N, RC2;
 int A[2*MAXN];
 int B[2*MAXN];
 PII S[2*MAXN];
 
 char sol[MAXN][MAXN];
 int V[MAXN][MAXN];
 int rit;
 int gid;
 
 inline int getid(int r, int c)
 {
 	int id = -1;
 	if(r == 0 || r == R+1)
 	{
 		if(r == 0) id = c-1;
 		else id = N + C - c;
 	}
 	if(c == 0 || c == C+1)
 	{
 		if(c == 0) id = RC2 - r;
 		else id = C + r - 1;
 	}
 
 	return id;
 }
 
 inline PII getpos(int id) // id in [0, RC2)
 {
 	if(id < C) return PII(0, id+1);
 	id -= C;
 	if(id < R) return PII(id+1, C+1);
 	id -= R;
 	if(id < C) return PII(R+1, C-id);
 	id -= C;
 	return PII(R-id, 0);
 }
 
 int dfs(int r, int c, int d)
 {
 	V[r][c] = rit;
 	int id = getid(r,c);
 	if(id != -1) return id == gid;
 
 	auto f = [&](int d1)
 	{
 		int dd = d ^ d1;
 		int rr = r+dr[dd];
 		int cc = c+dc[dd];
 		if(V[rr][cc] != rit && dfs(rr, cc, dd))
 		{
 			sol[r][c] = (d1 == 1) ? '\\' : '/';
 			return 1;
 		}
 		return 0;
 	};
 
 	if(sol[r][c] == '/')
 	{
 		if(f(3)) return 1;
 	}
 	else if(sol[r][c] == '\\')
 	{
 		if(f(1)) return 1;
 	}
 	else
 	{
 		if(f(((d+3)&3) ^ d)) return 1;
 		if(f(((d+1)&3) ^ d)) return 1;
 	}
 	return 0;
 }
 
 int main()
 {
 /*
 	R = 2;
 	C = 5;
 	N = R+C;
 	RC2 = 2*N;
 	FOR(i,0,RC2)
 	{
 		PII p = getpos(i);
 		printf("%d : %d %d\n", i+1, p._1, p._2);
 		assert(getid(p._1,p._2) == i);
 	}
 	return 0;
 */
 
 	IO();
 	cint1(TT);
 	FOR(T,1,TT+1)
 	{
 		MSET(sol,0);
 		MSET(V,0);
 		rit = 0;
 
 		cin >> R >> C;
 		N = R+C;
 		RC2 = 2*N;
 		int valid = 1;
 
 		FOR(i,0,N)
 		{
 			cint2(a,b);
 			--a; --b;
 			int d1 = (b-a+RC2) % RC2;
 			int d2 = (a-b+RC2) % RC2;
 			if(d1 > d2) swap(a,b);
 			A[i] = a;
 			B[i] = b;
 			S[i] = PII(min(d1,d2), i);
 
 			if(S[i]._1 % 2 == 0) valid = 0;
 		}
 
 		cout << "Case #" << T << ":" << nl;
 		if(!valid)
 		{
 			cout << "IMPOSSIBLE" << nl;
 			continue;
 		}
 
 		sort(S,S+N);
 
 /*
 		FOR(i,0,N)
 		{
 			int d = S[i]._1;
 			int id = S[i]._2;
 			if(A[id] < B[id]) printf("%d %d : %d -> %d  L\n", d, id, A[id]+1, B[id]+1);
 			else printf("%d %d : %d -> %d  R\n", d, id, A[id]+1, B[id]+1);
 		}
 //*/
 
 		FOR(i,0,N)
 		{
 			int p = S[i]._2;
 			int id = A[p];
 			gid = B[p];
 
 			int r = 0, c = 0, d = 0;
 			if(id >= 0 && id < C) r = 1, c = id+1, d = 1;
 			id -= C;
 			if(id >= 0 && id < R) r = id+1, c = C, d = 2;
 			id -= R;
 			if(id >= 0 && id < C) r = R, c = C-id, d = 3;
 			id -= C;
 			if(id >= 0 && id < R) r = R-id, c = 1, d = 0;
 
 			++rit;
 			if(!dfs(r,c,d))
 			{
 				valid = 0;
 				break;
 			}
 
 /*
 			FOR(i,1,R+1)
 			{
 				FOR(j,1,C+1) if(!sol[i][j]) sol[i][j] = '/';
 				cout << sol[i]+1 << nl;
 			}
 //*/
 		}
 //		putchar(nl);
 
 		if(valid)
 		{
 			FOR(i,1,R+1)
 			{
 				FOR(j,1,C+1) if(!sol[i][j]) sol[i][j] = '/';
 				cout << sol[i]+1 << nl;
 			}
 		}
 		else cout << "IMPOSSIBLE" << nl;
 	}
 
 	return 0;
 }