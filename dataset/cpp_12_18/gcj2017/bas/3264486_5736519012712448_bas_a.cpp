#include<iostream>
 #include<vector>
 #include<string>
 
 using namespace std;
 	int C, n;
 	string s;
 int main(){
 	ios_base::sync_with_stdio(false);
 	cin>>C; 
 	for(int c=0; c<C; c++){
 		cin>>s>>n; int l = s.size();
 		int res=0;
 		for(int i=0; i<=l-n; i++){
 		    if(s[i]=='-'){
 			res++;
 			for(int j=i; j<i+n; j++){
 			    if(s[j]=='-')s[j]='+'; else s[j]='-';
 			}
 		    }
 		}
 		if(s.find('-')!=string::npos){
 		    cout<<"Case #"<<c+1<<": IMPOSSIBLE\n" ;
 		    continue;
 		}
 		
 		cout<<"Case #"<<c+1<<": "<<res<<"\n" ;
 	}
 	
 }
