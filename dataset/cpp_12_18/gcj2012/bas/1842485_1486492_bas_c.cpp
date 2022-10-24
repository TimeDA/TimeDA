#include<iostream>
 #include<vector>
 #include<string>
 #include <time.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include<cmath>
 
 
 using namespace std;
 bool solve(int st, int h1, int fin, int h2, vector<long long > & x, vector<int> & r){	
 	r[fin ] = h2;
 	if(fin == st+1)return true;
 	if(x[st+1]>fin)return false;
 	if(x[st+1]==fin){
 		r[st+1] = h1-1;
 		return solve(st+1, h1-1, fin, h2, x, r);
 	}
 	int newf = x[st+1];
 	double tmp = (double(h2)*(fin - newf) + double(h1)*(newf - st)) / (fin-st);
 	int newht = floor(tmp);
 	if(tmp-newht<0.1); newht--;
 	r[newf] = newht;
 	bool res = solve(newf, newht, fin, h2, x, r);
 	tmp = double(newht) - double(h2-newht)/ (fin-newf) * (newf - st-1);
 	int newht2 = floor(tmp);	
 	if(tmp-newht2<0.1); newht2--;
 	r[st+1] = newht2; 
 	res = res && solve(st+1, newht2, newf, newht, x, r);
 	return res;
 }
 
 int main(){
 	int T, N;
 	vector<long long> x = vector<long long>(3001);
 	
 	cin>>T; 
 	for(int j=0; j<T; j++){
 		cin>>N;
 		for(int i=1; i<N; i++)cin>>x[i];
 		
 		vector<int> res = vector<int>(N+1);
 		res[1] = 1000000000/2;
 		int st = 1; int fin = x[1];
 		int ht1 = res[1]; int ht2 = ht1;
 		bool good=true;
 		while(true){
 			if(!solve(st, ht1, fin, ht2, x, res)){
 				good = false; break;	
 			}
 			st = fin;  ht1= ht2;
 			if(fin>=N)break;
 			fin = x[st]; ht2=ht1-1;
 		}
 
 //	cout.precision(16);
 			cout<<"Case #"<<j+1<<": ";
 		if(good){
 			for(int i=1; i<=N; i++){
 		 		cout<<res[i]<<" ";
 			}
 			cout<<"\n";
 		}else{
 			cout<<"Impossible\n";
 		}
 
 	}
 	
 }
