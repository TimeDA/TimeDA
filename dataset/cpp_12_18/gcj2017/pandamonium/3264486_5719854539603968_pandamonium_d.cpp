#include <bits/stdc++.h>
 using namespace std;
 struct AugPath {
     int A, B;   //size of left, right groups
     vector<vector<int> > G; //size A
     vector<bool> visited;   //size A
     vector<int> P;          //size B
     
     AugPath(int _A, int _B): A(_A), B(_B), G(_A), P(_B, -1) {}
     
     void AddEdge(int a, int b) {    //a from left, b from right
         G[a].push_back(b);
     }
     bool Aug(int x) {
         if (visited[x]) return 0;
         visited[x] = 1;
         /* Greedy heuristic */
         for (auto it:G[x]) {
             if (P[it] == -1) {
                 P[it] = x;
                 return 1;
             }
         }
         for (auto it:G[x]) {
             if (Aug(P[it])) {
                 P[it] = x;
                 return 1;
             }
         }
         return 0;
     }
     int MCBM() {
         int matchings = 0;
         for (int i = 0; i < A; ++i) {
             visited.resize(A, 0);
             matchings += Aug(i);
             visited.clear();
         }
         return matchings;
     }
     vector<pair<int, int> > GetMatchings() {
         vector<pair<int, int> > matchings;
         for (int i = 0; i < B; ++i) {
             if (P[i] != -1) matchings.emplace_back(P[i], i);
         }
         return matchings;
     }
 };
 int t,n,m,r,c;
 char str[2];
 bitset <105> row,col;
 bitset <205> ldiag,rdiag;
 bool pluss[105][105],cross[105][105];
 char grid[105][105];
 int main(){
 	scanf("%d",&t);
 	for(int tc=1;tc<=t;tc++){
 		scanf("%d %d",&n,&m);
 		int ans1=n,ans2=0;
 		row.reset();
 		col.reset();
 		ldiag.reset();
 		rdiag.reset();
 		memset(pluss,0,sizeof(pluss));
 		memset(cross,0,sizeof(cross));
 		AugPath mcbm = AugPath(2*n,2*n);
 		for(int x=0;x<n;x++){
 			for(int y=0;y<n;y++){
 				grid[x][y]='.';
 			}
 		}
 		for(int x=0;x<m;x++){
 			scanf("%s %d %d",str,&r,&c);
 			grid[r-1][c-1]=str[0];
 			if(str[0]!='+'){
 				row[r-1]=1;
 				col[c-1]=1;
 			}
 			if(str[0]!='x'){
 				ldiag[r+c-2]=1;
 				rdiag[r-c+n]=1;
 				ans1++;
 			}
 		}
 		for(int x=0;x<n;x++){
 			for(int y=0;y<n;y++){
 				if(!row[x]&&!col[y]){
 					cross[x][y]=1;
 					row[x]=1;
 					col[y]=1;
 					ans2++;
 				}
 				if(!ldiag[x+y]&&!rdiag[x-y+n]){
 					mcbm.AddEdge(x+y,x-y+n);
 				}
 			}
 		}
 		ans1+=mcbm.MCBM();
 		for(pair <int,int> e: mcbm.GetMatchings()){
 			pluss[(e.first+e.second-n)/2][(e.first-e.second+n)/2]=1;
 			if(!cross[(e.first+e.second-n)/2][(e.first-e.second+n)/2]) ans2++;
 		}
 		printf("Case #%d: %d %d\n",tc,ans1,ans2);
 		for(int x=0;x<n;x++){
 			for(int y=0;y<n;y++){
 				if(pluss[x][y]&&cross[x][y]||pluss[x][y]&&grid[x][y]=='x'||cross[x][y]&&grid[x][y]=='+') printf("o %d %d\n",x+1,y+1);
 				else if(pluss[x][y]) printf("+ %d %d\n",x+1,y+1);
 				else if(cross[x][y]) printf("x %d %d\n",x+1,y+1);
 			}
 		}
 	}
 	return 0;
 }						
