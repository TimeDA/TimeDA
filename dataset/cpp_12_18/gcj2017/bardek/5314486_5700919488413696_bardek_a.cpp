#include <bits/stdc++.h>
 using namespace std;
 
 #define fru(j,n) for(int j=0; j<(n); ++j)
 #define tr(it,v) for(auto it=(v).begin(); it!=(v).end(); ++it)
 #define x first
 #define y second
 #define pb push_back
 #define ALL(G) (G).begin(),(G).end()
 
 #if 1
 #define DEB printf
 #else
 #define DEB(...)
 #endif
 
 typedef long long LL;
 typedef double D;
 typedef pair<int,int> pii;
 typedef vector<int> vi;
 const int inft = 1000000009;
 const int MOD = 1000000007;
 const int MAXN = 101;
 
 char T[MAXN][MAXN][MAXN][4];
 int p;
 inline int mm(int a){
 /*	 assert(a<2*p);
 	 assert(a>-p);
 	 return (a+p)%p;
 */	 
 	 return a<0?a+p:(a>=p?a-p:a);}
 
 int main(){
 	 int o;
 	 scanf("%d",&o);
 	 fru(oo,o){
 		  int n;
 		  scanf("%d%d",&n,&p);
 		  vi E(4,0);
 		  int sum=0;
 		  fru(i,n){
 				int a;
 				scanf("%d",&a);
 				sum+=a;
 				E[a%p]++;
 		  }
 		  fru(i,MAXN) fru(j,MAXN) fru(k,MAXN) fru(e,4) T[i][j][k][e]=-105;
 		  T[0][0][0][0]=0;
 		  for(int s=1;s<=n-E[0];s++)
 				for(int i=0;i<=s && i<=E[1];++i)
 					 for(int j=max(0,s-i-E[3]);j+i<=s && j<=E[2];++j){
 						  int k=s-i-j;
 						  assert(k>=0 && k<=E[3]);
 								fru(r,p)
 								{
 									 char ret=-105;
 									 if(i) ret=max(ret,char(T[i-1][j][k][mm(r+p-1)]+(r==1)));
 									 if(j) ret=max(ret,char(T[i][j-1][k][mm(r+p-2)]+(r==2)));
 									 if(k) ret=max(ret,char(T[i][j][k-1][mm(r+p-3)]+(r==3)));
 									 T[i][j][k][r]=ret;
 								}
 					 }
 		  int w=T[E[1]][E[2]][E[3]][sum%p];
 		  if(n==E[0]) w=0;
 		  printf("Case #%d: ",oo+1);
 		  printf("%d\n",E[0]+w);
 	 }
 	 return 0;
 }
