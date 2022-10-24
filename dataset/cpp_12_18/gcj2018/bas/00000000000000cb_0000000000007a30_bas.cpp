#include<bits/stdc++.h>
#define ll long long

using namespace std;
	int T;
	ll a;
int main(){

    cin>>T; 
    for(int j=0; j<T; j++){
	cin>>a;
	set<pair<int, int> > nei;
	int x = 2;
	bool done = false, error = false;
	while(!done && !error){
	    nei.clear();
	    while(nei.size()!=9){
		cout<<x<<" "<<2<<"\n"; cout.flush();
		int xin, yin;
		cin>>xin>>yin;
		if(xin==0){
		    done = true;
		    break;
		}
		if(xin == -1){
		    error = true;
		    break;
		}
		nei.insert({xin, yin});
	    }
	    x+=3;
	}
	if(error)exit(0);
	
    }
	
}
