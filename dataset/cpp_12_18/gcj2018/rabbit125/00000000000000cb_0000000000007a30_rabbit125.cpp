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
int matrix[520][520], A;
int sol20[6][2] = {{2,2}, {2,3}, {2,4},
                   {3,2}, {3,3}, {3,4}};
int checek20[6][4][2] = {{{1,1},{1,2},{2,1},{2,2}},
                         {{1,3},{2,3},{2,3},{2,3}},
                         {{1,4},{2,4},{1,5},{2,5}},
                         {{3,1},{3,2},{4,1},{4,2}},
                         {{3,3},{4,3},{3,3},{3,3}},
                         {{3,4},{3,5},{4,4},{4,5}}};
int rA, rB;
void printCmd(int a, int b) {
    printf("%d %d\n", a, b);
    fflush(stdout);
    scanf("%d %d", &rA, &rB);
}

void fixedSolA20() {
    int step = 0;
    while (1) {
        bool stepOK = true;
        for( int i = 0; i < 4; i++)
            if(matrix[checek20[step][i][0]][checek20[step][i][1]] == 0) {
                stepOK = false;
                break;
            }
        if (stepOK) step++;
        printCmd(sol20[step][0], sol20[step][1]);
        if (rA == 0 && rB == 0)
            break;
        matrix[rA][rB] = 1;
    }
}

int stepCheck[3][2] = {{-1, -1}, {-1, 0}, {-1, 1}};

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &A);
        memset(matrix, 0, sizeof(matrix));
        //fixedSolA20();
        int fillLen = A / 3 + (A % 3 != 0);
        int curP[2] = {2, 2};
        int stopX = fillLen - 1;
        while (1) {
            bool stepOK = true;
            for (int i = 0; i < 3; i++)
                if(matrix[ curP[0] + stepCheck[i][0] ][ curP[1] + stepCheck[i][1] ] == 0) {
                    stepOK = false;
                    break;
                }
            if (curP[0] == stopX) {
                int threeCol[3] = {-1, 0, 1};
                for (int j = 0; j < 3; j++)
                    for (int i = 0; i < 3; i++)
                        if(matrix[ curP[0] + threeCol[j] * stepCheck[i][0] ][ curP[1] + stepCheck[i][1] ] == 0) {
                            stepOK = false;
                            break;
                    }
            }
            if (stepOK) {
                curP[0] += 1;
            }
            printCmd(curP[0], curP[1]);
            if (rA == 0 && rB == 0)
                break;
            matrix[rA][rB] = 1;
        }
    }
    return 0;
}
/*
input
*/
/*
output
*/
