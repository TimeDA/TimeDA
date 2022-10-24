


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
using namespace std;

const double eps = 1e-12;

int T, n;
double area;

void cross(double &px, double &py, double qx, double qy) {
    double tx = px, ty = py;
    px = tx * qx - ty * qy;
    py = tx * qy + ty * qx;
}

double calc(double ang) {
    double sx = 0, sy = -sqrt(2) / 2, sz = 0.5;
    cross(sz, sy, cos(ang), sin(ang));
    return sz * sqrt(2) + cos(ang) * sqrt(2) / 2;
}

int main() { 
    scanf("%d", &T);
    for (int testcase = 1; testcase <= T; ++ testcase) {
        scanf("%lf", &area);
        if (area * area < 2.0 + eps) {
            double lx = -sqrt(2) / 2, ly = 0, rx = 0, ry = sqrt(2) / 2;
            double ratio = area / sqrt(2), angle = acos(ratio);
            cross(lx, ly, cos(angle), sin(angle));
            cross(rx, ry, cos(angle), sin(angle));
        
            printf("Case #%d:\n", testcase);
            printf("%.8f %.8f 0\n", (lx + rx) / 2, (ly + ry) / 2);
            printf("%.8f %.8f 0\n", (rx - lx) / 2, (ry - ly) / 2);
            puts("0 0 0.5");
        }
        else {
            double px = -sqrt(2) / 4, py = sqrt(2) / 4, pz = 0;
            double qx =  sqrt(2) / 4, qy = sqrt(2) / 4, qz = 0;
            double rx = 0, ry = 0, rz = 0.5;
            
            double langle = 0, rangle = asin(sqrt(3) / 3);
            while (langle < rangle - eps) {
                double mid = (langle + rangle) / 2;
                if (calc(mid) < area) langle = mid; else rangle = mid;
            }
            cross(pz, py, cos(langle), sin(langle));
            cross(qz, qy, cos(langle), sin(langle));
            cross(rz, ry, cos(langle), sin(langle));
            
            printf("Case #%d:\n", testcase);
            printf("%.8f %.8f %.8f\n", px, py, pz);
            printf("%.8f %.8f %.8f\n", qx, qy, qz);
            printf("%.8f %.8f %.8f\n", rx, ry, rz);
        }
    }

    return 0;
}
