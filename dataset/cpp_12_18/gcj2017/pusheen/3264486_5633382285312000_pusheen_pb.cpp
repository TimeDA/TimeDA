#include<stdio.h>
 char s[1001];
 bool check(long long n){
 	char t[23];
 	sprintf(t,"%lld",n);
 	for(int i=1;t[i];i++){
 		if(t[i-1]>t[i]) return false;
 	}
 	return true;
 }
 int main(){
 	int T,TN;
 	scanf("%d",&TN);
 	for(T=1;T<=TN;T++){
 		long long n;
 		scanf("%lld",&n);
 		if(n==1000000000000000000LL){
 			n--;
 		}
 		while(!check(n)){
 			long long m;
 			if(n%10==9){
 				m=10;
 				while(((n+1)/10)%m==0) m*=10;
 			} else {
 				m=n%10+1;
 			}
 			n-=m;
 		}
 		printf("Case #%d: %lld\n",T,n);
 	}
 }
 
