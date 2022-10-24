#include<cstdio>
 #include<algorithm>
 
 using namespace std;
 
 bool solve(int X,int R,int C){
 	if(X==1){
 		return true;
 	}else if(X==2){
 		if((R*C)%2!=0) return false;
 		return true;
 	}else if(X==3){
 		if((R*C)%3!=0) return false;
 		if(R==1||C==1) return false;
 		return true;
 	}else{//X=4
 		if((R*C)%4!=0) return false;
 		if(min(R,C)<=2) return false;
 		return true;
 	}
 }
 
 int main(){
 	int T;
 	scanf("%d",&T);
 	for(int datano=1;datano<=T;datano++){
 		int X,R,C;
 		scanf("%d%d%d",&X,&R,&C);
 		bool flg=solve(X,R,C);
 		if(flg){
 			printf("Case #%d: GABRIEL\n",datano);
 		}else{
 			printf("Case #%d: RICHARD\n",datano);
 		}
 	}
 	return 0;
 }
