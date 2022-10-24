#include<stdio.h>
 long long a[10001], b[10001];
 int main(){
 	int T,TN;
 	scanf("%d",&TN);
 	for(T=1;T<=TN;T++){
 		int i,j,k;
 		long long m,n;
 		scanf("%lld%lld",&m,&n);
 		for(i=0;i<n;i++){
 			scanf("%lld%lld",&a[i],&b[i]);
 		}
 		double speed=m / ((double)(m-a[0]) / b[0]);
 		for(i=1;i<n;i++){
 			double speed2=m / ((double)(m-a[i]) / b[i]);
 			if(speed2<speed){
 				speed=speed2;
 			}
 		}
 		printf("Case #%d: %f\n",T,speed);
 	}
 }
