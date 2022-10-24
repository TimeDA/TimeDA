#include <bits/stdc++.h>
using namespace std;
#define pb push_back 
#define REP(i,n) for(int i=0;i<(n);i++ )
typedef long long LL;
typedef pair<int, int> pii;

set<string> words;
set<char> letters[16];
string ans;
int N, L;

void gao(int i, string cur) {
	if (ans != "-") return;
	if (i == L) {
		if (words.count(cur) == 0) ans = cur;
		return;
	}
	for (char c : letters[i])
		gao(i + 1, cur + c);
}

int main() {
	int caseN; cin>>caseN;
	REP(_i, caseN) {
		cin>>N>>L;
		words.clear();
		REP(i, L) letters[i].clear();
		ans = "-";
		REP(i, N) {
			string x; cin>>x;
			words.insert(x);
			REP(j, L) letters[j].insert(x[j]);
		}
		gao(0, "");
		printf("Case #%d: %s\n", _i + 1, ans.c_str());
	}
    return 0;
}