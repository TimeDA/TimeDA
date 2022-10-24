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

namespace {
int N;
const int MAX_N = 1000000;
int A[MAX_N];
int B[MAX_N];

int find_another(int start, const vector<int>& change) {
    int k = upper_bound(change.begin(), change.end(), start) - change.begin();
    if (k == change.size()) {
        return N;
    } else {
        return change[k];
    }
}


void solve() {
    int N;
    cin >> N;
    for(int i = 0; i < N; i++) {
        int d, a, b;
        cin >> d >> a >> b;
        A[i] = d + a;
        B[i] = d - b;
    }
    vector<int> changeA;
    vector<int> changeB;
    for(int i = 1; i < N; i++) {
        if (A[i] != A[i-1]) {
            changeA.push_back(i);
        }
        if (B[i] != B[i-1]) {
            changeB.push_back(i);
        }
    }

    map<int, vector<int>> indexA;
    map<int, vector<int>> indexB;
    map<pair<int, int>, vector<int>> indexAB;
    for(int i = 0; i < N; i++) {
        indexA[A[i]].push_back(i);
        indexB[B[i]].push_back(i);
        indexAB[make_pair(A[i], B[i])].push_back(i);
    }

    auto count = [&](int lb, int ub, int x, int y) {
        int ca = lower_bound(indexA[x].begin(), indexA[x].end(), ub) - lower_bound(indexA[x].begin(), indexA[x].end(), lb);
        int cb = lower_bound(indexB[y].begin(), indexB[y].end(), ub) - lower_bound(indexB[y].begin(), indexB[y].end(), lb);
        auto ab = make_pair(x, y);
        int cab = lower_bound(indexAB[ab].begin(), indexAB[ab].end(), ub) - lower_bound(indexAB[ab].begin(), indexAB[ab].end(), lb);
        return ca + cb - cab;
    };

    auto calcA = [&](int startA) {
        int startB = find_another(startA, changeA);
        if (startB == N) {
            return N - startA;
        }
        const int start = startA;
        const int bound = startB;
        int x = A[startA];
        int y = B[startB];
        int ok = bound;
        int ng = N;
        while (abs(ok - ng) > 1) {
            int mid = (ok + ng) / 2;
            int left = bound + 1;
            int right = mid + 1;
            int size = right - left;
            int c = count(left, right, x, y);
            if (c == size) {
                ok = mid;
            } else {
                ng = mid;
            }
        }
        int size = (ok+1) - start;
        return size;
    };
    auto calcB = [&](int startB) {
        int startA = find_another(startB, changeB);
        if (startA == N) {
            return N - startB;
        }
        const int start = startB;
        const int bound = startA;
        int x = A[startA];
        int y = B[startB];
        int ok = bound;
        int ng = N;
        while (abs(ok - ng) > 1) {
            int mid = (ok + ng) / 2;
            int left = bound + 1;
            int right = mid + 1;
            int size = right - left;
            int c = count(left, right, x, y);
            if (c == size) {
                ok = mid;
            } else {
                ng = mid;
            }
        }
        int size = (ok+1) - start;
        return size;
    };

    int answer = 0;
    int max_size = -1;

    for(int i = 0; i < N; i++) {
        int c = max(calcA(i), calcB(i));
        if (max_size < c) {
            max_size = c;
            answer = 1;
        } else if(max_size == c) {
            answer += 1;
        }
    }
    cout << max_size << " " << answer << endl;
}

}

int main(){
    iostream_init();
    int T;
    cin >> T;
    for(int t = 1; t <= T; t++) {
        cout << "Case #" << t << ": ";
        solve();
    }
    return 0;
}
