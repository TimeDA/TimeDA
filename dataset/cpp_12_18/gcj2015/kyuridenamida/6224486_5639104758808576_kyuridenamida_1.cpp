#include <bits/stdc++.h>
 using namespace std;
 
 
 
 int chk(vector<int> v){
 	int sum = 0;
 	for(int i = 0 ; i < v.size() ; i++){
 		if( sum < i ) return 0;
 		sum += v[i];
 	}
 	return 1;
 }
 int main(){
 	int T;
 	int t=0;
 	cin >> T;
 	while(T--){
 		t++;
 		int n;
 		string s;
 		cin >> n >> s;
 		vector<int> v;
 		for(int i = 0 ; i < s.size() ; i++)
 			v.push_back(s[i]-'0');
 		for(int i = 0 ; ; i++){
 			if( chk(v) ){
 				cout << "Case #" << t << ": " << i << endl;
 				break;
 			}
 			v[0]++;
 		}
 	}
 }