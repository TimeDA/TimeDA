#include<cstdio>
 #include<cstring>
 #include<algorithm>
 
 using namespace std;
 
 char ch[55][55];
 bool ok;
 
 void init(int R,int C){
 	for(int i=0;i<R;i++){
 		for(int j=0;j<C;j++) ch[i][j]='.';
 		ch[i][C]='\0';
 	}
 	ok=true;
 }
 
 void rev(int R,int C){
 	char tmp[55][55];
 	for(int i=0;i<R;i++) for(int j=0;j<C;j++) tmp[j][i]=ch[i][j];
 	for(int i=0;i<C;i++) for(int j=0;j<R;j++) ch[i][j]=tmp[i][j];
 	for(int i=0;i<C;i++) ch[i][R]='\0';
 }
 
 void ROne(int C,int M){
 	ok=true;
 /*	int emp=C-M;
 	if(emp>=4){
 		ok=false;
 		return;
 	}
 	for(int i=0;i<C;i++) ch[0][i]='*';
 	if(emp==1){
 		ch[0][C-1]='c';
 	}else if(emp==2){
 		ch[0][C-1]='c';
 		ch[0][C-2]='.';
 	}else{
 		ch[0][C-1]='.';
 		ch[0][C-2]='c';
 		ch[0][C-3]='.';
 	}*/
 	for(int i=0;i<C;i++) ch[0][i]='.';
 	for(int i=0;i<M;i++) ch[0][i]='*';
 	ch[0][C-1]='c';
 }
 
 void RTwo(int C,int M){
 	ok=true;
 	int emp=C*2-M;
 	for(int i=0;i<2;i++) for(int j=0;j<C;j++) ch[i][j]='*';
 	if(emp==1){
 		ch[1][C-1]='c';
 	}else if(emp%2==1){
 		ok=false;
 	}else if(emp==2){
 		ok=false;
 	}else{
 		int a=emp/2;
 		for(int i=C-1;i>=C-a;i--){
 			ch[0][i]='.';
 			ch[1][i]='.';
 		}
 		ch[1][C-1]='c';
 	}
 }
 
 bool check(int R,int C,int M,int a,int b){
 	int emp=R*C-M;
 	int mi=a*2+b*2-4;
 	int Ma=a*b;
 	if(emp<mi||emp>Ma) return false;
 	for(int i=0;i<R;i++) for(int j=0;j<C;j++){
 		ch[i][j]='*';
 	}
 	for(int i=C-1;i>=C-a;i--){
 		ch[R-1][i]='.';
 		ch[R-2][i]='.';
 	}
 	for(int i=R-1;i>=R-b;i--){
 		ch[i][C-1]='.';
 		ch[i][C-2]='.';
 	}
 	int to=emp-mi;
 	for(int i=R-3;i>=R-b;i--) for(int j=C-3;j>=C-a;j--){
 		if(to==0) break;
 		ch[i][j]='.';
 		to--;
 	}
 	return true;
 }
 
 void solve(int R,int C,int M){
 	init(R,C);
 	int emp=R*C-M;
 	bool flipped=false;
 	int nR=R,nC=C;
 	if(R>C){
 		rev(R,C);
 		nR=C,nC=R;
 		flipped=true;
 	}
 	if(nR==1){
 		ROne(nC,M);
 	}else if(nR==2){
 		RTwo(nC,M);
 	}else{
 		if(emp==1){
 			ok=true;
 			for(int i=0;i<nR;i++) for(int j=0;j<nC;j++){
 				ch[i][j]='*';
 			}
 			ch[nR-1][nC-1]='c';
 		}else{
 			ok=false;
 			for(int i=2;i<=nC;i++) for(int j=2;j<=nR;j++){
 				bool flg=check(nR,nC,M,i,j);
 				if(flg==true){
 					ok=true;
 					ch[nR-1][nC-1]='c';
 					break;
 				}
 			}
 		}
 	}
 	if(flipped){
 		rev(nR,nC);
 	}
 }
 
 void output(int T,int R,int C){
 	printf("Case #%d:\n",T);
 	if(ok==false){
 		printf("Impossible\n");
 	}else{
 		for(int i=0;i<R;i++) printf("%s\n",ch[i]);
 	}
 }
 
 int main(){
 	int T;
 	scanf("%d",&T);
 	for(int tnum=0;tnum<T;tnum++){
 		int R,C,M;
 		scanf("%d%d%d",&R,&C,&M);
 		init(R,C);
 		solve(R,C,M);
 		output(tnum+1,R,C);
 	}
 	return 0;
 }
