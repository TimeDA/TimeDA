#include <iostream>
 #include <cstdio>
 #include <cstring>
 #include <algorithm>
 #include <vector>
 using namespace std;
 int in(){int r=0,c;for(c=getchar_unlocked();c<=32;c=getchar_unlocked());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar_unlocked());return r;}
 
 const double eps = 1e-8;
 
 bool can(vector<int> &K,vector<int> &S, double speed,int D){
 	int n = K.size();
 	
 	
 	for(int i=0;i<n;i++){
 		//~ if (S[i] > speed) continue;s
 		
 		if(speed - S[i] == 0) continue;
 		
 		if (speed * (K[i] *1. / (speed - S[i])) < D){
 			//~ cerr << speed << ' ' << i << endl;
 			return false;
 		}
 	}
 	
 	return true;
 	
 }
 
 void solve(){
 	
 	int D,N;
 	cin >> D >> N;
 	//~ cerr << D << ' ' << N << endl;
 	
 	double ans = 1e300;
 	double mxt = 0;
 	for(int i=0;i<N;i++){
 		int x,y;
 		cin >> x >> y;
 		
 		//~ cerr << x<< ' ' << y << endl;
 		
 		double t = (D - x) * 1. / y;
 		//~ cerr << t << endl;
 		mxt = max(t,mxt);
 	}
 	
 	ans = D / mxt;
 	
 	printf("%.10lf\n",ans);
 }
 
 int main(){
   for(int i=0,T=in();i<T;i++){
 	  cout << "Case #"<<i+1<<": ";
       solve();
       
       //~ if(i == 16) exit(1);
   }
 }
