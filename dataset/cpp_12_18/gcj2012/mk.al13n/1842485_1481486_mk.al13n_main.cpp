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
 		vector<PLL> ar(n);
 		forn(i,n)
 			cin>>ar[i].X>>ar[i].Y;
 		lng D;
 		cin>>D;
 		queue<PLL> qu;
 		qu.push(mp(ar[0].X,0));
 		lng maxp=ar[0].X;
 		forn(i,n){
 			if(maxp<ar[i].X)
 				break;
 			while(qu.front().X<ar[i].X)
 				qu.pop();
 			lng p=ar[i].X+min(ar[i].Y,ar[i].X-qu.front().Y);
 			if(p>maxp){
 				maxp=p;
 				qu.push(mp(p,ar[i].X));
 			}
 		}
 		cout<<"Case #"<<qqq+1<<": "<<(maxp>=D?"YES":"NO")<<endl;
 	}
 
     return 0;
 }
