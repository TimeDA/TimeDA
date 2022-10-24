#include<stdio.h>
 #include<string.h>
 #include<algorithm>
 double a[10001];
 int n,H,W;
 double x[11],y[11];
 double dis(double xx,double xy){
 	return xx*xx+xy*xy;
 }
 int myrand(){
 	return (rand()*5512114+rand()*1214+rand())&0x7FFFFFFF;
 }
 bool ok;
 void go(int dep){
 	if(dep==n){
 		for(int i=0;i<n;i++){
 			printf("%lf %lf ",x[i],y[i]);
 		}
 		ok=1;
 		return;
 	}
 	int i,j,k;
 	for(i=0;i<20;i++){
 		int t=0;
 		while(t++<10000){
 			x[dep]=(myrand()%(2*(W+1)-1))*0.5;
 			y[dep]=(myrand()%(2*(H+1)-1))*0.5;
 			for(j=0;j<dep;j++){
 				//printf("%lf ",(a[j]+a[dep])*(a[j]+a[dep]));
 				if(dis(x[j]-x[dep],y[j]-y[dep])<(a[j]+a[dep])*(a[j]+a[dep]))break;
 			}
 			if(j>=dep)break;
 			
 		}
 		if(t<10000-1)go(dep+1);
 		if(ok)return;
 	}
 }
 main(){
 	int i,j,k;
 	int T,TN;
 	int m;
 
 	scanf("%d",&TN);
 	for(T=1;T<=TN;T++){
 		printf("Case #%d: ",T);
 		scanf("%d%d%d",&n,&W,&H);
 		for(i=0;i<n;i++){
 			scanf("%lf",&a[i]);
 		}
 		go(0);
 		
 		
 		
 		printf("\n");
 	}
 }
 	
