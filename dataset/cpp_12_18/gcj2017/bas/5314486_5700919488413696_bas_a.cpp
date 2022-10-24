#include<iostream>
 #include<vector>
 #include<string>
 #include<algorithm>
 #define ll long long
 
 using namespace std;
 	int   C;
 int main(){
     std::ios_base::sync_with_stdio(false);
 	
 	cin>>C; 
 	for(int j=0; j<C; j++){
 		int n, p;
 		cin>>n>>p;
 		vector<int> gmp(p,0);
 		for(int i=0; i<n; i++){
 		    int x; cin>>x;
 		    gmp[x%p]++;
 	    
 		}
 		int res = gmp[0];
 		for(int i=1; i<(p+1)/2; i++){
 		    int c = min(gmp[i], gmp[p-i]);
 		    res+=c; gmp[i]-=c; gmp[p-i]-=c;
 		}
 //cout<<res<<";";
 		if(p%2==0){
 		    int c = gmp[p/2]/2;
 		    res+=c; gmp[p/2]-=2*c;
 		}
 		if(p==4){
 		    int c = min(gmp[2], gmp[1]/2);
 		    res+=c; gmp[2]-=c; gmp[1]-=c*2;
 		    c = min(gmp[2], gmp[3]/2);
 		    res+=c; gmp[2]-=c; gmp[3]-=c*2;
     
 		}
 		if(gmp[1]>=p){
 		    res+=gmp[1]/p; gmp[1]%=p;
 		}
 		if(p==3 && gmp[2]>=p){
 		    res+=gmp[2]/p; gmp[2]%=p;
 		    
 		}
 		if(p==4 && gmp[3]>=p){
 		    res+=gmp[3]/p; gmp[3]%=p;
 		    
 		}
 		for(int i=1; i<p; i++){
 		    if(gmp[i]){
 			res++; break;
 		    }
 		}
 		cout<<"Case #"<<j+1<<": "<<res<<"\n" ;
 //		cout.flush();
 
 	}
 	
 }
