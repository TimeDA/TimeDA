#include <iostream>
 #include <vector>
 #include <string>
 #include <cstdio>
 #include <set>
 #include <cmath>
 
 using namespace std;
 
 int gcd(int a, int b){ return a%b ? gcd(b, a%b) : b; }
 
 int solveSmall(const vector<string>& vs, int D){
 	int h = vs.size(), w = vs[0].size();
 	int a, b;
 	for(int i=1;i<h-1;i++){
 		for(int j=1;j<w-1;j++){
 			if(vs[i][j] == 'X'){
 				a = 2*i-1;
 				b = 2*j-1;
 			}
 		}
 	}
 	int xs = -50*(h-2);
 	set< pair<int,int> > S;
 	for(int i=0;i<=100;i++){
 		int ys = -50*(w-2);
 		for(int j=0;j<=100;j++){
 			if((xs!=0 || ys!=0) && xs*xs+ys*ys <= D*D){
 				if(xs == 0){
 					if(ys > 0) S.insert(make_pair(0, 1));
 					else       S.insert(make_pair(0,-1));
 				}
 				else if(ys == 0){
 					if(xs > 0) S.insert(make_pair( 1, 0));
 					else       S.insert(make_pair(-1, 0));
 				}
 				else {
 					int g = gcd(abs(xs), abs(ys));
 					S.insert(make_pair(xs/g, ys/g));
 				}
 			}
 			if(j%2==0) ys += b;
 			else       ys += 2*(w-2)-b;
 		}
 		if(i%2==0) xs += a;
 		else       xs += 2*(h-2)-a;
 	}
 	return S.size();
 }
 
 int main(){
 	int T; cin >> T;
 	for(int test=1;test<=T;test++){
 		int H, W, D; cin >> H >> W >> D;
 		vector<string> vs(H);
 		for(int i=0;i<H;i++) cin >> vs[i];
 		printf("Case #%d: %d\n", test, solveSmall(vs, D));
 	}
 }