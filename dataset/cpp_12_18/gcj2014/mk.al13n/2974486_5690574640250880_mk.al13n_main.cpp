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
 template<class T> inline T sqr(T x) { return x * x; }
 template<class T> inline string tostr(const T & x) { stringstream ss; ss << x; return ss.str(); }
 typedef long long lng;
 typedef unsigned long long ulng;
 typedef unsigned int uint;
 typedef unsigned char uchar;
 typedef long double ld;
 typedef pair<int, int> PII;
 typedef pair<string, string> PSS;
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
 const ld EPS = 1e-12;
 const int INF = 1000*1000*1000;
 const char CINF = 102;
 const lng LINF = INF * 1ll * INF;
 const ld DINF = 1e200;
 const ld PI = 3.1415926535897932384626433832795l;
 int gcd(int a,int b){return a?gcd(b%a,a):b;}
 lng gcd(lng a,lng b){return a?gcd(b%a,a):b;}
 lng powmod(lng a,lng p,lng m){lng r=1;while(p){if(p&1)r=r*a%m;p>>=1;a=a*a%m;}return r;}
 #define TASKA "sequence"
 
 int n,m,k;
 bool hasans;
 char ans[55][55];
 bool was[55][55];
 
 int dfs(int a,int b){
 	if(a<0 || b<0 || a>=n || b>=m || ans[a][b]=='*' || was[a][b])
 		return 0;
 	was[a][b]=true;
 	int r=1;
 	for(int ii=a-1;ii<=a+1;++ii){
 		for(int jj=b-1;jj<=b+1;++jj){
 			if(ii==a&&jj==b)
 				continue;
 			if(ii<0 || ii>=n || jj<0 || jj>=m)
 				continue;
 			if(ans[ii][jj]=='*')
 				return r;
 		}
 	}
 	for(int ii=a-1;ii<=a+1;++ii){
 		for(int jj=b-1;jj<=b+1;++jj){
 			if(ii==a&&jj==b)
 				continue;
 			r+=dfs(ii,jj);
 		}
 	}
 	return r;
 }
 
 bool check(){
 	clr(was,0);
 	int i0=-1,j0=-1;
 	int cnt=0;
 	forn(i,n){
 		forn(j,m){
 			was[i][j]=false;
 			if(ans[i][j]=='c'){
 				if(i0==-1)
 					i0=i,j0=j;
 				else
 					return false;
 			}else if(ans[i][j]=='.')
 				++cnt;
 			else if(ans[i][j]!='*')
 				return false;
 		}
 	}
 	if(cnt+1!=k || i0==-1)
 		return false;
 	if(dfs(i0,j0)!=k)
 		return false;
 	return true;
 }
 
 void solve(){
 	clr(ans,0);
 	hasans=false;
 	for(int a=1;a<=n;++a){
 		for(int b=1;b<=m;++b){
 			forn(aa,b==m ? 1 : (a+1)){
 				forn(bb,a==n ? 1 : (b+1)){
 					if(a*b+aa+bb!=k)
 						continue;
 					forn(i,n){
 						forn(j,m){
 							ans[i][j]='*';
 						}
 					}
 					forn(i,a){
 						forn(j,b){
 							ans[i][j]='.';
 						}
 					}
 					forn(i,aa){
 						ans[i][b]='.';
 					}
 					forn(j,bb){
 						ans[a][j]='.';
 					}
 					ans[0][0]='c';
 					if(a==3 && b==6 && aa==1 && bb==6){
 						//cout<<"hi\n";
 					}
 					if(check()){
 						hasans=true;
 						return;
 					}
 				}
 			}
 		}
 	}
 }
 
 void brute(){
 	forn(q,1<<(n*m)){
 		forn(ci,n){
 			forn(cj,m){
 				forn(i,n){
 					forn(j,m){
 						ans[i][j]=(q&(1<<(i*m+j)))?'*':'.';
 					}
 				}
 				ans[ci][cj]='c';
 				if(check()){
 					hasans=true;
 					return;
 				}
 			}
 		}
 	}
 	hasans=false;
 }
 
 void test(){
 	for(n=1;n<=5;++n){
 		for(m=1;m<=5;++m){
 			for(k=1;k<=n*m;++k){
 				cerr<<n<<' '<<m<<' '<<k<<endl;
 				brute();
 				bool b=hasans;
 				solve();
 				bool r=hasans;
 				if(r!=b){
 					cout<<"failed "<<n<<' '<<m<<' '<<k<<": "<<b<<' '<<r<<endl;
 					return;
 				}
 			}
 		}
 	}
 	cout<<"passed"<<endl;
 }
 
 int main(){
 #ifdef __ASD__
 	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
 #else
 	//freopen(TASKA".in", "r", stdin); freopen(TASKA".out", "w", stdout);
 #endif
 	
 	//test();return 0;
 	
 	int tc;
 	cin>>tc;
 	forn(qqq,tc){
 		cin>>n>>m>>k;
 		k=n*m-k;
 		solve();
 		if(hasans && !check()){
 			cout<<"UPCHK!!1"<<endl;
 			exit(123);
 		}
 		printf("Case #%d:\n", qqq+1);
 		if(hasans){
 			forn(i,n){
 				printf("%s\n", ans[i]);
 			}
 		}else{
 			printf("Impossible\n");
 		}
 	}
 
 	return 0;
 }
