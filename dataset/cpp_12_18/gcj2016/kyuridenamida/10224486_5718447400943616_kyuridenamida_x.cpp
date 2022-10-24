#include <bits/stdc++.h>
 using namespace std;
 
 
 void put_case(int t){
   printf("Case #%d: ",t++);
 }
 
 int memo[210][210];
 
 
 int nb[4] = {};
 int N;
 bool sim(int bit,int available){
 
 	for(int i = 0 ; i < N ; i++){
 		if( bit >> i & 1 ){
 			int f = 0;
 			for(int j = 0 ; j < N ; j++){
 				if( (nb[i] >> j & 1) and (available >> j & 1) ){
 					f = 1;
 					if( !sim(bit-(1<<i),available-(1<<j)) )
 						return 0;
 				}
 			
 			}
 			if( !f ) return 0;
 		}
 	}
 	return 1;
 }
 int main(int argc,char *argv[]){
 
   int T;
   cin >> T;
   for(int t = 1 ; t <= T ; t++){
     
     cin >> N;
     int bt[4] = {};
     for(int i = 0 ; i < N ; i++){
     	bt[i] = 0;
     	for(int j = 0 ; j < N ; j++){
     		char c;
     		cin >> c;
     		c = c == '1';
     		bt[i] += c * (1<<j);
     	}
     }
     int ans = 1e9;
    	for(int i = 0 ; i < (1<<(N*N)) ; i++){
    		
    		int f = 1;
    		int tot = 0;
    		for(int j = 0 ; j < N ; j++){
    			nb[j] = i >> (N*j) & ((1<<N)-1);
    			if( (nb[j] & bt[j]) != bt[j] )
    				f = 0;
    			tot += __builtin_popcount(nb[j]^bt[j]);
    		}
    		if(f){
 
    			if( sim((1<<N)-1,(1<<N)-1) ){
    				//cout << nb[0] << " " << nb[1] << " " << nb[2] << " " << tot << endl;
    			
    				ans = min(ans,tot);
    			}
    		}
    	}
     put_case(t);
     cout << ans << endl;
 
   }
 }
