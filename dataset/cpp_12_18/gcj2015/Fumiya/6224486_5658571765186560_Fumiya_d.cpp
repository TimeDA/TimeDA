#include <iostream>
 #include <string>
 #include <cstdio>
 
 using namespace std;
 
 string solveSmall(int X, int R, int C){
 	if(R*C%X != 0) return "RICHARD";
 	if(X >= 3 && (R == 1 || C == 1)) return "RICHARD";
 	if(X >= 4 && (R <= 2 || C <= 2)) return "RICHARD";
 	return "GABRIEL";
 }
 
 int main(){
 	int T; cin >> T;
 	for(int t=1;t<=T;t++){
 		int X, R, C; cin >> X >> R >> C;
 		printf("Case #%d: %s\n", t, solveSmall(X, R, C).c_str());
 	}
 }
