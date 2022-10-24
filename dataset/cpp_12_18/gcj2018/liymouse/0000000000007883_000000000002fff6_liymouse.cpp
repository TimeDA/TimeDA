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

int cmp(i64d x , i64d y)
{
    return x > y;
}
int main()
{
	int cas;
	scanf("%d" , &cas);
	for (int ca = 1; ca <= cas; ca ++)
	{
        int R , B , C;
        scanf("%d %d %d" , &R , &B , &C);
        i64d m[1002];
        i64d s[1002];
        i64d p[1002];
        i64d low = 0;
        i64d high = 0;
        for (int i = 0; i < C; i ++)
        {
            scanf("%lld %lld %lld" , &m[i] , &s[i] , &p[i]);
            if (m[i] * s[i] + p[i] > high)
                high = m[i] * s[i] + p[i];
        }
        i64d res = high;
        while (low <= high)
        {
            i64d mid = (low + high) / 2;
            i64d a[1002] = {0};
            for (int i = 0; i < C; i ++)
                if (mid >= p[i])
                {
                    i64d t = (mid - p[i]) / s[i];
                    a[i] = min(t , m[i]);
                }
            sort(a , a + C, cmp);
            i64d tot = 0;
            for (int i = 0; i < R; i ++) tot += a[i];
            if (tot >= B)
            {
                res = min(mid , res);
                high = mid-1;
            }
            else low = mid + 1;
        }
        printf("Case #%d: %lld\n" , ca, res);
    }
    return 0;
}