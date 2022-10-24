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

const ll inf = (ll)maxn * 1e9;

int was[maxn];
bool broke[maxn];
int l[maxn], r[maxn];
int g[maxn];
ll need[maxn];
vector<int> order;
int n;

bool toorder(int cur)
{
    if (was[cur] == 1) return false;
    if (was[cur] == 2) return true;
    was[cur] = 1;
    if (broke[cur])
    {
        if (!toorder(l[cur])) return false;
        if (!toorder(r[cur])) return false;
    }
    was[cur] = 2;
    order.pb(cur);
    return true;
}

bool can(ll th)
{
    for (int i = 0; i < n; i++) broke[i] = false;
    for (int IT = 0; IT < n; IT++)
    {
        for (int i = 0; i < n; i++) was[i] = 0;
        order.clear();
        for (int i = 0; i < n; i++) if (!was[i])
        {
            if (!toorder(i)) return false;
        }
        reverse(all(order));
        for (int i = 0; i < n; i++)
        {
            need[i] = 0;
        }
        need[0] = th;
        bool found = false;
        for (auto i : order)
        {
            if (need[i] > g[i])
            {
                if (!broke[i])
                {
                    broke[i] = true;
                    found = true;
                    break;
                } else
                {
                    if (need[i] > inf) return false;
                    need[i] -= g[i];
                    need[l[i]] += need[i];
                    need[r[i]] += need[i];
                }
            }
        }
        if (!found) return true;
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
            scanf("%d%d", &l[i], &r[i]);
            l[i]--, r[i]--;
        }
        for (int i = 0; i < n; i++) scanf("%d", &g[i]);
        ll lb = 0;
        ll rb = inf;
        while (rb - lb > 1)
        {
            ll mb = (lb + rb) / 2;
            if (can(mb)) lb = mb;
            else rb = mb;
        }
        printf(" %lld\n", lb);
        
        fprintf(stderr, "%d/%d cases done!\n", T, NT);
    }
    return 0;
}
