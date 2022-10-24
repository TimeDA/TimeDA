#include <iostream>
 #include <cstdio>
 #include <cstring>
 #include <algorithm>
 #include <vector>
 #include <string>
 #include <cmath>
 using namespace std;
 int in(){int r=0,c;for(c=getchar_unlocked();c<=32;c=getchar_unlocked());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar_unlocked());return r;}
 
 void solve(){
 	int N = in();
 	int P = in();
 	
 	
 	vector<int> cant;
 	for(int i=0;i<N;i++){
 		int x = in() * 100;
 		cant.push_back(x);
 	}
 	
 	
 	if(N==1){
 		int ans = 0;
 		for(int i=0;i<P;i++){
 			int x = in() * 100;
 			
 			double mn = x / (cant[0] * 1.1);
 			double mx = x / (cant[0] * 0.9);
 			
 			int mncnt = ceil(mn);
 			int mxcnt = floor(mx);
 			
 			if(mncnt<=mxcnt){
 				ans ++;
 			}
 		}
 		
 		cout << ans << endl;
 		
 		return;
 	}
 	
 	if(N == 2){
 		
 		vector<int> c1,c2;
 		for(int i=0;i<P;i++){
 			int x = in() * 100;
 			c1.push_back(x);
 		}
 		
 		for(int i=0;i<P;i++){
 			int x = in() * 100;
 			c2.push_back(x);
 			
 		}
 		int ans = 0;
 		
 		sort(c2.begin(),c2.end());
 		
 		do{
 			
 			int cur = 0;
 			for(int i=0;i<P;i++){
 				double mn1 = c1[i] / (cant[0] * 1.1);
 				double mx1 = c1[i] / (cant[0] * 0.9);
 				
 				int mncnt1 = ceil(mn1);
 				int mxcnt1 = floor(mx1);
 				
 				if(mncnt1>mxcnt1){
 					continue;
 				}
 				
 				double mn2 = c2[i] / (cant[1] * 1.1);
 				double mx2 = c2[i] / (cant[1] * 0.9);
 				
 				int mncnt2 = ceil(mn2);
 				int mxcnt2 = floor(mx2);
 				
 				if(mncnt2>mxcnt2){
 					continue;
 				}
 				
 				if((mncnt1<=mncnt2 && mncnt2<=mxcnt1) || (mncnt1<=mxcnt2 && mxcnt2<=mxcnt1) ||
 				
 					(mncnt2<=mncnt1 && mncnt1<=mxcnt2) || (mncnt2<=mxcnt1 && mxcnt1<=mxcnt2)
 				){
 					cur++;
 				}
 				
 				if(cur>ans) ans = cur;
 			}
 			
 			
 		}while(next_permutation(c2.begin(),c2.end()));
 		
 		
 		cout << ans << endl;
 		
 	}
 		
 	
 	
 }
 
 int main(){
   for(int i=0,T=in();i<T;i++){
 	  cout << "Case #"<< i+1 << ": " ;
       solve();
   }
 }
