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
 const int MAXN = 1000006;
 char win(char x, char y){
 	 fru(i,2){
 		  if(x=='P' && y=='S') return 'S';
 		  if(x=='P' && y=='R') return 'P';
 		  if(x=='S' && y=='R') return 'R';
 		  swap(x,y);
 	 }
 	 assert(0);
 }
 
 bool ok(string a){
 	 if(a.size()==1) return 1;
 	 assert(__builtin_popcount(a.size())==1);
 	 string b="";
 	 fru(i,a.size()/2){
 		  char x=a[2*i],y=a[2*i+1];
 		  if(x==y) return 0;
 		  b=b+win(x,y);
 	 }
 	 return ok(b);
 }
 
 string solve(){
 	 int p,r,s,n;
 	 scanf("%d%d%d%d",&n,&r,&p,&s);
 	 string A="";
 	 fru(i,p) A=A+"P";
 	 fru(i,r) A=A+"R";
 	 fru(i,s) A=A+"S";
 	 sort(ALL(A));
 	 do{
 		  if(ok(A)) return A;
 	 }
 	 while(next_permutation(ALL(A)));
 	 return "IMPOSSIBLE";
 }
 
 int main(){
 	int o;
 	scanf("%d",&o);
 	fru(oo,o){
 		 printf("Case #%d: ",oo+1);
 		 printf("%s\n",solve().c_str());		 
 	}
     return 0;
 }
