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
 
 int n;
 int src[22];
 const int B=1500000;
 PII dp[3100000];
 
 int main(){
 #ifdef __ASD__
     freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
 #endif
     //ios_base::sync_with_stdio(false);
 
 	int tc;
 	cin>>tc;
 	forn(qqq,tc){
 		int n;
 		cin>>n;
 		forn(i,n)
 			cin>>src[i];
 		memset(dp,0,sizeof(dp));
 		forn(k,n){
 			int v=src[k];
 			for(int i=B-1100000;i<=B+1100000;++i){
 				if((i!=B&&!dp[i].X&&!dp[i].Y)||(dp[i].X&(1<<k))||(dp[i].Y&(1<<k)))
 					continue;
 				int t;
 
 				t=i+v;
 				if(!dp[t].X&&!dp[t].Y)
 					dp[t]=mp(dp[i].X|(1<<k),dp[i].Y);
 
 				t=i-v;
 				if(!dp[t].X&&!dp[t].Y)
 					dp[t]=mp(dp[i].X,dp[i].Y|(1<<k));
 			}
 		}
 
 		cout<<"Case #"<<qqq+1<<":"<<endl;
 		if(!dp[B].X&&!dp[B].Y)
 			cout<<"Impossible"<<endl;
 		else{
 			forn(i,n){
 				if(dp[B].X&(1<<i))
 					cout<<src[i]<<' ';
 			}
 			cout<<endl;
 			forn(i,n){
 				if(dp[B].Y&(1<<i))
 					cout<<src[i]<<' ';
 			}
 			cout<<endl;
 		}
 	}
 
     return 0;
 }
