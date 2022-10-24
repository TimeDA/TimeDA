#include<cstdio>
 
 using namespace std;
 
 int cnt[20];
 int nums[2][4][4];
 
 void init(){
 	for(int i=0;i<20;i++) cnt[i]=0;
 }
 
 void get(int id,int r){
 	for(int i=0;i<4;i++){
 		cnt[nums[id][r][i]]++;
 	}
 }
 
 int main(){
 	int T;
 	scanf("%d",&T);
 	for(int datano=0;datano<T;datano++){
 		init();
 		int a;
 		scanf("%d",&a);
 		a--;
 		for(int i=0;i<4;i++) for(int j=0;j<4;j++) scanf("%d",&nums[0][i][j]);
 		get(0,a);
 		scanf("%d",&a);
 		for(int i=0;i<4;i++) for(int j=0;j<4;j++) scanf("%d",&nums[1][i][j]);
 		get(1,a-1);
 		int ans=-1;
 		bool ok=true;
 		for(int i=1;i<=16;i++){
 			if(ans==-1&&cnt[i]==2) ans=i;
 			else if(cnt[i]==2) ok=false;
 		}
 		printf("Case #%d: ",datano+1);
 		if(ans==-1) printf("Volunteer cheated!\n");
 		else if(ok==false) printf("Bad magician!\n");
 		else printf("%d\n",ans);
 	}
 	return 0;
 }
