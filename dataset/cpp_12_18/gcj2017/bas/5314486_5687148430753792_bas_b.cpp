#include<iostream>
 #include<vector>
 #include<string>
 #include<algorithm>
 #include<set>
 #define ll long long
 
 using namespace std;
     
 	int T, n,c,m;
     vector<vector<int> > s2c;
 int check(int r){
     vector<vector<int> > so(r, vector<int>(n+1, 0));
     vector<set<int> > inr(r);
     vector<int> ncu(r, 0);
     int res=0;
     for(int s=1; s<=n; s++){
 	for(int ci=0; ci<s2c[s].size(); ci++){
 	    int cust = s2c[s][ci];
 	    //find ride without cust, and with empty s
 	    bool es=false;
 	    int fr = -1; 
 		int minc = 1000000;
 	    for(int i=0; i<r; i++){
 		if((!inr[i].count(cust)) && so[i][s]==0 && ncu[i]<minc){
 		    fr = i; es = true;
 		    minc = ncu[i];
 		    if(!minc)break;
 		}
 	    }
 	    if(es){
 //cout<<"r "<<fr<<" s "<<s<<" curst "<<cust<< "\n";
 		so[fr][s]=1; inr[fr].insert(cust); ncu[fr]++;
 		continue;
 	    }
 	    //if not found, ride without cust and with space < s
 	    es=false;
 	    fr = -1;
 	    int ns = -1;
 	    minc = 1000000;
 	    for(int i=0; i<r; i++){
 		if((!inr[i].count(cust)) && ncu[i]<s  && ncu[i]<minc){
 			minc = ncu[i];
 			fr = i; es = true;
 		    if(!minc)break;
 			//break;
 //		    }
 		}
 	    }
 	    
 	    if(es){
 		//so[fr][ns]=1;
 		inr[fr].insert(cust); ncu[fr]++;
 		res++;
 		continue;
 	    }
 
 	    // if not, 
 	    return -1;
 	}
     } 
     return res;
 }
 int main(){
 
 	cin>>T; 
 	for(int j=0; j<T; j++){
 		cin>>n>>c>>m;
 		s2c.clear(); s2c.resize(n+1, vector<int>(0));
 		for(int i=0; i<m; i++){
 		    int p, b; cin>>p>>b; s2c[p].push_back( b);
 		}
 		for(int i=0; i<=n; i++){
 		    sort(s2c[i].begin(), s2c[i].end());
 //cout<<i<<";;; ";
 //cout<<s
 		}
 		int l = 0; int r=1000;
 //		int prom1;
 		while(r>l+1){
 		    int cc = (l+r)/2;
 		    if((check(cc))>-1){
 			r = cc;
 		    }else{
 			l=cc;
 		    }
 //    cout<<cc<<" "<<prom1<<"\n";
 		}
 		int res;
 		int prom = check(l);
 		if((prom)>-1){
 		    res=l; 
 		    
 		}else{
 		     res=r;
 		    prom = check(r);
 		}
 		cout<<"Case #"<<j+1<<": "<<res<<" "<<prom<<"\n" ;
 
 	}
 	
 }
