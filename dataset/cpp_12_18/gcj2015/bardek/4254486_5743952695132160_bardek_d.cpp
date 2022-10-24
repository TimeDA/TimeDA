#include <bits/stdc++.h>
 using namespace std;
 
 #define fru(j,n) for(int j=0; j<(n); ++j)
 #define tr(it,v) for(typeof ((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
 #define trr(it,v) for(typeof ((v).rbegin()) it=(v).rbegin(); it!=(v).rend(); ++it)
 #define x first
 #define y second
 #define pb push_back
 #define ALL(G) (G).begin(),(G).end()
 
 #if 0
 #define DEB printf
 #else
 #define DEB(...)
 #endif
 
 typedef long long ll;
 typedef long long LL;
 typedef double D;
 typedef pair<int,int> pii;
 typedef vector<int> vi;
 
 const int inft = 1000000009;
 const int MOD = 1000000007;
 const int MAXN = 1000006;
 
 map<LL,LL> INPUT;
 
 bool dasie(LL w)
 {
 	if(w==0) {
 		tr(it,INPUT) if(it->y%2) return 0;
 		tr(it,INPUT) it->y/=2;
 		return 1;
 	}
 	map<LL,LL> M=INPUT;
 	map<LL,LL> NEW;
 	if(w<0)
 	{
 		tr(it,M)
 			if(it->y){
 				LL q=it->x-w;
 				M[q]-=it->y;
 				if(M[q]<0) return 0;
 				NEW[q]=it->y;
 			}
 	}
 	else trr(it,M)
 		if(it->y){
 			LL q=it->x-w;
 			M[q]-=it->y;
 			if(M[q]<0) return 0;
 			NEW[q]=it->y;
 		}
 	INPUT=NEW;
 	return 1;
 }
 
 int main()
 {
 	int o;
 	scanf("%d",&o);
 	fru(oo,o)
 	{
 		INPUT.clear();
 		printf("Case #%d:",oo+1);
 		vector<LL> ANS;
 		int n;
 		scanf("%d",&n);
 		LL A[n][2];
 		fru(j,2) fru(i,n) scanf("%lld",&A[i][j]);
 		fru(i,n) INPUT[A[i][0]]=A[i][1];
 		DEB("teraz:\n");
 		tr(it2,INPUT) DEB("%lld %lld\n",it2->x,it2->y);
 		while(INPUT.size()>0){
 			if(INPUT.size()==1 && INPUT[0]==1) break;
 			tr(it,INPUT){
 				LL e=it->x;
 				if(dasie(e)){
 					DEB("dorzucam e = %lld\n",e);
 					DEB("teraz:\n");
 					tr(it2,INPUT) DEB("%lld %lld\n",it2->x,it2->y);
 					ANS.pb(e);
 					break;
 				}
 			}
 		}
 		tr(it,ANS) printf(" %lld",*it);
 		printf("\n");
 	}
 	return 0;
 }
