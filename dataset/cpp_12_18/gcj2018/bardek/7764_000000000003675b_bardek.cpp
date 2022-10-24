#include <bits/stdc++.h>
using namespace std;

#define fru(j,n) for(int j=0; j<(n); ++j)
#define tr(it,v) for(auto it=(v).begin(); it!=(v).end(); ++it)
#define x first
#define y second
#define pb push_back
#define ALL(G) (G).begin(),(G).end()

#if 0
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
const int MAXN = 100006;

pii P[MAXN];
unordered_map<int,vi> M;
unordered_map<int,int> ile;
unordered_set<int> S[MAXN];

int mmax;
int n;

void solve(){
    int n;
    scanf("%d",&n);
    DEB("\n");
    fru(i,n){
        int aa,bb,dd;
        scanf("%d%d%d",&dd,&aa,&bb);
        int a=dd+aa;
        int b=dd-bb;
        P[i]=pii(a,b);
        DEB("%d %d\n",a,b);
    }
    unordered_set<int> X,Y;
    fru(i,n) X.insert(P[i].x);
    fru(i,n) Y.insert(P[i].y);
    int najdl=0;
    unordered_set<int> spos;
    tr(x,X) tr(y,Y){
        int ile=0;
        fru(i,n){
            if(P[i].x==*x || P[i].y==*y){
                ++ile;
                if(najdl<ile){
                    najdl=ile;
                    spos.clear();
                }
                if(najdl==ile) spos.insert(i);
            }
            else ile=0;
        }
    }
    printf("%d %d\n",najdl,spos.size());
/*    int p=0,k=n+1;
    while(p+1<k){
        int m=(p+k)/2;
        if(ile(m)>0) p=m;
        else k=m;
    }
    printf("%d %d\n",k,ile(k));*/
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
