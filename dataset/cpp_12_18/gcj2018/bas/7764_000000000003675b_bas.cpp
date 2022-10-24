#include<bits/stdc++.h>
#define big 2000000000LL*1000000000
#define fi first
#define se second
#define ll long long

using namespace std;
	int T;
int main(){
	ios_base::sync_with_stdio(false);
	cin>>T; 
	for(int cc=0; cc<T; cc++){
	    int n;
	    cin>>n;
	    vector<int> a(n), b(n);
	    for(int i=0; i<n; i++){
		int x, y, z; cin>>x>>y>>z;
		a[i] = x+y; b[i] = x-z;
	    }	
	    vector<set<int> > seql(n+1);
	    for(int i=0; i<=n; i++) seql[i].clear();
	    for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
		    for(int start=0; start<n ; start++){
			for(int ind=start; ind<n; ind++){
			    if(a[ind]!=a[i] && b[ind]!=b[j]){
				break;
				
			    }
			    seql[ind-start+1].insert(start);
			}
		    }
		}
	    }
	    int len = 1, nseq = n; 
	    for(int i=n; i>=0; i--){
		if(seql[i].size()){
		    len=i; nseq = seql[i].size();
		    break;
		}
	    }
	    cout<<"Case #"<<cc+1<<": " <<len<<" "<<nseq<<"\n";

	}
	
}
