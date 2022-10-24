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
 
 int T[6],IN[6];
 string X="ROYGBV";
 char ANS[1003];
 void solve(){
 	 int n;
 	 scanf("%d",&n);
 	 fru(i,6) scanf("%d",&T[i]);
 //	 scanf("%d%d%d",&T[0],&T[2],&T[4]);
 	 n=T[0]+T[2]+T[4];
 	 fru(i,6) IN[i]=T[i];
 	 ANS[n]=0;
 	 int w=0;
 	 fru(i,6) if(T[i]>T[w]) w=i;
 	 ANS[0]=X[w];
 	 T[w]--;
 	 int last=w;
 	 fru(i,n-1){
 		  int e=-1;
 		  fru(j,6) if(T[j] && j!=last && (e==-1 || T[e]<T[j] || (T[e]==T[j] && j==w))) e=j;
 		  if(e==-1){
 				ANS[0]='#';
 				return;
 		  }
 		  ANS[i+1]=X[e];
 		  T[e]--;
 		  last=e;
 	 }
 	 if(ANS[0]==ANS[n-1]) ANS[0]='#';
 }
 
 int BACK[300];
 
 void sprawdz(){
 	 vi C(6);
 	 int n=0;
 	 fru(i,6) n+=IN[i];
 	 fru(i,n) C[BACK[ANS[i]]]++;
 	 fru(i,6) assert(C[i]==IN[i]);
 }
 
 int main(){
 	 fru(i,6) BACK[X[i]]=i;
 	 int o;
 	 scanf("%d",&o);
 	 fru(oo,o){
 		  printf("Case #%d: ",oo+1);
 		  solve();
 		  if(ANS[0]=='#') printf("IMPOSSIBLE\n");
 		  else {
 				printf("%s\n",ANS);
 			  sprawdz();
 		  }
 		  /*if(zle()){
 				printf("wypisalem: %s\ndla wejscia:\n",ANS);
 				fru(i,6) printf("%d ",IN[i]);
 				puts("");
 		  }
 		  else fprintf(stderr,"%d:ok\n",oo);*/
 	 }
 	 return 0;
 }
