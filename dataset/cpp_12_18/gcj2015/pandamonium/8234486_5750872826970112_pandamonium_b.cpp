#include <cstdio>
 #define EPS 0.000000000000001
 int t,n;
 double vol,temp,r[105],c[105];
 int main(){
 	scanf("%d",&t);
 	for(int a=1;a<=t;a++){
 		scanf("%d",&n);
 		scanf("%lf %lf",&vol,&temp);
 		for(int x=0;x<n;x++){
 			scanf("%lf %lf",&r[x],&c[x]);
 		}
 		if(n==1){
 			if(c[0]-temp>EPS||temp-c[0]>EPS){
 				printf("Case #%d: IMPOSSIBLE\n",a);
 			}
 			else{
 				printf("Case #%d: %.7lf\n",a,vol/r[0]);
 			}
 		}
 		else if(n==2){
 			if(c[0]-temp>EPS&&c[1]-temp>EPS||temp-c[0]>EPS&&temp-c[1]>EPS){
 				printf("Case #%d: IMPOSSIBLE\n",a);
 				continue;
 			}
 			if(c[0]-c[1]<EPS&&c[1]-c[0]<EPS){
 				printf("Case #%d: %.7lf\n",a,r[0]-r[1]>EPS?vol/r[0]:vol/r[1]);
 				continue;
 			}
 			double b=vol*(temp-c[1])/(r[0]*(c[0]-c[1]));
 			double d=(vol-r[0]*b)/r[1];
 			printf("Case #%d: %.7lf\n",a,b-d>EPS?b:d);
 		}
 	}
 	return 0;
 }
