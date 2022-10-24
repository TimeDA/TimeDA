#include<iostream>
 #include<vector>
 
 using namespace std;
 	int T;
 	string s;
 int main(){
 
 	cin>>T; 
 	for(int j=0; j<T; j++){
 	    cin>>s;
 	    int n = s.length();
 	    vector< vector<int> > sav(2, vector<int>(n, 0));
 	    if(s[0]=='+') // 1===+
 		sav[0][0]=1;
 	    else
 		sav[1][0]=1;
 	    for(int i=1; i<n; i++){
 		if(s[i]=='+'){
 		    sav[1][i] = sav[1][i-1];
 		    sav[0][i] = sav[1][i-1] +1;
 		}else{
 		    sav[1][i] = sav[0][i-1]+1;
 		    sav[0][i] = sav[0][i-1];
 		}
 	    }
 	    cout<<"Case #"<<j+1<<": " <<sav[1][n-1]<<"\n";
 	}
 	
 }
