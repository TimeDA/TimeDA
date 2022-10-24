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
 
 char S[MAXN];
 
 int main(){
 	 int o;
 	 scanf("%d",&o);
 	 fru(oo,o){
 		  printf("Case #%d: ",oo+1);
 		  scanf("%s",S);
 		  int d=strlen(S);
 		  bool ok=0;
 		  fru(i,d) if(i && S[i]<S[i-1] && !ok){
 				for(int j=i-1;j>=0;--j) if(j==0 || S[j]>S[j-1]){
 					 S[j]--;
 					 for(int k=j+1;k<d;++k) S[k]='9';
 					 ok=1;
 					 break;
 				}
 		  }
 		  printf("%s\n",S[0]=='0'?S+1:S);
 	 }
 	 return 0;
 }
