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
 #include <ctime>
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
 #define eps 1e-5
 #define EQ(a,b) (fabs((a)-(b))<eps)
 #define SQ(a) ((a)*(a))
 #define PI 3.14159265359
 #define index asdindex
 #define FI first
 #define SE second
 #define prev asdprev
 #define PII pair<int,int> 
 #define PLL pair<lng,lng> 
 #define PDD pair<double,double> 
 #define X first
 #define Y second
 #define unlink asdunlink
 typedef unsigned char uchar;
 typedef unsigned int uint;
 inline int mymax(int a,int b){return a<b?b:a;}
 inline int mymin(int a,int b){return a>b?b:a;}
 inline lng mymax(lng a,lng b){return a<b?b:a;}
 inline lng mymin(lng a,lng b){return a>b?b:a;}
 
 int n,W,H;
 int R[1100];
 PDD res[1100];
 vector<PII> order;
 
 double frand(){
 	double r=.5;
 	forn(qqq,10)
 		r=(r+rand())/(RAND_MAX+1);
 	return r;
 }
 
 void read(){
 	cin>>n>>W>>H;
 	forn(i,n)
 		cin>>R[i];
 }
 
 void gentest(int nn){
 	n=nn;
 	double area=0;
 	forn(i,n){
 		R[i]=frand()*(100000-1)+1;
 		area+=PI*SQ(1.*R[i]);
 	}
 	area*=5;
 	W=rand()%(int)area+1;
 	H=((lng)ceil(area)+W-1)/W;
 }
 
 bool check(){
 	forn(i,n)
 		forn(j,i)
 			if(SQ(res[i].X-res[j].X)+SQ(res[i].Y-res[j].Y)<SQ(R[i]+R[j]+eps))
 				return false;
 	return true;
 }
 
 void random_fit(){
 	forn(i,n)
 		res[i]=mp(frand()*W,frand()*H);
 }
 
 void compact_fit(){
 	
 }
 
 void sorted_order(){
 
 }
 
 void random_order(){
 	
 }
 
 void almost_sorted_order(){
 	
 }
 
 void solve(){
 	do{
 		random_fit();
 	}while(!check());
 }
 
 void stress(){
 	double sumtime=0;
 	int cnt=0;
 	forn(qqq,1000){
 		gentest(1000);
 		clock_t t0=clock();
 		solve();
 		clock_t t1=clock();
 		double t=(t1-t0)*1./CLOCKS_PER_SEC;
 		cerr<<"time: "<<t<<endl;
 		sumtime+=t;
 		++cnt;
 	}
 	cout<<"avg time: "<<sumtime/cnt<<endl;;
 }
 
 int main(){
 #ifdef __ASD__
     freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
 #endif
     //ios_base::sync_with_stdio(false);
 
 	//stress();return 0;
 
 	int tc;
 	cin>>tc;
 	forn(qqq,tc){
 		read();
 		solve();
 		cout<<"Case #"<<qqq+1<<": ";
 		forn(i,n){
 			printf("%.15lf %.15lf ",res[i].X,res[i].Y);
 		}
 		cout<<endl;
 	}
 
     return 0;
 }
