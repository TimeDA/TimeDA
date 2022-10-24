#include<iostream>
 #include<vector>
 #include<string>
 #define ll long long
 
 using namespace std;
 	int T;
 	ll n, k;
 int main(){
 
     cin>>T; 
     for(int j=0; j<T; j++){
 		cin>>n>>k;
 		ll rx,rn;
 	ll tmp=k; ll num=1; ll n2=n;
 	while(tmp){
 	    n2-=num;
 	    tmp>>=1LL;
 	    num*=2;
 	}
 	num/=2;
 //cout<<tmp<<" "<<num<<" "<<n2<<"\n";
 //cout<<k<<" "<<num<<" "<<n2<<"\n";
 		ll tot = n2/num;
 		if(k%num<n2%num){
 		    tot++;
 		}
 		rx=rn=tot/2; if(tot%2)rx++;
 	    
 	
 		cout<<"Case #"<<j+1<<": "<<rx<<" "<<rn<<"\n";
 	
     }
 	
 }
