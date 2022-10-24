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
 #define arlen(a) (sizeof(a)/sizeof(a[0]))
 const double EPS = 1e-6;
 const int INF = 1000*1000*1000;
 const char CINF = 102;
 const lng LINF = INF * 1ll * INF;
 const ld PI = 3.1415926535897932384626433832795;
 lng gcd(lng a,lng b){return a?gcd(b%a,a):b;}
 uint gcd(uint a,uint b){return a?gcd(b%a,a):b;}
 
 double solve(lng B,vector<PLL> v){
 	double res=0;
 	while(true){
 		sort(all(v));
 		double r=0;
 		lng mn=v[0].X;
 		int mc=0;
 		int sc=0;
 		forv(i,v){
 			if(v[i].X==mn)
 				++mc;
 		}
 		forv(i,v){
 			if(sz(v)>mc && v[i].X<=v[mc].X)
 				++sc;
 		}
 		forv(i,v){
 			lng b=-v[i].Y;
 			if(v[i].X==mn)
 				r+=-b+36.*b/mc;
 			else
 				r-=b;
 			//cout<<v[i].X<<' '<<v[i].Y<<endl;
 		}
 		//cout<<endl;
 		res=max(res,r);
 		if(!B)
 			break;
 		
 		if(mc>1){
 			--v[mc-1].Y;
 			++v[mc-1].X;
 			--B;
 		}else{
 			lng mn3=LINF;
 			if(sc<sz(v))
 				mn3=v[sc].X;
 			lng mn2=v[mc].X;
 			lng i=min(B/sc,mn3-mn2)-1;
 			if(i>0){
 				B-=sc*i;
 				forn(j,sc){
 					v[j].Y-=i;
 					v[j].X+=i;
 				}
 			}else{
 				--v[mc-1].Y;
 				++v[mc-1].X;
 				--B;
 			}
 		}
 	}
 	return res;
 }
 
 double brute(lng B,vector<PLL> v){
 	double res=0;
 	while(true){
 		sort(all(v));
 		double r=0;
 		lng mn=v[0].X;
 		int mc=0;
 		int sc=0;
 		forv(i,v){
 			if(v[i].X==mn)
 				++mc;
 		}
 		forv(i,v){
 			if(sz(v)>mc && v[i].X<=v[mc].X)
 				++sc;
 		}
 		forv(i,v){
 			lng b=-v[i].Y;
 			if(v[i].X==mn)
 				r+=-b+36.*b/mc;
 			else
 				r-=b;
 			//cout<<v[i].X<<' '<<v[i].Y<<endl;
 		}
 		//cout<<endl;
 		if(r>res){
 			res=r;
 			//cout<<B<<endl;
 		}
 		if(!B)
 			break;
 		
 		--v[mc-1].Y;
 		++v[mc-1].X;
 		--B;
 	}
 	return res;
 }
 
 int main() {
 #ifdef __ASD__
 	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
 #endif
 	
 	int tc;
 	cin>>tc;
 	forn(qqq,tc){
 		lng B;
 		int n;
 		cin>>B>>n;
 		vector<PLL> v(37,mp(0,0));
 		forn(i,n){
 			cin>>v[i].X;
 		}
 		double r=solve(B,v);
 		double b=brute(B,v);
 		if(fabs(b-r)>1e-13){
 			cout<<"oops "<<qqq<<": "<<b<<' '<<r<<endl;
 			return 1;
 		}
 		printf("Case #%d: %.15lf\n",qqq+1,r);
 	}
 	
 	return 0;
 }
