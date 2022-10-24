// Google Code Jam Template by rabbit125 @2018/04/07
/* Libs. */
#include <bits/stdc++.h>
/* Define Value Vars. */
#define BIT         17
#define INF 2000000000
#define MOD 1000000007
#define STRMAX    1000
#define MAX     120000
/* Time Evaluation */
#define runtime() ((double)clock() / CLOCKS_PER_SEC)
/* EPS */
const double eps = 1e-7;
using namespace std;
/* Start Code Here */
int n;
int  okArr[MAX];
int oriArr[MAX];
void runTroubleSort() {
    bool done = false;
    while(!done) {
        done = true;
        for (int i = 0; i < n-2; ++i) {
            if (oriArr[i] > oriArr[i+2]) {
                done = false;
                swap(oriArr[i], oriArr[i+2]);
            }
        }
    }
}
int main() {
    int t, T = 1;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &oriArr[i]);
            okArr[i] = oriArr[i];
        }
        sort(okArr, okArr+n);
        runTroubleSort();
        bool isSame = true;
        for (int i = 0; i < n; ++i) {
            if (okArr[i] != oriArr[i]) {
                printf("Case #%d: %d\n", T++, i);
                isSame = false;
                break;
            }
        }
        if (isSame)
            printf("Case #%d: OK\n", T++);
    }
    return 0;
}
/*
2
5
5 6 8 4 3
3
8 9 7
*/
/*
Case #1: OK
Case #2: 1
*/
