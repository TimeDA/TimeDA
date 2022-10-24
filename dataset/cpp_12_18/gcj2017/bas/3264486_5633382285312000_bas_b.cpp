#include<bits/stdc++.h>
 
 using namespace std;
 	int T;
 	string s;
 string f(string s){
     if(s.length()==1)return s;
     string s1 = f(s.substr(1));
     string res=string(1,s[0])+s1;
 //cout<<s<<" "<<s1<<"\n";
     if( s1[0]<s[0]){
 	res[0]--;
 	for(int k=1; k<s.length(); k++)res[k]='9';
     }
 	    
     return res;
     
 }
 int main(){
 
 	cin>>T; 
 	for(int j=0; j<T; j++){
 	    cin>>s;
 	    string res=f(s);
 	    if(res[0]=='0')res = res.substr(1);
 	    cout<<"Case #"<<j+1<<": " <<res<<"\n";
 	}
 	
 }
