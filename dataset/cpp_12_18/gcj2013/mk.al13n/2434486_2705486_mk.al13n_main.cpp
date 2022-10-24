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
 
 vector<vector<int> > go(1,vector<int>(26,-1));
 vector<char> end(1,0);
 
 void add(const string &s){
 	int v=0;
 	forv(i,s){
 		int a=s[i]-'a';
 		if(a<0||a>=26){
 			cout<<"oops"<<endl;
 			exit(123);
 		}
 		if(go[v][a]==-1){
 			go[v][a]=sz(go);
 			go.pb(vector<int>(26,-1));
 			end.pb(0);
 		}
 		v=go[v][a];
 	}
 	end[v]=1;
 }
 
 void readdict(){
 	ifstream in("dict.txt");
 	int c=0;
 	int l=0;
 	string s;
 	while(in>>s){
 		add(s);
 		++c;
 		l+=sz(s)+1;
 	}
 	if(c!=521196 || l!=3844492){
 		cout<<"oops"<<endl;
 		exit(55);
 	}
 }
 
 string S;
 int dp[4100][5];
 
 void doit(int a,int p,int v,int d){
 	if(end[v]){
 		dp[a][min(4,a-p-1)]=min(dp[a][min(4,a-p-1)],d);
 	}
 	if(a==sz(S))
 		return;
 	forn(i,26){
 		bool typo=i!=S[a]-'a';
 		if(a-p<5 && typo)
 			continue;
 		int vv=go[v][i];
 		if(vv==-1)
 			continue;
 		int pp=typo?a:p;
 		int dd=d+(typo?1:0);
 		doit(a+1,pp,vv,dd);
 	}
 }
 
 int main() {
 #ifdef __ASD__
 	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
 #endif
 	
 	readdict();
 	
 	int tc;
 	cin>>tc;
 	forn(qqq,tc){
 		cin>>S;
 		forn(i,sz(S)+1){
 			forn(q,5){
 				dp[i][q]=INF;
 			}
 		}
 		dp[0][4]=0;
 		forn(i,sz(S)){
 			for(int q=4;q>=0;--q){
 				if(dp[i][q]==INF)
 					continue;
 				if(q<4 && dp[i][q]==dp[i][q+1])
 					continue;
 				doit(i,i-q-1,0,dp[i][q]);
 			}
 		}
 		int res=INF;
 		forn(q,5){
 			res=min(res,dp[sz(S)][q]);
 		}
 		if(res==INF){
 			cout<<"oops"<<endl;
 			exit(666);
 		}
 		printf("Case #%d: %d\n",qqq+1,res);
 	}
 	
 	return 0;
 }
