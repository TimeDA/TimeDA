#pragma comment(linker,"/STACK:256000000")
 #include <iostream>
 #include <cstdio>
 #include <algorithm>
 #include <vector>
 #include <cmath>
 #include <memory.h>
 #include <string>
 #include <set>
 #include <queue>
 #include <map>
 #include <iomanip>
 #include <sstream>
 #include <stack>
 using namespace std;
 #define forn(i,n) for(int i=0;i<(n);++i)
 #define forv(i,v) forn(i,(int)(v).size())
 #define iinf 1000000000
 #define linf 1000000000000000000LL
 #define dinf 1e200
 #define all(v) (v).begin(),(v).end()
 #define pb push_back
 #define mp make_pair
 #define lng long long
 #define eps 1e-10
 #define EQ(a,b) (fabs((a)-(b))<eps)
 #define SQ(a) ((a)*(a))
 #define PI 3.14159265359
 #define index asdindex
 #define FI first
 #define SE second
 #define prev asdprev
 #define PII pair<int,int> 
 #define PLL pair<lng,lng> 
 #define X first
 #define Y second
 #define unlink asdunlink
 typedef unsigned char uchar;
 typedef unsigned int uint;
 inline int mymax(int a,int b){return a<b?b:a;}
 inline int mymin(int a,int b){return a>b?b:a;}
 inline lng mymax(lng a,lng b){return a<b?b:a;}
 inline lng mymin(lng a,lng b){return a>b?b:a;}
 
 int res[3000];
 int high[3000];
 vector<int> src[3000];
 int n;
 
 void doit(int a,int y,int d){
 	res[a]=y;
 	forv(i,src[a]){
 		++d;
 		doit(src[a][i],y-d*(a-src[a][i]),d);
 	}
 }
 
 bool check(){
 	forn(i,n-1){
 		pair<double,int> mx(-dinf,-1);
 		for(int j=i+1;j<n;++j)
 			mx=max(mx,mp(1.*(res[j]-res[i])/(j-i),j));
 		if(mx.Y!=high[i])
 			return false;
 	}
 	return true;
 }
 
 int main(){
 #ifdef __ASD__
     freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
 #endif
     //ios_base::sync_with_stdio(false);
 
 	int tc;
 	cin>>tc;
 	forn(qqq,tc){
 		cin>>n;
 		forn(i,n)
 			src[i].clear();
 		vector<int> st;
 		st.pb(iinf);
 		bool imp=false;
 		forn(i,n-1){
 			while(st.back()==i)
 				st.pop_back();
 			int a;
 			cin>>a;
 			--a;
 			if(a>st.back())
 				imp=true;
 			src[a].pb(i);
 			high[i]=a;
 			st.pb(a);
 		}
 		doit(n-1,iinf/2,-1000);
 		cout<<"Case #"<<qqq+1<<": ";
 		if(imp){
 			cout<<"Impossible";
 		}else{
 			forn(i,n)
 				cout<<res[i]<<' ';
 			if(!check())
 				cout<<"WRONG!";
 		}
 		cout<<endl;
 	}
 
     return 0;
 }
