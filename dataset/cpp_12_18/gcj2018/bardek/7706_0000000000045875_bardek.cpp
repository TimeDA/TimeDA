#include <bits/stdc++.h>
using namespace std;

#define fru(j,n) for(int j=0; j<(n); ++j)
#define tr(it,v) for(auto it=(v).begin(); it!=(v).end(); ++it)
#define x first
#define y second
#define pb push_back
#define ALL(G) (G).begin(),(G).end()

#if 1
#define DEB printf
#else
#define DEB(...)
#endif

typedef long long LL;
typedef double D;
typedef pair<int,int> pii;
typedef vector<int> vi;
const int inft = 1000000009;
const int MOD = 1000000007;
const int MAXN = 1000006;

namespace HK{ //Hopcroft-Karp: O(msqrt(n))
    const int MAXN = 205;//musi pomiescic c+d
    vector<int> V[MAXN];//krawedzie tylko w jedna strone: od C do D
    int M[MAXN];
    bool odw[MAXN];
    int dist[MAXN];
    queue<int> Q;

    inline bool dfs(int u)
    {
        odw[u]=1;
#define s M[*it]
        tr(it,V[u]) if((s==-1) || (!odw[s] && dist[s]==dist[u]+1 && dfs(s)))
        {
            M[u]=*it;
            M[*it]=u;
            return 1;
        }
        return 0;
    }
    int c,d; //chlopcy 0..c-1, dziewczyny: c..c+d-1
    bool bfs(){
        fru(i,c) odw[i]=0;
        fru(i,c) if(M[i]==-1) {dist[i]=0; Q.push(i);} else dist[i]=-1;
        bool ret=0;
        while(!Q.empty()){
            int u=Q.front(); 
            Q.pop();
            tr(it,V[u]) if(s!=-1 && dist[s]==-1){
                dist[s]=dist[u]+1;
                Q.push(s);
            }
            else if(s==-1) ret=1;
        }
        return ret;
    }
    int matching()
    {
        fru(i,c+d) { odw[i]=0;M[i]=-1;}
        int ret=0;
        while(bfs()) fru(i,c) if(M[i]==-1 && dfs(i)) ++ret;
        fru(i,c+d) V[i].clear();
        return ret;
    }
}

int T[105][105];

int solve(){
    int n;
    scanf("%d",&n);
    fru(i,n) fru(j,n) scanf("%d",&T[i][j]);
    HK::c=HK::d=n;
    int zost=0;
    for(int c=-n;c<=n;++c){
        fru(i,n) fru(j,n) if(T[i][j]==c)
            HK::V[i].pb(j+n);
        zost+=HK::matching();
    }
    return n*n-zost;
}

int main(){
    int o;
    scanf("%d",&o);
    fru(oo,o){
        printf("Case #%d: %d\n",oo+1,solve());
    }
    return 0;
}
