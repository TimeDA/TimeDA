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

using namespace std;

int a[1001][1001] = {0};

int main()
{
	int cas;
	scanf("%d" , &cas);
	for (int ca = 1; ca <= cas; ca ++)
	{
		//printf("Case #%d: " , ca);
        int n;
        scanf("%d" , &n);
        memset(a , 0 , sizeof(a));
        int step = 0;
        int height = 3;
        int width = (n / 3) + (n%3 > 0);
        width = ((width / 3) + (width % 3 > 0)) * 3;
        int x = 2;
        int b[1001] = {0};
        while (step < 1000)
        {
            while (b[x] != 0)
            {
                x += 3;
                if (x > width) x = 2;
            }
            printf("%d %d\n" , 2 , x);
            fflush(stdout);
            int i , j;
            scanf("%d %d" , &j , &i);
            if (i == 0 && j == 0) break;
            if (i == -1 && j == -1) break;
            a[j][i] = 1;
            if (a[1][x-1] == 1 && a[1][x] == 1 && a[1][x+1] == 1 &&
                a[2][x-1] == 1 && a[2][x] == 1 && a[2][x+1] == 1 &&
                a[3][x-1] == 1 && a[3][x] == 1 && a[3][x+1] == 1)
                b[x] = 1;
        }
    }
    return 0;
}