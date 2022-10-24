#include<bits/stdc++.h>
#define eps 1e-12
#define fi first
#define se second
using namespace std;
	int T;
	int n; double p;
int main(){

	cin>>T; 
	for(int j=0; j<T; j++){
	    cin>>n>>p;
	    double res=0;
	    double per = 0;
	    vector<double> w(n), h(n);
	    for(int i=0; i<n; i++){
		cin>>w[i]>>h[i];
		if(w[i]>h[i])swap(w[i], h[i]);
		per+=2.0*(w[i]+h[i]);
	    }
	    set<pair<double, double>> ints; ints.clear();
	    ints.insert({per,per});
	    for(int i=0; i<n; i++){
		double a1 = w[i]; double a2 = sqrt(a1*a1+h[i]*h[i]);
		a1*=2; a2*=2;
//cout<<a1<<" "<<a2<<";\n";
		for(auto it = ints.rbegin(); it!=ints.rend(); it++){
		    double a = it->fi; double b = it->se;
		    a+=a1; b+=a2;
		    auto it2 = ints.lower_bound({a,a});
		    auto it3 = it2;
		    if(it3!=ints.begin() && it3!=ints.end()){
			it3--;
		    }
		    if(it2!=ints.end()){
			double c = it2->fi; double d = it2->se;
			if(c<=b){
			    ints.erase(it2);
			    b = max(b, d);
			}
		    }
		    if(it3!=ints.end()){
			double c= it3->fi; double d = it3->se;
			if(d>=a){
			    ints.erase(it3);
			    a=c;
			    b=max(b,d);
			}
		    }
		    ints.insert({a,b});
		}
/*for(auto it=ints.begin(); it!=ints.end(); it++){
    cout<<"( "<<it->fi<<", "<<it->se<<") , ";
}
cout<<"\n";
*/
	    }
	    auto it = ints.lower_bound({1.0*p, 1.0*p});
	    res = 1.0*p;
	    if(it!=ints.begin()){
		if(it!=ints.end()){
		    if(it->fi>=-eps+p){
		    }else{
			it--;
			res = min(it->se, res);
		    }
		}else{
		    it--;
		    res = min(it->se, res);
		}
		
	    }
	    cout<<setprecision(15);
	    cout<<"Case #"<<j+1<<": "<<res<<"\n";
		
		
	}
	
}
