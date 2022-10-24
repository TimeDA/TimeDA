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

int cut(vector<int> &a , int b[] , int n , int num)
{
    a.push_back(0);
    int sum = 0;
    for (int i = 0; i < n; i ++)
    {
        sum += b[i];
        if (sum == num)
        {
            a.push_back(i+1);
            sum = 0;
        }
        else if (sum > num) return 0;
    }
    if (sum != 0) return 0;
    return 1;
}
int main()
{
	int cas;
	scanf("%d" , &cas);
	for (int ca = 1; ca <= cas; ca ++)
	{
		printf("Case #%d: " , ca);
        int r , c , h , v;
        int a[101][101] = {0};
        int B[101] = {0};
        int C[101] = {0};
        scanf("%d %d %d %d" , &r , & c , &h , &v);
        int tot = 0;
        for (int y = 0; y < r; y ++)
        {
            char s[111];
            scanf("%s" , s);
            for (int x = 0; x < c; x ++)
            {
                if (s[x] == '.') a[y][x] = 0;
                else a[y][x] = 1;
                B[x] += a[y][x];
                C[y] += a[y][x];
                tot += a[y][x];
            }
        }
        if (tot % ((h+1)*(v+1)) > 0) {printf("IMPOSSIBLE\n"); continue;}
        vector<int> hh;
        vector<int> vv;
        if (cut(hh , C , r , tot/(h+1)) == 0) {printf("IMPOSSIBLE\n"); continue;}
        if (cut(vv , B , c , tot/(v+1)) == 0) {printf("IMPOSSIBLE\n"); continue;}
        int ok = 1;
        for (int y = 1; y < hh.size(); y ++)
        {
            for (int x = 1; x < vv.size(); x ++)
            {
                int num = 0;
                for (int yy = hh[y-1]; yy < hh[y]; yy ++)
                    for (int xx = vv[x-1]; xx < vv[x]; xx ++)
                        num += a[yy][xx];
                if (num != tot / ((h+1)*(v+1))) {ok = 0; break;}
            }
            if (ok == 0) break;
        }
        if (ok) printf("POSSIBLE\n");
        else printf("IMPOSSIBLE\n");
    }
    return 0;
}