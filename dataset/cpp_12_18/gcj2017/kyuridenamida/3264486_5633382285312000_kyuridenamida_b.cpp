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
 		string t = s;
 		for(int i = 1 ; i < s.size() ; i++){
 			if( s[i-1] > s[i] ){
 				int j = i - 1;
 				int id = -1;
 				for( ; j >= 0 ; j--){
 					if( s[i-1] == s[j] ){
 						id = j;
 						t[j]--;
 					}else{
 						break;
 					}
 				}
 				if( t[0] == '0' ){
 					t = string(s.size()-1,'9');
 				}else{
 					for(int j = id+1 ; j < t.size() ; j++)
 						t[j] = '9';
 				}
 				break;
 			} 
 		}
 		cs();
 		cout << t << endl;
 		
 	}
 }
