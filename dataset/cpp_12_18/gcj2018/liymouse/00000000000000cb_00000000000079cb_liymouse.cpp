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
        int n;
        int a[100001];
        scanf("%d" , &n);
        for (int i = 0; i < n; i ++)
        {
            scanf("%d" , &a[i]);
        }
        int b[50001];
        int k = 0;
        for (int i = 0; i < n; i += 2) b[k ++] = a[i];
        sort(b , b + k);
        k = 0;
        for (int i = 0; i < n; i += 2) a[i] = b[k++];

        k = 0;
        for (int i = 1; i < n; i += 2) b[k ++] = a[i];
        sort(b , b + k);
        k = 0;
        for (int i = 1; i < n; i += 2) a[i] = b[k++];
        int ans = -1;
        for (int i = 0; i < n-1; i ++)
            if (a[i] > a[i+1]) {ans = i; break;}
        if (ans == -1) printf("OK\n");
        else printf("%d\n" , ans);
    }
    return 0;
}