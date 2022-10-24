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
const int MAXN = 106;

void solve(){
    int A;
    scanf("%d",&A);
    int y=-1;
    if(A==20) y=9;
    else if(A==200) y=69;
    else assert(0);
    int q=0;
    fru(i,y/3){
        set<pii> S;
        while(S.size()<9){
            ++q;
            int a=3*i+2,b=2;
            printf("%d %d\n",a,b);
            fflush(stdout);
            scanf("%d %d",&a,&b);
            if(a==0 && b==0) break;
            assert(a!=-1);
            S.insert({a,b});
        }
    }
    fprintf(stderr,"A = %d, questions = %d\n",A,q);
}

int main(){
    int o;
    scanf("%d",&o);
    fru(oo,o) solve();
    return 0;
}
