#include<stdio.h>
 char s[1001];
 int main(){
 	int T,TN;
 	scanf("%d",&TN);
 	for(T=1;T<=TN;T++){
 		int n,m;
 		int i,j,k=0;
 		scanf("%s%d",s,&m);
 		for(n=0;s[n];n++);
 		for(i=0;i+m<=n;i++){
 			if(s[i]=='-'){
 				k++;
 				for(j=i;j<i+m;j++){
 					s[j]=s[j]=='-'?'+':'-';
 				}
 			}
 		}
 		for(i=0;i<n;i++){
 			if(s[i]=='-'){
 				break;
 			}
 		}
 		if(i<n){
 			printf("Case #%d: IMPOSSIBLE\n",T);
 		} else {
 			printf("Case #%d: %d\n",T,k);
 		}
 	}
 }
 
