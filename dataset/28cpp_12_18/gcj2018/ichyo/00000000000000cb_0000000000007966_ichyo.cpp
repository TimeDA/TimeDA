#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)
using namespace std;
typedef long long LL;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
inline bool valid(int x, int w) { return 0 <= x && x < w; }

void iostream_init() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.setf(ios::fixed);
    cout.precision(12);
}

int calc(string s) {
    int power = 1;
    int sum = 0;
    for(char c : s) {
        if ( c == 'C') {
            power *= 2;
        } else {
            sum += power;
        }
    }
    return sum;
}

void solve() {
    int d;
    string p;
    cin >> d >> p;
    int n = p.size();

    int answer = 0;
    while( calc(p) > d ) {
        int idx = -1;
        for(int i = n-1; i > 0; i--) {
            if(p[i-1] == 'C' && p[i] == 'S') {
                idx = i;
                break;
            }
        }
        if(idx == -1) {
            cout << "IMPOSSIBLE" << endl;
            return;
        }
        swap(p[idx-1], p[idx]);
        answer += 1;
    }

    cout << answer << endl;
}

int main(){
    iostream_init();

    int T;
    cin >> T;
    for(int testcase = 1; testcase <= T; testcase++) {
        cout << "Case #";
        cout << testcase;
        cout << ": ";
        solve();
    }

    return 0;
}
