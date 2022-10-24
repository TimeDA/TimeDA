


/*
    Prob:
    Author: 
    Time:   
    Description:
*/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
using namespace std;

const int MaxN = 1005;

int T, n, d;
string str;

bool check() {
    long long cur = 1, sum = 0, lim = d;
    for (int k = 0; k < n; ++ k) {
        if (str[k] == 'C') cur <<= 1;
        if (str[k] == 'S') sum += cur;
        if (sum > lim) return true;
    }
    return false;
}

int main() { 
    cin >> T;
    for (int testcase = 1; testcase <= T; ++ testcase) {
        cin >> d >> str;
        n = str.length();
        int cnt = 0, ans = 0;
        for (int k = 0; k < n; ++ k)
            if (str[k] == 'S') ++ cnt;
        if (cnt <= d) {
            while (check()) {
                ++ ans;
                int pos = -1;
                for (int k = 0; k + 1 < n; ++ k)
                    if (str[k] == 'C' && str[k + 1] == 'S') pos = k;
                swap(str[pos], str[pos + 1]);
            }
        }
        
        printf("Case #%d: ", testcase);
        if (cnt <= d) printf("%d\n", ans); else puts("IMPOSSIBLE");
    }
       
    return 0;
}
