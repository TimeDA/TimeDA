#include<iostream>
 #include<vector>
 #include<string>
 
 using namespace std;
 	int T;
 	int k,c, s;
 int main(){
 
 	cin>>T; 
 	for(int j=0; j<T; j++){
 	    cin>>k>>c>>s;
 	    int num = (k+c-1)/c;
 	    if(num>s){
 		cout<<"Case #"<<j+1<<": IMPOSSIBLE\n";
 		continue;
 	    }
 	    cout<<"Case #"<<j+1<<": ";
 	    int tile = 0;
 	    while(tile<k){
 		long long out = tile;
 		for(int i=0; i<min(c, k)-1; i++){
 		    tile++; if(tile>k-1)tile=k-1;
 		    out = out*k+tile;
 		}
 		cout<<out+1<<" ";
 		tile++;
 	    }
 	    cout<<"\n";
 		
 		
 	}
 	
 }
