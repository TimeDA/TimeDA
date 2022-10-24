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
 
 const int mod=INF+7;
 
 struct trie{
 	struct node{
 		vector<int> go;
 		
 		node():go(26,-1){}
 	};
 	
 	vector<node> T;
 	
 	trie():T(1){}
 	
 	void addw(const string &s){
 		int v=0;
 		forv(i,s){
 			int c=s[i]-'A';
 			if(T[v].go[c]==-1){
 				T[v].go[c]=sz(T);
 				T.pb(node());
 			}
 			v=T[v].go[c];
 		}
 	}
 };
 
 int n,M;
 PII ans;
 vector<string> A;
 int P[100];
 
 void doit(int a){
 	if(a==n){
 		trie t[4];
 		forn(i,n){
 			t[P[i]].addw(A[i]);
 		}
 		int r=0;
 		forn(i,M){
 			int s=sz(t[i].T);
 			if(s>1)
 				r+=s;
 		}
 		if(r>ans.X)
 			ans=mp(r,1);
 		else if(r==ans.X)
 			++ans.Y;
 		return;
 	}
 	for(P[a]=0;P[a]<M;++P[a]){
 		doit(a+1);
 	}
 }
 
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
 		
 		cin>>n>>M;
 		A.resize(n);
 		forn(i,n){
 			cin>>A[i];
 		}
 		
 		ans=mp(-1,0);
 		doit(0);
 				
 		cout<<"Case #"<<qqq+1<<": "<<ans.X<<' '<<ans.Y<<endl;
 	}
 	
 	return 0;
 }
