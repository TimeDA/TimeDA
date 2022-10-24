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

const int maxn = 25;

int p[maxn][maxn];
bool was[maxn][maxn];
char s[maxn];
int n, m;

int go(int x, int y)
{
    if (x < 0 || x >= n || y < 0 || y >= m) return 0;
    if (was[x][y]) return 0;
    if (p[x][y] != 0) return 0;
    was[x][y] = true;
    int ans = 1;
    ans += go(x - 1, y);
    ans += go(x + 1, y);
    ans += go(x, y + 1);
    ans += go(x, y - 1);
    return ans;
}

void invert(int lx, int ly, int rx, int ry)
{
    for (int x = lx; x < rx; x++)
    {
        for (int y = ly; y < ry; y++) p[x][y] = 1 - p[x][y];
    }
}

int findmax0()
{
    memset(was, false, sizeof(was));
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++) if (p[i][j] == 0 && !was[i][j])
        {
            ans = max(ans, go(i, j));
        }
    }
    return ans;
}

int main()
{
    int NT = 0;
    scanf("%d", &NT);
    for (int T = 1; T <= NT; T++)
    {
        printf("Case #%d:", T);
        
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; i++)
        {
            scanf("%s", s);
            for (int j = 0; j < m; j++) p[i][j] = (s[j] == 'B' ? 0 : 1);
        }
        
        int answer = 0;
        for (int mirx = 0; mirx < 2; mirx++)
        {
            for (int miry = 0; miry < 2; miry++)
            {
                
        for (int rot = 0; rot < 2; rot++)
        {
            for (int col = 0; col < 2; col++)
            {
//                 cout << "try " << endl;
//                 for (int i = 0; i < n; i++)
//                 {
//                     for (int j = 0; j < m; j++) cout << p[i][j];
//                     cout << endl;
//                 }
                { // single
                    answer = max(answer, findmax0());
                }
                { // 2, horizontal
                    bool found01 = false;
                    for (int i = 0; i < n; i++)
                    {
                        for (int j = 0; j < m - 1; j++) if (p[i][j] == 0 && p[i][j + 1] == 1) found01 = true;
                    }
                    if (found01)
                    {
                        for (int j = 1; j < m; j++)
                        {
                            invert(0, j, n, m);
                            answer = max(answer, findmax0());
                            invert(0, j, n, m);
                        }
                    }
                }
                { // 4
                    bool found0110 = false;
                    for (int i = 0; i < n - 1; i++)
                    {
                        for (int j = 0; j < m - 1; j++) if (p[i][j] == 0 && p[i][j + 1] == 1 && p[i + 1][j] == 1 && p[i + 1][j + 1] == 0) found0110 = true;
                    }
                    if (found0110)
                    {
                        for (int i = 1; i < n; i++)
                        {
                            for (int j = 1; j < m; j++)
                            {
                                invert(0, j, n, m);
                                invert(i, 0, n, m);
                                answer = max(answer, findmax0());
                                invert(0, j, n, m);
                                invert(i, 0, n, m);
                            }
                        }
                    }
                    bool found0001 = false;
                    for (int i = 0; i < n - 1; i++)
                    {
                        for (int j = 0; j < m - 1; j++) if (p[i][j] == 0 && p[i][j + 1] == 0 && p[i + 1][j] == 0 && p[i + 1][j + 1] == 1) found0001 = true;
                    }
                    if (found0001)
                    {
//                         cout << "here " << endl;
                        for (int i = 1; i < n; i++)
                        {
                            for (int j = 1; j < m; j++)
                            {
                                invert(i, j, n, m);
                                answer = max(answer, findmax0());
                                invert(i, j, n, m);
                            }
                        }
                    }
                }
                invert(0, 0, n, m);
            }
            for (int i = 0; i < max(n, m); i++)
            {
                for (int j = 0; j < i; j++) swap(p[i][j], p[j][i]);
            }
            swap(n, m);
        }
                for (int i = 0; i < n; i++)
                {
                    for (int j = 0; j < m - j - 1; j++) swap(p[i][j], p[i][m - j - 1]);
                }
            }
            for (int j = 0; j < m; j++)
            {
                for (int i = 0; i < n - i - 1; i++) swap(p[i][j], p[n - i - 1][j]);
            }
        }
        printf(" %d\n", answer);

        fprintf(stderr, "%d/%d cases done!\n", T, NT);
    }
    return 0;
}
