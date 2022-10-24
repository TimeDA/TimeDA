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

struct pt
{
    ll x, y, z;
};

inline pt operator-(const pt &a, const pt &b)
{
    return {a.x - b.x, a.y - b.y, a.z - b.z};
}

inline ll operator*(const pt &a, const pt &b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

inline pt cross(const pt &a, const pt &b)
{
    return {a.y * b.z - b.y * a.z,
            a.z * b.x - b.z * a.x,
            a.x * b.y - a.y * b.x};
}

const int maxn = 1005;

int p[maxn];
pt col[maxn];
int n;

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
            scanf("%lld%lld%lld", &col[i].x, &col[i].y, &col[i].z);
        }
        for (int i = 0; i < n; i++) p[i] = i;
        do
        {
            bool ok = true;
            for (int i = 1; i + 2 < n && ok; i++)
            {
                pt norm = cross(col[p[i + 1]] - col[p[i]], col[p[i + 2]] - col[p[i]]);
                ll d = norm * col[p[i]];
                if (norm * pt{col[p[i]].x, col[p[i]].y, 0} - d > 0)
                {
                    norm.x *= -1;
                    norm.y *= -1;
                    norm.z *= -1;
                    d *= -1;
                }
//                 cout << i << ' ' << norm.x << ' ' << norm.y << ' ' << norm.z << ' ' << d << endl;
//                 cout << norm * col[p[i]] << ' ' << norm * col[p[i + 1]] << ' ' << norm * col[p[i + 2]] << endl;
                for (int j = 0; j < i; j++) if (norm * col[p[j]] - d > 0) ok = false;
            }
            if (ok)
            {
                for (int i = 0; i < n; i++) printf(" %d", p[i] + 1);
                printf("\n");
                break;
            }
        } while (next_permutation(p, p + n));

        fprintf(stderr, "%d/%d cases done!\n", T, NT);
    }
    return 0;
}
