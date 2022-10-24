#include <cstdio>
#include <cstring>
#include <algorithm>
#define FOR(i,s,e) for (int i=(s); i<(e); i++)
#define FOE(i,s,e) for (int i=(s); i<=(e); i++)
#define FOD(i,s,e) for (int i=(s)-1; i>=(e); i--)
#define CLR(a,x) memset(a, x, sizeof(a))
#define EXP(i,l) for (int i=(l); i; i=qn[i])
#define LLD long long
#define RI(x) scanf("%d", &x)
#define PB push_back
using namespace std;

#define N 40005
#define M 300005
struct FG{
    int n, m, x, y, w, S, T, V, ret, ed;
    int g[N], l[N], v[N], qd[M], qc[M], qn[M], qr[M];

    void init(int s, int t, int v){
        S = s, T = t, V = v, ed = 1;
        for (int i=0; i<V; i++) l[i] = 0;
    }

    void bd(int x, int y, int w){
        qd[++ed] = y;
        qc[ed] = qr[ed] = w;
        qn[ed] = l[x];
        l[x] = ed;
        if (!(ed & 1)) bd(y, x, 0);
    }

    int gao(int x, int y){
        int mn = V - 1, F = 0, R = y, t;
        if (x == T) return y;
        for (int i=l[x]; i; i=qn[i]) if (qc[i] > 0){
            if (v[x] == v[qd[i]]+1){
                t = gao(qd[i], min(qc[i], R));
                qc[i] -= t, qc[i^1] += t;
                R -= t, F += t;
                if (v[S] >= V) return F;
                if (!R) break;
            }
            mn = min(mn, v[qd[i]]);
        }
        if (!F){
            g[v[x]]--;
            if (!g[v[x]]) v[S] = V;
            v[x] = mn+1;
            g[v[x]]++;
        }
        return F;
    }

    int go(){
        for (int i=0; i<V; i++) v[i] = g[i] = 0;
        int F = 0;
        g[0] = V;
        while (v[S] < V) F += gao(S, 1<<30);
        return F;
    }
};


int n, a[111][111], R[111][222];
FG F;

int main(){int tc;scanf("%d", &tc);FOE(TC,1,tc){printf("Case #%d: ", TC);
	RI(n);
	CLR(R, 0);
	FOR(i,0,n) FOR(j,0,n){
		RI(a[i][j]);
		if (a[i][j] < 0) a[i][j] = n+n+1+a[i][j];
		--a[i][j];
		R[i][a[i][j]] = 1;
	}
	
	int V = 4*n*n+2, S=V-2, T=V-1;
	F.init(S, T, V);
	FOR(i,0,n) FOR(j,0,n){
        F.bd(i*2*n + a[i][j], 2*n*n+j*2*n + a[i][j], 1);
	}
	
	int t=2*n;
	FOR(i,0,2*n*n){
		if (R[i/t][i%t]) F.bd(S, i, 1);
  		F.bd(i + 2*n*n, T, 1);
	}
	   
	
	int ret = n*n-F.go();
	printf("%d\n", ret);
}return 0;}