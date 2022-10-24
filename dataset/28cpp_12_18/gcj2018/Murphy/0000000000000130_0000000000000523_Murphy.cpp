#include <bits/stdc++.h>
using namespace std;
#define pb push_back 
#define REP(i,n) for(int i=0;i<(n);i++ )
typedef long long LL;
typedef pair<int, int> pii;


int main(){
	int T; cin>>T;
	while (T--) {
		int A, B, N;
		cin>>A>>B>>N;
		while (1) {
			int M = (A + B) / 2;
			if (B - A == 1) M = B;
			cout<<M<<endl;
			string s; cin>>s;
			if (s == "CORRECT") break; else
			if (s == "TOO_SMALL") A = M + 1; else
			if (s == "TOO_BIG") B = M - 1; else {
				cerr<<s<<endl;
				break;
			}
		}
	}
    return 0;
}