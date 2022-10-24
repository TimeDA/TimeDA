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
    int A;
    cin >> A;
    // [100, 115]
    bool used[1000][1000] = {};
    for(int y = 0; y < 5; y++) {
        for(int x = 0; x < 5; x++) {
            int r = 100 + 3 * y + 1;
            int c = 100 + 3 * x + 1;
            int cnt = 0;
            while (true) {
                cout << r << " " << c << endl;
                int p, q;
                cin >> p >> q;
                if (!used[p][q]) {
                    used[p][q] = true;
                    cnt ++;
                }
                if (p == 0 && q == 0) {
                    return;
                }
                if (p == -1 && q == -1) {
                    assert(false);
                }
                if(cnt == 9) {
                    break;
                }
            }
        }
    }
}

int main(){
    iostream_init();

    int T;
    cin >> T;
    for(int testcase = 1; testcase <= T; testcase++) {
        /*
        cout << "Case #";
        cout << testcase;
        cout << ": ";
        */
        solve();
    }

    return 0;
}
