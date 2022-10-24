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
 #include <cstdlib>
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
 #define div asddiv
 #define divides asddivides
 typedef unsigned char uchar;
 typedef unsigned int uint;
 inline int mymax(int a,int b){return a<b?b:a;}
 inline int mymin(int a,int b){return a>b?b:a;}
 inline lng mymax(lng a,lng b){return a<b?b:a;}
 inline lng mymin(lng a,lng b){return a>b?b:a;}
 inline lng abs(lng a){return a<0?-a:a;}
 #ifdef __ASD__
 #define LOG(x) cerr<<x<<endl
 #else
 #define LOG(x)
 #endif
 
 bool wall[200][200];
 bool was[200][200];
 PII src[11000];
 int M;
 int n;
 int s;
 bool ring,bridge,fork;
 
 bool edg[7];
 bool corn[7];
 
 const int da[6]={0,0,-1,1,-1,1};
 const int db[6]={-1,1,0,0,-1,1};
 
 void dfs1(int a,int b){
 	if(was[a][b]||wall[a][b])
 		return;
 	was[a][b]=true;
 	forn(i,6){
 		dfs1(a+da[i],b+db[i]);
 	}
 }
 
 bool inside(int i,int j){
 	return i>0&&j>0&&i<n-1&&j<n-1&&abs(i-j)<s;
 }
 
 void dfs2(int a,int b){
 	if(!inside(a,b)||was[a][b]||!wall[a][b])
 		return;
 	was[a][b]=true;
 	if(a==1&&b==1)
 		corn[0]=true;
 	else if(a==1&&b==s)
 		corn[1]=true;
 	else if(a==s&&b==1)
 		corn[2]=true;
 	else if(a==n-2&&b==n-2)
 		corn[3]=true;
 	else if(a==n-2&&b==s)
 		corn[4]=true;
 	else if(a==s&&b==n-2)
 		corn[5]=true;
 	else{
 		if(a==1)
 			edg[0]=true;
 		if(b==1)
 			edg[1]=true;
 		if(a-b==s-1)
 			edg[2]=true;
 		if(b-a==s-1)
 			edg[3]=true;
 		if(a==n-2)
 			edg[4]=true;
 		if(b==n-2)
 			edg[5]=true;
 	}
 	forn(i,6){
 		dfs2(a+da[i],b+db[i]);
 	}
 }
 
 void detect(){
 	memset(was,0,sizeof(was));
 	forn(i,n){
 		forn(j,n){
 			if(inside(i,j)&&i==1||j==1||i==n-2||j==n-2||abs(i-j)==s-1)
 				dfs1(i,j);
 		}
 	}
 	forn(i,n){
 		forn(j,n){
 			if(!wall[i][j]&&!was[i][j])
 				ring=true;
 		}
 	}
 
 	memset(was,0,sizeof(was));
 	forn(i,n){
 		forn(j,n){
 			if(!inside(i,j)||was[i][j]||!wall[i][j])
 				continue;
 			memset(edg,0,sizeof(edg));
 			memset(corn,0,sizeof(corn));
 			dfs2(i,j);
 			int e=0,c=0;
 			forn(k,6){
 				if(edg[k])
 					++e;
 				if(corn[k])
 					++c;
 			}
 			if(e>=3)
 				fork=true;
 			if(c>=2)
 				bridge=true;
 		}
 	}
 }
 
 int main(){
 #ifdef __ASD__
     freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
 #endif
     //ios_base::sync_with_stdio(false);
 
 	int tc;
 	cin>>tc;
 	forn(qqq,tc){
 		cerr<<qqq<<endl;
 		cin>>s;
 		n=s+s+1;
 		forn(i,n){
 			forn(j,n){
 				if(inside(i,j))
 					wall[i][j]=false;
 				else
 					wall[i][j]=true;
 			}
 		}
 		cin>>M;
 		forn(i,M){
 			cin>>src[i].X>>src[i].Y;
 		}
 		bool done=false;
 		cout<<"Case #"<<qqq+1<<": ";
 		forn(i,M){
 			wall[src[i].X][src[i].Y]=true;
 			ring=bridge=fork=false;
 			detect();
 			vector<string> v;
 			if(bridge)
 				v.pb("bridge");
 			if(fork)
 				v.pb("fork");
 			if(ring)
 				v.pb("ring");
 			if(v.size()){
 				done=true;
 				forv(i,v){
 					if(i)
 						cout<<'-';
 					cout<<v[i];
 				}
 				cout<<" in move "<<i+1;
 				break;
 			}
 		}
 		if(!done)
 			cout<<"none";
 		cout<<endl;
 	}
 
     return 0;
 }
