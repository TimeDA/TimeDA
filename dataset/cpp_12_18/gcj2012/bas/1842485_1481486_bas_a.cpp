#include<iostream>
 #include<vector>
 #include<string>
 
 using namespace std;
 
 
 int main(){
 	int T, N, D;
 	vector<int> d = vector<int>(10001);
 	vector<int> l = vector<int>(10001);
 	vector<int> sav = vector<int>(10001);
 	
 	cin>>T; 
 	for(int j=0; j<T; j++){
 		cin>>N;
 		for(int i=0; i<N; i++)cin>>d[i]>>l[i];
 		cin>>D;        d[N] = D;
 
 		sav.clear(); sav.resize(10001, -1);
 		
 
 		for(int i=N-1; i>=0; i--){
 			int mn = 2000000000;
 			for(int k = i+1; k<=N; k++){
 				if(sav[k] == 2000000000)continue;
 				if(d[k]-d[i]<=l[i] && d[k]-d[i]>=sav[k]){
 					if(d[k]-d[i]<=mn)mn = d[k]-d[i];
 				}
 			}
 			
 			sav[i] = mn;
 //			cout<<i<<" "<<sav[i]<<"\n";
 		}
 		string res;
 		if(sav[0]<=d[0])res="YES"; else res = "NO";
 
 	cout.precision(16);
 		cout<<"Case #"<<j+1<<": " <<res<<"\n";
 	}
 	
 }
