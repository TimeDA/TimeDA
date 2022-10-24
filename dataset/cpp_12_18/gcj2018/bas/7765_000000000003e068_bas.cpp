#include<bits/stdc++.h>
#define big 2000000000LL*1000000000
#define fi first
#define se second
#define ll long long

using namespace std;
	int T;
int main(){
	cin>>T; 
	srand (time(NULL));
	for(int cc=0; cc<T; cc++){
	    int n;
	    cin>>n;
	    vector<int> sold(n,0);
	    vector<int> liked(n,0);
	    if(n==-1)exit(0);
	    for(int j=0; j<n; j++){
		int d;
		cin>>d;
		if(d==-1)exit(0);
		vector<int> tmp(0);
		int minl = 1000; int minind = 0;
		for(int i=0; i<d; i++){
		    int x; cin>>x;
		    liked[x]++;
		    if(!sold[x] && liked[x]<minl){
			minl = liked[x];
			minind = x;
		    }
		    if(!sold[x])tmp.push_back(x);
		}
		if(minl!=1000){
		    cout<<minind<<"\n"; cout.flush();
		    sold[minind]=1;
		}else{
		    cout<<"-1\n"; cout.flush();
		}
	    }
	}
	
}
