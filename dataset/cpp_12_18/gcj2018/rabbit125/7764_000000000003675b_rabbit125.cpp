// Google Code Jam Template by rabbit125 @2018/04/07
/* Libs. */
#include <bits/stdc++.h>
/* Define Value Vars. */
#define BIT         17
#define INF 2000000000
#define MOD 1000000007
#define STRMAX    1000
#define MAX    1200000
/* MATH */
const double PI  = 4.0 * atan( 1.0 ) ;
const double eps = 1e-7;
using namespace std;
/* Start Code Here */
int n;
struct S {
    int D, A, B;
    int idx;
};
int R[2][2][MAX];

int findNext(int diffR, int order, int startInx) {
    int tarVal = R[diffR][order][startInx];
    int ret = 0;
    while (startInx + ret < n && tarVal == R[diffR][order][startInx+ret]) {
        ret += 1;
    }
    //printf("dd %d\n", ret);
    return ret;
}

struct Ans {
    int M, N;
};
set<string> sA;

int main() {
    int t, T = 1;
    scanf("%d", &t);
    vector<S> vS;
    S tS;
    while (t--) {
        vS.clear();
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d%d%d", &tS.D, &tS.A, &tS.B);
            tS.idx = i;
            vS.push_back(tS);
        }
        for (int i = 0; i < n; i++) {
            R[0][0][i] = vS[i].D + vS[i].A;
            R[1][0][i] = vS[i].D - vS[i].B;
            R[0][1][n-1-i] = vS[i].D + vS[i].A;
            R[1][1][n-1-i] = vS[i].D - vS[i].B;
            //printf("%3d %3d\n", R[0][0][i], R[1][0][i]);
        }
        int ansMaxS = 1;
        for (int order = 0; order <= 1; order++) {
            for (int i = 0; i < 2; i++) {
                int M = R[i][order][0];
                int c1 = 1;
                for (int j = 1; j < n; j++) {
                    if (M == R[i][order][j]) {
                        c1 += 1;
                    } else {
                        int N = R[1-i][order][j];
                        int c2 = findNext(1-i, order, j);
                        //printf("%d+%d, M %d N %d // j %d\n", c1, c2, M, N, j);
                        ansMaxS = max(ansMaxS, c1 + c2);
                        M = R[i][order][j];
                        c1 = 1;
                    }
                }
                //ansMaxS = max(ansMaxS, c1);
                //printf("max %d\n", ansMaxS);
            }
        }
        sA.clear();
        Ans tAns;
        for (int order = 0; order <= 0; order++) {
            for (int i = 0; i < 2; i++) {
                int M = R[i][order][0];
                int c1 = 1;
                for (int j = 1; j < n; j++) {
                    if (M == R[i][order][j]) {
                        c1 += 1;
                    } else {
                        int N = R[1-i][order][j];
                        int c2 = findNext(1-i, order, j);
                        if (ansMaxS == c1 + c2) {
                            tAns.M = M;
                            tAns.N = N;
                            if (i == 1)
                                swap(tAns.M, tAns.N);
                            string tmpAns = std::to_string(c1) + "x" + to_string(j) + "x" + to_string(c2);
                            //printf("%s\n", tmpAns.c_str());
                            sA.insert(tmpAns);

                        }
                        M = R[i][order][j];
                        c1 = 1;
                    }
                }
                if (ansMaxS == c1)
                    sA.insert("xxx");
            }
        }

        printf("Case #%d: %d %d\n", T++, ansMaxS, sA.size());
    }
    return 0;
}
/*
3
1
1 1 1
5
2 7 12
6 3 11
8 10 1
11 11 12
13 9 14
5
1 3 3
2 2 2
3 1 1
4 2 2
5 3 3
*/
/*
output
*/
