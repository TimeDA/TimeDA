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

int a[maxn][maxn];
int was[maxn];
int p[maxn];
vector<int> gr[maxn];
int n;

bool go(int cur)
{
    if (was[cur]) return false;
    was[cur] = true;
    for (auto t : gr[cur]) if (p[t] == -1 || go(p[t]))
    {
        p[t] = cur;
        return true;
    }
    return false;
}


int main()
{
    int NT = 0;
    scanf("%d", &NT);
    for (int T = 1; T <= NT; T++)
    {
        printf("Case #%d:", T);
        
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                scanf("%d", &a[i][j]);
                if (a[i][j] > 0) a[i][j]--;
                else a[i][j] = -a[i][j] - 1 + n;
            }
        }
        int answer = n * n;
        for (int t = 0; t < 2 * n; t++)
        {
            for (int i = 0; i < n; i++)
            {
                gr[i].clear();
                p[i] = -1;
                for (int j = 0; j < n; j++) if (a[i][j] == t) gr[i].pb(j);
            }
            for (int i = 0; i < n; i++)
            {
                memset(was, 0, sizeof(was));
                if (go(i)) answer--;
            }
        }

        printf(" %d\n", answer);
        
        fprintf(stderr, "%d/%d cases done!\n", T, NT);
    }
    return 0;
}
