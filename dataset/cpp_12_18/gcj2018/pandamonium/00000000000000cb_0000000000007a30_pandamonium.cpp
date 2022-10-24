#include <bits/stdc++.h>
using namespace std;
int t,a,r,c,b[4][1004];
int main(){
	scanf("%d",&t);
	for(int tc=0;tc<t;tc++){
		scanf("%d",&a);
		memset(b,0,sizeof(b));
		int col=2;
		bool done=0;
		while(col<a/3){
			printf("%d %d\n",2,col);
			fflush(stdout);
			scanf("%d %d",&r,&c);
			if(r==-1) return 0;
			if(r==0){
				done=1;
				break;
			}
			b[r][c]=1;
			if(b[1][col-1]&&b[2][col-1]&&b[3][col-1]) col++;
		}
		if(!done){
			while(1){
				printf("%d %d\n",2,col);
				fflush(stdout);
				scanf("%d %d",&r,&c);
				if(r==-1) return 0;
				if(r==0) break;
			}
		}
	}
	return 0;
}

