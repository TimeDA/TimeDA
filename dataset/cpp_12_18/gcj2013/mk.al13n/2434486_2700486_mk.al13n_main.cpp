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
 
 const int lim=10000;
 ld fact[lim];
 
 ld theprob(int n,int k){
 	return pow(2,fact[n]-fact[k]-fact[n-k]-n);
 }
 
 int main() {
 #ifdef __ASD__
 	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
 #endif
 	
 	forn(i,lim){
 		if(i)
 			fact[i]=fact[i-1]+log2(i);
 	}
 	
 	int tc;
 	cin>>tc;
 	forn(qqq,tc){
 		int N,X,Y;
 		cin>>N>>X>>Y;
 		X=abs(X);
 		int k0=0;
 		while(N>=4*k0+1){
 			N-=4*k0+1;
 			++k0;
 		}
 		--k0;
 		int k=(X+Y)/2;
 		ld res;
 		if(k<=k0)
 			res=1;
 		else if(X==0||k>k0+1)
 			res=0;
 		else if(N==4*k)
 			res=1;
 		else{
 			priority_queue<ld> qu;
 			for(int a=max(Y+1,N-2*k);a<=2*k&&a<=N;++a){
 				if(a==N-2*k || a==2*k){
 					forn(i,N-2*k+1){
 						qu.push(-.5*theprob(2*k+i-1,i));
 					}
 				}else{
 					qu.push(-theprob(N,a));
 				}
 			}
 			while(sz(qu)>1){
 				ld a=qu.top();
 				qu.pop();
 				ld b=qu.top();
 				qu.pop();
 				qu.push(a+b);
 			}
 			if(sz(qu))
 				res=-qu.top();
 			else
 				res=0;
 		}
 		
 		printf("Case #%d: %.15lf\n",qqq+1,(double)res);
 	}
 	
 	return 0;
 }