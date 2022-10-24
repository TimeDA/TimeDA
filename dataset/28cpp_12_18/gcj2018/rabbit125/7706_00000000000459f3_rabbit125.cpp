// Google Code Jam Template by rabbit125 @2018/04/07
/* Libs. */
#include <bits/stdc++.h>
/* Define Value Vars. */
#define BIT         17
#define INF 2000000000
#define MOD 1000000007
#define STRMAX    1000
#define MAX        510
/* MATH */
const double PI  = 4.0 * atan( 1.0 ) ;
const double eps = 1e-7;
using namespace std;
/* Start Code Here */
int dp[MAX][MAX];
int main() {
    int t, T = 1;
    int r, b;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &r, &b);
        int ans = 0;
        int tR = r, tB = b;
        int R0 = 0, B0 = 0;
        for(int i = 1; i < MAX; i++) {
            if (i * (i+1) / 2 <= tR) {
                R0 = i;
            } else {
                break;
            }
        }
        for(int i = 1; i < MAX; i++) {
            if (i * (i+1) / 2 <= tB) {
                B0 = i;
            } else {
                break;
            }
        }
        tR -= R0 * (R0+1) / 2;
        tB -= B0 * (B0+1) / 2;
        //printf("%d %d\n", tR, tB);
        if (tR < tB && r > 0) {
            ans = B0;
            tR = r;
            int RR0 = 0;
            for(int i = 1; i < MAX; i++) {
                if (i * (i+1) / 2 <= tB) {
                    RR0 = i;
                } else {
                    break;
                }
            }
            tB -= RR0 * (RR0+1) / 2;
            tR -= (RR0+1);
            ans += RR0 + 1;
            if (tR > 0)
                ans += 1;
        } else if (tR > tB && b > 0) {
            ans = R0;
            tB = b;
            int RR0 = 0;
            for(int i = 1; i < MAX; i++) {
                if (i * (i+1) / 2 <= tR) {
                    RR0 = i;
                } else {
                    break;
                }
            }
            tR -= RR0 * (RR0+1) / 2;
            tB -= (RR0+1);
            ans += RR0 + 1;
            if (tR > 0)
                ans += 1;
        } else if (tR == tB && tB > 0){
            ans = R0 + B0;
            int RR0 = 0;
            for(int i = 1; i < MAX; i++) {
                if (i * (i+1) / 2 <= tR) {
                    RR0 = i;
                } else {
                    break;
                }
            }
            ans += RR0;
        } else {
            ans = R0 + B0;
        }
        printf("Case #%d: %d\n", T++, ans);
    }
    return 0;
}
/*
2
2 0
4 5
*/
/*
output
*/
