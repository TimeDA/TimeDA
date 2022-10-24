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

const int maxn = 105;

char ans[maxn][maxn];
int a[maxn];
int wh[maxn];
int n;

int main()
{
    int NT = 0;
    scanf("%d", &NT);
    for (int T = 1; T <= NT; T++)
    {
        printf("Case #%d:", T);
        
        scanf("%d", &n);
        for (int i = 0; i < n; i++) scanf("%d", &a[i]);
        if (a[0] == 0 || a[n - 1] == 0)
        {
            printf(" IMPOSSIBLE\n");
            continue;
        }
        int cur = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < a[i]; j++) wh[cur++] = i;
        }
        int answer = 0;
        for (int i = 0; i < n; i++) answer = max(answer, abs(i - wh[i]));
        answer++;
        for (int i = 0; i < answer; i++)
        {
            for (int j = 0; j < n; j++) ans[i][j] = '.';
            ans[i][n] = '\0';
        }
        for (int i = 0; i < n; i++)
        {
            if (wh[i] > i)
            {
                for (int j = i; j < wh[i]; j++) ans[j - i][j] = '\\';
            } else if (wh[i] < i)
            {
                for (int j = i; j > wh[i]; j--) ans[i - j][j] = '/';
            }
        }
        printf(" %d\n", answer);
        for (int i = 0; i < answer; i++) printf("%s\n", ans[i]);

        fprintf(stderr, "%d/%d cases done!\n", T, NT);
    }
    return 0;
}
