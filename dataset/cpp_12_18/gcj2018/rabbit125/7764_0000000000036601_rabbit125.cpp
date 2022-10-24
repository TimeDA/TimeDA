// Google Code Jam Template by rabbit125 @2018/04/07
/* Libs. */
#include <bits/stdc++.h>
/* Define Value Vars. */
#define BIT         17
#define INF 2000000000
#define MOD 1000000007
#define STRMAX    1000
#define MAX     120000
/* MATH */
const double PI  = 4.0 * atan( 1.0 ) ;
const double eps = 1e-7;
using namespace std;
/* Start Code Here */
int N, L, remain;
int p[MAX];
int x[MAX];
struct R {
    int idx;
    int add;
};
vector<R> rv;

bool cmp(R r1, R r2) {
    if (r1.add != r2.add)
        return r1.add < r2.add;
    return r1.idx < r2.idx;
}


bool ifAdd(int x, int& ret) {
    double a1 = (double)x;
    double a2 = (double)N;
    double a3 = (int)(a1 * 100.0 / a2 );
    double a4 = (int)(a1 * 100.0 / a2 + 0.5);
    //printf("x %d x %.2lf %.2lf\n", x , a3, a4);
    ret = (int)a4;
    if (a3 != a4) return 1;
    return 0;
}

int findAddX(int base) {
    int t1 = base, tmp = 0;
    int c1 = 0;
    //printf("%d\n", remain);
    while(ifAdd(t1 + c1, tmp) == 0 && c1 < remain) {
        c1 += 1;
        //printf("xx %d\n", c1);
    }
    if (ifAdd(t1 + c1, tmp) == 1) return c1;
    return 1e9;
}



int main() {
    int t, T = 1;
    int tmp = 0;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &N, &L);
        remain = N;
        for (int i = 0; i < L; i++) {
            scanf("%d", &p[i]);
            remain -= p[i];
        }
        rv.clear();
        R tR;
        for (int i = 0; i < L; i++) {
            tR.idx = i;
            tR.add = findAddX(p[i]);
            //printf("%d %d\n", tR.idx, tR.add);
            rv.push_back(tR);
        }
        tR.idx = L;
        tR.add = findAddX(0);
        //printf("%d %d\n", tR.idx, tR.add);
        rv.push_back(tR);
        sort(rv.begin(), rv.end(), cmp);
        int remainT = remain;
        int Ladd = 0, Lcnt = 0;
        while (remainT > 0 && remainT >= rv[0].add) {
            tR = rv[0];
            if (tR.idx != L) {
                p[tR.idx] += tR.add;
                remainT -= tR.add;
                rv.erase(rv.begin());
            } else {
                Lcnt = remainT / tR.add;
                Ladd = tR.add;
                remainT %= tR.add;
            }
        }
        int ans = 0;
        for (int i = 0; i < L; i++) {
            ifAdd(p[i], tmp);
            //printf("%d = %d %d\n", i, p[i], tmp);
            ans += tmp;
        }
        ifAdd(Ladd, tmp);
        ans += tmp * Lcnt;
        ifAdd(remainT, tmp);
        ans += tmp;

        printf("Case #%d: %d\n", T++, ans);
    }
    return 0;
}
/*
4
3 2
1 1
10 3
1 3 2
6 2
3 1
9 8
1 1 1 1 1 1 1 1
*/
/*
output
*/
