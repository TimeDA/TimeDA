#include<stdio.h>
 #include<algorithm>
 int solve2(int m0,int m1){
 	return m0+(m1+1)/2;
 }
 int solve3(int m0,int m1,int m2){
 	if(m1<=m2){
 		return m0+m1+(m2-m1+2)/3;
 	} else {
 		return m0+m2+(m1-m2+2)/3;
 	}
 }
 int solve4(int m0,int m1,int m2,int m3){
 	int ans=m0;
 	if(m1>=m3){
 		ans+=m3;
 		m1-=m3;
 		if(m2%2==0){
 			ans+=m2/2;
 			ans+=(m1+3)/4;
 		} else {
 			ans+=m2/2+1;
 			if(m1>2)ans+=(m1-2+3)/4;
 		}
 	} else {
 		ans+=m1;
 		m3-=m1;
 		if(m2%2==0){
 			ans+=m2/2;
 			ans+=(m3+3)/4;
 		} else {
 			ans+=m2/2+1;
 			if(m3>2)ans+=(m3-2+3)/4;
 		}
 	}
 	return ans;
 }
 int a[4];
 int n,m;
 void input(){
 	int i,j,k;
 	scanf("%d%d",&n,&m);
 	a[0]=a[1]=a[2]=a[3]=0;
 	for(i=0;i<n;i++){
 		scanf("%d",&k);
 		a[k%m]++;
 	}
 }
 void solve(int T){
 	if(m==2){
 		printf("Case #%d: %d\n", T,solve2(a[0],a[1]));
 	} else if(m==3){
 		printf("Case #%d: %d\n", T,solve3(a[0],a[1],a[2]));
 	} else if(m==4){
 		printf("Case #%d: %d\n", T,solve4(a[0],a[1],a[2],a[3]));
 	}
 }
 int main(int argc, char *argv[]){
 	int T,TN;
 	scanf("%d",&TN);
 	int w;
 	if(argc>1&&sscanf(argv[1],"%d",&w)==1);
 	else w=-1;
 	for(T=1;T<=TN;T++){
 		input();
 		if(w==-1||T==w) solve(T);
 	}
 }
