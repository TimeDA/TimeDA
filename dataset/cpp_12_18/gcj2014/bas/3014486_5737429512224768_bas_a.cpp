#include<iostream>
 #include<vector>
 #include<string>
 #include<algorithm>
 #define ll long long
 
 using namespace std;
 	int   C;
 int main(){
 	
 	cin>>C; 
 	for(int j=0; j<C; j++){
 		int n, x;
 		cin>>n>>x;
 		vector<int> s(n, 0);
 		for(int i=0; i<n; i++)cin>>s[i];
 		sort(s.begin(), s.end());
 		int a=0; int b=n-1;
 		int res = 0;
 		while (a<b){
 		    if(s[a]+s[b]<=x){
 			res++; a++; b--;
 		    }else{
 			res++; b--;
 		    }
 		}
 		if(a==b)res++;
 		cout<<"Case #"<<j+1<<": " ;
 		cout<<res;		
 		cout<<"\n";
 
 	}
 	
 }
