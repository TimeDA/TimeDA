#include<stdio.h>
 long long e[10001], s[10001];
 long long map[101][101];
 double f[101][101];
 int main(){
 	int T,TN;
 	scanf("%d",&TN);
 	for(T=1;T<=TN;T++){
 		int i,j,k;
 		int n,m;
 		scanf("%d%d",&n,&m);
 		for(i=0;i<n;i++){
 			scanf("%lld%lld",&e[i],&s[i]);
 		}
 		for(i=0;i<n;i++){
 			for(j=0;j<n;j++){
 				scanf("%lld",&map[i][j]);
 				if(map[i][j]==-1) map[i][j]=1LL<<48;
 				f[i][j]=1e20;
 			}
 		}
 		for(i=0;i<n;i++){
 			f[i][i]=0;
 		}
 		for(k=0;k<n;k++){
 			for(i=0;i<n;i++){
 				for(j=0;j<n;j++){
 					if(map[i][j]>map[i][k]+map[k][j]){
 						map[i][j]=map[i][k]+map[k][j];
 					}
 				}
 			}
 		}
 		for(i=0;i<n;i++){
 			for(j=0;j<n;j++){
 				if(map[i][j]<=e[i]){
 					f[i][j]=map[i][j]/(double)s[i];
 				}
 			}
 		}
 		for(k=0;k<n;k++){
 			for(i=0;i<n;i++){
 				for(j=0;j<n;j++){
 					if(f[i][j]>f[i][k]+f[k][j]){
 						f[i][j]=f[i][k]+f[k][j];
 					}
 				}
 			}
 		}
 		printf("Case #%d:",T);
 		while(m--){
 			int a,b;
 			scanf("%d%d",&a,&b);
 			a--;
 			b--;
 			printf(" %f", f[a][b]);
 		}
 		puts("");
 
 	}
 }
