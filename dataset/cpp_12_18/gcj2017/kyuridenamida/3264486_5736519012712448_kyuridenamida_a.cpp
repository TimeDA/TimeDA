#include <bits/stdc++.h>
 using namespace std;
 
 
 
 void cs(){
 	static int t = 1;
 	cout << "Case #" << t++ << ": ";
 }
 int main()
 {
 	int T;
 	cin >> T;
 	while(T--){
 		string s;
 		cin >> s;
 		int K;
 		cin >> K;
 		int ans = 0;
 		for(int i = 0 ; i+K <= s.size() ; i++){
 			if( s[i] == '-' ){
 				for(int j = 0 ; j < K ; j++)
 					s[i+j] = s[i+j] == '+' ? '-' : '+'; 
 				ans++;
 			}
 		}
 		cs();
 		if( count(s.begin(),s.end(),'+') != s.size() ){
 			cout << "IMPOSSIBLE" << endl;
 		}else{
 			cout << ans << endl;
 		}
 	}
 }
