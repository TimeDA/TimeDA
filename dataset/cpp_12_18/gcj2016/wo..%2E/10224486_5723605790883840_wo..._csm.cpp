#include<cstdio>
 #include<vector>
 #include<algorithm>
 
 using namespace std;
 
 struct UnionFind{
 	int par[200];
 	void init(int N){
 		for(int i = 0; i < N; ++i) par[i] = i;
 	}
 	int find(int x){
 		if(x == par[x]) return x;
 		return par[x] = find(par[x]);
 	}
 	void unite(int x, int y){
 		//printf("unite %d %d\n", x, y);
 		x = find(x);
 		y = find(y);
 		if(x == y) return;
 		par[x] = y;
 	}
 	bool same(int x, int y){
 		return find(x) == find(y);
 	}
 };
 
 UnionFind uf;
 
 const int di[] = {-1, 0, 1, 0};
 const int dj[] = {0, 1, 0, -1};
 
 int R, C;
 int K;//(R + C) * 2
 
 bool isin(int i, int j){
 	return i >= 0 && j >= 0 && i < R && j < C;
 }
 
 int calcId(int i, int j, int dir){
 	return K + ((i * C + j) * 4 + dir);
 }
 
 void conAdj(int i, int j){
 	for(int k = 0; k < 4; ++k){
 		int ni = i + di[k];
 		int nj = j + dj[k];
 		if(!isin(ni, nj)) continue;
 		int v1 = calcId(i, j, k);
 		int v2 = calcId(ni, nj, k ^ 2);
 		uf.unite(v1, v2);
 	}
 }
 
 void conAdjAll(){
 	for(int i = 0; i < R; ++i){
 		for(int j = 0; j < C; ++j){
 			conAdj(i, j);
 		}
 	}
 }
 
 int field[100][100];//0 : \, 1 : /
 
 void conInner(int i, int j){
 	int vs[4];
 	for(int k = 0; k < 4; ++k) vs[k] = calcId(i, j, k);
 	if(field[i][j] == 0){
 		uf.unite(vs[0], vs[1]);
 		uf.unite(vs[2], vs[3]);
 	}else{
 		uf.unite(vs[0], vs[3]);
 		uf.unite(vs[1], vs[2]);
 	}
 }
 
 void conInnerAll(){
 	for(int i = 0; i < R; ++i){
 		for(int j = 0; j < C; ++j){
 			conInner(i, j);
 		}
 	}
 }
 
 void conEdgeAll(){
 	for(int i = 0; i < C; ++i){
 		int v = calcId(0, i, 0);
 		uf.unite(v, i);
 	}
 	for(int i = 0; i < R; ++i){
 		int v = calcId(i, C - 1, 1);
 		uf.unite(C + i, v);
 	}
 	for(int i = 0; i < C; ++i){
 		int v = calcId(R - 1, C - 1 - i, 2);
 		uf.unite(R + C + i, v);
 	}
 	for(int i = 0; i < R; ++i){
 		int v = calcId(R - 1 - i, 0, 3);
 		uf.unite(R + 2 * C + i, v);
 	}
 }
 
 int perm[100];
 
 bool check(){
 	uf.init((R * C * 4) + (R + C) * 2);
 	conAdjAll();
 	conInnerAll();
 	conEdgeAll();
 	for(int i = 0; i < (R + C) * 2; ++i){
 		int j = i ^ 1;
 		if(!uf.same(perm[i], perm[j])) return false;
 	}
 	return true;
 }
 
 void solve(int tnum){
 	K = (R + C) * 2;
 	for(int state = 0; state < (1 << (R * C)); ++state){
 		int c = 0;
 		for(int i = 0; i < R; ++i){
 			for(int j = 0; j < C; ++j){
 				field[i][j] = ((state >> (c++)) & 1);
 			}
 		}
 		bool flg = check();
 		if(flg){
 			printf("Case #%d:\n", tnum);
 			for(int i = 0; i < R; ++i){
 				for(int j = 0; j < C; ++j){
 					if(field[i][j] == 0) printf("\\");
 					else printf("/");
 				}
 				printf("\n");
 			}
 			return;
 		}
 	}
 	printf("Case #%d:\n", tnum);
 	printf("IMPOSSIBLE\n");
 }
 
 void input(){
 	scanf("%d%d", &R, &C);
 	for(int i = 0; i < (R + C) * 2; ++i){
 		scanf("%d", perm + i);
 		perm[i]--;
 	}
 }
 
 int main(){
 	int T;
 	scanf("%d", &T);
 	for(int datano = 0; datano < T; ++datano){
 		input();
 		solve(datano + 1);
 	//	return 0;
 	}
 	return 0;
 }
