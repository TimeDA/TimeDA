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
int check(int a[] , int d)
{
    i64d x = 0;
    i64d t = 1;
    for (int i = 0; i < 40; i ++)
    {
        if (a[i] > 0) x += t * a[i];
        t <<= 1;
    }
    if (x <= (i64d)d) return 1;
    return 0;
}
int main()
{
	//freopen("input.txt" , "r" , stdin);
	//freopen("output.txt" , "w" , stdout);
	//freopen("B-large.in" , "r" , stdin);
	//freopen("B-large.out" , "w" , stdout);
	int cas;
	scanf("%d" , &cas);
	for (int ca = 1; ca <= cas; ca ++)
	{
		printf("Case #%d: " , ca);
        int a[50] = {0};
        char s[50] = "";
        int d;
        scanf("%d %s" , &d , s);
        int k = 0;
        for (int i = 0; i < strlen(s); i ++)
        {
            if (s[i] == 'S') a[k] ++;
            else k ++;
        }
        int tot = 0;
        while (1)
        {
            if (check(a , d) == 1) {printf("%d\n" , tot); break;}
            k = 40;
            while (k > 0 && a[k] == 0) k --;
            if (k == 0) {printf("IMPOSSIBLE\n"); break;}
            a[k-1] ++;
            a[k] --;
            tot ++;
        }
    }
    return 0;
}