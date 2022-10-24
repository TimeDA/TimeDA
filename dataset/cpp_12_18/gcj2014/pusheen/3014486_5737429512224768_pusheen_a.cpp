#include<stdio.h>
 #include<algorithm>
 //#define DEBUG
 #ifdef DEBUG
 #define CASET printf("Case #%d: \n",T)
 #define eprintf(...) printf(__VA_ARGS__)
 #else
 #define CASET printf("Case #%d: ",T)
 #define eprintf(...) 
 #endif
 int a[100001];
 int solve(){
 	int i,j,k;
 	int n,m;
 	scanf("%d%d",&n,&m);
 	for(i=0;i<n;i++){
 		scanf("%d",&a[i]);
 	}
 	std::sort(a,a+n);
 	int ans=0;
 	for(i=n-1;i>=0;i--){
 		if(a[i]<=0)continue;
 		k=m-a[i];
 		for(j=i-1;j>=0;j--){
 			if(a[j]<=0)continue;
 			if(a[j]<=k)break;
 		}
 		ans++;
 		a[i]=0;
 		if(j>=0){
 			a[j]=0;
 		}
 			
 	}
 	return ans;
 }
 int main(){
 	int T,TN=1000000;
 #ifndef DEBUG
 	scanf("%d",&TN);
 #endif
 	for(T=1;T<=TN;T++){
 		CASET;
 		int k=solve();
 		if(k==-1){
 			puts("NOT POSSIBLE");
 		} else {
 			printf("%d\n",k);
 		}
 	}
 }
