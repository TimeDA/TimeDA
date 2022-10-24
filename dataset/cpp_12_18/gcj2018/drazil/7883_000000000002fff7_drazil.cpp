#include <bits/stdc++.h>

using namespace std;

int n, p;
vector<pair<double, double>> arr, narr;

void merge(double L, double R) {
    int s = arr.size();
    for (int i = 0; i < s; ++i) {
        arr.emplace_back(arr[i].first + L, arr[i].second + R);
    }
    arr.emplace_back(L, R);
    
    sort(arr.begin(), arr.end());
    
    //merge here
    narr.clear();
    bool got = false;
    for (const auto &p : arr) {
        if (!got) {
            got = true;
            L = p.first;
            R = p.second;
        } else {
            if (p.first <= R) R = max(p.second, R);
            else {
                narr.emplace_back(L, R);
                L = p.first;
                R = p.second;
            }
        }
    }
    if (got) narr.emplace_back(L, R);
    
    swap(arr, narr);
}

int main() {
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t) {
        scanf("%d%d", &n, &p);
        arr.clear();
        int rp = p;
        for (int i = 0; i < n; ++i) {
            int x, y;
            scanf("%d%d", &x, &y);
            merge(min(x, y) * 2, 2 * sqrt(x * x + y * y));
            p -= 2 * (x + y);
        }
        double ans = p;
        for (const auto &it : arr) {
            //cout << it.first << ' ' << it.second << endl;
            if (it.first <= p && p <= it.second) ans = 0;
            else if(it.second < p) ans = min(ans, p - it.second);
        }
        printf("Case #%d: %.10f\n", t, rp - ans);
    }

    return 0;
}
