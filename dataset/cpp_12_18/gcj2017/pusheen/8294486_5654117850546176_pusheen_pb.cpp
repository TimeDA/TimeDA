#include<stdio.h>
 int c[7]; // " R, O, Y, G, B, V"
 char ch[8]=" RYOBVG";
 char sol[1000001];
 int main(){
 	int T,TN;
 	scanf("%d",&TN);
 	for(T=1;T<=TN;T++){
 		int i,j,k;
 		int n;
 		scanf("%d%d%d%d%d%d%d",&n,c+1,c+3,c+2,c+6,c+4,c+5);
 		if(c[1]*2>n||c[2]*2>n||c[4]*2>n){
 			printf("Case #%d: IMPOSSIBLE\n", T);
 			continue;
 		}
 		sol[n]=0;
 		int major, minor;
 		if(c[1]>=c[2]&&c[1]>=c[4]){
 			major=1;
 			if(c[2]>=c[4]){
 				minor=2;
 			} else {
 				minor=4;
 			}
 		} else if(c[2]>=c[1]&&c[2]>=c[4]){
 			major=2;
 			if(c[1]>=c[4]){
 				minor=1;
 			} else {
 				minor=4;
 			}
 		} else if(c[4]>=c[1]&&c[4]>=c[2]){
 			major=4;
 			if(c[2]>=c[1]){
 				minor=2;
 			} else {
 				minor=1;
 			}
 		}
 		for(i=0;i<n;i++) sol[i]='?';
 		for(i=j=0;j<c[major];i+=2,j++){
 			sol[i]=ch[major];
 		}
 		if(j!=c[major]){
 			fprintf(stderr, "QQ");
 			while(1);
 		}
 		for(i=n-1-(n%2?1:0),j=0;j<c[minor];i-=2,j++){
 			sol[i]=ch[minor];
 		}
 		if(j!=c[minor]){
 			fprintf(stderr, "QQ");
 			while(1);
 		}
 		for(i=0;i<n;i++) {
 			if(sol[i]=='?'){
 				sol[i]=ch[7-minor-major];
 			}
 		}
 		
 		printf("Case #%d: %s\n",T,sol);
 	}
 }
