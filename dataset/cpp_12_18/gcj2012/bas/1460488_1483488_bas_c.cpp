#include<iostream>
 #include<vector>
 
 using namespace std;
 
 int num_dig(int num){
 	int res=0;
 	while(num>0){
 		num/=10;
 		res++;
 	}
 	return res;
 }
 
 int main(){
 	int C, A, B;
 	cin>>C;
 	for(int i=0; i<C; i++){
 		//cin>>wrds[i]; 
 		cin>>A>>B;
 		int res = 0;
 		int nd = num_dig(A);
 		int nmod = 1; for(int j=0; j<nd-1; j++) nmod*=10;
 		for(int n=A; n<=B; n++){
 			int m=n;
 			for(int j=0; j<nd-1; j++){
 				int t = m % 10;
 				
 				m = t*nmod + (m/10);
 				if(n==m) break;
 				if(m>n && m<=B){
 					 res++;
 				} 
 				
 			}
 		}
 		cout<<"Case #"<<i+1<<": " <<res<<"\n";
 	}
 	
 }
