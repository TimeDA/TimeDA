#include <bits/stdc++.h>
 #define INF (1<<30)
 using namespace std;
 int t;
 int hd,ad,hk,ak,b,d,attacks;
 int main(){
 	scanf("%d",&t);
 	for(int tc=1;tc<=t;tc++){
 		scanf("%d %d %d %d %d %d",&hd,&ad,&hk,&ak,&b,&d);
 		int ans=INF;
 		for(int debuf=0;debuf<=(d?(ak-1)/d+1:0);debuf++){
 			for(int buff=0;buff<=(b?(hk-1)/ad+1:0);buff++){
 				int turns=debuf+buff,curhd=hd,curad=ad,curhk=hk,curak=ak;
 				bool fail=0;
 				for(int x=0;x<debuf;x++){
 					if(curhd-max(curak-d,0)<=0){
 						turns++;
 						curhd=hd-curak;
 					}
 					curak=max(curak-d,0);
 					curhd-=curak;
 					if(curhd<=0) fail=1;
 				}
 				if(fail) break;
 				for(int x=0;x<buff;x++){	
 					if(curhd-curak<=0){
 						curhd=hd-curak;
 						turns++;
 					}
 					curad+=b;
 					curhd-=curak;
 					if(curhd<=0) fail=1;
 				}
 				if(fail) continue;
 				while(curhk>curad&&turns<1000000){
 					if(curhd-curak<=0){
 						curhd=hd-curak;
 						turns++;
 					}
 					turns++;
 					curhk-=curad;
 					curhd-=curak;
 					if(curhd<=0) fail=1;
 				}
 				if(fail||turns==1000000) continue;
 				ans=min(turns+1,ans);
 			}
 		}
 		if(ans<INF) printf("Case #%d: %d\n",tc,ans);
 		else printf("Case #%d: IMPOSSIBLE\n",tc);			
 	}
 	return 0;
 }
