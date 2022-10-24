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

pii P[MAXN];

int dis(int a,int b){
    a=abs(a);
    b=abs(b);
    return a+b-min(a,b);
}

void solve(){
    int n;
    scanf("%d",&n);
    fru(i,n) scanf("%d%d",&P[i].x,&P[i].y);
    int ret=0;
    fru(i,n) fru(j,i) ret=max(ret,dis(P[i].x-P[j].x,P[i].y-P[j].y));
    printf("%d\n",(ret+1)/2);
}

int main(){
    int o;
    scanf("%d",&o);
    fru(oo,o){
        printf("Case #%d: ",oo+1);
        solve();
    }
    return 0;
}
