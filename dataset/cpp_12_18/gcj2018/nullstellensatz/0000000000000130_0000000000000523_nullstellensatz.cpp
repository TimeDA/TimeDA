


#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
using namespace std;

int A, B, n, T;

void guess() {
    int l = A, r = B;
    while (l < r - 1) {
        int mid = (l + r) >> 1;
        cout << mid << endl;
        cout.flush();
        string res;
        cin >> res;
        if (res[0] == 'C') return;
        if (res.length() == 7) r = mid - 1; else l = mid + 1;
    }
    while (l <= r) {
        cout << r << endl;
        cout.flush();
        string res;
        cin >> res;
        if (res[0] == 'C') return; else -- r;
    }
}

int main() {
    cin >> T;
    for (int testcase = 1; testcase <= T; ++ testcase) {
        cin >> A >> B >> n;
        guess();
    }

    return 0;
}
