#include <string>
#include <iostream>

using namespace std;

int main(){
	int t; cin >> t;
	while(t--){
		int a, b, n;
		cin >> a >> b;
		cin >> n;
		for(int i=0;i<n;i++){
			int m = (a+b+1)/2;
			cout << m << endl;
			string s; cin >> s;
			if(s == "CORRECT"){
				b = m;
				break;
			} else if(s == "TOO_BIG"){
				b = m - 1;
			} else {
				a = m;
			}
		}
	}
}
