#include<iostream>
 #include<vector>
 #include<string>
 
 using namespace std;
 vector<vector<int> > d;
 vector<int> sav;
 	int T, N;
 int main(){
 
 	cin>>T; 
 	d.clear(); d.resize(1000, vector<int>(1000, 0));
 	
 	for(int j=0; j<T; j++){
 		cin>>N;
 		vector<int > a(1000, 0);
 		sav.clear(); sav.resize(1002, -1);
 		for(int i=0; i<N; i++){
 		    cin>>a[i];d[0][i]=a[i];}
 		sort(a[0].begin(), a[0].end());
 		for(int i=1; i<N; i++){
 		    int p=0;
 		    for(int j=0; j<N-i; j++){
 			if(d[i-1][j] == a[i-1]){p=1; continue;}
 			d[i][j]   = d[i-1][j+p];
 		    }
 		}
 		int res =0;
 		cout<<"Case #"<<j+1<<": "<<res<<"\n" ;
 
 	}
 	
 }
