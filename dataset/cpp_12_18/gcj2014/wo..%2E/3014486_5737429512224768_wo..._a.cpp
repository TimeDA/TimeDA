#include<cstdio>
 #include<set>
 #include<algorithm>
 
 using namespace std;
 
 int a[10100];
 
 int main(){
 	int T;
 	scanf("%d",&T);
 	for(int datano=0;datano<T;datano++){
 		int N,X;
 		scanf("%d%d",&N,&X);
 		for(int i=0;i<N;i++){
 			scanf("%d",a+i);
 		}
 		int ans=0;
 		sort(a,a+N);
 		int le=0,ri=N-1;
 		for(;ri>le;){
 			if(a[ri]+a[le]<=X){
 				ri--;
 				le++;
 				ans++;
 			}else{
 				ans++;
 				ri--;
 			}
 		}
 		if(ri==le){
 			ans++;
 		}
 		printf("Case #%d: %d\n",datano+1,ans);
 	}
 	return 0;
 }
