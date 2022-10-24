#include<iostream>
 #include<vector>
 #include<string>
 
 using namespace std;
 	int C, n;
 void proc(int num, int & digs){
     while(num){
 	int d = num%10;
 	num/=10;
 	digs = digs |(1<<d);
     }
 }
 int main(){
 	
 	cin>>C; 
 	for(int j=0; j<C; j++){
 		cin>>n;
 		int digs = 0;
 		if(!n){
 		    cout<<"Case #"<<j+1<<": INSOMNIA\n" ;
 		    continue;
 		}
 		long long sum=0;
 		do{
 		    sum+=n;
 		    proc(sum, digs);
 		}while(digs!=(1<<10)-1);
 		
 		cout<<"Case #"<<j+1<<": "<<sum<<"\n" ;
 	}
 	
 }
