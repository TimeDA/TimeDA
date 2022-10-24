#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using D = double;
using uint = unsigned int;
template<typename T>
using pair2 = pair<T, T>;

#ifdef WIN32
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second

const int maxn = 505;

int ans[50][maxn][maxn];
int R, B;

int main()
{
    for (int mr = 0; mr * (mr - 1) / 2 <= 500; mr++)
    {
        for (int r = 0; r <= 500; r++)
        {
            for (int b = 0; b <= 500; b++)
            {
                for (int i = 1; i * (i - 1) / 2 <= b && i * mr <= r; i++)
                {
                    ans[mr + 1][r][b] = max(ans[mr + 1][r][b], ans[mr][r - i * mr][b - i * (i - 1) / 2] + i);
                }
            }
        }
    }
    
    int NT = 0;
    scanf("%d", &NT);
    for (int T = 1; T <= NT; T++)
    {
        printf("Case #%d:", T);
        
        scanf("%d%d", &R, &B);
        int answer = 0;
        for (int mr = 0; mr * (mr - 1) / 2 <= R; mr++)
        {
            for (int r = 0; r <= R; r++)
            {
                for (int b = 0; b <= B; b++) answer = max(answer, ans[mr + 1][r][b]);
            }
        }
        printf(" %d\n", answer - 1);

        fprintf(stderr, "%d/%d cases done!\n", T, NT);
    }
    return 0;
}
