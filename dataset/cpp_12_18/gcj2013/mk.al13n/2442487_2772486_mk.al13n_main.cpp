#pragma comment(linker, "/STACK:512000000")
 #define _CRT_SECURE_NO_DEPRECATE
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
 template<class T> inline T sqr(T x) { return x * x; }
 template<class T> inline string tostr(const T & x) { stringstream ss; ss << x; return ss.str(); }
 typedef long long lng;
 typedef unsigned long long ulng;
 typedef unsigned int uint;
 typedef unsigned char uchar;
 typedef double ld;
 typedef pair<int, int> PII;
 typedef pair<PII, int> PIII;
 typedef pair<int, lng> PLL;
 typedef pair<lng, int> PLI;
 typedef pair<ld, ld> PDD;
 #define left asdleft
 #define right asdright
 #define link asdlink
 #define unlink asdunlink
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
 #define pow10 asdpow10
 const double EPS = 1e-6;
 const int INF = 1000*1000*1000;
 const char CINF = 102;
 const lng LINF = INF * 1ll * INF;
 const ld PI = 3.1415926535897932384626433832795;
 lng gcd(lng a,lng b){return a?gcd(b%a,a):b;}
 uint gcd(uint a,uint b){return a?gcd(b%a,a):b;}
 
 
 
 int main() {
 #ifdef __ASD__
 	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
 #endif
 	
 	int tc;
 	cin>>tc;
 	forn(qqq,tc){
 		const lng mod=1000002013;
 		lng N;
 		int m;
 		cin>>N>>m;
 		lng cost0=0;
 		vector<pair<pair<lng,int>,lng> > v;
 		forn(i,m){
 			lng a,b,p;
 			cin>>a>>b>>p;
 			v.pb(mp(mp(a,-1),p));
 			v.pb(mp(mp(b,1),p));
 			lng k=b-a;
 			(cost0+=k*(N*2-k+1)/2%mod*p)%=mod;
 		}
 		sort(all(v));
 		vector<PLL> st;
 		lng cost1=0;
 		forv(i,v){
 			lng b=v[i].X.X;
 			lng p=v[i].Y;
 			if(v[i].X.Y==-1){
 				st.pb(mp(b,p));
 			}else{
 				while(p){
 					if(st.empty()){
 						cout<<"oops "<<i<<endl;
 						exit(123);
 					}
 					lng a=st.back().X;
 					lng c=st.back().Y;
 					st.pop_back();
 					lng t=min(p,c);
 					lng k=b-a;
 					(cost1+=k*(N*2-k+1)/2%mod*t)%=mod;
 					c-=t;
 					if(c)
 						st.push_back(mp(a,c));
 					p-=t;
 				}
 			}
 		}
 		//cerr<<cost0<<' '<<cost1<<endl;
 		cout<<"Case #"<<qqq+1<<": "<<(cost0-cost1+mod)%mod<<endl;
 	}
 	
 	return 0;
 }
 
