#include<cstdio>
 #include<algorithm>
 
 using namespace std;
 
 double C,F,X;
 
 int li(){
 	double num=(F+2)*(X-C)-X*2;
 	double den=C*F;
 	return num/den;
 }
 
 double dif(int n){
 	double pl=C/(2.0+n*F)+X/(2.0+(n+1)*F);
 	double mi=X/(2.0+n*F);
 	return pl-mi;
 }
 
 double get(int n){
 	double ans=0;
 	for(int i=0;i<n;i++) ans+=C/(2.0+i*F);
 	ans+=X/(2.0+n*F);
 	return ans;
 }
 
 int main(){
 	int T;
 	scanf("%d",&T);
 	for(int datano=0;datano<T;datano++){
 		scanf("%lf%lf%lf",&C,&F,&X);
 		if(C>X){
 			printf("Case #%d: %.7f\n",datano+1,X/2);
 			continue;
 		}
 		int st=li()-2;
 		if(st<0) st=0;
 		double ans=get(st);
 		double tmp=ans;
 		for(int i=st;i<st+6;i++){
 			tmp+=dif(i);
 			ans=min(ans,tmp);
 		}
 		printf("Case #%d: %.7f\n",datano+1,ans);
 	}
 	return 0;
 }
