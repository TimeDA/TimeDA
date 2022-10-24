#include <bits/stdc++.h>
 using namespace std;
 
 
 
 typedef vector< vector<int> > Board;
 
 
 vector< vector< pair<int,int> > > tmm;
 set< vector< pair<int,int> > > S;
 int dfs(int t,vector< pair<int,int> > now){
 	sort(now.begin(),now.end());
 	if( S.count(now) ) return 0;
 	else S.insert(now);
 	if( t == 0 ){
 		tmm.push_back(now);
 		return 0;
 	}
 	for(int i = 0 ; i < now.size() ; i++){
 		int dx[] = {0,1,0,-1};
 		int dy[] = {1,0,-1,0};
 		
 		for(int j = 0 ; j < 4 ; j++){
 			int tx = now[i].first + dx[j];
 			int ty = now[i].second + dy[j];
 			if( count(now.begin(),now.end(),make_pair(tx,ty)) ) continue;
 			auto ne = now;
 			ne.push_back({tx,ty});
 			dfs(t-1,ne);
 		}
 	}
 	return 0;
 }
 
 
 set<int> one;
 int X,R,C;
 
 bool settable(Board &b,int x,int y,int i){
 	for( auto p : tmm[i] ){
 		int tx = x + p.first;
 		int ty = y + p.second;
 		if( tx < 0 || ty < 0 || tx >= C || ty >= R || b[ty][tx] == true) return false;
 	}
 	return true;
 }
 bool sett(Board &b,int x,int y,int i){
 	for( auto p : tmm[i] ){
 		int tx = x + p.first;
 		int ty = y + p.second;
 		b[ty][tx] = true;
 	}
 	return true;
 }
 
 struct UnionFind {
   vector<int> data;
   UnionFind(int size) : data(size, -1) { }
   bool unionSet(int x, int y) {
     x = root(x); y = root(y);
     if (x != y) {
       if (data[y] < data[x]) swap(x, y);
       data[x] += data[y]; data[y] = x;
     }
     return x != y;
   }
   bool findSet(int x, int y) {
     return root(x) == root(y);
   }
   int root(int x) {
     return data[x] < 0 ? x : data[x] = root(data[x]);
   }
   int size(int x) {
     return -data[root(x)];
   }
 };
 
 
 map<Board,int> memo[2];
 
 int dfs(Board b,UnionFind &uf,vector<int> &item,int bit){
 	if( memo[bit].count(b) ) return memo[bit][b];
 	int fil = 1;
 	for(int i = 0 ; i < R ; i++){
 		for(int j = 0 ; j < C ; j++)
 			if( b[i][j] == 0 ) fil = 0;
 	}
 	//cout << fil << "|" << bit << endl;
 	if(fil) return bit == (1<<item.size())-1;
 	set<int> okok;
 	int all = true;
 	for(int i = 0 ; i < tmm.size() ; i++){
 		int ok = 0;
 		int p = find(item.begin(),item.end(),uf.root(i)) - item.begin();
 		
 		for(int j = 0 ; j < R ; j++){
 			for(int k = 0 ; k < C ; k++){
 				if( settable(b,k,j,i) ){
 					Board cp = b;
 					sett(cp,k,j,i);
 					int bit2 = bit;
 					if( p != item.size() ) bit2 |= (1<<p);
 					if( dfs(cp,uf,item,bit2) ){
 						return memo[bit][b] = true;
 					}
 				}
 			}
 			if(ok)break;
 		}
 	}
 	return memo[bit][b] = false;
 }
 
 typedef complex<double> P;
 namespace std {bool operator < (const P& a, const P& b) {
 	return abs(real(a)-real(b)) > 1e-9 ? real(a) < real(b) : imag(a) < imag(b);} }
 vector<P> to(vector< pair<int,int> > a){
 	vector<P> r;
 	P g;
 	for(int i = 0 ; i < a.size() ; i++){
 		r.push_back(P(a[i].first,a[i].second));
 		g += r.back();
 	}
 	g /= a.size();
 	for(int i = 0 ; i < a.size() ; i++)
 		r[i] -= g;
 	return r;
 }
 
 double PI = acos(-1);
 int same(vector< pair<int,int> > a,vector< pair<int,int> > b ){
 	vector<P> A,B;
 	A = to(a);
 	B = to(b);
 	for(int k = 0 ; k < 2 ; k++){
 		for(int i = 0 ; i < 4 ; i++){
 			int diff = 0;
 			sort(A.begin(),A.end());
 			sort(B.begin(),B.end());
 			for(int j = 0 ; j < B.size() ; j++){
 				if( abs(B[j]-A[j]) > 1e-9 ){
 					diff = 1;
 				}
 			}
 			for(int j = 0 ; j < B.size() ; j++){
 			
 				B[j] = B[j] * exp(P(0,PI/2.));
 			}
 			if( !diff ) return 1;
 		}
 		for(int j = 0 ; j < B.size() ; j++){
 			B[j] = P(-B[j].real(),B[j].imag());
 		}
 	}
 	return 0;
 }
 int main(){
 	int T;
 	int t=0;
 	cin >> T;
 	while(T--){
 		t++;
 		//mp.clear();
 		one.clear();
 		tmm.clear();
 		S.clear();
 		cin >> X >> R >> C;
 		dfs(X-1,{{0,0}});
 		Board b(R,vector<int>(C));
 		UnionFind uf(tmm.size());
 		for(int i = 0 ; i < tmm.size() ; i++){
 			for(int j = i + 1 ; j < tmm.size() ; j++){
 				if( same(tmm[i],tmm[j]) )
 					uf.unionSet(i,j);
 			}
 		}
 		for(int i = 0 ; i < tmm.size() ; i++){
 			one.insert(uf.root(i));
 		}
 		vector<int> item;
 		for( auto a : one ){
 			item.push_back(a);
 		}
 		//cout << item.size() << endl;
 		int ans = 1;
 		for(int i = 0; i < item.size() ; i++){
 			vector<int> item2;
 			item2.push_back(item[i]);
 			memo[0].clear();
 			memo[1].clear();
 			ans &= dfs(b,uf,item2,0);
 			//cout << dfs(b,uf,item2,0) << "<<<" << endl;
 		}
 		cout << "Case #" << t << ": " << (ans?"GABRIEL":"RICHARD") << endl;
 		
 		
 	}
 }