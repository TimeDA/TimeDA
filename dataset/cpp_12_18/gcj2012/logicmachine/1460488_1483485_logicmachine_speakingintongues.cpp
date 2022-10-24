#include <iostream>
 #include <string>
 #include <cctype>
 
 using namespace std;
 
 const char TABLE[] = "yhesocvxduiglbkrztnwjpfmaq";
 
 int main(){
 	int T;
 	cin >> T;
 	string s;
 	getline(cin, s);
 	for(int caseNum = 1; caseNum <= T; ++caseNum){
 		getline(cin, s);
 		for(int i = 0; i < s.size(); ++i){
 			if(islower(s[i])){ s[i] = TABLE[s[i] - 'a']; }
 		}
 		cout << "Case #" << caseNum << ": " << s << endl;
 	}
 	return 0;
 }
 
