#include <iostream>
 #include <vector>
 #include <algorithm>
 #include <cstdio>
 
 using namespace std;
 
 void solveSmall(int N, int C, const vector<int>& P, const vector<int>& B){
 	if(C > 2){
 		printf("\n"); return;
 	}
 	vector<int> p[2];
 	int one = 0;
 	for(int i=0;i<P.size();++i){
 		p[B[i]-1].push_back(P[i]-1);
 		if(P[i] == 1) ++one;
 	}
 	int sz = max(p[0].size(), p[1].size());
 	if(one > sz){
 		printf("%d 0\n", one);
 	} else {
 		vector< vector<int> > c(2, vector<int>(N, 0));
 		for(int i=0;i<2;++i){
 			for(int j=0;j<p[i].size();j++) c[i][p[i][j]]++;
 		}
 		int res = 0;
 		for(int i=0;i<N;i++){
 			res = max(res, c[0][i]+c[1][i]-sz);
 		}
 		printf("%d %d\n", sz, res);
 	}
 }
 
 int main(){
 	int T; cin >> T;
 	for(int t=1;t<=T;++t){
 		int N, C, M; cin >> N >> C >> M;
 		vector<int> P(M), B(M);
 		for(int i=0;i<M;i++) cin >> P[i] >> B[i];
 		printf("Case #%d: ", t);
 		solveSmall(N, C, P, B);
 	}
 }
 
