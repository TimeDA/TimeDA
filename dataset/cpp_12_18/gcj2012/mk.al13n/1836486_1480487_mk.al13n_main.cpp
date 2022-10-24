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
 		vector<double> J(n);
 		double s=0;
 		forn(i,n){
 			cin>>J[i];
 			s+=J[i];
 		}
 		forn(i,n)
 			J[i]/=s;
 		cout<<"Case #"<<qqq+1<<":";
 		forn(k,n){
 			double a=0,b=1;
 			forn(qqqqqq,30){
 				double y=(a+b)/2;
 				double v=0;
 				forn(i,n)
 					v+=max(0.,J[k]+y-J[i]);
 				if(v>1)
 					b=y;
 				else
 					a=y ;
 			}
 			printf(" %.15lf",(a+b)/2*100);
 		}
 		cout<<endl;
 	}
 
     return 0;
 }
