#include<bits/stdc++.h>

using namespace std;
	int C, n, l;
string f(int ind, string & cur, set<string> & oldw, vector<set<char> > & cati){
    set<char> chars = cati[ind];
    for(auto it = chars.begin(); it!=chars.end(); it++){
	cur[ind]=*it;
	if(ind == l-1){
	    if(!oldw.count(cur))return cur;
	
	}else{
	    string res = f(ind+1, cur, oldw, cati);
	    if(res!="-")return res; 
	}
	
    }
    return "-";
    
}
int main(){
	
    cin>>C; 
    for(int cc=0; cc<C; cc++){
        cin>>n>>l;
	vector<string> s(n);
	set<string> oldw; oldw.clear();
	vector<set<char> > cati(l);
	for(int i=0; i<n; i++){
	    cin>>s[i];
	    oldw.insert(s[i]);		
	    for(int j=0; j<l; j++){
		cati[j].insert(s[i][j]);
	    }
	}
	string res = "-";
	string tmp = string(l,' ');
    	res = f(0, tmp, oldw, cati);
    
        cout<<"Case #"<<cc+1<<": "<<res<<"\n";
    }
	
}
