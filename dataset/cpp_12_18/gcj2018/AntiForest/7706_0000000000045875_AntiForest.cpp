#include <bits/stdc++.h>

#define INF 1000000010
#define INFLL ((1LL<<62)-5)
#define FO(i,a,b) for (int (i) = (a); (i) < (b); ++(i))
#define OF(i,a,b) for (int (i) = (a)-1; (i) >= (b); --(i))
#define SZ(v) int(v.size())

using namespace std;
//PAIRS:
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pii;
typedef long long ll;

/*~~~~TEMPLATE END~~~~*/




namespace MF {
    const int N = 105*10, M = 105*105*5;
    int f[N], e[2*M], c[2*M], fl[2*M], nxt[2*M], ce;
    int n, s, t;
    int Q[N], lvl[N];
    int le[N];

    void init(int _n) {
        n = _n+2; s = _n; t = _n+1; ce = 0;
        FO(i,0,n) f[i]=-1;
    }

    void add(int a, int b, int cap) {
        nxt[ce]=f[a]; f[a]=ce; e[ce]=b; fl[ce]=0; c[ce]=cap; ce++;
        nxt[ce]=f[b]; f[b]=ce; e[ce]=a; fl[ce]=0; c[ce]=0; ce++;
    }

    bool bfs() {
        FO(i,0,n) lvl[i]=-1;
        int qi = 1;
        Q[0] = s; lvl[s] = 0;
        FO(i,0,qi) {
            int x=Q[i];
            le[x]=f[x];
            for (int j=f[x];j>=0;j=nxt[j]) if (c[j]-fl[j]>0) {
                int y=e[j];
                if (lvl[y]==-1) {
                    lvl[y]=lvl[x]+1;
                    Q[qi++]=y;
                }
            }
        }
        return lvl[t]!=-1;
    }

    int aug(int cu, int cf) {
        if (cu == t) return cf;
        for (int &i=le[cu];i>=0;i=nxt[i]) if (c[i]-fl[i]>0) {
            int x=e[i];
            if (lvl[x]!=lvl[cu]+1) continue;
            int rf = aug(x,min(cf,c[i]-fl[i]));
            if (rf>0) {
                fl[i]+=rf;
                fl[i^1]-=rf;
                return rf;
            }
        }
        lvl[cu]=-1;
        return 0;
    }

    int mf() {
        int tot = 0;
        while (bfs())
            for (int x=aug(s,1e9);x;x=aug(s,1e9)) tot+=x;
        return tot;
    }

    vector<pair<int,int> > mc() {
        bfs();
        vector<pair<int,int> > res;
        FO(i,0,n) if (lvl[i] != -1) {
            for (int j=f[i];j>=0;j=nxt[j]) if (lvl[e[j]] == -1) {
                res.push_back(pair<int,int>(i,e[j]));
            }
        }
        return res;
    }
}


struct soln {
    int N;
    int gr[105][105];
    void solve() {
        scanf("%d", &N);
        FO (i,0,N) {
            FO (j,0,N) {
                scanf("%d", &gr[i][j]);
            }
        }
        int ans = 0;
        FO(i,-N,N+1) {
            MF::init(2*N);
            FO (i,0,N) {
                MF::add(MF::s, i, 1);
                MF::add(N+i, MF::t, 1);
            }
            FO (r,0,N) {
                FO (c,0,N) {
                    if (gr[r][c] == i) {
                        MF::add(r, N+c, 1);
                    }
                }
            }
            ans += MF::mf();
        }
        printf("%d\n", N*N-ans);
    }
};

int T;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    scanf("%d", &T);
    FO (_z,0,T) {
        printf("Case #%d: ", _z+1);
        soln s;
        s.solve();
    }
    return 0;
}
