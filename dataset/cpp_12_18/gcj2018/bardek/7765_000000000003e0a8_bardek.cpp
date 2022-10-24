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
const int MAXN = 100005;

LL A[MAXN];

void solve(){
    int n;
    scanf("%d",&n);
    int s=0;
    fru(_,n){
        LL w;
        scanf("%lld",&w);
        if(A[s]<=6*w){
            A[s+1]=A[s]+w;
            ++s;
        }
        for(int i=s;i;--i) if(A[i-1]<=6*w) A[i]=min(A[i],A[i-1]+w);
    }
    printf("%d\n",s);
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
