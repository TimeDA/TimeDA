// Google Code Jam Template by rabbit125 @2018/04/07
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
/* Start Code Here */
double A;
const double Pi = 2.0 * acos( 0.0 ) ;
const double sq2 = sqrt(2.0);
const double r = 0.5 * sq2;
void sol1() {
    double cosX = A / sq2;
    double sinX = sqrt( 1.0 - cosX * cosX);

    printf("tttt %.10lf %.10lf\n", r*cosX, r*sin(acos(A / sq2)));
    printf("xxxx %.10lf %.10lf\n", r*cosX, r*sinX);



    double mid = (r*cosX + r*sinX) / 2.0;

    printf("%.15lf %.15lf 0\n", mid, mid);
    printf("%.15lf %.15lf 0\n", mid * -1.0, mid);
    printf("0 0 0.5\n");
}

int main() {
    int t, T = 1;
    scanf("%d", &t);
    while(t--) {
        scanf("%lf", &A);
        double maxArc = Pi/4.0; // 45' --> min Area
        double minArc = 0.0;    // 0'  --> max Area
        while(maxArc > minArc) {
            double midArc = (maxArc + minArc) / 2.0;
            double realA = sq2 * cos(midArc);
            //printf("%.9lf / %.9lf / %.9lf // curA %.7lf\n", maxArc, minArc, midArc, realA);
            if (abs(realA - A) < 1e-10) {
                double realX = 0.5 * sq2 * cos(midArc);
                double realY = 0.5 * sq2 * sin(midArc);
                double cneterP = (realX + realY) / 2.0;
                printf("Case #%d:\n", T++);
                printf("%.15lf %.15lf 0\n", cneterP, cneterP);
                printf("%.15lf %.15lf 0\n", cneterP * -1.0, cneterP);
                printf("0 0 0.5\n");
                break;
            }
            if (realA > A)
                minArc = midArc;
            else
                maxArc = midArc;
        }
    }
    return 0;
}
/*
2
1.000000
1.414213
*/
/*
Case #1:
0.5 0 0
0 0.5 0
0 0 0.5
Case #2:
0.3535533905932738 0.3535533905932738 0
-0.3535533905932738 0.3535533905932738 0
0 0 0.5
*/
