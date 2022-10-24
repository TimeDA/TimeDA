#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

static ll simulate(const string& s){
	ll damage = 0, power = 1;
	for(const char c : s){
		if(c == 'C'){
			power *= 2;
		}else if(c == 'S'){
			damage += power;
		}
	}
	return damage;
}

static string next_sequence(string s){
	const int n = s.size();
	for(int i = n - 1; i > 0; --i){
		if(s[i] == 'S' && s[i - 1] == 'C'){
			swap(s[i], s[i - 1]);
			return s;
		}
	}
	return "";
}

static void solve(){
	ll d;
	string s;
	cin >> d >> s;
	int answer = 0;
	while(s != ""){
		if(simulate(s) <= d){
			cout << answer << endl;
			return;
		}
		++answer;
		s = next_sequence(s);
	}
	cout << "IMPOSSIBLE" << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	int T;
	cin >> T;
	for(int case_num = 1; case_num <= T; ++case_num){
		cout << "Case #" << case_num << ": ";
		solve();
	}
	return 0;
}

