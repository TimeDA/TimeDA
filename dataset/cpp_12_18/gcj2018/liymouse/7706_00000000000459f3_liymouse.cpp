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

int a[501][501];
int main()
{
	int cas;
	scanf("%d" , &cas);
	for (int ca = 1; ca <= cas; ca ++)
	{
		printf("Case #%d: " , ca);
        int r , b;
        scanf("%d %d" , &r , &b);
#if 0
        //FILE *f = fopen("b_a.txt" , "w");
        //for (int rr = 0; rr <= 50; rr ++)
        {
            //for (int bb = 0; bb <= 50; bb ++)
            {
                //r = rr;
                //b = bb;
                int ans = 0;
                for (int k = 1; ; k ++)
                {
                    if (r > b) swap(r , b);
                    if (r + b < k) break;
                    int n = (1 + k) * k / 2;
                    if (r >= n && b >= n) {ans += k+1; r -= n; b -=n;}
                    else
                    {
                        for (int i = 0; i <= k; i ++)
                            if (r >= i && b >= (k-i))
                            {
                                ans ++;
                                r -= i;
                                b -= k-i;
                                //if (r > b) swap(r , b);
                            }
                    }
                }
                printf("%d\n" , ans);
                //fprintf(f , "%d " , ans+1);
            }
            //fprintf(f , "\n");
        }
        //fclose(f);
#else
        int ans = 0;
        memset(a , 0 , sizeof(a));
        a[0][0] = 1;
        for (int i = 0; i <= 50; i ++)
            for (int j = 0; j <= 50; j ++)
                if (i != 0 || j != 0)
                {
                    for (int x = 50; x >= 0; x --)
                        for (int y = 50; y >= 0; y --)
                        {
                            if (a[x][y] > 0) a[x+i][y+j] = max(a[x][y] + 1 , a[x+i][y+j]);
                            //if (x+i == 2 && y+j == 16 && a[x+i][y+j] == 8) printf("%d %d %d %d\n" , i , j , x , y);
                        }
                }
        printf("%d\n" , a[r][b]-1);
        //FILE *f = fopen("b.txt" , "w");
        //for (int i = 0; i <= 50; i ++)
        //{
        //    for (int j = 0; j <= 50; j ++)
        //        fprintf(f , "%d " , a[i][j]);
        //    fprintf(f , "\n");
        //}
        //fclose(f);
#endif
        
    }
    return 0;
}