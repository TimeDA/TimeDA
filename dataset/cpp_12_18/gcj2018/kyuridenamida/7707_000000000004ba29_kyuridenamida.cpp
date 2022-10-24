// failed to generate code
#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for(int i = 0 ; i < (int)(n) ; i++)
#define int long long
typedef long double Double;

unsigned int randxor() {
    static unsigned int x = 123456789, y = 362436069, z = 521288629, w = 88675123;
    unsigned int t;
    t = (x ^ (x << 11));
    x = y;
    y = z;
    z = w;
    return (w = (w ^ (w >> 19)) ^ (t ^ (t >> 8)));
}

#define rand() randxor()

struct Edge {
    int a, b;
};

void reportEdges(vector<Edge> es) {
    for (auto e : es) {
        cout << e.a << " " << e.b << endl;
    }
}

void showProgress(set<int> es[50], int n) {
    for (int i = 0; i < n; i++) {
        for (auto j : es[i]) cout << j << " ";
        cout << endl;
    }
    cout << endl;
}


vector<Edge> randomGraph(int n) {
    assert(n >= 5);
    set<int> ps[50];
    vector<Edge> es;
    int fail = 0;
    auto addE = [&](int a, int b) {
        if (a < b) swap(a, b);
        es.push_back({a, b});
        ps[a].insert(b);
        ps[b].insert(a);
    };

    if (n == 10) {
        for (int i = 0; i + 1 < 10; i++)
            addE(i, i + 1);
        addE(0, 2);
        addE(0, 3);
        addE(0, 4);

        addE(7, 9);
        addE(6, 9);
        addE(4, 9);

    }

    while (es.size() != 2 * n) {
        if (fail > 100000) {
//            showProgress(ps, n);
            for (int i = 0; i < n; i++) ps[i].clear();
            es.clear();
            fail = 0;
        }
        int id1 = rand() % n;
        int id2 = rand() % n;
//        cout << id1 << " " << id2 << endl;
        fail++;
        if (id1 == id2) continue;
        if (ps[id1].size() >= 4) continue;
        if (ps[id2].size() >= 4) continue;
        if (ps[id2].count(id1)) continue;
        addE(id1, id2);
        fail--;
    }
    vector<int> deg(50);
    for (auto e : es) deg[e.a]++, deg[e.b]++;
    for (int i = 0; i < n; i++)
        assert(deg[i] == 4);
    return es;

}

typedef unsigned long long Hash;

Hash depthHash[] = {8999, 9001, 17957, 9973, 103, 9929, 9949, 9857, 63, 31, 2, 3, 7};

Hash memo[10][50];
bool memoized[10][50];

Hash identifier(int wf[50][50], int depth, int i, int n) {
    if (memoized[depth][i]) return memo[depth][i];
    if (depth == 0) {
        vector<int> arr;
        for (int j = 0; j < n; j++) {
            arr.push_back(wf[i][j]);
        }
        sort(arr.begin(), arr.end());
        Hash hash = 0;
        for (int j = 0; j < arr.size(); j++)
            hash = hash * depthHash[depth] + arr[j];
        memoized[depth][i] = true;
        return memo[depth][i] = hash;
    }

    vector<Hash> arr;
    for (int k = 1; k < 5; k++) {
        vector<Hash> subArr;
        for (int j = 0; j < n; j++) {
            if (wf[i][j] == k) {
                subArr.push_back(identifier(wf, depth - 1, j, n));
            }
        }
        sort(subArr.begin(), subArr.end());
        arr.insert(arr.end(), subArr.begin(), subArr.end());
    }


    Hash hash = 0;
    for (int j = 0; j < arr.size(); j++)
        hash = hash * depthHash[depth] + arr[j];
    memoized[depth][i] = true;
    return memo[depth][i] = hash;
}


map<Hash, int> ok(vector<Edge> es, int n) {

    memset(memoized, 0, sizeof(memoized));
    int wf[50][50] = {};
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            wf[i][j] = i == j ? 0 : 10000000;
    for (auto e : es) {
        wf[e.a][e.b] = 1, wf[e.b][e.a] = 1;
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                wf[j][k] = min(wf[j][k], wf[j][i] + wf[i][k]);


    if (n == 10) {
        map<Hash, int> S;
        map<map<Hash, int>, int> cnt;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int l = 0; l < n; l++) {
                    map<Hash, int> S;
                    for (int k = 0; k < n; k++) {
                        S[(wf[i][k] * 103 + wf[j][k]) * 103 + wf[l][k]] = k;
                    }
                    if (S.size() == 10) cnt[S]++;
                }
            }
        }

        for (auto i : cnt) {
//            cout << i.second << endl;
//            for (auto j : i.first)
//                cout << j.first << " " << j.second << "<" << endl;
            if (i.second == 1) return i.first;
        }
        return {};
    }

    map<Hash, int> S;

    for (int i = 0; i < n; i++) {
        S[identifier(wf, n < 15 ? 6 : 2, i, n)] = i;
    }
    return S;
}


vector<Edge> res[55];

int solve() {

    int L, U;
    cin >> L >> U;
    int x = 50;
    cout << x << endl;
    for (auto e : res[x]) {
        cout << e.a + 1 << " " << e.b + 1 << endl;
    }
    cout.flush();
    vector<Edge> nexts;
    int nn;
    cin >> nn;
    assert(nn == x);
    for (int i = 0; i < 2 * x; i++) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        nexts.push_back({a, b});
    }
    auto A = ok(res[x], x);
    auto B = ok(nexts, x);
    assert(B.size() == x);
    vector<int> res(x, -1);
    for (auto p : A) {
        res[p.second] = B[p.first];
    }
    for (int i = 0; i < x; i++) {
        cout << res[i] + 1;
        if (i + 1 == x) cout << endl;
        else cout << " ";
    }
    cout.flush();

}

void main_(istream &cin) {
    for (int i = 10; i <= 50; i++) {
        int mx;
        while (true) {
            auto e = randomGraph(i);
            mx = max<int>(mx, ok(e, i).size());
//            cout << i << " " << mx << endl;
            if (ok(e, i).size() == i) {
                res[i] = e;
                break;
            }
        }
    }

    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        solve();
    }

}


signed main() {
#ifdef INTELLIJ
    ifstream ifs("/home/kyuridenamida/CLionProjects/untitled/input.txt");
    if (ifs.is_open()) {
        main_(ifs);
        ifs.close();
    } else {
        cerr << "Error: no input." << endl;
    }
#else
    ios::sync_with_stdio(false);
    cin.tie(0);
    main_(cin);
#endif
}


