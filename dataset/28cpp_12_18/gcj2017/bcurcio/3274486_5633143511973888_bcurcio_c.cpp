#include <iostream>
 #include <cstdio>
 #include <cstring>
 #include <algorithm>
 #include <cmath>
 #include <vector>
 using namespace std;
 int in(){int r=0,c;for(c=getchar_unlocked();c<=32;c=getchar_unlocked());if(c=='-') return -in();for(;c>32 && r!='.';r=(r<<1)+(r<<3)+c-'0',c=getchar_unlocked());return r;}
 
 typedef __int128 ll;
 typedef pair<int,int> pii;
 
 bool can(double m,double u, vector<double> &p){
 	
 	double acum = 0;
 	for(int i=0;i<p.size();i++){
 		if(p[i]<m){
 			acum+= (m-p[i]);
 		}
 		if(acum >u) return false;
 	}
 	
 	return true;
 }
 
 void solve(){
 	
 	int n = in();
 	int k = in();
 	
 	double u;
 	cin >> u;
 	vector<double> p;
 	
 	for(int i=0;i<n;i++){
 		double x;
 		cin >> x;
 		p.push_back(x);
 	}
 	
 	double inf = 0;
 	double sup = 1;
 	
 	
 	while(inf+1e-11 < sup){
 		double mid = (inf+sup)/2;
 		
 		if(can(mid,u,p)){
 			inf = mid;
 		}else{
 			sup = mid;
 		}
 	}
 	
 	double ans = 1;
 	//~ cerr << inf << endl;
 	for(int i=0;i<n;i++){
 		//~ cerr << ans << endl;
 		if(p[i]<inf){
 			ans*=inf;
 		}else{
 			ans*=p[i];
 		}
 	}
 	
 	printf("%.9lf\n",ans);
 }
 
 int main(){
   for(int i=0,T=in();i<T;i++){
 	  cout <<"Case #"<<i+1 << ": ";
       solve();
   }
 }
