#include<stdio.h>
 #include<algorithm>
 #define eps (1e-6)
 int main(){
 	int i,j,k;
 	int T,TN;
 	double v,x;
 	double r[101],c[101];
 	
 	scanf("%d",&TN);
 	for(T=1;T<=TN;T++){
 		int n;
 		scanf("%d",&n);
 		scanf("%lf%lf",&v,&x);
 		for(i=0;i<n;i++)scanf("%lf%lf",&r[i],&c[i]);
 		double rb=0,cb=0,rs=0,cs=0,re=0;
 		for(i=0;i<n;i++){
 			if(c[i]>x+eps){
 				rb+=r[i];
 				cb+=r[i]*c[i];
 			} else if(c[i]<x-eps){
 				rs+=r[i];
 				cs+=r[i]*c[i];
 			} else {
 				re+=r[i];
 			}
 		}
 		if(rb<eps||rs<eps){
 			if(re<eps){
 				printf("Case #%d: IMPOSSIBLE\n",T);
 				continue;
 			} else {
 				printf("Case #%d: %.10f\n",T,v/re);
 				continue;
 			}
 		}
 		//cb/=rb;
 		//cs/=rs;
 		if((cs+cb)/(rs+rb)>=x){
 			cb/=rb;
 			cs/=rs;
 			rb=(rs*cs-x*rs)/(x-cb);
 			//rb small
 		} else {
 			cb/=rb;
 			cs/=rs;
 			rs=(rb*cb-x*rb)/(x-cs);
 		}
 		
 			//rs small
 			
 		
 		
 		
 	
 			printf("Case #%d: %.10f\n",T,v/(rb+rs+re));
 	}
 }
