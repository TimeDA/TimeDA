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

int main()
{
	int cas;
	scanf("%d" , &cas);
	for (int ca = 1; ca <= cas; ca ++)
	{
		printf("Case #%d: " , ca);
        int n , a[110];
        scanf("%d" , &n);
        for (int i = 0; i < n; i ++) scanf("%d" , &a[i]);
        if (a[0] == 0 || a[n-1] == 0) {printf("IMPOSSIBLE\n"); continue;}
        int b[110] = {0};
        int k = 0;
        for (int i = 0; i < n; i ++)
        {
            while (a[i] > 0)
            {
                b[k] = i-k;
                a[i] --;
                k ++;
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i ++)
            ans = max(ans , abs(b[i]));
        ans ++;
        printf("%d\n" , ans);
        for (int i = 0; i < ans; i ++)
        {
            char s[110] = {0};
            for (int j = 0; j < n; j ++)
                if (b[j] == 0) s[j] = '.';
                else if (b[j] < 0) {s[j] = '/'; b[j-1] = b[j]+1; b[j] = 0;}
            for (int j = n-1; j >= 0; j --)
                if (b[j] > 0) {s[j] = '\\'; b[j+1] = b[j]-1; b[j] = 0;}
            s[n] = 0;
            printf("%s\n" , s);
        }
    }
    return 0;
}