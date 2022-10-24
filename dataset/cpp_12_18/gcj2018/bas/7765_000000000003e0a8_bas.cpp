#include<bits/stdc++.h>
#define big 1000000000L*1000000000
#define fi first
#define se second
using namespace std;
	int T;
	int n; 
int main(){

	cin>>T; 
	for(int j=0; j<T; j++){
	    cin>>n;
	    vector<long long> c(n);
	    vector<long long> w(n+1,big);
	    w[0]=0;
	    int maxi = 0;
	    for(int i=0; i<n; i++)cin>>c[i];
	    for(int i=0; i<n; i++){
		for(int j=min(i, maxi); j>=0; j--){
		    if(w[j]<=c[i]*6){
			w[j+1] = min(w[j+1], w[j]+c[i]);
			maxi = max(maxi, j+1);
		    }
		}
/*		cout<<i<<":";
		for(int j=0; j<=i+1; j++)cout<<w[j]<<" ";
		cout<<"\n";
*/    
	    }
	    int res = maxi;
	    cout<<"Case #"<<j+1<<": "<<res<<"\n";
		
		
	}
	
}
