#pragma comment(linker, "/STACK:512000000")
 #define _CRT_SECURE_NO_DEPRECATE
 #include <iostream>
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
 typedef long double ld;
 typedef pair<int, int> PII;
 typedef pair<PII, int> PIII;
 typedef pair<lng, lng> PLL;
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
 const double EPS = 1e-6;
 const int INF = 1000*1000*1000;
 const char CINF = 102;
 const lng LINF = INF * 1ll * INF;
 const ld PI = 3.1415926535897932384626433832795;
 
 int doit(lng A,const vector<lng> &v){
 	int r=0;
 	forv(i,v){
 		while(A<=v[i]){
 			++r;
 			A+=A-1;
 		}
 		A+=v[i];
 	}
 	return r;
 }
 
 int main() {
 #ifdef __ASD__
 	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
 #endif
 	
 	int tc;
 	cin>>tc;
 	forn(qqq,tc){
 		lng A;
 		int n;
 		cin>>A>>n;
 		vector<lng> v(n);
 		forn(i,n){
 			cin>>v[i];
 		}
 		int res=n;
 		if(A>1){
 			sort(all(v));
 			forn(p,n+1){
 				res=min(res,p+doit(A,v));
 				if(sz(v))
 					v.pop_back();
 			}
 		}
 		cout<<"Case #"<<qqq+1<<": "<<res<<endl;
 	}
 	
 	return 0;
 }