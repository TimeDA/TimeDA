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

void solve() {
    int N;
    cin >> N;
    vector<int> a;
    vector<int> b;
    REP(i, N){
        int x;
        cin >> x;
        if (i % 2 == 0) {
            a.push_back(x);
        } else {
            b.push_back(x);
        }
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    vector<int> c;
    for(int i = 0; i < a.size(); i++) {
        c.push_back(a[i]);
        if (i < b.size()) {
            c.push_back(b[i]);
        }
    }
    int answer = -1;
    for(int i = 0; i+1 < c.size(); i++) {
        if (c[i] > c[i+1]) {
            answer = i;
            break;
        }
    }
    if(answer == -1) {
        cout << "OK" << endl;
    } else {
        cout << answer << endl;
    }
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
