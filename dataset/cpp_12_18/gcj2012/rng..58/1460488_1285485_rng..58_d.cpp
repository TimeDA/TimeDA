#include <iostream>
 #include <sstream>
 #include <string>
 #include <vector>
 #include <deque>
 #include <queue>
 #include <set>
 #include <map>
 #include <algorithm>
 #include <functional>
 #include <utility>
 #include <cmath>
 #include <cstdlib>
 #include <ctime>
 #include <cstdio>
 
 using namespace std;
 
 #define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
 #define foreach(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
 
 string board[40];
 vector <pair <int, int> > v;
 
 bool compare(const pair <int, int> &p, const pair <int, int> &q){
 	return p.first * q.second < p.second * q.first;
 }
 
 int func2(int X, int Y, int x, int y, int D){
 	int ans=0,i,j,k;
 	
 	if(2*x <= D) ans++;
 	
 	int dx2[] = {2*x, 2*x, 2*X, 2*X};
 	int dy2[] = {2*y, 2*Y, 2*y, 2*Y};
 	
 	v.clear();
 	REP(k,4){
 		for(i=0;;i++){
 			int dx = dx2[k] + 2*i*X;
 			if(dx*dx > D*D) break;
 			for(j=0;;j++){
 				int dy = dy2[k] + 2*j*Y;
 				if(dx*dx + dy*dy > D*D) break;
 				v.push_back(make_pair(dx,dy));
 			}
 		}
 	}
 	
 	sort(v.begin(),v.end(),compare);
 	REP(i,v.size()) if(i == 0 || v[i].first * v[i-1].second != v[i-1].first * v[i].second) ans++;
 	
 	return ans;
 }
 
 int func(int X, int Y, int x, int y, int D){ // cout << X << ' ' << Y << ' ' << x << ' ' << y << ' ' << D << endl;
 	return func2(X,Y,x,y,D) + func2(Y,X,Y-y,x,D) + func2(X,Y,X-x,Y-y,D) + func2(Y,X,y,X-x,D);
 }
 
 void main2(void){
 	int X,Y,D,x,y,i,j;
 	
 	cin >> X >> Y >> D;
 	REP(i,X) cin >> board[i];
 	REP(i,X) REP(j,Y) if(board[i][j] == 'X') {x = i; y = j;}
 	
 	int ans = func(2*(X-2), 2*(Y-2), 2*x-1, 2*y-1, 2*D);
 	cout << ans << endl;
 }
 
 int main(void){
 	int T,t;
 	scanf("%d",&T);
 	REP(t,T){
 		printf("Case #%d: ",t+1);
 		main2();
 	}
 	return 0;
 }
