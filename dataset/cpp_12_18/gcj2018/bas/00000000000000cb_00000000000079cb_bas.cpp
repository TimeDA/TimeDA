#include<bits/stdc++.h>

using namespace std;
	int T, n;
int main(){
    ios_base::sync_with_stdio(false);

	cin>>T; 
	for(int j=0; j<T; j++){
	    cin>>n;
	    vector<int> v(n);
	    vector<int> v1(0), v2(0);
	    for(int i=0; i<n; i++){ 
		cin>>v[i];
		if(i%2){
		    v2.push_back(v[i]);
		}else{
		    v1.push_back(v[i]);
		}
	    }
	    sort(v1.begin(), v1.end());
	    sort(v2.begin(), v2.end());
	    for(int i=0; i<n; i++){
		if(i%2)v[i] = v2[i/2];
		    else v[i] = v1[i/2];
	    }
	    int res=-1;
	    for(int i=0; i<n-1; i++)
		if(v[i]>v[i+1]){
		    res = i;
		    break;
		}
	    if(res>=0)
		cout<<"Case #"<<j+1<<": " <<res<<"\n";
	    else
		cout<<"Case #"<<j+1<<": OK\n";
	}
	
}
