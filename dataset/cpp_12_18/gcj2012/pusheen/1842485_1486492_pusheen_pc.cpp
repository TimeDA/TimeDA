#include<stdio.h>
 #include<string.h>
 #include<algorithm>
 int h[10001],a[10001],n;
 int check(){
 	int i,j,k;
 	for(i=0;i<n-1;i++){
 		for(j=i+1;j<a[i];j++){
 			if((h[j]-h[i])*(a[i]-i)  >= (h[a[i]]-h[i])*(j-i))break;
 		}
 		if(j<a[i])break;
 		for(j=a[i]+1;j<n;j++){
 			if((h[j]-h[i])*(a[i]-i)  > (h[a[i]]-h[i])*(j-i))break;
 		}
 		if(j<n)break;
 	}
 	if(i<n-1)return a[i];
 	return n;
 }
 main(){
 	int i,j,k;
 	int T,TN;
 	int m;
 	int S;
 	scanf("%d",&TN);
 	for(T=1;T<=TN;T++){
 		printf("Case #%d: ",T);
 		scanf("%d",&n);
 		for(i=0;i<n-1;i++){
 			scanf("%d",&a[i]);
 			a[i]--;
 			h[i]=10000;
 		}
 		h[n-1]=10000;
 		S=0;
 		while((k=check())<n){
 			S++;
 			if(S>=1000000)break;
 			//printf("[%d]",k);
 			//getchar();
 			//break;
 			h[k]++;
 		}
 		if(S>=1000000){
 			printf("Impossible");
 		} else {
 			for(i=0;i<n;i++){
 				printf("%d ",h[i]);
 			}
 		}
 		//go(0);
 		
 		
 		
 		
 		printf("\n");
 	}
 }
 	
