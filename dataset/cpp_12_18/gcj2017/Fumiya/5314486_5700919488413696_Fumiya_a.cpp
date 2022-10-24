#include <iostream>
 #include <vector>
 #include <cstdio>
 
 using namespace std;
 
 void solve(int caseNum){
 	int N, P; cin >> N >> P;
 	vector<int> v(P, 0);
 	for(int i=0;i<N;i++){
 		int t; cin >> t;
 		++v[t%P];
 	}
 	int res = v[0];
 	if(P == 2){
 		res += (v[1]+1)/2;
 	} else if(P == 3){
 		int m = min(v[1], v[2]);
 		res += m;
 		v[1] -= m;
 		v[2] -= m;
 		res += (v[1]+2)/3;
 		res += (v[2]+2)/3;
 	} else if(P == 4){
 		res += v[2]/2;
 		v[2] -= v[2]/2;
 		int m = min(v[1], v[3]);
 		res += m;
 		v[1] -= m;
 		v[3] -= m;
 		while(v[1] >= 2 && v[2] >= 1){
 			++res;
 			v[1] -= 2;
 			v[2] -= 1;
 		}
 		while(v[3] >= 2 && v[2] >= 1){
 			++res;
 			v[3] -= 2;
 			v[2] -= 1;
 		}
 		res += (v[1]+3)/4;
 		res += (v[3]+3)/4;
 		res += (v[2]+1)/2;
 	}
 	printf("Case #%d: %d\n", caseNum, res);
 }
 
 int main(){
 	int T; cin >> T;
 	for(int t=1;t<=T;t++){
 		solve(t);
 	}
 }
