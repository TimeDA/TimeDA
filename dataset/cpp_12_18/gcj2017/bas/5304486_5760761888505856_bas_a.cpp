#include<iostream>
 #include<vector>
 #include<string>
 
 using namespace std;
 	int C;
 int main(){
 	
 	cin>>C; 
     for(int cc=0; cc<C; cc++){
 	int r,c;
         cin>>r>>c;
 	vector<string> s(r);
 	for(int i=0; i<r; i++)cin>>s[i];    
 
 	for(int i=0; i<r; i++){
 	    int j=0; 
 	    while(j<c){
 		if(s[i][j]=='?' && j>0){
 		    s[i][j] = s[i][j-1];
 		}
 		j++;
 	    }
 	}
 	for(int i=0; i<r; i++){
 	    int j=c-1; 
 	    while(j>=0){
 		if(s[i][j]=='?' && j<c-1){
 		    s[i][j] = s[i][j+1];
 		}
 		j--;
 	    }
 	}
 	for(int j=0; j<c; j++){
 	    int i=0; 
 	    while(i<r){
 		if(s[i][j]=='?' && i>0){
 		    s[i][j] = s[i-1][j];
 		}
 		i++;
 	    }
 	}
 	for(int j=0; j<c; j++){
 	    int i=r-1; 
 	    while(i>=0){
 		if(s[i][j]=='?' && i<r-1){
 		    s[i][j] = s[i+1][j];
 		}
 		i--;
 	    }
 	}
 	    cout<<"Case #"<<cc+1<<":\n";
 	    for(int i=0; i<r; i++){
 		cout<<s[i]<<"\n";
 	    }
 //	    cout<<"\n" ;
     }
 	
 }
