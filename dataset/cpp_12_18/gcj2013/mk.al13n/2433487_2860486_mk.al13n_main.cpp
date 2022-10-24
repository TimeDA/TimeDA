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
 typedef pair<lng, lng> PLL;
 typedef pair<lng, int> PLI;
 typedef pair<int, lng> PIL;
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
 #define arlen(a) (sizeof(a)/sizeof(a[0]))
 const double EPS = 1e-6;
 const int INF = 1000*1000*1000;
 const char CINF = 102;
 const lng LINF = INF * 1ll * INF;
 const ld PI = 3.1415926535897932384626433832795;
 lng gcd(lng a,lng b){return a?gcd(b%a,a):b;}
 uint gcd(uint a,uint b){return a?gcd(b%a,a):b;}
 
 struct graph{
 	int n;
 	double dist[1100][1100];
 	vector<PIL> gr[1100];
 	
 	void clear(){
 		forn(i,n){
 			gr[i].clear();
 		}
 	}
 	
 	void getdist(double *dist,int v0){
 		forn(i,n){
 			dist[i]=LINF;
 		}
 		priority_queue<PLI> qu;
 		dist[v0]=0;
 		qu.push(mp(-0,v0));
 		while(!qu.empty()){
 			int v=qu.top().Y;
 			lng d=-qu.top().X;
 			qu.pop();
 			if(d!=dist[v])
 				continue;
 			forv(i,gr[v]){
 				int p=gr[v][i].X;
 				lng w=gr[v][i].Y;
 				if(d+w<dist[p]){
 					dist[p]=d+w;
 					qu.push(mp(-dist[p],p));
 				}
 			}
 		}
 	}
 	
 	void getdist(){
 		forn(i,n){
 			getdist(dist[i],i);
 		}
 	}
 };
 
 pair<PII,PLL> ed[2100];
 graph mn,mx;
 int n,m,p;
 int P[1100];
 
 int solve(){
 	cin>>n>>m>>p;
 	mn.n=mx.n=n;
 	forn(i,m){
 		int a,b;
 		lng x,y;
 		cin>>a>>b>>x>>y;
 		--a;--b;
 		ed[i]=mp(mp(a,b),mp(x,y));
 		mn.gr[a].pb(mp(b,x));
 		mx.gr[a].pb(mp(b,y));
 	}
 	mn.getdist();
 	mx.getdist();
 	forn(i,p){
 		cin>>P[i];
 		--P[i];
 	}
 	
 	vector<int> ps;
 	vector<lng> ds;
 	lng dd=0;
 	forn(i,p){
 		int e=P[i];
 		int v1=ed[e].X.X;
 		int v2=ed[e].X.Y;
 		ps.pb(v1);
 		ds.pb(dd);
 		dd+=ed[e].Y.X;
 		lng d=mn.dist[v2][1];
 		vector<pair<PLL,int> > jm;
 		jm.pb(mp(mp(d,d),1));
 		forn(f,m){
 			int p1=ed[f].X.X;
 			int p2=ed[f].X.Y;
 			if(mn.dist[v2][p1]+mn.dist[p2][1]+ed[f].Y.X!=d)
 				continue;
 			jm.pb(mp(mp(mn.dist[v2][p1],mn.dist[v2][p1]+ed[f].Y.X),p1));
 		}
 		sort(all(jm));
 		lng t=0;
 		forv(i,jm){
 			if(t<=jm[i].X.X){
 				int p2=jm[i].Y;
 				forv(ii,ps){
 					int p1=ps[ii];
 					lng d1=dd-ds[ii]+jm[i].X.X;
 					lng d2=mx.dist[p1][p2];
 					if(d2<d1){
 						return e+1;
 					}
 				}
 			}
 			t=max(t,jm[i].X.Y);
 		}
 	}
 	
 	return -1;
 }
 
 int main() {
 #ifdef __ASD__
 	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
 #endif
 	
 	int tc;
 	cin>>tc;
 	forn(qqq,tc){
 		int r=solve();
 		printf("Case #%d: ",qqq+1);
 		if(r==-1)
 			cout<<"Looks Good To Me"<<endl;
 		else
 			cout<<r<<endl;
 	}
 	
 	return 0;
 }
