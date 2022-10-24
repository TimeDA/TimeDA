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
 
 #define MAXN (204)
 #define MAXW (5004)
 
 int T, N;
 VI W[MAXN];
 int V[MAXW];
 int C[MAXW];
 
 char S[16];
 map<string, int> M;
 int id;
 
 int getID(const string &s)
 {
 	auto si = M.find(s);
 	if(si == M.end())
 	{
 		M[s] = id++;
 		return id-1;
 	}
 	else return si->_2;
 }
 
 int main()
 {
 	cin >> T;
 	int rit = 0;
 	FOR(tt,1,T+1)
 	{
 		M.clear();
 		id = 0;
 		scanf("%d\n", &N);
 
 		int wn = 0;
 		FOR(i,0,N)
 		{
 			int n = 0;
 			VI w;
 			while(1)
 			{
 				char c;
 				scanf("%s%c", S, &c);
 				w.PB(getID(S));
 
 				++n;
 				if(c == '\n') break;
 			}
 			sort(w.begin(), w.end());
 			w.resize(distance(w.begin(), unique(w.begin(), w.end())));
 			W[i] = w;
 			wn += w.size();
 		}
 
 		++rit;
 		int res = id;
 		FOR(b0,0,1<<(N-2))
 		{
 			FOR(i,0,id) C[i] = 0;
 			int b = (b0 << 2) | 2;
 			FOR(i,0,N)
 			{
 				int j = 1 << ((b >> i) & 1);
 				for(int w: W[i]) C[w] |= j;
 			}
 
 			int n = 0;
 			FOR(i,0,id) n += C[i] == 3;
 			mina(res, n);
 		}
 		printf("Case #%d: %d\n", tt, res);
 	}
 
 	return 0;
 }
