#include<stdio.h>
 char s[101][101];
 int n,m;
 int T;
 int main(){
 	freopen("A-small-attempt0.in.txt","r",stdin);
 	freopen("a.out","w",stdout);
 	scanf("%d",&T);
 	for(int tt=1;tt<=T;++tt){
 		scanf("%d%d",&n,&m);
 		for(int i=0;i<n;++i) scanf("%s",s[i]);
 		for(int i=0;i<n;++i) for(int j=0;j<m;++j) if(s[i][j]!='?'){
 			for(int k=j-1;k>=0&&s[i][k]=='?';--k){
 				s[i][k]=s[i][j];
 			}
 			for(int k=j+1;k<m&&s[i][k]=='?';++k){
 				s[i][k]=s[i][j];
 			}
 		}
 		for(int j=0;j<m;++j) for(int i=0;i<n;++i) if(s[i][j]!='?'){
 			for(int k=i-1;k>=0&&s[k][j]=='?';--k){
 				s[k][j]=s[i][j];
 			}
 			for(int k=i+1;k<n&&s[k][j]=='?';++k){
 				s[k][j]=s[i][j];
 			}
 		}
 		printf("Case #%d:\n",tt);
 		for(int i=0;i<n;++i) printf("%s\n",s[i]);
 	}
 	return 0;
 }
