#include <iostream>
 #include <cstdio>
 #include <cstring>
 #include <algorithm>
 using namespace std;
 int in(){int r=0,c;for(c=getchar_unlocked();c<=32;c=getchar_unlocked());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar_unlocked());return r;}
 typedef long long ll;
 
 
 void solve(){
 	ll hd,ad,hk,ak,b,d;
 	
 	cin >> hd >> ad >> hk >> ak >> b >> d;
 	
 	if(ad>=hk){
 		cout << 1 << endl;
 		return;
 	}
 	//~ if(d<ak && ak - d >=hd){
 		//~ cout << "IMPOSSIBLE" << endl;
 		//~ return;
 	//~ }
 	
 	ll mxd = 0;
 	ll mxb = 0;
 	
 	ll cantc = 0;
 	
 	if(d > 0){
 		mxd = ak / d + 1;
 	}
 	
 	if(b > 0){
 		mxb = hk / b + 1;
 	}
 	
 	ll ans = -1;
 	
 	for(int i=0;i<=mxd;i++){
 		for(int j=0;j<=mxb;j++){
 			cantc = 0;
 			ll aux = i;
 			
 			ll health = hd;
 			ll curad = ad;
 			ll curak = ak;
 			
 			bool lose = false;
 			
 			while(aux>0){
 				curak -= d;
 				health -= curak;
 				if(health < 0 ) lose = true;
 				
 				aux --;
 				
 				if(aux>0){
 					if(health <= (curak - d)){
 						health = hd - curak;
 						cantc++;
 					}
 				}else{
 					
 					
 					if(health <= curak){
 						if(j == 0 && curad >= hk  ){
 						}
 						else{
 							health = hd - curak;
 							cantc++;
 						}
 					}
 				}
 			}
 			if(lose) continue;
 			
 			aux = j;
 			
 			while(aux>0){
 				curad += b;
 				health -= curak;
 				if(health < 0 ) lose = true;
 				
 				aux --;
 				
 				if(health <= curak){
 					if(aux == 0 && curad >= hk){
 					}else{
 						health = hd - curak;
 						cantc++;
 					}
 				}
 			}
 			if(lose) continue;
 			
 			
 			
 			ll hits = 0;
 			
 			ll healthk = hk;
 			
 			
 			while(1){
 				healthk -= curad;
 				hits++;
 				if(healthk<=0) break;
 				
 				health -= curak;
 				
 				if(health < 0 ) lose = true;
 				
 				if(lose) break;
 				
 				if(health <= curak && curad < healthk){
 					health = hd - curak;
 					cantc++;
 				}
 			}
 			
 			if(lose) continue;
 			
 			//~ cerr << i << ' ' << j << ' ' << cantc << ' ' << hits << endl;
 			if(ans == -1) ans = i+j+cantc + hits;
 			ans = min(ans, i+j+cantc + hits);
 			
 		}
 	}
 	
 	if(ans == -1){
 		cout << "IMPOSSIBLE" << endl;
 	}else{
 		cout << ans << endl;
 	}
 }
 
 int main(){
   for(int i=0,T=in();i<T;i++){
 	  cout << "Case #"<< i+1 << ": " ;
       solve();
   }
 }
