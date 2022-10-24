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

int x[10004], y[10004];
const int inf = 1e9;

int main()
{
    int NT = 0;
    scanf("%d", &NT);
    for (int T = 1; T <= NT; T++)
    {
        printf("Case #%d:", T);
        
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) scanf("%d%d", &x[i], &y[i]);
        pair2<int> mmx = {inf + 1, -1};
        pair2<int> mmy = {inf + 1, -1};
        for (int i = 0; i < n; i++)
        {
            mmx.fi = min(mmx.fi, x[i]);
            mmx.se = max(mmx.se, x[i]);
            mmy.fi = min(mmy.fi, y[i]);
            mmy.se = max(mmy.se, y[i]);
        }
        int answer = max((mmx.se - mmx.fi + 1) / 2, (mmy.se - mmy.fi + 1) / 2);
        printf(" %d\n", answer);

        fprintf(stderr, "%d/%d cases done!\n", T, NT);
    }
    return 0;
}
