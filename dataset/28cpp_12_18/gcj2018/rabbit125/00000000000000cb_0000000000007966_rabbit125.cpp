// Google Code Jam Template by rabbit125 @2017/04/08
/* Libs. */
#include <bits/stdc++.h>
/* Define Value Vars. */
#define BIT         17
#define INF 2000000000
#define MOD 1000000007
#define STRMAX    1000
#define MAX    1200000
/* Time Evaluation */
#define runtime() ((double)clock() / CLOCKS_PER_SEC)
/* EPS */
const double eps = 1e-7;
using namespace std;
char pStr[50];
int  pAtk[50];
int len;
int D, curAtk = 0, tolAtk = 0;
/* Start Code Here */
void calTotalAtk() {
    curAtk = 1;
    tolAtk = 0;
    for (int i = 0; i < len; ++i) {
        if (pStr[i] == 'C') {
            curAtk *= 2;
            pAtk[i] = curAtk;
        } else {
            pAtk[i] = curAtk;
            tolAtk += curAtk;
        }
    }
}

int main() {
    //freopen("A-small-attempt0.in", "r", stdin);
    //freopen("A-small-attempt0.out", "w" , stdout);
    //freopen("A-large.in", "r", stdin);
    //freopen("A-large.out", "w" , stdout);
    int t, T = 1;
    scanf("%d", &t);
    while(t--) {
        scanf("%d %s", &D, &pStr);
        len = strlen(pStr);
        calTotalAtk();
        if (tolAtk <= D) {
            printf("Case #%d: 0\n", T++);
        } else {
            int ans = 0;
            bool findSwap = 0;
            do {
                findSwap = 0;
                for (int i = len-1; i >= 1; --i) {
                    if (pStr[i] == 'S' && pStr[i-1] == 'C') {
                        swap(pStr[i], pStr[i-1]);
                        findSwap = 1;
                        ans += 1;
                        calTotalAtk();
                        break;
                    }
                }
            } while (findSwap && tolAtk > D);
            if (tolAtk <= D)
                printf("Case #%d: %d\n", T++, ans);
            else
                printf("Case #%d: IMPOSSIBLE\n", T++);
        }
    }
    return 0;
}
/*
10
8 CCSS

6
1 CS
2 CS
1 SS
6 SCCSSC
2 CC
3 CSCSS
*/
/*
Case #1: 1
Case #2: 0
Case #3: IMPOSSIBLE
Case #4: 2
Case #5: 0
Case #6: 5
*/
