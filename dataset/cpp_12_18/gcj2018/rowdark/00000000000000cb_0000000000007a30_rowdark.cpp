#include<stdio.h>
#include<vector>
#include<algorithm>
//#include<time.h>
//#include<stdlib.h>
#include<string.h>
using namespace std;
/*pair<int,int> selftest(int x,int y){
	int a=rand()%3-1,b=rand()%3-1;
	return {x-a,y-b};
}*/
int T,A;
int H,W;
int sx,sy,tx,ty,rx,ry,ox,oy;
bool mark[20][20];
void output(int x,int y){
	printf("%d %d\n",x,y);
	fflush(stdout);
}
/*int cnt=0;
void read(int &rx,int &ry,int x,int y){
	++cnt;
	pair<int,int> ret=selftest(x,y);
	rx=ret.first,ry=ret.second;
	for(int i=0;i<H;++i) for(int j=0;j<W;++j){
		if(i!=rx-ox||j!=ry-ox){
			if(!mark[i][j]){
				return;
			}
		}
	}
	rx=ry=0;
}*/
void solve(){
	memset(mark,0,sizeof(mark));
//#ifndef rowdark
	output(500,500);
	scanf("%d%d",&ox,&oy);
//#else
//	read(ox,oy,500,500);
//#endif
	sx=ox,sy=oy,tx=sx+H-1,ty=sy+W-1;
	mark[0][0]=true;
	while(sx<=tx&&sy<=ty){
		for(int i=sy;i<=ty;++i){
			while(!mark[sx-ox][i-oy]){
//#ifndef rowdark
				output(sx+1,i>=ty-1?ty-1:i+1);
				scanf("%d%d",&rx,&ry);
//#else
//				read(rx,ry,sx+1,i>=ty-1?ty-1:i+1);
//#endif
				if(rx<=0||ry<=0) return;
				mark[rx-ox][ry-oy]=1;
			}
			while(!mark[tx-ox][i-oy]){
//#ifndef rowdark
				output(tx-1,i>=ty-1?ty-1:i+1);
				scanf("%d%d",&rx,&ry);
//#else
//				read(rx,ry,tx+1,i>=ty-1?ty-1:i+1);
//#endif
				if(rx<=0||ry<=0) return;
				mark[rx-ox][ry-oy]=1;
			}
		}
		for(int i=sx;i<=tx;++i){
			while(!mark[i-ox][sy-oy]){
//#ifndef rowdark
				output(i>=tx-1?tx-1:i+1,sy+1);
				scanf("%d%d",&rx,&ry);
//#else
//				read(rx,ry,i>=tx-1?tx-1:i+1,sy+1);
//#endif
				if(rx<=0||ry<=0) return;
				mark[rx-ox][ry-oy]=1;
			}
			while(!mark[i-ox][ty-oy]){
//#ifndef rowdark
				output(i>=tx-1?tx-1:i+1,ty-1);
				scanf("%d%d",&rx,&ry);
//#else
//				read(rx,ry,i>=tx-1?tx-1:i+1,ty+1);
//#endif
				if(rx<=0||ry<=0) return;
				mark[rx-ox][ry-oy]=1;
			}
		}
		++sx,--tx,++sy,--ty;
	}
}
int main(){
//#ifdef rowdark
//	srand(unsigned(time(0)));
//#endif
	scanf("%d",&T);
	for(int tt=1;tt<=T;++tt){
		scanf("%d",&A);
		if(A==20) H=4,W=5;
		else H=14,W=15;
		solve();
//#ifdef rowdark
//		printf("###%d\n",cnt);
//		cnt=0;
//#endif
	}
	return 0;
}
