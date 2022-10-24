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
 
 typedef pair<pii,int> elem;
 
 priority_queue<elem> PQ;
 set<int> S;
 
 elem licz(int u){
 	 int L,R;
 	 auto it=S.upper_bound(u);
 	 L=*it;
 	 --it;
 	 R=*it;
 	 L=abs(L-u);
 	 R=abs(R-u);
 	 return elem(pii(min(L,R),-max(L,R)),-u);
 }
 
 int main(){
 	int o;
 	scanf("%d",&o);
 	fru(oo,o){
 		 printf("Case #%d: ",oo+1);
 		 while(!PQ.empty()) PQ.pop();
 		 S.clear();
 		 int n,k;
 		 scanf("%d%d",&n,&k);
 		 S.insert(0);
 		 S.insert(n+1);
 		 fru(i,n) PQ.push(licz(i+1));
 		 elem t;
 		 fru(_,k){
 			  while(1){
 					elem el=PQ.top();
 					PQ.pop();
 					int u=-el.y;
 					t=licz(u);
 //					printf("(%d,%d,%d) -> %d,%d,%d\n",el.x.x,el.x.y,el.y,t.x.x,t.x.y,t.y);
 					if(t!=el){
 						 PQ.push(t);
 //						 assert(t.x.x*2<el.x.x+5);
 					}
 					else{
 						 S.insert(u);
 						 break;
 					}
 			  }
 		 }
 		 printf("%d %d\n",-t.x.y-1,t.x.x-1);
 	}
     return 0;
 }
