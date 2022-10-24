// spnauT
 //
 #include <bits/stdc++.h>
 using namespace std;
 #define FOR(i,a,b) for(int _b=(b),i=(a); i<_b; ++i)
 #define ROF(i,b,a) for(int _a=(a),i=(b); i>_a; --i)
 #define _1 first
 #define _2 second
 #define PB(x) push_back(x)
 #define MSET(m,v) memset(m,v,sizeof(m))
 #define MAX_PQ(T) priority_queue <T>
 #define MIN_PQ(T) priority_queue <T,vector<T>,greater<T>>
 typedef long long LL;
 typedef pair<int,int> PII;
 typedef vector<int> VI; typedef vector<LL> VL; typedef vector<PII> VP;
 template<typename A, typename B> inline bool mina(A &x, B y) {return(x>y)?(x=y,1):0;}
 template<typename A, typename B> inline bool maxa(A &x, B y) {return(x<y)?(x=y,1):0;}
 template<typename A, typename B> inline A geta(A &x, const B y) {A t=x;x=y;return t;}
 
 #define MAXN (104)
 
 const int dr[4] = {0, 1, 0, -1};
 const int dc[4] = {1, 0, -1, 0};
 
 int T;
 int R, C;
 char B[MAXN][MAXN];
 
 inline int in(int r, int c)
 {
 	return r >= 0 && r < R && c >= 0 && c < C;
 }
 
 int check(int r, int c)
 {
 	FOR(d,0,4) FOR(k,1,1000)
 	{
 		int rr = r + k*dr[d];
 		int cc = c + k*dc[d];
 		if(!in(rr,cc)) break;
 		if(B[rr][cc] != '.') return 1;
 	}
 	return 0;
 }
 
 int main()
 {
 	cin >> T;
 	FOR(tt,1,T+1)
 	{
 		cin >> R >> C;
 		FOR(i,0,R) scanf("%s", B[i]);
 
 		int valid = 1;
 		int sol = 0;
 		FOR(i,0,R)
 		{
 			FOR(j,0,C)
 			{
 				if(B[i][j] == '.') continue;
 				if(B[i][j] == '<')
 				{
 					++sol;
 					valid &= check(i,j);
 				}
 				break;
 			}
 			ROF(j,C-1,-1)
 			{
 				if(B[i][j] == '.') continue;
 				if(B[i][j] == '>')
 				{
 					++sol;
 					valid &= check(i,j);
 				}
 				break;
 			}
 		}
 		FOR(j,0,C)
 		{
 			FOR(i,0,R)
 			{
 				if(B[i][j] == '.') continue;
 				if(B[i][j] == '^')
 				{
 					++sol;
 					valid &= check(i,j);
 				}
 				break;
 			}
 			ROF(i,R-1,-1)
 			{
 				if(B[i][j] == '.') continue;
 				if(B[i][j] == 'v')
 				{
 					++sol;
 					valid &= check(i,j);
 				}
 				break;
 			}
 		}
 
 		printf("Case #%d: ", tt);
 		if(valid) printf("%d\n", sol);
 		else printf("IMPOSSIBLE\n");
 	}
 
 	return 0;
 }
