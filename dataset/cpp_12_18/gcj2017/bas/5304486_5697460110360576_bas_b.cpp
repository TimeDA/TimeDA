#include<bits/stdc++.h>
 #define big 2000000000LL*1000000000
 #define fi first
 #define se second
 
 using namespace std;
 	int T;
 	int n,p;
  
 int main(){
 
 	cin>>T; 
 	for(int cc=0; cc<T; cc++){
 	    cin>>n>>p;
 //cout<<n<<p; cout.flush();
 	    vector<int> r(n);
 	    for(int i=0; i<n; i++) cin>>r[i];
 	    vector<vector<int> > q(n, vector<int>(p));
 	    for(int i=0; i<n; i++) 
 	    for(int j=0; j<p; j++)  cin>>q[i][j];
 
 	    vector<vector<pair<int,int> > >  k(n, vector<pair<int,int> > (p));
 	    for(int i=0; i<n; i++) {
 	    for(int j=0; j<p; j++) {
 		int kmin = (q[i][j]*10+r[i]*11-1)/(r[i]*11);
 		int kmax = (q[i][j]*10)/(r[i]*9);
 		k[i][j] = {kmin, kmax};
 	    }
 		sort(k[i].begin(), k[i].end());
 	    }
 	    vector<int> start(n,0);
 	    int res=0;
 	    for(int kk=1; kk<=1111111; kk++){
 	    while(true){
 		vector<int> found(n, -1); 
 		int nfound=0;
 		for(int x=0; x<n; x++){
 		    for(int y=start[x]; y<k[x].size(); y++){
 			int k1 = k[x][y].fi; int k2 = k[x][y].se;
 			if(k1<=kk && kk<=k2){
 //cout<<k1<<" "<<k2<<"\n";
 			    found[x] = y; nfound++;
 			    break;
 			}
 		    }
 		}
 		if(nfound<n)break;
 //cout<<"fnd "<<kk<<"\n";
 		res++;
 		for(int i=0; i<n; i++){
 		    start[i] = found[i]+1;
 		}
 	    }
 	    }
 	
 	    cout<<"Case #"<<cc+1<<": " <<res<<"\n";
 
 	}
 	
 }
