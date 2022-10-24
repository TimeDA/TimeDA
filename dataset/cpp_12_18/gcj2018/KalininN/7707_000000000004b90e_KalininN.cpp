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

vector<pair<pair<int, ld>, int>> all;
int n, k;

int main()
{
    int NT = 0;
    scanf("%d", &NT);
    for (int T = 1; T <= NT; T++)
    {
        printf("Case #%d:", T);
        
        scanf("%d%d", &n, &k);
        all.clear();
        for (int i = 0; i < n; i++)
        {
            int x1, y1, x2, y2;
            scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
            if (x1 > x2)
            {
                swap(x1, x2);
                swap(y1, y2);
            }
            ld v2 = y2;
            if (x1 == x2) v2 = 1e9;
            else v2 += (y1 - y2) * 0.5 / (x2 - x1);
            all.pb({pair<int, ld>{x2, v2}, i});
        }
        sort(all(all));
        for (int i = 0; i < n;)
        {
            int j = i;
            while (j < n && all[j].fi.fi == all[i].fi.fi) j++;
            int was0 = -1;
            for (int k = i; k < j; k++) if (all[k].se == 0) was0 = k;
            if (was0 != -1 && all[was0].fi.se < 1e8)
            {
                reverse(all.begin() + i, all.begin() + was0);
            }
            i = j;
        }
//         if (k == 2)
//         {
//             int was1 = -1;
//             for (int i = 0; i < n; i++)
//             {
//                 if (all[i].se == 1) was1 = i;
//                 if (all[i].se == 0 && was1 != -1)
//                 {
//                     swap(all[was1], all[i]);
//                     break;
//                 }
//             }
//         }
        printf(" 1");
        for (auto t : all) if (t.se != 0) printf(" %d", t.se + 1);
        printf("\n");

        fprintf(stderr, "%d/%d cases done!\n", T, NT);
    }
    return 0;
}
