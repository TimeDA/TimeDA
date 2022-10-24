#pragma comment(linker, "/STACK:512000000")
 #define _CRT_SECURE_NO_DEPRECATE
 #define _USE_MATH_DEFINES
 #include <iostream>
 #include <fstream>
 #include <cstdio>
 #include <cstdlib>
 #include <cassert>
 #include <climits>
 #include <ctime>
 #include <numeric>
 #include <vector>
 #include <algorithm>
 #include <bitset>
 #include <cmath>
 #include <cstring>
 #include <iomanip>
 #include <complex>
 #include <deque>
 #include <functional>
 #include <list>
 #include <map>
 #include <string>
 #include <sstream>
 #include <set>
 #include <stack>
 #include <queue>
 using namespace std;
 typedef long long lng;
 typedef unsigned long long ulng;
 typedef unsigned int uint;
 typedef unsigned char uchar;
 typedef long double ld;
 typedef pair<int, int> PII;
 typedef pair<short, short> PSS;
 typedef pair<PII, int> PIII;
 typedef pair<lng, lng> PLL;
 typedef pair<ulng, ulng> PUU;
 typedef pair<lng, int> PLI;
 typedef pair<int, lng> PIL;
 typedef pair<ld, ld> PDD;
 template<class T> inline T sqr(T x) { return x * x; }
 template<class T> inline string tostr(const T & x) { stringstream ss; ss << x; return ss.str(); }
 inline lng parse(const string & s) { stringstream ss(s); lng x; ss >> x; return x; }
 #define left asdleft
 #define right asdright
 #define link asdlink
 //#define unlink asdunlink
 #define next asdnext
 #define prev asdprev
 #define y0 asdy0
 #define y1 asdy1
 #define mp make_pair
 #define pb push_back
 #define sz(x) ((int)(x).size())
 #define all(x) (x).begin(), (x).end()
 #define clr(ar,val) memset(ar, val, sizeof(ar))
 #define istr stringstream
 #define forn(i,n) for(int i=0;i<(n);++i)
 #define forv(i,v) forn(i,sz(v))
 #define X first
 #define Y second
 #define hash asdhash
 #define move asdmove
 const ld EPS = 1e-12;
 const int INF = 1000*1000*1000;
 const char CINF = 102;
 const lng LINF = INF * 1ll * INF;
 const ld DINF = 1e200;
 const ld PI = 3.1415926535897932384626433832795l;
 int gcd(int a,int b){return a?gcd(b%a,a):b;}
 lng gcd(lng a,lng b){return a?gcd(b%a,a):b;}
 lng powmod(lng a,lng p,lng m){lng r=1;while(p){if(p&1)r=r*a%m;p>>=1;a=a*a%m;}return r;}
 #define TASKA "iota"
 
 void gen(){
 	freopen("input.txt", "w", stdout);
 	
 }
 
 struct tree{
 	vector<int> tr;
 	
 	tree(int n):tr(n*4+10) {}
 	
 	void add1(int p,int a,int b,int k){
 		if(b==a+1){
 			++tr[k];
 			return;
 		}
 		int c=(a+b)/2;
 		if(p<c)
 			add1(p,a,c,k*2+1);
 		else
 			add1(p,c,b,k*2+2);
 		tr[k]=tr[k*2+1]+tr[k*2+2];
 	}
 	
 	int getsum(int l,int r,int a,int b,int k){
 		if(r<=a || l>=b)
 			return 0;
 		if(l<=a && r>=b)
 			return tr[k];
 		int c=(a+b)/2;
 		return getsum(l,r,a,c,k*2+1)+getsum(l,r,c,b,k*2+2);
 	}
 };
 
 int main(){
 #ifdef __ASD__
 	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
 #else
 	//freopen(TASKA".in", "r", stdin); freopen(TASKA".out", "w", stdout);
 #endif
 
 	//gen();return 0;
 
 	int tc;
 	cin>>tc;
 	forn(qqq,tc){
 		cerr<<qqq<<"/"<<tc<<endl;
 		
 		int n;
 		cin>>n;
 		vector<PII> A(n);
 		forn(i,n){
 			cin>>A[i].X;
 			A[i].Y=i;
 		}
 		sort(all(A));
 		vector<vector<int> > dp(n+1,vector<int>(n+1,INF));
 		dp[0][0]=0;
 		tree tr(n);
 		for(int s=0;s<n;++s){
 			int q=A[s].Y;
 			for(int a=0;a<=s;++a){
 				int b=s-a;
 				int p=tr.getsum(0,q,0,n,0);
 				dp[a+1][b]=min(dp[a+1][b],dp[a][b]+(q-p));
 				dp[a][b+1]=min(dp[a][b+1],dp[a][b]+((n-q-1)-(s-p)));
 			}
 			tr.add1(q,0,n,0);
 		}
 		
 		int ans=INF;
 		forn(k,n+1){
 			ans=min(ans,dp[k][n-k]);
 		}
 		
 		cout<<"Case #"<<qqq+1<<": "<<ans<<endl;
 	}
 	
 	return 0;
 }
