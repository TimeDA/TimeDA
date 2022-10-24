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

const int inf = 1e9;

int n, l;
int ans[505], ans2[505];
int percent[100005];
int forpercent[505];

int main()
{
    int NT = 0;
    scanf("%d", &NT);
    for (int T = 1; T <= NT; T++)
    {
        printf("Case #%d:", T);
        
        scanf("%d%d", &n, &l);
        
        for (int i = 0; i <= n; i++)
        {
            percent[i] = (i * 200 / n + 1) / 2;
        }
        for (int i = n; i >= 0; i--) forpercent[percent[i]] = i;
        
        for (int i = 0; i <= 200; i++) ans[i] = inf;
        ans[0] = 0;
        
        for (int i = 0; i < l; i++)
        {
            int x;
            scanf("%d", &x);
            for (int j = 200; j >= 0; j--) ans2[j] = inf;
            for (int j = 200; j >= 0; j--)
            {
                for (int k = x; k <= n; k++)
                {
                    ans2[j + percent[k]] = min(ans2[j + percent[k]], ans[j] + k);
                }
            }
            for (int j = 200; j >= 0; j--) ans[j] = ans2[j];
        }
        for (int IT = 0; IT <= 200; IT++)
        {
            for (int j = 200; j >= 0; j--)
            {
                for (int k = 1; k <= n; k++) ans[j + percent[k]] = min(ans[j + percent[k]], ans[j] + k);
            }
        }
        int answer = 0;
        for (int j = 0; j <= 200; j++) if (ans[j] <= n) answer = j;
        printf(" %d\n", answer);

        fprintf(stderr, "%d/%d cases done!\n", T, NT);
    }
    return 0;
}
