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
 
 int F[110][110];
 int C[110][110];
 double dist[110][110];
 bool done[110][110];
 
 int main(){
 #ifdef __ASD__
     freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
 #endif
     //ios_base::sync_with_stdio(false);
 
 	int tc;
 	cin>>tc;
 	forn(qqq,tc){
 		int H,N,M;
 		cin>>H>>N>>M;
 		forn(i,N+2){
 			forn(j,M+2){
 				dist[i][j]=dinf;
 				done[i][j]=false;
 				C[i][j]=F[i][j]=0;
 			}
 		}
 		forn(i,N){
 			forn(j,M){
 				cin>>C[i+1][j+1];
 			}
 		}
 		forn(i,N){
 			forn(j,M){
 				cin>>F[i+1][j+1];
 			}
 		}
 		priority_queue<pair<double,PII>,vector<pair<double,PII> >, greater<pair<double,PII> > > qu;
 		dist[1][1]=0;
 		qu.push(mp(0,mp(1,1)));
 		while(!qu.empty()){
 			int a,b;
 			do{
 				a=qu.top().Y.X;
 				b=qu.top().Y.Y;
 				qu.pop();
 			}while(!qu.empty()&&done[a][b]);
 			if(done[a][b])
 				break;
 			done[a][b]=true;
 			const int da[]={0,0,-1,1};
 			const int db[]={-1,1,0,0};
 			forn(dd,4){
 				int aa=a+da[dd];
 				int bb=b+db[dd];
 				if(F[a][b]+50>C[aa][bb]||F[aa][bb]+50>C[aa][bb]||F[aa][bb]+50>C[a][b])
 					continue;
 				double dt=(H-10*dist[a][b]-(C[aa][bb]-50))/10;
 				if(dt<eps)
 					dt=0;
 				double v=dist[a][b]+dt;
 				if(dist[a][b]==0&&dt==0)
 					v=0;
 				else if(H-10*(dist[a][b]+dt)-F[a][b]+eps>=20)
 					v+=1;
 				else
 					v+=10;
 				if(v<dist[aa][bb]-eps){
 					if(done[aa][bb])
 						exit(321);
 					dist[aa][bb]=v;
 					qu.push(mp(v,mp(aa,bb)));
 				}
 			}
 		}
 		if(!done[N][M])
 			exit(123);
 		printf("Case #%d: %.15lf\n",qqq+1,dist[N][M]);
 	}
 
     return 0;
 }
