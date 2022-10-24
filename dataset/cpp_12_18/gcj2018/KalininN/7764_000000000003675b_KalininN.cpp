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

const int maxn = 300005;

vector<int> poss[maxn];
int l[maxn], r[maxn];
map<int, int> lastl, lastr;
map<pair2<int>, int> lastlr;
int ids = 0;
int n;
int answerl;
set<pair2<int>> answers;

inline int count(int id, int l, int r)
{
    if (id == -1) return 0;
    return upper_bound(all(poss[id]), r) - lower_bound(all(poss[id]), l);
}

void check(int lv, int rv, int pos)
{
//     cout << "check " << lv << ' ' << rv << ' ' << pos << endl;
    int lid = lastl[lv];
    int rid = lastr[rv];
    int lrid = -1;
    if (lastlr.count({lv, rv})) lrid = lastlr[{lv, rv}];
    int l = pos;
    int r = n;
    while (r - l > 1)
    {
        int m = (l + r) / 2;
        if (count(lid, pos, m) + count(rid, pos, m) - count(lrid, pos, m) == m - pos + 1) l = m;
        else r = m;
    }
    int R = l;
    l = -1;
    r = pos;
    while (r - l > 1)
    {
        int m = (l + r) / 2;
        if (count(lid, m, pos) + count(rid, m, pos) - count(lrid, m, pos) == pos - m + 1) r = m;
        else l = m;
    }
    int L = r;
    if (answerl < R - L + 1)
    {
        answerl = R - L + 1;
        answers.clear();
    }
    if (answerl == R - L + 1)
    {
        answers.insert({L, R});
    }
//     cout << L << ' ' << R << endl;
}

int main()
{
    int NT = 0;
    scanf("%d", &NT);
    for (int T = 1; T <= NT; T++)
    {
        printf("Case #%d:", T);
        
        scanf("%d", &n);
        lastl.clear();
        lastr.clear();
        lastlr.clear();
        ids = 0;
        for (int i = 0; i < n; i++)
        {
            int x;
            scanf("%d%d%d", &x, &l[i], &r[i]);
            l[i] = x + l[i];
            r[i] = x - r[i];
            if (lastl.count(l[i]))
            {
                poss[lastl[l[i]]].pb(i);
            } else
            {
                poss[ids].clear();
                lastl[l[i]] = ids++;
                poss[ids - 1].pb(i);
            }
            if (lastr.count(r[i]))
            {
                poss[lastr[r[i]]].pb(i);
            } else
            {
                poss[ids].clear();
                lastr[r[i]] = ids++;
                poss[ids - 1].pb(i);
            }
            if (lastlr.count({l[i], r[i]}))
            {
                poss[lastlr[{l[i], r[i]}]].pb(i);
            } else
            {
                poss[ids].clear();
                lastlr[{l[i], r[i]}] = ids++;
                poss[ids - 1].pb(i);
            }
        }
//         for (int i = 0; i < n; i++) cout << l[i] << ' ' << r[i] << endl;
//         for (int i = 0; i < ids; i++)
//         {
//             cout << "id = " << i << endl;
//             for (auto t : poss[i]) cout << t << ' ';
//             cout << endl;
//         }
        
        answerl = 1;
        answers.clear();
        for (int i = 0; i < n; i++) answers.insert({i, i});
        for (int i = 0; i < n - 1; i++)
        {
            check(l[i], r[i + 1], i);
            check(l[i + 1], r[i], i);
        }
        printf(" %d %d\n", answerl, (int)answers.size());

        fprintf(stderr, "%d/%d cases done!\n", T, NT);
    }
    return 0;
}
