#include <iostream>
 #include <cstdio>
 #include <cstring>
 #include <algorithm>
 #include <vector>
 #include <string>
 #include <set>
 #include <map>
 using namespace std;
 int in(){int r=0,c;for(c=getchar_unlocked();c<=32;c=getchar_unlocked());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar_unlocked());return r;}
 
 typedef pair<int,int> pii;
 
 int pos[1050][1050];
 int prom = 0;
 
 bool can(int t,vector<vector<int>> req,int it){
 	//~ cerr << " P " << t << endl;
 	prom = 0;
 	vector<vector<bool>> sitc(req.size(),vector<bool>(t,false));
 	//~ cerr << t << endl;
 	for(int i=0;i<req.size();i++){
 		for(int j=0;j<req[i].size();j++){
 			int s = req[i][j];
 			//~ cerr << "a " << s << endl;
 			for(int k=0;k<t;k++){
 				if(pos[k][s]!=it && !sitc[i][k]){
 					pos[k][s]=it;
 					req[i][j]=-1;
 					//~ cerr << " entra " << i <<  ' ' << k << endl;
 					sitc[i][k] = true;
 					break;
 				}
 			}
 		}
 	}
 	
 	
 	for(int i=0;i<req.size();i++){
 		for(int j=0;j<req[i].size();j++){
 			int s = req[i][j];
 			if(s<0) continue;
 			//~ cerr << "p " << s << endl;
 			
 			bool found = false;
 			while(s>=0 && !found){
 				//~ cerr << "T " << s << endl;
 				for(int k=0;k<t;k++){
 					if(pos[k][s]!=it && !sitc[i][k]){
 					//~ cerr << " entra " << i <<  ' ' << k << endl;
 						sitc[i][k] = true;
 						pos[k][s] = it;
 						found = true;
 						break;
 					}
 				}
 				
 				s--;
 				
 			}
 			
 			if(!found) return false;
 			prom++;
 		}
 	}
 	
 	return true;
 }
 
 void solve(){
 	int n = in();
 	int c = in();
 	int m = in();
 		
 	vector<vector<int>> req(c,vector<int>());
 	//~ cerr << m << endl;
 	for(int i=0;i<m;i++){
 		int s = in() - 1;
 		int r = in() - 1;
 		req[r].push_back(s);
 	}
 	for(int i=0;i<c;i++) sort(req[i].begin(),req[i].end());
 	for(int i=0;i<c;i++) reverse(req[i].begin(),req[i].end());
 	
 	for(int i=0;i<=m;i++){
 		for(int j=0;j<=n;j++){
 			pos[i][j] = 0;
 		}
 	}
 	
 	
 	int inf = 0;
 	int sup = m;
 	int it=2;
 	
 	//~ cerr << sup << endl;
 	while(inf+1 < sup){
 		it++;
 		
 		int mid = (inf+sup)/2;
 		//~ cerr << mid << endl;
 		if(can(mid,req,it)){
 			sup = mid;
 		}else{
 			inf = mid;
 		}
 	}
 	
 	it+=2;
 	can(sup,req,it);
 
 	cout << sup << ' ' << prom << endl;
 	
 }
 
 int main(){
   for(int i=0,T=in();i<T;i++){
 	  cout << "Case #"<<i+1 << ": ";
       solve();
   }
 }
