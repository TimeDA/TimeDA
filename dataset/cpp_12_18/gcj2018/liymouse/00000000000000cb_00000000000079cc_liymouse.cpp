#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <numeric>
#include <cstring>

typedef long long i64d;
#define PI acos(-1.0)
using namespace std;

void mm(double m[4][4] , double x0 , double y0 , double z0 , double& x1 , double &y1 , double &z1)
{
    x1 = m[0][0] * x0 + m[0][1] * y0 + m[0][2] * z0 + m[0][3];
    y1 = m[1][0] * x0 + m[1][1] * y0 + m[1][2] * z0 + m[1][3];
    z1 = m[2][0] * x0 + m[2][1] * y0 + m[2][2] * z0 + m[2][3];
}

void m2(double a[4][4] , double b[4][4] , double c[4][4])
{
    for (int i = 0; i < 4; i ++)
        for (int j = 0; j < 4; j ++)
        {
            c[i][j] = 0;
            for (int k = 0; k < 4; k ++)
                c[i][j] += a[i][k] * b[k][j];
        }
}
int main()
{
	int cas;
	scanf("%d" , &cas);
	for (int ca = 1; ca <= cas; ca ++)
	{
		printf("Case #%d:\n" , ca);
        double area;
        scanf("%lf" , &area);
        if (area <= 1.414213)
        {
            double a = asin(area / 1.414213) - PI / 4.0;
            //printf("a = %.16lf\n" , a);
            //printf("a = %.16lf\n" , a * 180 / PI);
            double r0[4][4] = {{cos(a) , -sin(a) , 0 , 0},
            {sin(a) , cos(a) , 0 , 0},
            {0 , 0 , 1 , 0},
            {0 , 0 , 0 , 1}};
            double x , y , z;
            mm(r0 , 0.5 , 0 , 0 , x , y , z);
            printf("%.10lf %.10lf %.10lf\n" , x , y , z);
            mm(r0 , 0 , 0.5 , 0 , x , y , z);
            printf("%.10lf %.10lf %.10lf\n" , x , y , z);
            mm(r0 , 0 , 0 , 0.5 , x , y , z);
            printf("%.10lf %.10lf %.10lf\n" , x , y , z);
        }
        else
        {
            double a = PI/4.0;
            double b = asin(area / 1.732050) - asin(sqrt(2.0)/sqrt(3.0));
            double r0[4][4] = {{cos(a) , -sin(a) , 0 , 0},
            {sin(a) , cos(a) , 0 , 0},
            {0 , 0 , 1 , 0},
            {0 , 0 , 0 , 1}};
            double r1[4][4] = {{1 , 0 , 0 , 0},
            {0 , cos(b) , -sin(b) , 0},
            {0 , sin(b) , cos(b) , 0},
            {0 , 0 , 0 , 1}};
            double r2[4][4] = {0};
            m2(r1 , r0 , r2);
            double x , y , z;
            mm(r2 , 0.5 , 0 , 0 , x , y , z);
            printf("%.10lf %.10lf %.10lf\n" , x , y , z);
            mm(r2 , 0 , 0.5 , 0 , x , y , z);
            printf("%.10lf %.10lf %.10lf\n" , x , y , z);
            mm(r2 , 0 , 0 , 0.5 , x , y , z);
            printf("%.10lf %.10lf %.10lf\n" , x , y , z);
        }
    }
    return 0;
}