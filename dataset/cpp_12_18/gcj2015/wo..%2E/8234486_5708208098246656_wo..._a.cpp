#include<cstdio>
 #include<vector>
 #include<algorithm>
 
 using namespace std;
 
 char field[110][110];
 int R,C;
 
 vector<int> rows[110],cols[110];
 
 int solve(){
 	for(int i=0;i<R;i++) rows[i].clear();
 	for(int i=0;i<C;i++) cols[i].clear();
 	for(int i=0;i<R;i++){
 		for(int j=0;j<C;j++){
 			if(field[i][j]!='.') rows[i].push_back(j);
 		}
 	}
 	for(int j=0;j<C;j++){
 		for(int i=0;i<R;i++){
 			if(field[i][j]!='.') cols[j].push_back(i);
 		}
 	}
 	int ans=0;
 	for(int i=0;i<R;i++) for(int j=0;j<C;j++){
 		if(field[i][j]=='.') continue;
 		if(rows[i].size()==1&&cols[j].size()==1) return -1;
 		if(field[i][j]=='>' && rows[i].back()==j) ans++;
 		if(field[i][j]=='v' && cols[j].back()==i) ans++;
 		if(field[i][j]=='<' && rows[i].front()==j) ans++;
 		if(field[i][j]=='^' && cols[j].front()==i) ans++;
 	}
 	return ans;
 }
 
 int main(){
 	int T;
 	scanf("%d",&T);
 	for(int datano=1;datano<=T;datano++){
 		scanf("%d%d",&R,&C);
 		for(int i=0;i<R;i++) scanf("%s",field[i]);
 		int ans=solve();
 		if(ans==-1) printf("Case #%d: IMPOSSIBLE\n",datano);
 		else printf("Case #%d: %d\n",datano,ans);
 	}
 	return 0;
 }
