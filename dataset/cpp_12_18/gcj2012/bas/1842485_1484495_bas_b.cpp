#include<iostream>
 #include<vector>
 #include<string>
 #include <time.h>
 #include <stdio.h>
 #include <stdlib.h>
 
 
 using namespace std;
 
 
 int main(){
 	int T, N, W, L;
 	vector<long long> r = vector<long long>(1001);
 	
 	cin>>T; 
 	for(int j=0; j<T; j++){
 		cin>>N>>W>>L;
 		for(int i=0; i<N; i++)cin>>r[i];
 		vector<long long> x = vector<long long>(0);
 		vector<long long> y = vector<long long>(0);
 		srand ( time(NULL) );
 
 		for(int i=0; i<N; i++){
 			bool good = false; long long x1, y1;
 			while(!good){
 				 x1 = rand()%(W+1); y1 = rand()%(L+1);
 				good = true;
 				for(int k=0; k<i; k++){
 					if((x1-x[k])*(x1-x[k])+(y1-y[k])*(y1-y[k])< (r[i]+r[k])*(r[k]+r[i])){
 						good = false; break;
 					}	
 				}	
 			}
 			x.push_back(x1); y.push_back(y1);
 		}
 //	cout.precision(16);
 		cout<<"Case #"<<j+1<<": ";
 		for(int i=0; i<N; i++){
 		 cout<<x[i]<<" "<<y[i]<<" ";
 		}
 		cout<<"\n";
 	}
 	
 }
