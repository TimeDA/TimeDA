#include <iostream>
 #include <cstdio>
 #include <cstring>
 #include <algorithm>
 #include <cmath>
 #include <vector>
 using namespace std;
 int in(){int r=0,c;for(c=getchar_unlocked();c<=32;c=getchar_unlocked());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar_unlocked());return r;}
 
 typedef __int128 ll;
 typedef pair<ll,int> pii;
 
 
 
 
 void solve(){
 	double pi = atan(1.)*4;
 	int n = in();
 	int k = in();	
 	
 	vector<pii> pancakes;
 	
 	for(int i=0;i<n;i++){
 		ll x = in();
 		ll y = in();
 		
 		ll s = x * 1LL * y * 2;
 		
 		pancakes.push_back(pii(-s,x));
 	}
 	
 	sort(pancakes.begin(),pancakes.end());
 	
 	ll bst = -1;
 	
 	for(int i=0;i<pancakes.size();i++){
 		ll r = pancakes[i].second;
 		ll acum = -pancakes[i].first;
 		int cnt = 1;
 		
 		for(int j=0;j<pancakes.size();j++) if(i!=j){
 			if(cnt==k) break;
 			
 			if(r>=pancakes[j].second){
 				acum += (-pancakes[j].first);
 				cnt++;
 			}
 		}
 		
 		
 		ll ans = r*r + acum;
 		if(ans > bst){
 			bst = ans;
 		}
 	}
 	
 	
 	printf("%.8lf\n",bst * pi);
 	
 	
 }
 
 int main(){
   for(int i=0,T=in();i<T;i++){
 	  cout <<"Case #"<<i+1 << ": ";
       solve();
   }
 }
