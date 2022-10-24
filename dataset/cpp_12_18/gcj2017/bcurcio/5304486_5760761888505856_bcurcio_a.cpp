#include <iostream>
 #include <cstdio>
 #include <cstring>
 #include <vector>
 #include <string>
 #include <algorithm>
 using namespace std;
 int in(){int r=0,c;for(c=getchar_unlocked();c<=32;c=getchar_unlocked());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar_unlocked());return r;}
 
 void solve(){
 	int R = in();
 	int C = in();
 	
 	vector<string> mat;
 	for(int i=0;i<R;i++){
 		string s;
 		cin >> s;
 		mat.push_back(s);
 	}
 	
 	
 	for(int i=1;i<R;i++){
 		for(int j=0;j<C;j++){
 			if(mat[i][j] == '?' && mat[i-1][j]!='?'){
 				mat[i][j] = mat[i-1][j];
 			}
 		}
 	}
 	
 	for(int i=R-2;i>=0;i--){
 		for(int j=0;j<C;j++){
 			if(mat[i][j] == '?' && mat[i+1][j]!='?'){
 				mat[i][j] = mat[i+1][j];
 			}
 		}
 	}
 	
 	
 	//~ for(int i=0;i<R;i++){
 		//~ cout << mat[i] << endl;
 	//~ }
 	for(int i=1;i<C;i++){
 		for(int j=0;j<R;j++){
 			if(mat[j][i] == '?' && mat[j][i-1]!='?'){
 				mat[j][i] = mat[j][i-1];
 			}
 		}
 	}
 	
 	
 	for(int i=C-2;i>=0;i--){
 		for(int j=0;j<R;j++){
 			if(mat[j][i] == '?' && mat[j][i+1]!='?'){
 				mat[j][i] = mat[j][i+1];
 			}
 		}
 	}
 	
 	for(int i=0;i<R;i++){
 		cout << mat[i] << endl;
 	}
 	
 }
 
 int main(){
   for(int i=0,T=in();i<T;i++){
 	  cout << "Case #"<< i+1 << ":" << endl;
       solve();
   }
 }
